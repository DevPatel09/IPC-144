/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, record = 0;

    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            record += 1;
        }
    }

    if (!record)
    {
        printf("*** No records found ***\n");
        printf("\n");
    }
    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int choose;

    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n..........................\n");
        printf("Selection: ");
        scanf("%d", &choose);
        printf("\n");

        if (choose == 1)
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }

        else if (choose == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();

        }
    } while (choose != 0);

}



// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)

{
    int x;//declaration of variables
    int number;
    int place;
    int t = 0;


    do
    {
        place = 0;

        if (patient[t].patientNumber == 0)
        {

            place = 1;
            number = t;

        }

        t++;
    }

    while (t < max && place == 0);

    if (place == 0)
    {
        printf("ERROR: Patient listing is FULL!");
        printf("\n\n");
    }

    else
    {

        x = nextPatientNumber(patient, max);
        patient[number].patientNumber = x;
        inputPatient(&patient[number]);
        printf("*** New patient record added ***");
        printf("\n\n");

    }
}


// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int number, x;
    printf("Enter the patient number: ");
    scanf("%d", &number);
    printf("\n");

    x = findPatientIndexByPatientNum(number, patient, max);

    if (x != -1)
    {
        
        menuPatientEdit(patient + x);

    }

    else
    {
        printf("ERROR: Patient record not found!\n");
    }
}


// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int number, x;
    char choose;
    printf("Enter the patient number: ");
    scanf("%d", &number);
    printf("\n");

    x = findPatientIndexByPatientNum(number, patient, max);

    if (x != -1)
    {
        
        printf("Name  : %s\n", patient[x].name);
        printf("Number: %05d\n", patient[x].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[x].phone.number);
        printf(" (%s)", patient[x].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");
        int y = 1;
        char nextInput;

        do {
            scanf(" %c%c", &choose, &nextInput);





            if ((choose == 'n' || choose == 'N') && (nextInput == '\n'))
            {
                printf("Operation aborted.");
                printf("\n\n");
                y = 0;
                clearInputBuffer();

            }
            else if ((choose == 'y' || choose == 'Y') && (nextInput == '\n'))
            {
                patient[x].patientNumber = 0;
                printf("Patient record has been removed!");
                printf("\n\n");
                y = 0;
            }

            else
            {

                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (y);

    }
    
    else
    {
        printf("ERROR: Patient record not found!");
        printf("\n\n");
        clearInputBuffer();
    }
}



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    //declaration of variables
    int i;
    int j;


    //Calling Sorting Function
    sortingAppointments(data->appointments, data->maxAppointments);

    //Calling Function
    displayScheduleTableHeader(NULL, 1);

    for (i = 0; i < data->maxAppointments; i++)

    {

        for (j = 0; j < data->maxPatient; j++)
        {

            if (data->appointments[i].PatientNumber && data->patients[j].patientNumber)
            {

                if (data->appointments[i].PatientNumber == data->patients[j].patientNumber)
                {

                    //Calling Function
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);

                }
            }
        }
    }

    printf("\n");
}
// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int EndOfDay = MAX_DAYS_IN_MONTH;//declaration of variables
    int t;
    int y;
    struct Date d;


    printf("Year        : ");
    d.year = inputIntPositive();


    printf("Month (1-12): ");
    d.month = inputIntRange(STARTING_MONTH, ENDING_MONTH);


    printf("Day (1-");
    if (d.month == 4 || d.month == 9 || d.month == 11)
    {

        EndOfDay = MIN_DAYS_IN_MONTH;

    }

    if (d.month == 2)
    {

        EndOfDay = DAYS_IN_NONLEAP_MONTH;

    }

    if (d.year % 4 == 0 && d.month == 2)
    {

        EndOfDay = DAYS_IN_LEAP_MONTH;
            

    }

    printf("%d)  : ", EndOfDay);
    d.day = inputIntRange(FIRSTDAY, EndOfDay);
    printf("\n");


    sortingAppointments(data->appointments, data->maxAppointments);


    displayScheduleTableHeader(&d, 0);

    for (t = 0; t < data->maxAppointments; t++)
    {

        for (y = 0; y < data->maxPatient; y++)
        {

            if (data->appointments[t].PatientNumber && data->patients[y].patientNumber)
            {

                if (data->appointments[t].PatientNumber == data->patients[y].patientNumber)
                {

                    if (data->appointments[t].date.year == d.year && data->appointments[t].date.month == d.month && data->appointments[t].date.day == d.day)
                    {

                        displayScheduleData(&data->patients[y], &data->appointments[t], 0);

                    }
                }
            }
        }
    }

    printf("\n");

}
// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* App, int MaxApp, struct Patient* patients, int MaxPatients)
{
    struct Date d;
    struct Time t;
    int EndOfDay = MAX_DAYS_IN_MONTH;
    int number, f, NotAvailabe = 1;

    printf("Patient Number: ");
    number = inputIntPositive();
    f = findPatientIndexByPatientNum(number, patients, MaxPatients);

    if (f >= 0)
    {
        while (NotAvailabe)
        {
            printf("Year        : ");
            d.year = inputIntPositive();

            printf("Month (1-12): ");
            d.month = inputIntRange(STARTING_MONTH, ENDING_MONTH);

            printf("Day (1-");

            if (d.month == 4 || d.month == 9 || d.month == 11)
            {
                EndOfDay = MIN_DAYS_IN_MONTH;
            }
            if (d.month == 2)
            {
                EndOfDay = DAYS_IN_NONLEAP_MONTH;
            }
            if (d.year % 4 == 0 && d.month == 2)
            {
                EndOfDay = DAYS_IN_LEAP_MONTH;
            }
            printf("%d)  : ", EndOfDay);
            d.day = inputIntRange(FIRSTDAY, EndOfDay);

            printf("Hour (0-23)  : ");
            t.hour = inputIntRange(MIN_HOUR, MAX_HOUR);

            printf("Minute (0-59): ");
            t.min = inputIntRange(MIN_MINUTE, MAX_MINUTE);

            if (verifyTimeSlot(d, t, App, MaxApp))
            {
                puts("\nERROR: Appointment timeslot is not available!\n");
            }
            else
            {
                while ((t.hour<START_HOUR || t.hour>END_HOUR) || (t.hour == END_HOUR && t.min > 0) || ((t.min % APPOINTMENT_INTERVAL) != 0))
                {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, APPOINTMENT_INTERVAL);
                    printf("Hour (0-23)  : ");
                    t.hour = inputIntRange(MIN_HOUR, MAX_HOUR);
                    printf("Minute (0-59): ");
                    t.min = inputIntRange(MIN_MINUTE, MAX_MINUTE);

                }
                NotAvailabe = 0;

            }
        }
        f = vacantNextSlot(App, MaxApp);
        App[f].date = d;
        App[f].time = t;
        App[f].PatientNumber = number;

        puts("\n*** Appointment scheduled! ***\n");
    }
    else
    {
        puts("\nERROR: Patient record not found!\n");
    }
    return;
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* App, int MaxApp, struct Patient* patients, int MaxPatients)
{
    struct Date d;//declaaration of variables
    int f;
    int number;
    int EndOfDay = 0;
    int Index;


    printf("Patient Number: ");
    number = inputIntPositive();
    f = findPatientIndexByPatientNum(number, patients, MaxPatients);

    if (f >= 0)
    {

        printf("Year        : ");
        d.year = inputIntPositive();


        printf("Month (1-12): ");
        d.month = inputIntRange(STARTING_MONTH, ENDING_MONTH);


        printf("Day (1-");

        if (d.month == 4 || d.month == 9 || d.month == 11)
        {

            EndOfDay = MIN_DAYS_IN_MONTH;

        }

        if (d.month == 2)
        {

            EndOfDay = DAYS_IN_NONLEAP_MONTH;

        }

        if (d.year % 4 == 0 && d.month == 2)
        {

            EndOfDay = DAYS_IN_LEAP_MONTH;

        }

        printf("%d)  : ", EndOfDay);
        d.day = inputIntRange(FIRSTDAY, EndOfDay);

        Index = validAppointment(number, d, App , MaxApp);

        if (Index >= 0)
        {
            printf("\n");

            displayPatientData(&patients[f], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y')
            {

                App[Index].PatientNumber = 0;
                puts("\nAppointment record has been removed!\n");

            }

            else
            {

                puts("ERROR: No appointment for this date!\n");
                
            }
        }
    }

    else
    {

        puts("ERROR: Patient record not found!\n");

    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int PatNumber, x;
    printf("Search by patient number: ");
    scanf("%d", &PatNumber);
    printf("\n");

    if (findPatientIndexByPatientNum(PatNumber, patient, max) != -1)
    {
        x = findPatientIndexByPatientNum(PatNumber, patient, max);
        printf("Name  : %s\n", patient[x].name);
        printf("Number: %05d\n", patient[x].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[x].phone.number);
        printf(" (%s)\n\n", patient[x].phone.description);


    }
    else
    {
        printf("*** No records found ***");
        printf("\n\n");
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, Match = 0;
    char PhoneNumber[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(PhoneNumber, sizeof(PhoneNumber), stdin);
    printf("\n");

    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, PhoneNumber) == 0)
        {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            Match++;
        }
    }
    printf("\n");

    if (Match == 0)
    {
        puts("*** No records found ***\n");
       
    }

}


// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, NextPatNum, MaxPatNum = patient[0].patientNumber;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > MaxPatNum)
        {
            MaxPatNum = patient[i].patientNumber;
        }
    }
    NextPatNum = MaxPatNum + 1;

    return NextPatNum;

}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }

    return -1;
}

