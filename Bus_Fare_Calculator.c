#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to validate the coupon
int validateCoupon(char *coupon) {
    char validCoupon[] = "10OFF";
    
    // Compare the provided coupon with the valid coupon string
    if (strcmp(coupon, validCoupon) == 0) {
        return 1; // Coupon is valid
    } else {
        return 0; // Coupon is not valid
    }
}

int main() {
    // Array of stops
    char stops[] = {'T', 'K', 'N', 'S', 'A', 'G', 'L'};
    // Corresponding stop names
    char *stopNames[] = {"Tiruporur", "Kelambakkam", "Navalur", "Shollinganallur", "Adyar", "Guindy", "Little Mount"};
    // Distance between consecutive stops (in kms)
    int distancePerStop = 5;
    // Fare rates based on distance (in Rs)
    int fareRates[] = {10, 20, 30, 40};
    // Number of fare rate categories
    int numFareCategories = sizeof(fareRates) / sizeof(fareRates[0]);
    
    char source, destination, coupon[10];
    int numTickets, totalDistance, farePerTicket, totalFare, discount;

    // Get source and destination stops from user
    printf("Enter source and destination stops (T, K, N, S, A, G, L): ");
    scanf(" %c %c", &source, &destination);
    
    // Convert input characters to uppercase
    source = toupper(source);
    destination = toupper(destination);
    
    // Get number of tickets
    printf("Enter number of tickets: ");
    scanf("%d", &numTickets);
    
    // Calculate total distance based on selected stops
    totalDistance = abs((destination - source) * distancePerStop);
    
    // Determine fare per ticket based on total distance
    if (totalDistance <= 5) {
        farePerTicket = fareRates[0];
    } else if (totalDistance <= 10) {
        farePerTicket = fareRates[1];
    } else if (totalDistance <= 15) {
        farePerTicket = fareRates[2];
    } else if (totalDistance <= 20) {
        farePerTicket = fareRates[3];
    } else {
        printf("Invalid source or destination selection.\n");
        return 1;
    }
    
    // Calculate total fare
    totalFare = farePerTicket * numTickets;
    
    // Check if coupon is needed (for distances greater than 10 kms)
    if (totalDistance > 10) {
        printf("Enter coupon code (if applicable, otherwise enter 'NONE'): ");
        scanf("%s", coupon);
        
        // Validate the coupon
        if (validateCoupon(coupon)) {
            discount = (totalFare * 10) / 100; // 10% discount
            totalFare -= discount;
            printf("Coupon applied successfully. You received a 10%% discount of Rs %d.\n", discount);
        } else {
            printf("Invalid coupon or no coupon entered.\n");
        }
    }
    
    // Output the details
    printf("\n");
    printf("Source: %s\n", stopNames[source - 'T']);
    printf("Destination: %s\n", stopNames[destination - 'T']);
    printf("Distance to be traveled: %d kms\n", totalDistance);
    printf("Number of tickets: %d\n", numTickets);
    printf("Fare per ticket: Rs %d\n", farePerTicket);
    printf("Total fare: Rs %d\n", totalFare);
    
    return 0;
}

/*
Sample Question:
Assume the stops array is ['T','K','N','S','A','G','L'] where:
'T' - 'Tiruporur', 'K' - 'Kelambakkam', 'N' - 'Navalur',
'S' - 'Shollinganallur', 'A' - 'Adyar', 'G' - 'Guindy', 'L' - 'Little mount'

The distance between two consecutive stops is 5 kms.

You are also provided with a string:
coupons="10OFF"

Get source and destination from the user and calculate the distance to be traveled. Source and destination can take any of the values from the array ‘stops’ mentioned above. Get the number of tickets also as input. Now according to the distance and number of tickets, the fare has to be calculated as follows:

Distance (in kms)    Rate per ticket (in Rs)
0 to 5               10
6 to 10              20
11 to 15             30
16 to 20             40

If the distance to be traveled is more than 10 kms, ask the user to enter a coupon code if they have any. Create a function to validate the coupon using the coupon string as mentioned above. If the coupon is valid, provide a 10 percent discount on the total fare and display the discounted amount.

Sample Output:
Enter source and destination stops (T, K, N, S, A, G, L): T N
Enter number of tickets: 3
Enter coupon code (if applicable, otherwise enter 'NONE'): 10OFF

Source: Tiruporur
Destination: Navalur
Distance to be traveled: 10 kms
Number of tickets: 3
Fare per ticket: Rs 20
Coupon applied successfully. You received a 10% discount of Rs 6.
Total fare: Rs 54
*/
