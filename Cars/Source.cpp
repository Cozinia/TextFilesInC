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

void printAllCars(Car car) 
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

			
			printf("\nCar ID: %d\n", car.carID);
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

void printCar(Car car) 
{

	printf("\nCar ID: %d\n", car.carID);
	printf("Make: %s\n", car.make);
	printf("Model: %s\n", car.model);
	printf("Year: %d\n", car.year);
	printf("Horsepower: %d\n", car.horsepower);
	printf("Kilometers: %d\n", car.mileage);
	printf("Fuel type: %s\n", car.fuelType);
	printf("Transmission: %s\n", car.gearbox);
	printf("Was in accident? %s\n", car.wasInAccident);

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

Car readCarFromFile(Car car, FILE* readFile) 
{
	fscanf(readFile, "\nCar ID: %d\n", &car.carID);
	fscanf(readFile, "Make: %s\n", car.make);
	fscanf(readFile, "Model: %s\n", car.model);
	fscanf(readFile, "Year: %d\n", &car.year);
	fscanf(readFile, "Horsepower: %d\n", &car.horsepower);
	fscanf(readFile, "Kilometers: %d\n", &car.mileage);
	fscanf(readFile, "Fuel: %s\n", car.fuelType);
	fscanf(readFile, "Trasmission: %s\n", car.gearbox);
	fscanf(readFile, "Was in accident? %s\n", car.wasInAccident);

	return car;
}

void writeInFile(Car car, FILE* writeFile) 
{

	fprintf(writeFile, "\nCar ID: %d\n", car.carID);
	fprintf(writeFile, "Make: %s\n", car.make);
	fprintf(writeFile, "Model: %s\n", car.model);
	fprintf(writeFile, "Year: %d\n", car.year);
	fprintf(writeFile, "Horsepower: %d\n", car.horsepower);
	fprintf(writeFile, "Kilometers: %d\n", car.mileage);
	fprintf(writeFile, "Fuel: %s\n", car.fuelType);
	fprintf(writeFile, "Trasmission: %s\n", car.gearbox);
	fprintf(writeFile, "Was in accident? %s\n", car.wasInAccident);

	return;
}

//void deleteCar(int carID, Car writeCar) {
//	FILE* readFile = fopen("cars.txt", "r");
//	FILE* writeFile = fopen("carsTemp.txt", "w");
//	FILE* readFromTempFile = fopen("carsTemp.txt", "r");
//	FILE* writeInOriginalFile = fopen("cars.txt", "w");
//	if (readFile != NULL)
//	{
//		while (!feof(readFile))
//		{
//			writeCar = readCarFromFile(writeCar, readFile);
//			if (writeCar.carID != carID)
//			{
//				writeInFile(writeCar, writeFile);
//
//			}
//		}
//		fclose(readFile);
//		fclose(writeFile);
//		printf("\nCar was deleted!");
//	}
//	else {
//		printf("Couldn't open cars.txt\n");
//	}
//
//	if (readFromTempFile != NULL)
//	{
//		while (!feof(readFromTempFile))
//		{
//			writeCar = readCarFromFile(writeCar, readFromTempFile);
//			writeInFile(writeCar, writeInOriginalFile);
//		}
//		fclose(readFromTempFile);
//		fclose(writeInOriginalFile);
//	}
//	return;
//}

void searchCar(Car car, int searchCarID) {
	FILE* readFile = fopen("cars.txt", "r");
	if (readFile != NULL)
	{
		//printf("\nCars: \n");
		while (!feof(readFile))
		{
			car = readCarFromFile(car, readFile);
			if (car.carID == searchCarID)
			{

				printCar(car);

			}
		}
		fclose(readFile);
	}
	else {
		printf("Couldn't open cars.txt\n");
	}
	return;
}

//Test delete car
void deleteCar(int searchCarID, Car car) {
	FILE* readFile = fopen("cars.txt", "r");
	FILE* file = fopen("carsTemp2.txt", "a+");
	if (readFile != NULL)
	{
		//printf("\nCars: \n");
		while (!feof(readFile))
		{
			car = readCarFromFile(car, readFile);
			if (car.carID != searchCarID)
			{
					fprintf(file, "\nCar ID: %d\n", car.carID);
			}
		}
		fclose(readFile);
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
				printAllCars(newCar);
			}
			else {
				printAllCars(newCar);
			}
			break;
			//Delete car
		case 3:
			printf("\nDelete car");
			printf("\nEnter car ID:");
			scanf("%d", &userCarID);
			deleteCar(userCarID, newCar);
			break;
			//Search car
		case 4:
			printf("\Search car");
			printf("\nEnter car ID:");
			scanf("%d", &userCarID);
			searchCar(newCar, userCarID);
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