/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P1)
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
#include <stdio.h>

int main()
{
	//Declaration of Variables
	int num_of_apples, num_of_orange, num_of_pears, num_of_tomatoes, num_of_cabbages, apples_picked, orange_picked, pears_picked, tomatoes_picked, cabbages_picked;
	int shopping_yes_or_not = 1;

	//Do While loop
	do {


		printf("Grocery Shopping\n================\n");

		//Asking user for number of APPLES they need
		printf("How many APPLES do you need? : ");
		scanf("%d%*c", &num_of_apples);

		//Loop will run if the number of apples is less than 0, else it won't run the loop again
		while (num_of_apples < 0)

		{
			printf("ERROR: Value must be 0 or more.\n");
			printf("How many APPLES do you need? : ");
			scanf("%d%*c", &num_of_apples);
		}

		//Asking user for number of ORANGES they need
		printf("\nHow many ORANGES do you need? : ");
		scanf("%d%*c", &num_of_orange);

		//Loop will run if the number of oranges is less than 0, else it won't run the loop again
		while (num_of_orange < 0)
		{
			printf("ERROR: Value must be 0 or more.\n");
			printf("How many ORANGES do you need? : ");
			scanf("%d%*c", &num_of_orange);
		}

		//Asking user for number of PEARS they need
		printf("\nHow many PEARS do you need? : ");
		scanf("%d%*c", &num_of_pears);
        
		//Loop will run if the number of pears is less than 0, else it won't run the loop again
		while (num_of_pears < 0)
		{
			printf("ERROR: Value must be 0 or more.\n");
			printf("How many PEARS do you need? : ");
			scanf("%d%*c", &num_of_pears);
		}

		//Asking user for number of TOMATOES they need
		printf("\nHow many TOMATOES do you need? : ");
		scanf("%d%*c", &num_of_tomatoes);

		//Loop will run if the number of tomatoes is less than 0, else it won't run the loop again
		while (num_of_tomatoes < 0)
		{
			printf("ERROR: Value must be 0 or more.\n");
			printf("How many TOMATOES do you need? : ");
			scanf("%d%*c", &num_of_tomatoes);
		}

		//Asking user for number of CABBAGES they need
		printf("\nHow many CABBAGES do you need? : ");
		scanf("%d%*c", &num_of_cabbages);

		//Loop will run if the number of cabbages is less than 0, else it won't run the loop again
		while (num_of_cabbages < 0)
		{
			printf("ERROR: Value must be 0 or more.\n");
			printf("How many CABBAGES do you need? : ");
			scanf("%d%*c", &num_of_cabbages);
		}

		//Displaying for the products
		printf("\n");
		printf("--------------------------\n");
		printf("Time to pick the products!\n");
		printf("--------------------------\n\n");

		while (num_of_apples > 0)
		{
			printf("Pick some APPLES... how many did you pick? : ");
			scanf("%d%*c", &apples_picked);

			if (apples_picked > num_of_apples)
			{
				printf("You picked too many... only %d more APPLE(S) are needed.\n", num_of_apples);
			}
			else if (apples_picked <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else if ((apples_picked > 0) && (apples_picked < num_of_apples))
			{
				printf("Looks like we still need some APPLES...\n");
				num_of_apples = num_of_apples - apples_picked;
			}
			else if (apples_picked == num_of_apples)
			{
				printf("Great, that's the apples done!\n\n");
				break;
			}
		}

		while (num_of_orange > 0)
		{
			printf("Pick some ORANGES... how many did you pick? : ");
			scanf("%d%*c", &orange_picked);

			if (orange_picked > num_of_orange)
			{
				printf("You picked too many... only %d more ORANGE(S) are needed.\n", num_of_orange);
			}
			else if (orange_picked <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else if ((orange_picked > 0) && (orange_picked < num_of_orange))
			{
				printf("Looks like we still need some ORANGES...\n");
				num_of_orange = num_of_orange - orange_picked;
			}
			else if (orange_picked == num_of_orange)
			{
				printf("Great, that's the oranges done!\n\n");
				break;
			}
		}

		while (num_of_pears > 0)
		{
			printf("Pick some PEARS... how many did you pick? : ");
			scanf("%d%*c", &pears_picked);
			if (pears_picked > num_of_pears)
			{
				printf("You picked too many... only %d more PEAR(S) are needed.\n", num_of_pears);
			}
			else if (pears_picked <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else if ((pears_picked > 0) && (pears_picked < num_of_pears))
			{
				printf("Looks like we still need some PEARS...\n");
				num_of_pears = num_of_pears - pears_picked;
			}
			else if (num_of_pears == pears_picked)
			{
				printf("Great, that's the pears done!\n\n");
				break;
			}
		}

		while (num_of_tomatoes > 0)
		{
			printf("Pick some TOMATOES... how many did you pick? : ");
			scanf("%d%*c", &tomatoes_picked);

			if (tomatoes_picked > num_of_tomatoes)
			{
				printf("You picked too many... only %d more TOMATO(ES) are needed.\n", num_of_tomatoes);
			}
			else if (tomatoes_picked <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else if ((tomatoes_picked > 0) && (tomatoes_picked < num_of_tomatoes))
			{
				printf("Looks like we still need some TOMATOES...\n");
				num_of_tomatoes = num_of_tomatoes - tomatoes_picked;
			}
			else if (tomatoes_picked == num_of_tomatoes)
			{
				printf("Great, that's the tomatoes done!\n\n");
				break;
			}
		}

		while (num_of_cabbages > 0)
		{
			printf("Pick some CABBAGES... how many did you pick? : ");
			scanf("%d%*c", &cabbages_picked);

			if (cabbages_picked > num_of_cabbages)
			{
				printf("You picked too many... only %d more CABBAGE(S) are needed.\n", num_of_cabbages);
			}
			else if (cabbages_picked <= 0)
			{
				printf("ERROR: You must pick at least 1!\n");
			}
			else if ((cabbages_picked > 0) && (cabbages_picked < num_of_cabbages))
			{
				printf("Looks like we still need some CABBAGES...\n");
				num_of_cabbages = num_of_cabbages - cabbages_picked;
			}
			else if (cabbages_picked == num_of_cabbages)
			{
				printf("Great, that's the cabbages done!\n\n");
				break;
			}
		}

		//All the items are picked!
		printf("All the items are picked!\n\n");

		//Asking user whether he/she want to do shopping again or not.
		printf("Do another shopping? (0=NO): ");
		scanf("%d%*c", &shopping_yes_or_not);
		printf("\n");
	} while (shopping_yes_or_not == 1);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}