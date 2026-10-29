#include <stdio.h>

void displayMenu() {
    printf("\n===== UNIVERSITY LIBRARY MENU =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void registerMember(char name[], int *studentID, int *memberType) {
    printf("Enter name: ");
    scanf(" %49[^\n]", name);
    printf("Enter student ID: ");
    scanf("%d", studentID);
    printf("Enter membership type (1 = Student, 2 = Faculty): ");
    scanf("%d", memberType);
    while (*memberType != 1 && *memberType != 2) {
        printf("Invalid membership type! Enter 1 for Student or 2 for Faculty: ");
        scanf("%d", memberType);
    }
    printf("Member registered successfully.\n");
}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks) {
    int i;
    printf("\n%-6s %-25s %s\n", "ID", "Title", "Copies");
    printf("------------------------------------------\n");
    for (i = 0; i < totalBooks; i++)
        printf("%-6d %-25s %d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
}

void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
                int borrowedBookIDs[], int *borrowedCount, int memberType) {
    int id, days, i, idx = -1;
    int limit = (memberType == 1) ? 14 : 30;

    if (*borrowedCount >= 3) {
        printf("Borrowing limit reached! You can borrow a maximum of 3 books at a time.\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &id);
    for (i = 0; i < totalBooks; i++)
        if (bookIDs[i] == id) idx = i;
    if (idx == -1) {
        printf("Invalid book ID!\n");
        return;
    }
    if (availableCopies[idx] == 0) {
        printf("Sorry, no copies of \"%s\" are available.\n", bookTitles[idx]);
        return;
    }
    printf("Enter number of days you intend to keep the book: ");
    scanf("%d", &days);
    while (days <= 0) {
        printf("Days must be positive! Enter again: ");
        scanf("%d", &days);
    }
    borrowedBookIDs[(*borrowedCount)++] = id;
    availableCopies[idx]--;
    printf("You have borrowed \"%s\". Permitted period: %d days.\n", bookTitles[idx], limit);
    if (days > limit)
        printf("Note: the intended period exceeds the permitted %d days; fines apply after %d days.\n", limit, limit);
}

float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int borrowedBookIDs[],
                 int *borrowedCount, int memberType, float *totalFine) {
    int id, days, i, pos = -1, idx = -1, extra, limit, rate;
    char code[20], correct[] = "LIB2026";
    float fine = 0;

    printf("Enter book ID to return: ");
    scanf("%d", &id);
    for (i = 0; i < *borrowedCount; i++)
        if (borrowedBookIDs[i] == id) pos = i;
    if (pos == -1) {
        printf("You have not borrowed this book!\n");
        return 0;
    }
    printf("Enter actual number of days the book was kept: ");
    scanf("%d", &days);
    while (days <= 0) {
        printf("Days must be positive! Enter again: ");
        scanf("%d", &days);
    }

    for (i = 0; i < totalBooks; i++)
        if (bookIDs[i] == id) idx = i;
    availableCopies[idx]++;

    limit = (memberType == 1) ? 14 : 30;
    rate = (memberType == 1) ? 20 : 10;
    if (days > limit) {
        extra = days - limit;
        fine = (float)extra * rate;
        printf("Book returned late by %d day(s). Late fine: Rs. %.2f\n", extra, fine);
        *totalFine += fine;

        printf("Enter membership code: ");
        scanf("%19s", code);
        for (i = 0; correct[i] != '\0' && code[i] == correct[i]; i++);
        if (correct[i] == '\0' && code[i] == '\0') {
            fine /= 2;
            printf("Correct code! 50%% waiver applied.\n");
        } else {
            printf("Incorrect code. No waiver applied.\n");
        }
        printf("Fine payable for this return: Rs. %.2f\n", fine);
    } else {
        printf("Book returned on time. No fine.\n");
    }

    for (i = pos; i < *borrowedCount - 1; i++)
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    (*borrowedCount)--;
    return fine;
}

void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[],
                         int borrowedCount, float totalFine, float fineAfterWaiver) {
    int i;
    printf("\n===== MEMBER RECORD =====\n");
    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    printf("Membership Type: %s\n", (memberType == 1) ? "Student" : "Faculty");
    printf("Currently borrowed books:");
    if (borrowedCount == 0)
        printf(" None");
    for (i = 0; i < borrowedCount; i++)
        printf(" %d", borrowedBookIDs[i]);
    printf("\nTotal fine before waiver: Rs. %.2f\n", totalFine);
    printf("Final fine payable: Rs. %.2f\n", fineAfterWaiver);
}

int main() {
    int bookIDs[4] = {101, 102, 103, 104};
    char bookTitles[4][50] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int availableCopies[4] = {5, 3, 0, 4};
    int totalBooks = 4;

    char name[50] = "";
    int studentID = 0, memberType = 0, registered = 0;
    int borrowedBookIDs[3], borrowedCount = 0;
    float totalFine = 0, fineAfterWaiver = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (registered)
                    printf("A member is already registered.\n");
                else {
                    registerMember(name, &studentID, &memberType);
                    registered = 1;
                }
                break;
            case 2:
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;
            case 3:
                if (!registered) printf("Please register a member first.\n");
                else borrowBook(bookIDs, bookTitles, availableCopies, totalBooks,
                                borrowedBookIDs, &borrowedCount, memberType);
                break;
            case 4:
                if (!registered) printf("Please register a member first.\n");
                else fineAfterWaiver += returnBook(bookIDs, availableCopies, totalBooks,
                                                   borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                break;
            case 5:
                if (!registered) printf("Please register a member first.\n");
                else displayMemberRecord(name, studentID, memberType, borrowedBookIDs,
                                         borrowedCount, totalFine, fineAfterWaiver);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select 1-6.\n");
        }
    } while (choice != 6);
    return 0;
}
