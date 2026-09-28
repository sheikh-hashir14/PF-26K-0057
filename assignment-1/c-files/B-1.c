#include <stdio.h>

int main(){

    int n, nights, room_type, season;
    int standard, deluxe, suite, rate;
    float discount, final_price;
    float total_revenue = 0;
    int i = 1;

    printf("Enter number of guests: ");
    scanf("%d", &n);

    while (n > 0){   
        printf("-----GUEST %d-----\n", i);
        printf("Enter nights staying: ");
        scanf("%d", &nights);
        printf("1. Standard\n2. Deluxe\n3. Suite\n");
        printf("Enter the Room Type: ");
        scanf("%d", &room_type);
        printf("Enter season (1. Peak, 2. Off Peak): ");
        scanf("%d", &season);

        switch (season){
            case 1:
                standard = 5000; deluxe = 8000; suite = 12000;
                break;
            case 2:
                standard = 3000; deluxe = 5000; suite = 8000;
                break;
            default: 
                printf("Invalid Input!");
                break;
        }

        switch (room_type){
            case 1:
                rate = standard;
                break;
            case 2:
                rate = deluxe;
                break;
            case 3:
                rate = suite;
                break;
            default: 
                printf("Invalid Input!");
                break;
        }

        if (nights > 7){
            discount = (rate * nights) * 0.15;
        }
        else{
            discount = 0;
        }

        final_price = (rate * nights) - discount;
        printf("Final price = %.2f\n", final_price);
        total_revenue = total_revenue + final_price;

        n = n - 1;
        i = i + 1;
    }

    printf("Total revenue = %.2f\n", total_revenue);
    return 0;
}