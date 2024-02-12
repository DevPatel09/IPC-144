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
#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *a)
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

	} while (value1 <=0);

	if (a != NULL)
	{
		*a = value1;
	}
	
	//returning value1
	return value1;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *b)
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
		
	}while(value1<=0);

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
	printf("Cat Food Product #%d\n",number +1);
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
void displayCatFoodData(int sku, double price, double weight, int calorie)
{
	//Displaying Output
	printf("%07d %10.2lf %10.1lf %8d\n", sku, price, weight, calorie);
}


// 7. Logic entry point
void start()
{
	//Declaring Variable
	int i;

	struct CatFoodInfo cat1[MAX_PRODUCTS] = { {0} };

	//Calling of function openingMessag
	openingMessage(MAX_PRODUCTS);

	//for loop 
	for (i = 0;i < MAX_PRODUCTS;i++)
	{
		//Calling of function getCatFoodInfo and giving values to cat1, which is an array
		cat1[i] = getCatFoodInfo(i);
	}

	//Calling of function displayCatFoodHeader
	displayCatFoodHeader();

	//for loop
	for (i = 0;i < MAX_PRODUCTS;i++)
	{
		//Calling of function displayCatFoodData
		displayCatFoodData(cat1[i].sku, cat1[i].productPrice,  cat1[i].productWeight,cat1[i].caloriesPerServings);
	}

}
