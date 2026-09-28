#include <stdio.h>

int main(){

    int x;
    printf("Enter number: ");
    scanf("%d", &x);

    if(x / 100 == 0) printf("double digit");
    else printf("More than 2 digit");
}