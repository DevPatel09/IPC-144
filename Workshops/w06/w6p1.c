/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

//Macrodirective
#define itemsMax 10
#define minCost 500.00
#define maxCost 400000.00
#define minCost1 100.00

#include <stdio.h>


int main(void)
{
   //Variable Declaration
    double netIncome, finalCost=0;
    int wishList;
    int i,j;
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

        for (j = 0;j < wishList;j++)
        {
            printf("%3d %6d %8c %14.2lf\n", j + 1, itemPriority[j], itemFinance[j], itemCost[j]);
            finalCost += itemCost[j];
        }

        printf("---- -------- -------- -----------\n");
        printf("                      $ %.2lf\n\n", finalCost);
        printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}