//Function to sort the values using bubble sort
void sortingAppointments(struct Appointment appointments[], int maxAppointments) {
    int i, j;
    struct Appointment x;

    // Storing all the date and time values in minutes for comparison
    for (i = 0; i < maxAppointments; i++) {
        appointments[i].time.min = (appointments[i].date.year * 12 * 30 * 24 * 60) + (appointments[i].date.month * 30 * 24 * 60) + (appointments[i].date.day * 24 * 60) + (appointments[i].time.hour * 60) + appointments[i].time.min;
    }

    // Using bubble sort to compare minutes and then swap the structs
    for (i = maxAppointments - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appointments[j].time.min > appointments[j + 1].time.min)
            {
                x = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = x;
            }
        }
    }

    // Converting total minutes back to minutes
    for (i = 0; i < maxAppointments; i++) {
        appointments[i].time.min = appointments[i].time.min - (appointments[i].date.year * 12 * 30 * 24 * 60) - (appointments[i].date.month * 30 * 24 * 60) - (appointments[i].date.day * 24 * 60) - (appointments[i].time.hour * 60);
    }

}



struct Date convertDaysToMonth(void)
{
    int leapYear = 0;
    struct Date date = { 0 };

    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (%d-%d): ", STARTING_MONTH, ENDING_MONTH);
    date.month = inputIntRange(STARTING_MONTH, ENDING_MONTH);

    if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0) {
        leapYear = 1;
    }


    
    switch (date.month) {
    case 2:
        date.day = leapYear ? DAYS_IN_LEAP_MONTH : DAYS_IN_NONLEAP_MONTH;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        date.day = MIN_DAYS_IN_MONTH;
        break;
    default:
        date.day = MAX_DAYS_IN_MONTH;
        break;
    }
    printf("Day (%d-%d)  : ", FIRSTDAY, date.day);
    date.day = inputIntRange(FIRSTDAY, date.day);

    return date;
}





int verifyTimeSlot(const struct Date date, const struct Time time,
    const struct Appointment* App, int MaxApp)
{
    int t;//declaration of variables
    int TimeSlotAvailable = 0;

    for (t = 0; t < MaxApp; t++)
    {

        if (date.year == App[t].date.year && date.month == App[t].date.month && date.day == App[t].date.day && time.hour == App[t].time.hour && time.min == App[t].time.min)
        {

            TimeSlotAvailable = 1;

        }
    }

    return TimeSlotAvailable;

}


int vacantNextSlot(struct Appointment* App, int MaxApp)
{
    int i = 0;
    int vacantSlotAvailable = 0;

    while (vacantSlotAvailable == 0 && i < MaxApp)
    {

        if (App[i].PatientNumber < 1)
        {

            vacantSlotAvailable = 1;

        }
        i++;
    }

    return i;
}


int validAppointment(int PatientNumber, struct Date date, struct Appointment* App, int MaxApp)
{
    {
        int i = 0;
        int j = 0;

        while (j == 0 && i < MaxApp)
        {

            if ((App[i].PatientNumber == PatientNumber) && (App[i].date.day == date.day) && (App[i].date.month == date.month) && (App[i].date.year == date.year))
            {

                j = 1;

            }

            i++;
        }

        return i - 1;
    }


}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input");
    printf("\n");

    printf("------------------");
    printf("\n");

    printf("Number: %05d", patient->patientNumber);
    printf("\n");

    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int choices;
    char Input[PHONE_LEN + 1];

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    choices = inputIntRange(1, 4);
    printf("\n");

    switch (choices)
    {
    case 1:

        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s", phone->description);
        printf("\n");

        printf("Number : ");
        inputCStringNumbers(Input, 10, 10);
        strcpy(phone->number, Input);
        putchar('\n');

        break;

    case 2:

        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s", phone->description);
        printf("\n");

        printf("Number : ");
        inputCStringNumbers(Input, 10, 10);
        strcpy(phone->number, Input);
        putchar('\n');

        break;
    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s", phone->description);
        printf("\n");

        printf("Number : ");
        inputCStringNumbers(Input, 10, 10);
        strcpy(phone->number, Input);
        putchar('\n');

        break;

    case 4:

        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = '\0';
        break;

    
    }

}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{

    int i = 0;


    FILE* fp;
    fp = fopen(datafile, "r");


    if (fp != NULL)
    {
        i = 0;
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber,
            patients[i].name,
            patients[i].phone.description,
            patients[i].phone.number) != EOF)
        {
            i++;
            if (i >= max)
                break;
        }


        fclose(fp);
    }

    else
    {
        printf("ERROR: File could not be read");
        printf("\n");
    }


    return i;

}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i;
    int count = 0;


    FILE* fp;
    fp = fopen(datafile, "r");


    if (fp != NULL)
    {


        for (i = 0; i < max && !feof(fp); i++)
        {

            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].PatientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);


            if (!feof(fp))
            {
                count++;
            }
        }

        fclose(fp);
    }

    else
    {

        printf("ERROR: File could not be read");
        printf("\n");

    }


    return count;
}