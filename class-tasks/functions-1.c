#include <stdio.h>

float sum(int a, int b){
    return a+b;
}

float subtract(int a, int b){
    return a-b;
}

float multiply(int a, int b){
    return a*b;
}

float divide(int a, int b){
    return (float)a / b;
}

int main(){
    int num1, num2;
    int choice;
    float result;

    printf("Choose your Operation: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    printf("Enter the First Number: ");
    scanf("%d", &num1);
    printf("Enter the Second Number: ");
    scanf("%d", &num2);

    switch(choice){
        case 1:
            result = sum(num1, num2);
            break;
        
        case 2:
            result = subtract(num1, num2);
            break;

        case 3:
            result = multiply(num1, num2);
            break;

        case 4:
            if(num2 == 0){
                printf("Error! Division by Zero. Check Number 2.");
            }
            else{
                result = divide(num1, num2);
            }
            break;

        default:
            printf("Invalid Choice.");
    }

    printf("Result of your Selected operation is: %.2f", result);
}