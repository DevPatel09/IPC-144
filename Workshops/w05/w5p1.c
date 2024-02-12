/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5 (P1)
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

//using magic numbers (macro directive)
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main()
{
	//Declaration of variables
	int JAN = 1, DEC = 12;
	int year, month;

	//Declaration of flag variable
	int loop = 0;

	//Displaying Output
	printf("General Well-being Log\n");
	printf("======================\n");

	//using while loop, we will rotate the loop
	while (loop == 0)
	{
		//Displaying Output 
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);

		if (((year < MIN_YEAR) || (year > MAX_YEAR)) && ((month >= JAN) && (month <= DEC)))
		{
			//If this condition is satisfied, then this will be printed
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
		}
		if (((year >= MIN_YEAR) && (year <= MAX_YEAR)) && ((month < JAN) || (month > DEC)))
		{
			//If this condition is satisfied, then this will be printed
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		if (((year < MIN_YEAR) || (year > MAX_YEAR)) && ((month < JAN) || (month > DEC)))
		{
		    //If this condition is satisfied, then this will be printed
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		 if (((year >= MIN_YEAR) && (year <= MAX_YEAR)) && ((month >= JAN) && (month <= DEC)))
		{
			//If this condition is satisfied, then this will be printed
			printf("\n*** Log date set! ***\n\n");

			//Switch is used for the specific output, according to the input that the user entered
			switch (month)
			{
			case 1:
				printf("Log starting date: %d-", year);
				printf("JAN-01");
				break;

			case 2:
				printf("Log starting date: %d-", year);
				printf("FEB-01");
				break;

			case 3:
				printf("Log starting date: %d-", year);
				printf("MAR-01");
				break;

			case 4:
				printf("Log starting date: %d-", year);
				printf("APR-01");
				break;

			case 5:
				printf("Log starting date: %d-", year);
				printf("MAY-01");
				break;
			case 6:
				printf("Log starting date: %d-", year);
				printf("JUN-01");
				break;
			case 7:
				printf("Log starting date: %d-", year);
				printf("JUL-01");
				break;
			case 8:
				printf("Log starting date: %d-", year);
				printf("AUG-01");
				break;
			case 9:
				printf("Log starting date: %d-", year);
				printf("SEP-01");
				break;
			case 10:
				printf("Log starting date: %d-", year);
				printf("OCT-01");
				break;
			case 11:
				printf("Log starting date: %d-", year);
				printf("NOV-01");
				break;
			case 12:
				printf("Log starting date: %d-", year);
				printf("DEC-01");
				break;
			}
			printf("\n");
			loop = 1;
		}
	}

	return 0;
}