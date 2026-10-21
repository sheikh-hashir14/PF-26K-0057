#include <stdio.h>

int main(){
    int rows, seats_in_row;
    int i, j;
    int count, total_vacant = 0;
    int group_size, group_vacant_count;

    printf("Enter the number of Rows in the Hall: ");
    scanf("%d", &rows);
    printf("Enter the Number of Seats in each row: ");
    scanf("%d", &seats_in_row);

    int seats[rows][seats_in_row];

    for(i=0 ; i<rows ; i++){
        for(j=0 ; j<seats_in_row ; j++){
            seats[i][j] = 0;
        }
    }

    while(1){
        
        //DISPLAY ALL SEATS
        for(i=0 ; i<rows ; i++){
            for(j=0 ; j<seats_in_row ; j++){
                printf(" ");
                if(seats[i][j] == 0){
                    printf("_");
                }
                if(seats[i][j] == 1){
                    printf("X");
                }
                printf(" ");
            }
            printf("\n");
        }

        //FIND SEAT AVAILABILITY REPORT
        for(i=0 ; i<rows ; i++){
            
            count = 0;
            for(j=0 ; j<seats_in_row ; j++){
                if(seats[i][j] == 0){
                    count = count+1;
                }
            }
            printf("Available Seats in Row %d: %d\n", i+1, count);
            total_vacant = total_vacant + count;
        }
        printf("Total Available Seats: %d\n", total_vacant);


        //GROUP BOOKING
        printf("----- GROUP BOOKING -----");
        printf("Enter the Number of customers in group: ");
        scanf("%d", &group_size);

        for(i=0 ; i<rows ; i++){
            printf("Row %d: ", i+1);
            group_vacant_count = 0;
            for(j=0 ; j<seats_in_row ; j++){
                if(seats[i][j] == 0){
                    group_vacant_count += 1;
                }
                if(seats[i][j] == 1){
                    group_vacant_count = 0;
                }
            }
        }

    break;
    }


}