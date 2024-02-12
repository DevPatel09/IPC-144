/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    //Declation of variables
    char c1_type, c2_type, c3_type, c1_cream, c2_cream, c3_cream, coffee_strength1, coffee_with_cream1, coffee_strength2, coffee_with_cream2;
    int c1_weight, c2_weight, c3_weight, number_of_servings1, number_of_servings2;

    //Output
    printf("Take a Break - Coffee Shop\n==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    //Output for Coffee-1
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &c1_type);
    printf("Bag weight (g): ");
    scanf("%d%*c", &c1_weight); 
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &c1_cream);

    //Output for Coffee-2
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &c2_type);
    printf("Bag weight (g): ");
    scanf("%d%*c", &c2_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &c2_cream);

    //Output for Coffee-3
    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &c3_type);
    printf("Bag weight (g): ");
    scanf("%d%*c", &c3_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &c3_cream);

    printf("\n");

    //Output for table 1
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", c1_type == 'L' || c1_type == 'l', c1_type == 'M' || c1_type == 'm', c1_type == 'R' || c1_type == 'r', c1_weight, c1_weight / GRAMS_IN_LBS, c1_cream == 'y' || c1_cream == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", c2_type == 'L' || c2_type == 'l', c2_type == 'M' || c2_type == 'm', c2_type == 'R' || c2_type == 'r', c2_weight, c2_weight / GRAMS_IN_LBS, c2_cream == 'y' || c2_cream == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", c3_type == 'L' || c3_type == 'l', c3_type == 'M' || c3_type == 'm', c3_type == 'R' || c3_type == 'r', c3_weight, c3_weight / GRAMS_IN_LBS, c3_cream == 'y' || c3_cream == 'Y');

    printf("\n");

    printf("Enter how you like your coffee...\n\n");

    //Output for preference
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf("%c%*c", &coffee_strength1);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &coffee_with_cream1);
    printf("Typical number of daily servings: ");
    scanf("%d%*c", &number_of_servings1);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");
    
    //Output for table 2
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",((c1_type == 'l' || c1_type == 'L') && (coffee_strength1 == 'l' || coffee_strength1 == 'L')), number_of_servings1 >= 1 && number_of_servings1 <= 4, ((c1_cream == 'y' || c1_cream=='Y') && (coffee_with_cream1 == 'y' || coffee_with_cream1 == 'Y')) || ((c1_cream == 'n' || c1_cream == 'N') && (coffee_with_cream1 == 'n' || coffee_with_cream1 == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n",((c2_type == 'l' || c2_type == 'L') && (coffee_strength1 == 'l' || coffee_strength1 == 'L')), number_of_servings1 >= 5 && number_of_servings1 <= 9, ((c2_cream == 'y' || c2_cream=='Y') && (coffee_with_cream1 == 'y' || coffee_with_cream1 == 'Y')) || ((c2_cream == 'n' || c2_cream == 'N') && (coffee_with_cream1 == 'n' || coffee_with_cream1 == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n",((c3_type == 'l' || c1_type == 'M') && (coffee_strength1 == 'l' || coffee_strength1 == 'L')), number_of_servings1 >= 10, ((c3_cream == 'y' || c3_cream=='Y') && (coffee_with_cream1 == 'y' || coffee_with_cream1 == 'Y')) || ((c3_cream == 'n' || c3_cream == 'N') && (coffee_with_cream1 == 'n' || coffee_with_cream1 == 'N')));
    printf("\n");

    printf("Enter how you like your coffee...\n\n");

    //Output for prefernece
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf("%c%*c", &coffee_strength2);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &coffee_with_cream2);
    printf("Typical number of daily servings: ");
    scanf("%d%*c", &number_of_servings2);

    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");

    //Output for table 3
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",((c1_type == 'm' || c1_type == 'M') && (coffee_strength2 == 'm' || coffee_strength2 == 'M')), number_of_servings2 >= 1 && number_of_servings2 <= 4, ((c1_cream == 'y' || c1_cream == 'Y') && (coffee_with_cream2 == 'y' || coffee_with_cream2 == 'Y')) || ((c1_cream == 'n' || c1_cream == 'N') && (coffee_with_cream2 == 'n' || coffee_with_cream2 == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n",((c2_type == 'm' || c2_type == 'M') && (coffee_strength2 == 'm' || coffee_strength2 == 'M')), number_of_servings2 >= 5 && number_of_servings2 <= 9, ((c2_cream == 'y' || c2_cream == 'Y') && (coffee_with_cream2 == 'y' || coffee_with_cream2 == 'Y')) || ((c2_cream == 'n' || c2_cream == 'N') && (coffee_with_cream2 == 'n' || coffee_with_cream2 == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n",((c3_type == 'm' || c3_type == 'M') && (coffee_strength2 == 'm' || coffee_strength2 == 'M')), number_of_servings2 >= 10 , ((c3_cream == 'y' || c3_cream == 'Y') && (coffee_with_cream2 == 'y' || coffee_with_cream2 == 'Y')) || ((c3_cream == 'n' || c3_cream == 'N') && (coffee_with_cream2 == 'n' || coffee_with_cream2 == 'N')));

    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
 
    //END

    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/