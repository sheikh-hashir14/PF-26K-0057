#include <stdio.h>

int main(){
    int score[11];

    for(int i = 0; i <= sizeof(score); i++){
        printf("Enter a Number: ");
        scanf("%d", &score[i]);
    }
    printf("%d", score);
}