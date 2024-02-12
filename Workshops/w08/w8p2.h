/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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
#define LBTOKG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
    double productPrice;
    int caloriesPerServings;
    double productWeight;
};

struct ReportData
{
    int sku;
    double productPrice;
    int  caloriesPerServings;
    double productWeightPounds;
    double productWeightKilos;
    int productWeightGrams;
    double servings;
    double costPerServing;
    double costCaloriesPerServing;
};




// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* a);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double*);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int, double*, double*, int);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds, double* Lb_To_Kg);

// 9. convert lbs: g
int convertLbsG(const double* pounds, int* LB_TO_G);

// 10. convert lbs: kg / g
void convertLbs(const double* pounds, double* Lb_To_Kg, int* LB_TO_GLB_TO_G);

// 11. calculate: servings based on gPerServ
double calculateServings(const int SizeGrams, const int Grams, double* Num_Of_Servings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* Num_Of_Servings, double* Answer);


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* Answer);


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cat1);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData Data, const int cheapestProductCheck);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cat1);


// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);