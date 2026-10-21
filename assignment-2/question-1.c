#include <stdio.h>

int main(){
    int rows, seats_in_row;
    int i, j;
    int count, total_vacant = 0;
    int group_size, group_vacant_count;
    int found = 0;

    printf("Enter the number of Rows in the Hall: ");
    scanf("%d", &rows);
    printf("Enter the Number of Seats in each row: ");
    scanf("%d", &seats_in_row);

    int seats[rows][seats_in_row];
    int mid = rows / 2;

    for(i=0 ; i<rows ; i++){
        for(j=0 ; j<seats_in_row ; j++){
            seats[i][j] = 0;
        }
    }

    while(1){
        
        total_vacant = 0;

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
        printf("----- BOOKING -----\n");
        printf("Enter the Number of customers in group(0 to exit): ");
        scanf("%d", &group_size);

        if(group_size == 0){
            break;
        }
        if(group_size < 0 || group_size > seats_in_row){
            printf("Invalid group size.\n");
            continue;
        }

        found = 0;
        for(int d = 0; d < rows && found == 0; d++){
        // candidate rows: mid - d first, then mid + d
            int candidates[2] = { mid-d, mid+d };
            int num = (d == 0) ? 1 : 2;   // at d = 0 both are the same row

            for(int c=0; c<num && found == 0; c++){
                int r = candidates[c];
                if(r < 0 || r >= rows){
                    continue;   // outside the hall
                }
                // look for the first block of group_size consecutive free seats
                group_vacant_count = 0;
                for(j = 0; j < seats_in_row; j++){
                    if(seats[r][j] == 0){
                        group_vacant_count++;
                    }
                    else{
                        group_vacant_count = 0;
                    }
                
                    if(group_vacant_count == group_size) {
                        int start = j - group_size + 1;
                        for(int s = start; s <= j; s++){
                            seats[r][s] = 1;        // book them
                        }
                        printf("Booked Row %d, Seats %d to %d\n", r + 1, start + 1, j + 1);
                        found = 1;
                        break;
                    }
                }
            }
        }
        if(found == 0){
            printf("No Group Slots available for Given Group Size.\n");
        }
    }

    return 0;
}