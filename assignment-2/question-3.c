#include <stdio.h>

void inputReadings(int m, int n, int readings[m][n]){
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            printf("Enter Sensor %d reading %d: ", i+1, j+1);
            scanf("%d", &readings[i][j]);
        }
    }
}

void sensorAnalysis(int n, int row[n], int sensorId){
    

    printf("\n-----SENSOR %d ANALYSIS REPORT-----\n", sensorId);
    //TOTAL READINGS
    int total = 0;

    for(int j=0 ; j<n ; j++){
        total = total + row[j];
    }

    printf("Total Readings: %d\n", total);

    //AVERAGE TEMPERATURE
    float avg_temp = 0;
    avg_temp = (float)total / n;
    printf("Average Temperature: %.2f\n", avg_temp);

    //MAX/MIN READINGS

    int max = row[0];
    int min = row[0];
    int crit_count = 0;
    int warn_count = 0;
    int streak = 0, longest = 0;

    for(int j=0 ; j<n ; j++){
        if(row[j] > max){
            max = row[j];
        }
        if(row[j] < min){
            min = row[j];
        }
        if(row[j] >= 40){
            crit_count += 1;
        }
        if(row[j]>=35 && row[j]<=39){
            warn_count += 1;
        }
        if(row[j] >= 35){
            streak++;
            if(streak > longest){
                longest = streak;
            }
        }
        else{
            streak = 0;
        }

    }
    

    printf("Maximum Reading: %d\n", max);
    printf("Minimum Reading: %d\n", min);
    printf("Number of Critical Readings: %d\n", crit_count);
    printf("Number of Warning Readings: %d\n", warn_count);
    printf("Longest streak (>= 35C): %d hours\n", longest);
}

int highestAverage(int m, int n, int readings[m][n]){
    int highest_avg_Sensor = 0;
    float highest_Avg = -1;

    for(int i = 0; i < m; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += readings[i][j];
        }
        float avg = (float)sum / n;

        if(avg > highest_Avg){
            highest_Avg = avg;
            highest_avg_Sensor = i+1;
        }
    }
    return highest_avg_Sensor;
}



int main(){

    int sensors, hours;
    
    printf("Enter the Number of Sensors: ");
    scanf("%d", &sensors);
    printf("Enter the Number of Readings taken in Hours: ");
    scanf("%d", &hours);

    int readings[sensors][hours];

    inputReadings(sensors, hours, readings);

    for(int i=0 ; i<sensors ; i++){
        sensorAnalysis(hours, readings[i], i+1);
    }

    int best = highestAverage(sensors, hours, readings);

    int sum = 0;
    for (int j = 0; j < hours; j++) {
        sum += readings[best - 1][j];     // best - 1 to get the row index
    }

    printf("\n-----FINAL REPORT-----\n");
    printf("Sensor with highest average: Sensor %d\n", best);      
    printf("Its average temperature: %.2f\n", (float)sum / hours);

    return 0;
}