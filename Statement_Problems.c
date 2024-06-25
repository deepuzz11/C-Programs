#include <stdio.h>
#include <math.h>

// 1. Take an int array as an input from the user along with the size of the array,
//    apply the following logic and print the output.
//    Example: [4,5,3,2] => 4 to the power 5 + 5 power 3 + 3 power 2 + 2 power 4

void calculatePowerSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i], arr[(i + 1) % size]);
    }
    printf("Result: %d\n\n", sum);
}

// 2. Maintenance Calculator:
//    Calculate maintenance bill for an apartment based on its size in square feet.

void calculateMaintenance(int sqFeet) {
    char* apartmentType;

    if (sqFeet >= 500 && sqFeet < 700) {
        apartmentType = "1BHK";
    } else if (sqFeet >= 700 && sqFeet < 1000) {
        apartmentType = "2BHK";
    } else if (sqFeet >= 1000 && sqFeet < 1500) {
        apartmentType = "3BHK";
    } else if (sqFeet >= 1500 && sqFeet <= 2400) {
        apartmentType = "Villa";
    } else {
        printf("Invalid square feet value.\n");
        return;
    }

    float maintenanceCharge = 3.0 * sqFeet;
    float quarterlyBill = maintenanceCharge * 3;
    float annualBill = maintenanceCharge * 12;

    printf("Maintenance Details:\n");
    printf("Apartment Type: %s\n", apartmentType);
    printf("Square Feet: %d sq.feet\n", sqFeet);
    printf("Maintenance Charge per month: Rs. %.2f\n", maintenanceCharge);
    printf("Maintenance Charge per quarter: Rs. %.2f\n", quarterlyBill);
    printf("Maintenance Charge per year: Rs. %.2f\n\n", annualBill);
}

// 3. Print certificate based on marital status of a woman attending an event.

void printCertificate(char name[], char maritalStatus[]) {
    printf("Certificate of Participation\n");
    printf("Name: %s\n", name);
    if (strcmp(maritalStatus, "yes") == 0) {
        printf("Mrs. %s\n\n", name);
    } else {
        printf("Miss %s\n\n", name);
    }
}

// 4. Execute the expression ++a * b where a = 5 and b = 10.

void executeExpression() {
    int a = 5, b = 10;
    int result = ++a * b;
    printf("Result of ++a * b where a = 5 and b = 10: %d\n", result);
}

int main() {
    // Example for question 1
    printf("Question 1: Calculate Power Sum of Elements in an Array\n");
    int arr1[] = {4, 5, 3, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    calculatePowerSum(arr1, size1);

    // Example for question 2
    printf("Question 2: Maintenance Calculator\n");
    int sqFeet;
    printf("Enter the square feet of the apartment: ");
    scanf("%d", &sqFeet);
    calculateMaintenance(sqFeet);

    // Example for question 3
    printf("Question 3: Print Certificate based on Marital Status\n");
    char name[100], maritalStatus[10];
    printf("Enter participant's name: ");
    scanf(" %[^\n]s", name);
    printf("Is the participant married? (yes/no): ");
    scanf(" %s", maritalStatus);
    printCertificate(name, maritalStatus);

    // Example for question 4
    printf("Question 4: Execute Expression ++a * b\n");
    executeExpression();

    return 0;
}
