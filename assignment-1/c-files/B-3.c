#include <stdio.h>

int main(){
    int n, mark, sum, failed_subject, count;
    float average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    while (n > 0){
        sum = 0;
        failed_subject = 0;
        count = 1;

        while (count <= 5){
            printf("Enter mark %d: ", count);
            scanf("%d", &mark);
            sum = sum + mark;

            if (mark < 33)
            {
                failed_subject = 1;
            }

            count = count + 1;
        }

        average = sum / 5.0;
        printf("Average = %.2f\n", average);

        if (failed_subject == 1){
            printf("Fail - Subject Deficiency\n");
        }
        
        else if (average >= 80){
            printf("Distinction\n");
        }

        else if (average >= 60){
            printf("Pass\n");
        }

        else{
            printf("Fail\n");
        }

        n = n - 1;
    }

    return 0;
}