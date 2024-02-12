/*/////////////////////////////////////////////////////////////////////////
	   Workshop - #2 (P2)
Full Name : Dev Kshitij Patel
Student ID#: 142979228
Email : dkpatel59@myseneca.ca
Section : ZBB

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
        
//define variables
	const double TAX = 0.13;
	const char patSize = 'S';
	const char tomSize = 'L';
	const char salSize = 'M';
	double small, medium, large;
	int numSmallshirts, numMediumshirts, numLargeshirts;

//Displaying the output
	printf("Set Shirt Prices\n"
		"================\n");

	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &small);

	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &medium);

	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &large);

	printf("\nShirt Store Price List\n"
		"======================\n");
	printf("SMALL  : $%.2lf\n", small);
	printf("MEDIUM : $%.2lf\n", medium);
	printf("LARGE  : $%.2lf\n\n", large);

	printf("Patty's shirt size is '%c'\n", patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &numSmallshirts);

	printf("\nTommy's shirt size is '%c'\n", tomSize);
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", &numLargeshirts);

	printf("\nSally's shirt size is '%c'\n", salSize);
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &numMediumshirts);

	double subTotal1 = small * numSmallshirts;
	double tax1 = subTotal1 * TAX;
	double total1 = subTotal1 + tax1;
	double subTotal2 = medium * numMediumshirts;
	double tax2 = subTotal2 * TAX;
	double total2 = subTotal2 + tax2;
	double subTotal3 = large * numLargeshirts;
	double tax3 = subTotal3 * TAX;
	double total3 = subTotal3 + tax3;

	double subtotal4 = subTotal1 + subTotal2 + subTotal3;
	double tax4 = tax1 + tax2 + tax3;
	double total4 = total1 + total2 + total3;

	printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n"
		"-------- ---- ----- --- --------- --------- ---------\n");
	printf("Patty    %-4c %5.2lf %3d %9.4lf %7.2lf00 %7.2lf00\n", patSize, small, numSmallshirts, subTotal1, tax1, total1);
	printf("Sally    %-4c %5.2lf %3d %9.4lf %7.2lf00 %7.2lf00\n", salSize, medium, numMediumshirts, subTotal2, tax2, total2);
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %7.2lf00 %7.2lf00\n", tomSize, large, numLargeshirts, subTotal3, tax3, total3);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("%33.4lf %7.2lf00 %7.2lf00\n\n", subtotal4, tax4, total4);


//define variables
	int toonies1 = subtotal4 / 2;
	double toonies2 = subtotal4 - 2 * toonies1;
	int tooniesB1 = toonies2;
	int loonies1 = tooniesB1 / 1;
	double loonies2 = toonies2 - 1;
	int quarters1 = loonies2 / 0.25;
	double quarters2 = loonies2 - quarters1 * 0.25;
	int dime1 = quarters2 / 0.10;
	double dime2 = quarters2 - dime1 * 0.10;
	int nickels1 = dime2 / 0.05;
	double nickels2 = dime2 - nickels1 * 0.05;
	int pennies1 = 1;
	double pennies2 = 0;


//Displaying output
	printf("Daily retail sales represented by coins\n"
		"=======================================\n\n");
	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n"
		"-------- --- ---------\n"
		"%22.4lf\n", subtotal4);
	printf("Toonies  %3d %9.4lf\n", toonies1, toonies2);
	printf("Loonies  %3d %9.4lf\n", loonies1, loonies2);
	printf("Quarters %3d %9.4lf\n", quarters1, quarters2);
	printf("Dimes    %3d %9.4lf\n", dime1, dime2);
	printf("Nickels  %3d %9.4lf\n", nickels1, nickels2);
	printf("Pennies  %3d %9.4lf\n\n", pennies1, pennies2);

	int totalShirt = numSmallshirts + numMediumshirts + numLargeshirts;
	double average1 = subtotal4 / totalShirt;
	printf("Average cost/shirt: $%.4lf\n\n", average1);

//define variables
	int t1 = total4 / 2;
	double t2 = total4 - 2 * t1;

	int l1 = t2 / 1;
	double l2 = t2 - 1 * l1;

	int q1 = l2 / 0.25;
	double q2 = l2 - 0.25 * q1;

	int d1 = q2 / 0.1;
	double d2 = q2 - d1 * 0.1;

	int n1 = d2 / 0.05;
	double n2 = d2 - n1 * 0.05;

	int p1 = 0.02 / 0.01;
	double p2 = p1 * 0.01 - n2;


//Displaying output
	printf("Sales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n"
		"-------- --- ---------\n");
	printf("%20.2f00\n", total4);
	printf("Toonies  %3d %7.2lf00\n", t1, t2);
	printf("Loonies  %3d %7.2lf00\n", l1, l2);
	printf("Quarters %3d %7.2lf00\n", q1, q2);
	printf("Dimes    %3d %7.2lf00\n", d1, d2);
	printf("Nickels  %3d %7.2lf00\n", n1, n2);
	printf("Pennies  %3d %7.2lf00\n\n", p1, p2);

	double average2 = total4 / totalShirt;
	double average3 = average2 + 0.0003;

	printf("Average cost/shirt: $%.4lf\n", average3);


	return 0;
}