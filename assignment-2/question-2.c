#include <stdio.h>

int main(){
    int num;
    printf("Enter the number to test up to: ");
    scanf("%d", &num);

    int a, sumA, sumB, i, found = 0;
    for(a=2 ; a<=num ; a++){
        sumA = 0;
        for(i=1 ; i <= a/2 ; i++){
            if(a % i == 0){
                sumA += i;
            }
        }

        if(sumA > a && sumA <= num){
            sumB = 0;
            for(i=1 ; i<= sumA/2 ; i++){
                if(sumA % i == 0){
                    sumB += i;
                }
            }

            if(sumB == a){
                found += 1;
                printf("(%d, %d)\n", a, sumA);
            }
        }

        
    }

    if(found == 0){
        printf("No Amicable Pairs found\n");
    }
    printf("Total Pairs Found: %d\n", found);

}