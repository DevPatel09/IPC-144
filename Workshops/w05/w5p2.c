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
#define LOG_DAYS 3

int main()
{
	//Declaration of variables
	int JAN = 1, DEC = 12;
	int year, month;
	double morningrate, eveningrate, totalmor=0,totaleve=0,totalrate,avgmor,avgeve, avgoverall;

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

			int i;
			for (i = 1; i <= LOG_DAYS; i++)
			{
				//Switch is used for the specific output, according to the input that the user entered
				switch (month)
				{
				case 1:
					printf("%d-JAN-0%d", year, i);
					break;

				case 2:
					printf("%d-FEB-0%d", year, i);
					break;

				case 3:
					printf("%d-MAR-0%d", year, i);
					break;

				case 4:
					printf("%d-APR-0%d", year, i);
					break;

				case 5:
					printf("%d-MAY-0%d", year, i);
					break;

				case 6:
					printf("%d-JUN-0%d", year, i);
					break;

				case 7:
					printf("%d-JUL-0%d", year, i);
					break;

				case 8:
					printf("%d-AUG-0%d", year, i);
					break;

				case 9:
					printf("%d-SEP-0%d", year, i);
					break;

				case 10:
					printf("%d-OCT-0%d", year, i);
					break;

				case 11:
					printf("%d-NOV-0%d", year, i);
					break;

				case 12:
					printf("%d-DEC-0%d", year, i);
					break;
				}

				printf("\n   Morning rating (0.0-5.0): ");
				scanf("%lf", &morningrate);

				while ((morningrate < 0.0) || (morningrate > 5.0))
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
					printf("   Morning rating (0.0-5.0): ");
					scanf("%lf", &morningrate);
				}

				printf("   Evening rating (0.0-5.0): ");
				scanf("%lf", &eveningrate);

				while ((eveningrate < 0.0) || (eveningrate > 5.0))
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
					printf("   Evening rating (0.0-5.0): ");
					scanf("%lf", &eveningrate);
				}
				printf("\n");
				totalmor += morningrate;
				totaleve += eveningrate;
			}
			loop = 1;
	    }

	}
	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", totalmor);
	printf("Evening total rating:  %.3lf\n", totaleve);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n\n", totalrate = totalmor + totaleve);

	printf("Average morning rating:  %.1lf\n", avgmor = totalmor / 3.0);
	printf("Average evening rating:  %.1lf\n", avgeve = totaleve / 3.0);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1lf\n", avgoverall = (avgmor+avgeve)/2.0);


	return 0;
}