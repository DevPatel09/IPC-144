/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//



#include "core.h"


// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


// inputInt
int inputInt(void) {

    char character = ' ';
    int number;

    do {
        scanf("%d%c", &number, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }



    } while (character != '\n');

    return number;
}

//inputIntPositive
int inputIntPositive(void) {

    int number;
    char character = ' ';

    do {
        scanf("%d%c", &number, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        if (number <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    } while (number <= 0);

    return number;

}


// inputIntRange
int inputIntRange(int lowest, int highest) {
    char m = ' ';
    int n;

    do {
        scanf("%d%c", &n, &m);

        if (m != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (!(n <= highest && n >= lowest)) {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    } while (!(n <= highest && n >= lowest));

    return n;
}

// inputCharOption
char inputCharOption(char* Str)
{
    int a, b = 0;
    char user;

    do {
        scanf(" %c", &user);

        for (a = 0; Str[a] != '\0'; a++) {
            if (user == Str[a]) {
                b++;
            }
        }

        if (b == 0) {
            printf("ERROR: Character must be one of [%s]: ", Str);
        }
    } while (b == 0);

    clearInputBuffer();
    return user;

}

//inputCString
void inputCString(char* Str, int Min_Num, int Max_Num) {
    int flag = 1;
    char chr = 'a';

    while (flag) {
        int length = 0;
        // Takes a string as input until it sees a newline character
        while (chr != '\n' && length <= Max_Num) {
            chr = getchar();
            Str[length] = chr;
            length++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (chr == '\n' && length <= (Max_Num + 1)) {
            length--;
            Str[length] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            Str[Max_Num] = '\0';
            clearInputBuffer();
        }

        if (Min_Num == Max_Num && length != Min_Num) {
            printf("ERROR: String length must be exactly %d chars: ", Min_Num);
            chr = 'a';
        }
        else if (length < Min_Num || length > Max_Num) {
            if (length > Max_Num) {
                printf("ERROR: String length must be no more than %d chars: ", Max_Num);
                chr = 'a';
            }
            else if (length < Min_Num) {
                printf("ERROR: String length must be between %d and %d chars: ", Min_Num, Max_Num);
                chr = 'a';
            }
        }
        else {
            flag = 0;
        }
    }
}


void displayFormattedPhone(const char* Str) {
    int i;

    if (Str == NULL) {
        printf("(___)___-____");
        return;
    }

    for (i = 0; i < 10; i++) {
        if (Str[i] < '0' || Str[i] > '9') {
            printf("(___)___-____");
            return;
        }
    }

    if (Str[i] != '\0') {
        printf("(___)___-____");
        return;
    }

    printf("(%c%c%c)%c%c%c-%c%c%c%c", Str[0], Str[1], Str[2], Str[3], Str[4], Str[5], Str[6], Str[7], Str[8], Str[9]);
}

