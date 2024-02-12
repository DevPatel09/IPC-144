/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : Dev Kshitij Patel
Student ID#: 142979228
Email      : dkpatel59@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* a)
{
	//Declaring variable
	int value1;

	//do-while loop for value1
	do {
		scanf("%d%*c", &value1);

		if (value1 <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (value1 <= 0);

	if (a != NULL)
	{
		*a = value1;
	}

	//returning value1
	return value1;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* b)
{
	//Declaring variable
	double value1;

	//do-while loop for value1
	do {
		scanf("%lf", &value1);
		if (value1 <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (value1 <= 0);

	if (b != NULL)
	{
		*b = value1;
	}

	//returning value1
	return value1;

}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(int number)
{
	//Displaying Output
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n\n", NUM_OF_GRAMS);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int number)
{
	//Allocating memory
	struct CatFoodInfo cat1;

	//Flag
	int z;

	//DIsplaying Output
	printf("Cat Food Product #%d\n", number + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	z = 1;

	//do-while loop for SKU
	do {
		scanf("%d%*c", &cat1.sku);

		if (cat1.sku <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			z = 0;
		}

	} while (z);

	//Displaying Output
	printf("PRICE         : $");

	//Initializing flag as 1
	z = 1;

	//do-while loop for PRICE
	do {
		scanf("%lf", &cat1.productPrice);

		if (cat1.productPrice <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			z = 0;
		}

	} while (z);

	//Displaying Output
	printf("WEIGHT (LBS)  : ");

	//Initializing flag as 1
	z = 1;

	//do-while loop for WEIGHT
	do {
		scanf("%lf", &cat1.productWeight);

		if (cat1.productWeight <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			z = 0;
		}

	} while (z);

	//Displaying Output
	printf("CALORIES/SERV.: ");

	//Initializing flag as 1
	z = 1;

	//do-while loop for CALORIES
	do {
		scanf("%d", &cat1.caloriesPerServings);

		if (cat1.caloriesPerServings <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			z = 0;
		}

	} while (z);

	printf("\n");

	//returning cat1 
	return cat1;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	//Displaying Output
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double *price, double *weight, int calorie)
{
	//Displaying Output
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calorie);
}



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* Lb_To_Kg) {

	double LBSTOKG = (*pounds) / LBTOKG;

	if (Lb_To_Kg != NULL)
	{
		*Lb_To_Kg = LBSTOKG;
	}

	return LBSTOKG;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* LB_TO_G) {

	int LBSTOG = ((*pounds) / LBTOKG) * 1000;

	if (LB_TO_G != NULL)
	{
		*LB_TO_G = LBSTOG;
	}

	return LBSTOG;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* Lb_To_Kg, int* LB_TO_G) {

	double LBSTOKG = (*pounds) / LBTOKG;
	int LBSTOG = ((*pounds) / LBTOKG) * 1000;

	if (LB_TO_G != NULL && Lb_To_Kg != NULL)
	{
		*LB_TO_G = LBSTOG;
		*Lb_To_Kg = LBSTOKG;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int SizeGrams, const int Grams, double* Num_Of_Servings) {

	double servings = ((double)Grams) / SizeGrams;

	if (Num_Of_Servings != NULL)
	{
		*Num_Of_Servings = servings;
	}

	return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* Num_Of_Servings, double* Answer) {

	double Cost_Per_Serving = (*price) / (*Num_Of_Servings);

	if (Answer != NULL)
	{
		*Answer = Cost_Per_Serving;
	}

	return Cost_Per_Serving;
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* Answer) {

	double Cost_Per_Calorie = (*price) / (*calories);

	if (Answer != NULL)
	{
		*Answer = Cost_Per_Calorie;
	}

	return Cost_Per_Calorie;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cat1) {

	struct ReportData Data;

	// Assigning Values
	Data.sku = cat1.sku;
	Data.productPrice = cat1.productPrice;
	Data.productWeightPounds = cat1.productWeight;
	Data.caloriesPerServings = cat1.caloriesPerServings;

	// Assigning calculated values
	Data.productWeightKilos = convertLbsKg(&Data.productWeightPounds, &Data.productWeightKilos);
	Data.productWeightGrams = convertLbsG(&Data.productWeightPounds, &Data.productWeightGrams);
	Data.servings = calculateServings(NUM_OF_GRAMS, Data.productWeightGrams, &Data.servings);

	// Total calories
	double totalCalories = Data.caloriesPerServings * Data.servings;

	Data.costPerServing = calculateCostPerServing(&Data.productPrice, &Data.servings, &Data.costPerServing);
	Data.costCaloriesPerServing = calculateCostPerCal(&Data.productPrice, &totalCalories, &Data.costCaloriesPerServing);


	// Returning the struct
	return Data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_OF_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData Data, const int cheapestProductCheck) {

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", Data.sku, Data.productPrice, Data.productWeightPounds, Data.productWeightKilos, Data.productWeightGrams, Data.caloriesPerServings, Data.servings, Data.costPerServing, Data.costCaloriesPerServing);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cat1) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cat1.sku, cat1.productPrice);
	printf("\n");

	// Ending line
	printf("Happy shopping!\n");
	printf("\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	// Struct Arrays
	struct ReportData Data[MAX_PRODUCTS] = { {0} };
	struct CatFoodInfo cat1[MAX_PRODUCTS] = { {0} };

	// Declaring variables
	int i, cheapest = 0;

	// Printing the opening message
	openingMessage(MAX_PRODUCTS);

	// Filling the cfi array
	for (i = 0; i < MAX_PRODUCTS; i++) {
		cat1[i] = getCatFoodInfo(i);
		Data[i] = calculateReportData(cat1[i]);
	}

	// Dsiplaying cat food header
	displayCatFoodHeader();

	// Displaying cat food data
	for (i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(cat1[i].sku, &cat1[i].productPrice, &cat1[i].productWeight, cat1[i].caloriesPerServings);
	}

	// Determining the cheapest product's sku and price
	double cheapestPrice = Data[0].costPerServing;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (Data[i].costPerServing <= cheapestPrice)
		{
			cheapestPrice = Data[i].costPerServing;
			cheapest = i;
		}
	}
	printf("\n");

	// Displaying the report header
	displayReportHeader();

	// Displaying the report data
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(Data[i], cheapest);

		if (cheapest == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	// Displaying final analysis
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (i == cheapest)
		{
			displayFinalAnalysis(cat1[i]);
		}
	}
}
