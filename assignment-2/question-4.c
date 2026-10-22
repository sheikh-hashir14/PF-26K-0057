#include <stdio.h>

int getValidDays(){
    int days;
    while(1){
        printf("Enter the Duration of Festival in days: ");
        scanf("%d", &days);

        if(days >= 1 && days <= 7){
            break;
        }
        else{
            continue;
        }
    }
    return days;
}

float calculateDailySales(int dayNumber){
    int orders, i;
    float amount, total = 0.0f, highest = 0.0f;
 
    printf("\n---Day %d---\n", dayNumber);
    printf("Enter number of orders: ");
    scanf("%d", &orders);
 
    for(i = 1; i <= orders; i++){
        printf("Enter amount for order %d (Rs.): ", i);
        scanf("%f", &amount);
 
        while(amount <= 0){
            printf("Invalid amount! Must be greater than zero. Re-enter order %d: ", i);
            scanf("%f", &amount);
        }
 
        total += amount;
        if(amount > highest){
            highest = amount;
        }
    }
 
    printf("Total sales for day %d: Rs. %.2f\n", dayNumber, total);
    printf("Average order amount : Rs. %.2f\n", total / orders);
    printf("Highest order amount : Rs. %.2f\n", highest);
 
    return total;
}

int findHighestSalesDay(float dailySales[], int numberOfDays){
    int i, highestDay = 1;
    float highest = dailySales[0];
 
    for(i=1 ; i<numberOfDays ; i++){
        if(dailySales[i] > highest){
            highest = dailySales[i];
            highestDay = i+1;
        }
    }
 
    return highestDay;
}

void displayBarChart(float dailySales[], int numberOfDays){
    int i, j, stars;
 
    printf("\n-----Daily Sales Bar Chart (* = Rs. 100)-----\n");
 
    for(i=0 ; i<numberOfDays ; i++){
        stars = (int)(dailySales[i] / 100);
 
        printf("Day %d: ", i+1);
        for(j=0 ; j<stars ; j++){
            printf("*");
        }
        printf("\n");
    }
}



int main(){

    float dailySales[7];
    float festivalTotal = 0.0f;
    int days, i, highestDay;
 
    days = getValidDays();
 
    for(i=0 ; i<days ; i++){
        dailySales[i] = calculateDailySales(i+1);
        festivalTotal += dailySales[i];
    }
 
    highestDay = findHighestSalesDay(dailySales, days);

    printf("\n-----Festival Sales Summary-----\n");
    printf("Total sales for the festival: Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales: Day %d (Rs. %.2f)\n", highestDay, dailySales[highestDay - 1]);
 
    displayBarChart(dailySales, days);
 
    return 0;


}