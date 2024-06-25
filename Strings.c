#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to print a string
void printString(char str[]) {
    printf("The entered string is: %s\n\n", str);
}

// Function to find the length of a string without using library function
int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to separate individual characters from a string
void separateCharacters(char str[]) {
    printf("Individual characters in the string:\n");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c ", str[i]);
    }
    printf("\n\n");
}

// Function to count the total number of words in a string
int countWords(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            count++;
        }
    }
    return count + 1; // Add 1 for the last word
}

// Function to concatenate two strings
void concatenateStrings(char str1[], char str2[]) {
    int i, j;

    // Finding the length of str1
    for (i = 0; str1[i] != '\0'; i++);

    // Concatenating str2 to str1
    for (j = 0; str2[j] != '\0'; j++) {
        str1[i + j] = str2[j];
    }
    str1[i + j] = '\0'; // Adding null character at the end
}

// Function to concatenate two strings lexicographically
void concatenateLexicographically(char str1[], char str2[]) {
    int i, j;

    // Finding the length of str1
    for (i = 0; str1[i] != '\0'; i++);

    // Concatenating str2 to str1 lexicographically
    for (j = 0; str2[j] != '\0'; j++) {
        if (str2[j] >= str1[i - 1]) {
            str1[i + j] = str2[j];
        } else {
            str1[i + j] = str2[j];
            break;
        }
    }
    str1[i + j] = '\0'; // Adding null character at the end
}

// Function to find the frequency of a character in a string
int findFrequency(char str[], char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

// Function to find the number of vowels, consonants, digits, and white spaces
void countVowelsConsonantsDigitsSpaces(char str[], int *vowels, int *consonants, int *digits, int *spaces) {
    *vowels = *consonants = *digits = *spaces = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        } else if (isdigit(str[i])) {
            (*digits)++;
        } else if (isspace(str[i])) {
            (*spaces)++;
        }
    }
}

// Function to copy a string
void copyString(char *source, char *destination) {
    while (*source) {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
}

// Function to remove all characters in a string
void removeAllCharacters(char *str, char *remove) {
    int hash[256] = {0};
    char *source = str;
    char *destination = str;
    while (*remove) {
        hash[*remove] = 1;
        remove++;
    }
    while (*source) {
        if (!hash[*source]) {
            *destination = *source;
            destination++;
        }
        source++;
    }
    *destination = '\0';
}

// Function to sort elements in lexicographical order (dictionary order)
void sortLexicographically(char str[]) {
    int length = strlen(str);
    char temp;

    // Perform bubble sort
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str1[100], str2[50], ch;
    int len, words, freq, vowels, consonants, digits, spaces;

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    // Remove newline character at the end of input
    if (str1[strlen(str1) - 1] == '\n') {
        str1[strlen(str1) - 1] = '\0';
    }

    // Task 1: Print the entered string
    printf("\n1. ");
    printString(str1);

    // Task 2: Find the length of the string without using library function
    printf("2. ");
    len = stringLength(str1);
    printf("Length of the string: %d\n\n", len);

    // Task 3: Separate individual characters from the string
    printf("3. ");
    separateCharacters(str1);

    // Task 4: Count the total number of words in the string
    printf("4. ");
    words = countWords(str1);
    printf("Total number of words in the string: %d\n\n", words);

    // Task 5: Concatenate Two Strings
    printf("5. Enter second string to concatenate: ");
    fgets(str2, sizeof(str2), stdin);
    if (str2[strlen(str2) - 1] == '\n') {
        str2[strlen(str2) - 1] = '\0';
    }
    concatenateStrings(str1, str2);
    printf("Concatenated string: %s\n\n", str1);

    // Task 6: Concatenate Two Strings Lexicographically
    printf("6. ");
    concatenateLexicographically(str1, str2);
    printf("Concatenated lexicographically: %s\n\n", str1);

    // Task 7: Find the frequency of a character in the string
    printf("7. Enter a character to find its frequency in the string: ");
    scanf(" %c", &ch);
    freq = findFrequency(str1, ch);
    printf("Frequency of '%c' in the string: %d\n\n", ch, freq);

    // Task 8: Find the number of vowels, consonants, digits, and white spaces
    printf("8. ");
    countVowelsConsonantsDigitsSpaces(str1, &vowels, &consonants, &digits, &spaces);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of white spaces: %d\n\n", spaces);

    // Task 9: Find the length of the string (repeated for clarity)
    printf("9. ");
    len = stringLength(str1);
    printf("Length of the string: %d\n\n", len);

    // Task 10: Concatenate two strings (repeated for clarity)
    printf("10. ");
    concatenateStrings(str1, str2);
    printf("Concatenated string: %s\n\n", str1);

    // Task 11: Copy a string
    printf("11. ");
    copyString(str1, str2);
    printf("Copied string: %s\n\n", str2);

    // Task 12: Remove all characters in a string
    printf("12. ");
    removeAllCharacters(str1, str2);
    printf("String after removal: %s\n\n", str1);

    // Task 13: Sort elements in lexicographical order (dictionary order)
    printf("13. ");
    sortLexicographically(str2);
    printf("String sorted in lexicographical order: %s\n\n", str2);

    return 0;
}
