/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Dev Kshitij Patel
Student ID#: 142979228
Email      : dkpatel59@myseneca.ca
Section    : IPC144 - ZBB

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main(void)
{
    double small, medium, large;
    int numSshirts,numMshirts,numLshirts;
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
   

    printf("Set Shirt Prices\n================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf_s("%lf", &small);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf_s("%lf", &medium);

    printf("Enter the price for a LARGE shirt: $");
    scanf_s("%lf", &large);

    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%.2lf\n", small);
    printf("MEDIUM : $%.2lf\n", medium);
    printf("LARGE  : $%.2lf\n", large);

    printf("\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf_s("%d", &numSshirts);

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf_s("%d", &numLshirts);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf_s("%d", &numMshirts);

    
    double subtotal1 = small * numSshirts;
    double tax1 = TAX * subtotal1;
    double total1 = subtotal1 + tax1;
    double subtotal2 = medium * numMshirts;
    double tax2 = TAX * subtotal2;
    double total2 = subtotal2 + tax2;
    double subtotal3 = large * numLshirts;
    double tax3 = TAX * subtotal3;
    double total3 = subtotal3 + tax3;
    double subtotal4 = subtotal1 + subtotal2 + subtotal3;
    double tax4 = tax1 + tax2 + tax3;
    double total4 = total1 + total2 + total3;
    

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf(  "-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %7.2lf00 %7.2lf00\n", patSize, small, numSshirts, subtotal1, tax1, total1);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %7.2lf00 %7.2lf00\n", salSize, medium, numMshirts, subtotal2, tax2, total2);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %7.2lf00 %7.2lf00\n", tomSize, large, numLshirts, subtotal3, tax3, total3);
    printf(  "-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %7.2lf00 %7.2lf00\n\n", subtotal4, tax4, total4);
    int dummy = (int)subtotal4;

    int toonies1 = dummy / 2;
    double toonies2 = subtotal4 - 2 * toonies1;
    int tooniesA1 = toonies2 ;
    int loonies1 = tooniesA1 / 1;
    double loonies2 = toonies2 - 1;
    int quarters1 = loonies2 / 0.25;
    double quarters2 = loonies2 - quarters1 * 0.25;
    int dimes1 = quarters2 / 0.10;
    double dimes2 = quarters2 - dimes1 * 0.10;
    int nickels1 = dimes2 / 0.05;
    double nickels2 = dimes2 - nickels1 * 0.05;
    int pennies1 = nickels2 / 0.01;
    double pennies2 = nickels2 - pennies1 * 0.01;



    printf("Daily retail sales represented by coins\n=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4f\n", subtotal4);
    printf("Toonies  %3d %9.4lf\n", toonies1, toonies2);
    printf("Loonies  %3d %9.4lf\n", loonies1, loonies2);
    printf("Quarters %3d %9.4lf\n", quarters1, quarters2);
    printf("Dimes    %3d %9.4lf\n", dimes1, dimes2);
    printf("Nickels  %3d %9.4lf\n", nickels1, nickels2);
    printf("Pennies  %3d %9.4lf\n\n", pennies1, pennies2);


    int totalshirts = numMshirts + numLshirts + numSshirts;
    double average1 = subtotal4 / totalshirts;
    printf("Average cost/shirt: $%.4lf\n", average1);
    
    int toonies3 = total4 / 2;
    double toonies4 = total4 - 2 * toonies3;
    int tooniesB = toonies4;
    int loonies3 = toonies4 / 1;
    double loonies4 = toonies4 - loonies3;
    int quarters3 = loonies4 / 0.25;
    double quarters4 = loonies4 - quarters3 * 0.25;
    int dimes3 = quarters4 / 0.10;
    double dimes4 = quarters4 - dimes3 * 0.10;
    int nickels3 = dimes4 / 0.05;
    double nickels4 = dimes4 - nickels3 * 0.05;
    int pennies3 = nickels4 / 0.01;
    double pennies4 = nickels4 - pennies3 * 0.01;
    

    printf("\nSales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%20.2lf00\n",total4);
    printf("Toonies  %3d %7.2lf00\n", toonies3, toonies4);
    printf("Loonies  %3d %7.2lf00\n", loonies3, loonies4);
    printf("Quarters %3d %7.2lf00\n", quarters3, quarters4);
    printf("Dimes    %3d %7.2lf00\n", dimes3, dimes4);
    printf("Nickels  %3d %7.2f00\n", nickels3, nickels4);
    printf("Pennies  %3d %7.2f00\n\n", pennies3, pennies4);

    double average2 = 0.0003+ total4 / totalshirts;

    printf("Average cost/shirt: $%.4lf\n", average2);




    






    return 0;
}