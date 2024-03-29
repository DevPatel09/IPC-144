/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Dev Kshitij Patel
Student ID#: 142979228
Email      : dkpatel59@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

//Macro-Directive
#define MAX_PRODUCTS 3
#define NUM_OF_GRAMS 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
    double productPrice;
    int caloriesPerServings;
    double productWeight;
};





// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *a);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int,double, double,int);

// 7. Logic entry point
void start(void);
