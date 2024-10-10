#include <stdio.h>

int main() {
    int book1_id = 101, book2_id = 102;
    int book1_available = 1, book2_available = 1;
    int option, issue_id;
    int book1_issued = 0, book2_issued = 0;

    while (1) {
        printf("\nLibrary Management\n");
        printf("1. Add Book (Only 2 books available)\n");
        printf("2. Display Books\n");
        printf("3. Issue Book\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Books have already been added!\n");
        } else if (option == 2) {
            printf("Available books:\n");
            if (book1_available) {
                printf("Book ID: %d (Available)\n", book1_id);
            } else {
                printf("Book ID: %d (Issued)\n", book1_id);
            }

            if (book2_available) {
                printf("Book ID: %d (Available)\n", book2_id);
            } else {
                printf("Book ID: %d (Issued)\n", book2_id);
            }
        } else if (option == 3) {
            printf("Enter the book ID to issue: ");
            scanf("%d", &issue_id);

            if (issue_id == book1_id && book1_available) {
                book1_available = 0;
                book1_issued = 1;
                printf("Book ID %d issued successfully!\n", book1_id);
            } else if (issue_id == book2_id && book2_available) {
                book2_available = 0;
                book2_issued = 1;
                printf("Book ID %d issued successfully!\n", book2_id);
            } else {
                printf("Book ID %d is either unavailable or invalid!\n", issue_id);
            }
        } else if (option == 4) {
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}