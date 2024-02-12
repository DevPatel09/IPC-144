/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : Dev Kshitij patel
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

//Macrodirective
#define itemsMax 10
#define minCost 500.00
#define maxCost 400000.00
#define minCost1 100.00

int main(void)
{

    {
        //Variable Declaration
        double netIncome, finalCost = 0;
        int wishList;
        int i;
        double itemCost[itemsMax];
        int itemPriority[itemsMax];
        char itemFinance[itemsMax];
        
                //Displaying the output
                printf("+--------------------------+\n");
                printf("+   Wish List Forecaster   |\n");
                printf("+--------------------------+\n\n");

                //loop for monthly net income
                do {
                    printf("Enter your monthly NET income: $");
                    scanf("%lf%*c", &netIncome);

                    if (netIncome < minCost)
                    {
                        printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
                    }
                    if (netIncome > maxCost)
                    {
                        printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
                    }

                } while ((netIncome < minCost) || (netIncome > maxCost));


                printf("\n");

                //loop for forecast
                do {
                    printf("How many wish list items do you want to forecast?: ");
                    scanf("%d%*c", &wishList);

                    if (wishList < 1)
                    {
                        printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
                    }
                    if (wishList > 10)
                    {
                        printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
                    }
                } while ((wishList < 1) || (wishList > 10));


                // loop for item details
                for (i = 0;i < wishList;i++)
                {
                    printf("\nItem-%d Details:\n", i + 1);

                    do {
                        printf("   Item cost: $");
                        scanf("%lf%*c", &itemCost[i]);
                        if (itemCost[i] < minCost)
                        {
                            printf("      ERROR: Cost must be at least $100.00\n");
                        }
                    } while (itemCost[i] < minCost1);


                    do {
                        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                        scanf("%d%*c", &itemPriority[i]);
                        if (itemPriority[i] < 1 || itemPriority[i]>3)
                        {
                            printf("      ERROR: Value must be between 1 and 3\n");
                        }
                    } while (itemPriority[i] < 1 || itemPriority[i]>3);


                    do {
                        printf("   Does this item have financing options? [y/n]: ");
                        scanf("%c%*c", &itemFinance[i]);
                        if (!(itemFinance[i] == 'y' || itemFinance[i] == 'n'))
                        {
                            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                        }

                    } while (!(itemFinance[i] == 'y' || itemFinance[i] == 'n'));
                }

                printf("\n");

                printf("Item Priority Financed        Cost\n");
                printf("---- -------- -------- -----------\n");

                for (i = 0;i < wishList;i++)
                {
                    printf("%3d %6d %8c %14.2lf\n", i + 1, itemPriority[i], itemFinance[i], itemCost[i]);
                    finalCost += itemCost[i];
                }

                printf("---- -------- -------- -----------\n");
                printf("                      $ %.2lf\n\n", finalCost);

        //Variable Declaration        
        int selection, filter, x ,z=0;
        double priorityCost = 0.0;
        //Do-While loop for asking for selection
        do {
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d", &selection);

            //If condition for selection=1
            if (selection == 1)
            {
                //Displaying Output
                printf("\n====================================================\n");
                printf("Filter:   All items\n");
                printf("Amount:   $%.2lf\n", finalCost);

                //Declaraing Variables for years and months forecast
                int years_forecast = (int)(finalCost / (12 * netIncome));
                int months_forecast = (int)((finalCost / netIncome) - (12 * years_forecast));

                //If condition for the month
                if ((finalCost / netIncome) - (12 * years_forecast) > months_forecast)
                {
                    //If month is more then it will add up
                    months_forecast++;
                }

                //Displaying output
                printf("Forecast: %d years, %d months\n", years_forecast, months_forecast);

                z = 0;
                for (x = 0;x < wishList;x++)
                {
                    if (itemFinance[x] == 'y')
                    {
                        z += 1;
                    }
                }
                if (z != 0)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n\n");

            }

            else if (selection == 2)
            {
                //do-While iteration for asking filter
                do {
                    printf("\nWhat priority do you want to filter by? [1-3]: ");
                    scanf("%d", &filter);
                } while (filter < 1 || filter>3);

                //initializing 
                priorityCost = 0.0;

                //For loop whether to add the sum if inside condition is true
                for (i = 0;i < wishList;i++)
                {
                    if (itemPriority[i] == filter)
                    {
                        priorityCost += itemCost[i];
                    }

                }

                //Displaying Output
                printf("\n====================================================\n");
                printf("Filter:   by priority (%d)\n", filter);
                printf("Amount:   $%.2lf\n", priorityCost);

                //Declaring Variables for years and months forecast
                int years_forecast = (int)(priorityCost / (12 * netIncome));
                int months_forecast = (int)((priorityCost / netIncome) - (12 * years_forecast));
                
                //If condition for the month
                if ((finalCost / netIncome) - (12 * years_forecast) > months_forecast)
                {
                    //If month is more then it will add up
                    months_forecast++;
                }

                //Displaying Output
                printf("Forecast: %d years, %d months\n", years_forecast, months_forecast);

                z = 0;
                for (x = 0;x < wishList;x++)
                {
                    if (itemFinance[x] == 'y' && itemPriority[x] == filter)
                    {
                        z += 1;
                    }
                }
                if (z != 0)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n\n");

            }

            //if the selection is out of the range
            else if (selection < 0 || selection>2)
            {
                printf("\nERROR: Invalid menu selection.\n\n");
            }


        } while (selection != 0);
       
    }

    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}