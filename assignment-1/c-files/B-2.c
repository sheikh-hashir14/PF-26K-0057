#include <stdio.h>

int main(){

    int n, request;
    int current_floor = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    while (n > 0){

        printf("Enter floor request: ");
        scanf("%d", &request);

        if (request > current_floor){
            printf("Moving Up\n");
        }

        else if (request < current_floor){
            printf("Moving Down\n");
        }

        else{
            printf("Doors Opening\n");
        }

        current_floor = request;
        n = n - 1;
    }

    return 0;
}