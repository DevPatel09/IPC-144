/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
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
    // You must use this variable in #3 data analysis section!
    //Declartion of variables
    const double testValue = 330.99;
    const int id1 = 111;
    const int id2 = 222;
    const int id3 = 111;
    const char tax1 = 'Y';
    const char tax2 = 'N';
    const char tax3 = 'N';
    const double price1 = 111.4900, price2 = 222.9900, price3 = 334.4900;
    double average = (price1+price2+price3)/3;
    double price4 = price1 + price2;
    
    //Output
    printf("Product Information\n===================\n"); 
    printf("Product-1 (ID:%d)\n", id1);
    printf("  Taxed: %c\n", tax1);
    printf("  Price: $%.4lf\n\n", price1);
    printf("Product-2 (ID:%d)\n", id2);
    printf("  Taxed: %c\n", tax2);
    printf("  Price: $%.4lf\n\n", price2);
    printf("Product-3 (ID:%d)\n", id3);
    printf("  Taxed: %c\n", tax3);
    printf("  Price: $%.4lf\n\n", price3);

    printf("The average of all prices is: $%.4lf\n\n", average);

    printf("About Relational and Logical Expressions!\n========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n=====================\n");

    printf("1. Is product 1 taxable? -> %d\n\n", tax1 == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", tax2 == 'N' && tax3 == 'N');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, price3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", price3 > price4);
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", price1 >= price3 - price2, price3 - price2);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", price2 >= average);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", (id1 != id2) && (id1 != id3));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", (id2 != id1) && (id2 != id3));
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", (id3 != id1) && (id3 != id1));

    return 0;
}