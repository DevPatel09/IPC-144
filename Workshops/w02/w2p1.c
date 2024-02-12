/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

int main(void)
{
    const double TAX = 0.13;
    //const char patSize = 'S';
    float small, medium, large,subtotal,taxes,total;
    int shirt;
    printf("Set Shirt Prices\n================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &small);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &medium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &large);

    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%.2f\n", small);
    printf("MEDIUM : $%.2f\n", medium);
    printf("LARGE  : $%.2f\n", large);

    printf("\nPatty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirt);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", shirt);

    printf("Sub-total: $%.4f\n",subtotal=shirt*small);
    printf("Taxes    : $%6.2f00\n", taxes = subtotal*TAX);
    printf("Total    : $%.2f00\n", total = subtotal + taxes);








    return 0;
}