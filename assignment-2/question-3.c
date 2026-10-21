#include <stdio.h>

int inputReadings(int m, int n, int readings[m][n]){
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            printf("Enter Sensor %d reading %d: ", i, j);
            scanf("%d", &readings[i][j]);
        }
    }

    return readings;
}

void sensorAnalysis(int m, int n, int readings[m][n]){
    
    //TOTAL READINGS
    int total = 0;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            total = total + readings[i][j];
        }
    }

    //AVERAGE TEMPERATURE
    int avg_temp = 0;
    avg_temp = total / (m*n);

    //MAX/MIN READINGS

    int max = readings[0][0];
    int min = readings[0][0];

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(readings[i][j] > max){
                max = readings[i][j];
            }
            if(readings[i][j] < min){
                min = readings[i][j];
            }
        }
    }

}

int main(){

}