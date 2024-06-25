#include <stdio.h>

/************ Task 1 ************/
// Display the first 10 natural numbers
void displayFirst10NaturalNumbers() {
    int i;
    printf("First 10 natural numbers are:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    /*
    Sample Output:
    First 10 natural numbers are:
    1 2 3 4 5 6 7 8 9 10
    */
}

/************ Task 2 ************/
// Display n terms of natural numbers and their sum
void displayNTermsOfNaturalNumbersAndSum(int n) {
    int i, sum = 0;
    printf("Natural numbers up to %d are:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
        sum += i;
    }
    printf("\nSum of first %d natural numbers = %d\n\n", n, sum);
    /*
    Sample Output for n = 5:
    Natural numbers up to 5 are:
    1 2 3 4 5
    Sum of first 5 natural numbers = 15
    */
}

/************ Task 3 ************/
// Display the multiplication table of a given integer
void displayMultiplicationTable(int num) {
    int i;
    printf("Multiplication table of %d:\n", num);
    for (i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", num, i, num * i);
    }
    printf("\n");
    /*
    Sample Output for num = 7:
    Multiplication table of 7:
    7 * 1 = 7
    7 * 2 = 14
    7 * 3 = 21
    7 * 4 = 28
    7 * 5 = 35
    7 * 6 = 42
    7 * 7 = 49
    7 * 8 = 56
    7 * 9 = 63
    7 * 10 = 70
    */
}

/************ Task 4 ************/
// Read 10 numbers from keyboard, find their sum and average
void read10NumbersAndFindSumAndAverage() {
    int i, n = 10;
    double sum = 0, average;
    int numbers[n];
    
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }
    
    average = sum / n;
    
    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n\n", average);
    /*
    Sample Input/Output:
    Enter 10 numbers:
    1 2 3 4 5 6 7 8 9 10
    Sum = 55.00
    Average = 5.50
    */
}

/************ Task 5 ************/
// Display n terms of odd natural numbers and their sum
void displayNTermsOfOddNaturalNumbersAndSum(int n) {
    int i, count = 1, sum = 0;
    printf("First %d odd natural numbers are:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", count);
        sum += count;
        count += 2;
    }
    printf("\nSum of first %d odd natural numbers = %d\n\n", n, sum);
    /*
    Sample Output for n = 4:
    First 4 odd natural numbers are:
    1 3 5 7
    Sum of first 4 odd natural numbers = 16
    */
}

/************ Task 6 ************/
// Display a pattern like a right angle triangle using asterisks
void displayRightAngleTrianglePattern() {
    int rows, i, j;
    printf("Enter number of rows for the triangle pattern: ");
    scanf("%d", &rows);
    
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    /*
    Sample Output for rows = 5:
    Enter number of rows for the triangle pattern: 5
    * 
    * * 
    * * * 
    * * * * 
    * * * * *
    */
}

/************ Task 7 ************/
// Display a pattern like a right angle triangle with numbers
void displayRightAngleTrianglePatternWithNumbers() {
    int rows, i, j, count = 1;
    printf("Enter number of rows for the number pattern: ");
    scanf("%d", &rows);
    
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", count++);
        }
        printf("\n");
    }
    printf("\n");
    /*
    Sample Output for rows = 4:
    Enter number of rows for the number pattern: 4
    1 
    2 3 
    4 5 6 
    7 8 9 10 
    */
}

/************ Task 8 ************/
// Display a pattern like a pyramid with numbers increased by 1
void displayPyramidPatternWithNumbers() {
    int rows, i, j, count = 1;
    printf("Enter number of rows for the pyramid pattern: ");
    scanf("%d", &rows);
    
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%d ", count++);
        }
        printf("\n");
    }
    printf("\n");
    /*
    Sample Output for rows = 4:
    Enter number of rows for the pyramid pattern: 4
       1 
      2 3 
     4 5 6 
    7 8 9 10 
    */
}

/************ Task 9 ************/
// Calculate the factorial of a given number
void calculateFactorial(int num) {
    int i;
    unsigned long long factorial = 1;
    
    if (num < 0) {
        printf("Error: Factorial of a negative number doesn't exist.\n\n");
    } else {
        for (i = 1; i <= num; i++) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n\n", num, factorial);
    }
    /*
    Sample Output for num = 5:
    Factorial of 5 = 120
    */
}

/************ Task 10 ************/
// Display n terms of even natural numbers and their sum
void displayNTermsOfEvenNaturalNumbersAndSum(int n) {
    int i, count = 1, sum = 0;
    printf("First %d even natural numbers are:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", count * 2);
        sum += count * 2;
        count++;
    }
    printf("\nSum of first %d even natural numbers = %d\n\n", n, sum);
    /*
    Sample Output for n = 3:
    First 3 even natural numbers are:
    2 4 6 
    Sum of first 3 even natural numbers = 12
    */
}

/************ Task 11 ************/
// Display a pattern like a pyramid using asterisks with each row containing an odd number of asterisks
void displayPyramidPatternWithOddAsterisks(int rows) {
    int i, j, k = 0;
    for (i = 1; i <= rows; i++, k = 0) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        while (k != 2 * i - 1) {
            printf("*");
            k++;
        }
        printf("\n");
    }
    printf("\n");
    /*
    Sample Output for rows = 4:
        *
       ***
      *****
     *******
    */
}

/************ Task 12 ************/
// Print Floyd's Triangle
void printFloydsTriangle(int rows) {
    int i, j, num = 1;
    printf("Floyd's Triangle with %d rows:\n", rows);
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }
    printf("\n");
    /*
    Sample Output for rows = 4:
    Floyd's Triangle with 4 rows:
    1 
    2 3 
    4 5 6 
    7 8 9 10 
    */
}

/************ Main Function ************/
int main() {
    int choice, n, num, rows;

    do {
        printf("Choose a task to execute (1-12), or enter 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFirst10NaturalNumbers();
                break;
            case 2:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                displayNTermsOfNaturalNumbersAndSum(n);
                break;
            case 3:
                printf("Enter an integer to display its multiplication table: ");
                scanf("%d", &num);
                displayMultiplicationTable(num);
                break;
            case 4:
                read10NumbersAndFindSumAndAverage();
                break;
            case 5:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                displayNTermsOfOddNaturalNumbersAndSum(n);
                break;
            case 6:
                displayRightAngleTrianglePattern();
                break;
            case 7:
                displayRightAngleTrianglePatternWithNumbers();
                break;
            case 8:
                displayPyramidPatternWithNumbers();
                break;
            case 9:
                printf("Enter an integer to calculate its factorial: ");
                scanf("%d", &num);
                calculateFactorial(num);
                break;
            case 10:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                displayNTermsOfEvenNaturalNumbersAndSum(n);
                break;
            case 11:
                printf("Enter number of rows for the pyramid pattern: ");
                scanf("%d", &rows);
                displayPyramidPatternWithOddAsterisks(rows);
                break;
            case 12:
                printf("Enter number of rows for Floyd's Triangle: ");
                scanf("%d", &rows);
                printFloydsTriangle(rows);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 0 and 12.\n\n");
        }
    } while (choice != 0);

    return 0;
}
