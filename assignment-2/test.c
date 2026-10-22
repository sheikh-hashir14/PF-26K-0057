int best = highestAverage(sensors, hours, readings);

int sum = 0;
for (int j = 0; j < hours; j++) {
    sum += readings[best - 1][j];     // best - 1 to get the row index
}

printf("\n-----FINAL REPORT-----\n");
printf("Sensor with highest average: Sensor %d\n", best);      // no +1 here
printf("Its average temperature: %.2f\n", (float)sum / hours);