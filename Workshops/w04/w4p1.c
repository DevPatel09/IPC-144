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

int main(void)
{
    int iteration ;
    char letter;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+");
    

    do  
    {
        printf("\n");
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf("%c%d%*c", &letter, &iteration);
        
        if (letter == 'D')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("DO-WHILE: ");
                int i = 0;
                do 
                {
                    printf("D");
                    i++;
                } while (i < iteration);
            }
            else 
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }

        else if (letter == 'W')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("WHILE   : ");
                int i = 0;

                while (i < iteration)
                {
                    printf("W");
                    i++;
                }
                
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }

        else if (letter == 'F')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("FOR     : ");
                int i;
                for (i = 0;i < iteration;i++)
                {
                    printf("F");
                }
                
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
            }
        }

        else if (letter == 'Q')
        {
            if (iteration == 0)
            {
                printf("\n+--------------------+\nLoop application ENDED\n+--------------------+\n");
            }
            else {
                printf("ERROR: To quit, the number of iterations should be 0!");
            }
        }
        else 
        {
            printf("ERROR: Invalid entered value(s)!");
        }
    }

    while (!(letter == 'Q' && iteration == 0)); 
    




    return 0;
}