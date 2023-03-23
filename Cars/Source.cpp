#include <stdio.h>
#include <string.h>
#include <stdlib.h>//for exit function
#include <ctype.h>
#pragma warning(disable:4996) //pentru a dezactiva _CRT_SECURE_NO_WARNINGS.

//global 
typedef struct {
	int carID;
	char make[32];
	char model[32];
	int year;
	int horsepower;
	int mileage;
	char fuelType[16];
	char gearbox[16];
	char wasInAccident[3];

}Car;


void printOptions() {

	printf("\nChoose option:\n");
	printf("1.Add car");
	printf("\t2. View cars");
	printf("\t3.Delete car");
	printf("\t4.Search car");
	printf("\t5.Close app\n");

	return;

}

Car addCar(Car newCar) {
	printf("Add new car\n");
	printf("Make: ");
	scanf("%s", newCar.make);
	printf("Model: ");
	scanf("%s", newCar.model);
	printf("Fabrication year: ");
	scanf("%d", &newCar.year);
	printf("Horsepower: ");
	scanf("%d", &newCar.horsepower);
	printf("Kilometers: ");
	scanf("%d", &newCar.mileage);
	printf("Fuel: ");
	scanf("%s", newCar.fuelType);
	printf("Transmission: ");
	scanf("%s", newCar.gearbox);
	printf("Was in accident? ");
	scanf("%s", newCar.wasInAccident);
	return newCar;
}

void printCar(Car car) 
{
	FILE* file = fopen("cars.txt", "r");
	if (file != NULL)
	{
		printf("\nCars: \n");
		while (!feof(file)) 
		{
			fscanf(file, "\nCar ID: %d\n", &car.carID);
			fscanf(file, "Make: %s\n", car.make);
			fscanf(file, "Model: %s\n", car.model);
			fscanf(file, "Year: %d\n", &car.year);
			fscanf(file, "Horsepower: %d\n", &car.horsepower);
			fscanf(file, "Kilometers: %d\n", &car.mileage);
			fscanf(file, "Fuel: %s\n", car.fuelType);
			fscanf(file, "Trasmission: %s\n", car.gearbox);
			fscanf(file, "Was in accident? %s\n", car.wasInAccident);

			
			printf("Car ID: %d\n", car.carID);
			printf("Make: %s\n", car.make);
			printf("Model: %s\n", car.model);
			printf("Year: %d\n", car.year);
			printf("Horsepower: %d\n", car.horsepower);
			printf("Kilometers: %d\n", car.mileage);
			printf("Fuel type: %s\n", car.fuelType);
			printf("Transmission: %s\n", car.gearbox);
			printf("Was in accident? %s\n", car.wasInAccident);
		}
		fclose(file);
	}
	else {
		printf("Couldn't open cars.txt\n");
	}

	return;
}

void saveCar(Car car) {
	FILE* file = fopen("cars.txt", "a+");
	if (file!= NULL)
	{
		fprintf(file, "\nCar ID: %d\n", car.carID);
		fprintf(file, "Make: %s\n", car.make);
		fprintf(file, "Model: %s\n", car.model);
		fprintf(file, "Year: %d\n", car.year);
		fprintf(file, "Horsepower: %d\n", car.horsepower);
		fprintf(file, "Kilometers: %d\n", car.mileage);
		fprintf(file, "Fuel: %s\n", car.fuelType);
		fprintf(file, "Trasmission: %s\n", car.gearbox);
		fprintf(file, "Was in accident? %s\n", car.wasInAccident);
		fclose(file);
		printf("The car was saved in file!\n");

	}
	else {
		printf("Couldn't open cars.txt\n");
	}

	return;
}

void deleteCar(int carID, Car car) {
	FILE* file = fopen("cars.txt", "w+");
	if (file != NULL)
	{
		printf("\nCars: \n");
		while (!feof(file))
		{
			fscanf(file, "\nCar ID: %d\n", &car.carID);
			if (car.carID != carID)
			{
				fscanf(file, "Make: %s\n", car.make);
				fscanf(file, "Model: %s\n", car.model);
				fscanf(file, "Year: %d\n", &car.year);
				fscanf(file, "Horsepower: %d\n", &car.horsepower);
				fscanf(file, "Kilometers: %d\n", &car.mileage);
				fscanf(file, "Fuel: %s\n", car.fuelType);
				fscanf(file, "Trasmission: %s\n", car.gearbox);
				fscanf(file, "Was in accident? %s\n", car.wasInAccident);

				fprintf(file, "\nCar ID: %d\n", car.carID);
				fprintf(file, "Make: %s\n", car.make);
				fprintf(file, "Model: %s\n", car.model);
				fprintf(file, "Year: %d\n", car.year);
				fprintf(file, "Horsepower: %d\n", car.horsepower);
				fprintf(file, "Kilometers: %d\n", car.mileage);
				fprintf(file, "Fuel: %s\n", car.fuelType);
				fprintf(file, "Trasmission: %s\n", car.gearbox);
				fprintf(file, "Was in accident? %s\n", car.wasInAccident);

			}
			else {
				continue;
			}
		}
		fclose(file);
		printf("\nCar was deleted!");
	}
	else {
		printf("Couldn't open cars.txt\n");
	}
	return;
}

void startMenu() {
	Car newCar;
	newCar.carID = 0;
	bool hasCars = false;
	int userOption, userCarID = 0;
	printOptions();
	scanf_s("%d", &userOption);
	while (userOption != 5)
	{
		switch (userOption)
		{
			//Add new car
		case 1:
			newCar = addCar(newCar);
			newCar.carID = newCar.carID +  1;
			hasCars = true;
			saveCar(newCar);
			break;
			//View cars from file
		case 2:
			if (hasCars)
			{
				printCar(newCar);
			}
			else {
				printf("\nThere are no cars registered.");
			}
			break;
			//Delete car
		case 3:
			printf("\nEnter car ID:");
			scanf("%d", &userCarID);
			deleteCar(userCarID, newCar);
			break;
			//Search car
		case 4:
			printf("\nNot implemented yet.");
			break;
			//Exit app
		case 5:
			exit(1);
			break;
		default:
			printf("I\nnvalid option, please enter another option!\n");
			break;
		}
		printOptions();
		scanf_s("%d", &userOption);
	}
		
	return;
}

int main() {

	startMenu();

	return 0;
}