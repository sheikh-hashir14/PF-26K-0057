#include <stdio.h>

void displayMenu(){
    printf("FAST NUCES Library Management System\n");
    printf("Menu\n");
    printf("1. member Registration\n2. Display Available Books\n3. Borrow a Book\n4. Return a Book\n5. Display Member Record\n6. Exit\n");
}

void registerMember(char name[], int *studentID, int *memberType){
    printf("\n-----Member Registration-----\n");

    printf("Enter name: ");
    scanf(" %49[^\n]", name);

    printf("Enter student ID: ");
    scanf("%d", studentID);

    do{
        printf("Enter membership type (1 = Student, 2 = Faculty): ");
        scanf("%d", memberType);

        if (*memberType != 1 && *memberType != 2)
            printf("Invalid membership type. Please enter 1 or 2.\n");
    }
    while(*memberType != 1 && *memberType != 2);

    printf("\nRegistration successful!\n");
    printf("Welcome, %s (%s member).\n", name, ((*memberType == 1) ? "Student" : "Faculty"));
}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks){
    int i;

    printf("\n-----Available Books-----\n");
    printf("%-6s %-25s %-6s\n", "ID", "Title", "Copies");
    printf("-------------------------------------\n");

    for(i=0 ; i<totalBooks ; i++){
        printf("%-6d %-25s %-6d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}

void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType){
    int id, days, i, index = -1;
    int maxDays = (memberType == 1) ? 14 : 30;

    printf("\n-----Borrow a Book-----\n");

    if(*borrowedCount >= 3){
        printf("You have already borrowed the maximum of 3 books.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &id);

    for(i=0 ; i<totalBooks ; i++){
        if(bookIDs[i] == id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Invalid book ID.\n");
        return;
    }

    if(availableCopies[index] == 0){
        printf("Sorry, no copies of \"%s\" are available.\n", bookTitles[index]);
        return;
    }

    printf("Enter number of days you want to keep the book: ");
    scanf("%d", &days);

    if(days <= 0){
        printf("Number of days must be positive.\n");
        return;
    }

    if(days > maxDays){
        printf("You can keep a book for %d days at most.\n", maxDays);
        return;
    }

    borrowedBookIDs[*borrowedCount] = id;
    (*borrowedCount)++;
    availableCopies[index] = availableCopies[index] - 1;

    printf("You have borrowed \"%s\" for %d days.\n", bookTitles[index], days);
}

float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine){
    int id, days, i, extraDays ; 
    int index = -1, pos = -1, match = 1;
    int maxDays = (memberType == 1) ? 14 : 30;
    int ratePerDay = (memberType == 1) ? 20 : 10;
    float fine = 0;
    char code[20];
    char correctCode[] = "LIB2026";

    printf("\n-----Return a Book-----\n");

    if(*borrowedCount == 0){
        printf("You have no borrowed books to return.\n");
        return 0;
    }

    printf("Enter book ID: ");
    scanf("%d", &id);

    for(i = 0; i < *borrowedCount; i++){
        if(borrowedBookIDs[i] == id){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("You have not borrowed a book with this ID.\n");
        return 0;
    }

    printf("Enter number of days the book was kept: ");
    scanf("%d", &days);

    if(days <= 0){
        printf("Number of days must be positive.\n");
        return 0;
    }

    for(i = 0; i < totalBooks; i++){
        if(bookIDs[i] == id){
            index = i;
            break;
        }
    }

    availableCopies[index]++;

    for(i=pos ; i<*borrowedCount-1 ; i++){
        borrowedBookIDs[i] = borrowedBookIDs[i+1];
    }
    (*borrowedCount)--;

    //LATE FNE
    extraDays = days - maxDays;
    if(extraDays > 0){
        fine = extraDays * ratePerDay;
        *totalFine = *totalFine + fine;
        printf("Book returned %d days late. Fine: Rs. %.2f\n", extraDays, fine);

        printf("Enter membership code for waiver: ");
        scanf("%19s", code);

        for(i=0 ; correctCode[i] != '\0' || code[i] != '\0' ; i++){
            if(correctCode[i] != code[i]){
                match = 0;
                break;
            }
        }

        if(match){
            fine = fine/2;
            printf("Code accepted. 50%% waiver applied.\n");
        }
        else{
            printf("Incorrect code. No waiver applied.\n");
        }
        printf("Fine payable for this return: Rs. %.2f\n", fine);
    }
    else{
        printf("Book returned on time. No fine.\n");
    }

    return fine;
}

void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[], int borrowedCount, float totalFine, float fineAfterWaiver){
    int i;

    printf("\n-----Member Record-----\n");
    printf("Name            : %s\n", name);
    printf("Student ID      : %d\n", studentID);

    if(memberType == 1){
        printf("Membership Type : Student\n");
    }
    else{
        printf("Membership Type : Faculty\n");
    }

    printf("Borrowed Books  : ");
    if(borrowedCount == 0){
        printf("None\n");
    }
    else{
        for(i=0 ; i<borrowedCount ; i++){
            printf("%d ", borrowedBookIDs[i]);
        }
        printf("\n");
    }

    printf("Total Fine (before waiver): Rs. %.2f\n", totalFine);
    printf("Final Fine Payable        : Rs. %.2f\n", fineAfterWaiver);
}

int main(){
    int bookIDs[4] = {101, 102, 103, 104};
    char bookTitles[4][50] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int availableCopies[4] = {5, 3, 0, 4};
    int totalBooks = 4;

    char name[50];
    int studentID = 0, memberType = 0;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    float totalFine = 0, fineAfterWaiver = 0;
    int registered = 0;

    int choice;
    
    do{
        displayMenu();
        printf("Enter your Choice[1-6]: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(registered){
                    printf("A Member Already exists");
                }
                else{
                    registerMember(name, &studentID, &memberType);
                    registered = 1;
                }
                break;

            case 2:
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;

            case 3:
                if(registered == 0){
                    printf("Please register a member first.\n");
                }
                else{
                    borrowBook(bookIDs, bookTitles, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType);
                }
                break;

            case 4:
                if(registered == 0){
                    printf("Please register a member first.\n");
                }
                else{
                    fineAfterWaiver = fineAfterWaiver + returnBook(bookIDs, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                }
                break;

            case 5: 
                if(registered == 0){
                    printf("Please register a member first.\n");
                }
                else{
                    displayMemberRecord(name, studentID, memberType, borrowedBookIDs, borrowedCount, totalFine, fineAfterWaiver);
                }
                break;

            case 6:
                printf("Exiting...");
                break;

            default:
                printf("Ivalid Choice. Select from 1 to 6\n");
                break;
        }
    }
    while(choice != 6);

    return 0;



}