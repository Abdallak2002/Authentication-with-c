#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 10
#define MIN_PASSWORD_LENGTH 6

// Struct to represent a user
struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MIN_PASSWORD_LENGTH];
};

// Array to store user data
struct User users[MAX_USERS];
int userCount = 0;

// Function to register a new user
void registerUser() {
    if (userCount < MAX_USERS) {
        printf("Enter username (max %d characters): ", MAX_USERNAME_LENGTH );
        scanf("%s", users[userCount].username);

        printf("Enter password (max %d characters): ", MIN_PASSWORD_LENGTH );
        scanf("%s", users[userCount].password);

        userCount++;
        printf("User registered successfully!\n");
    } else {
        printf("Maximum user limit reached!\n");
    }
}

// Function to log in a user
void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MIN_PASSWORD_LENGTH];
    int loggedIn = 0;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            loggedIn = 1;
            break;
        }
    }

    if (!loggedIn) {
        printf("Invalid username or password. Please try again.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Register\n2. Login\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
