#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 12

// Define the structure for a contact
struct contact {
    char firstname[21];
    char lastname[21];
    char phonenumber[14];
};

// Global array of contacts
struct contact usercontacts[MAX_CONTACTS];

// Function prototypes
void initializeContacts();
void addContact(const char *firstname, const char *lastname, const char *phonenumber);
void deleteContact(int index);
void updateContact(const char *firstname, const char *lastname, const char *phonenumber, const char *oldfirstname);
void viewContacts();

int main() {
    char choice;
    int index;

    // Initialize contacts to empty strings
    initializeContacts();

    while (true) {
        // Display the user menu
        printf("Select an Operation from the Menu.\n");
        printf("\t1. Add a new Contact.\n");
        printf("\t2. Update a Contact.\n");
        printf("\t3. View Contacts.\n");
        printf("\t4. Delete a Contact.\n");
        printf("\tQ(q). Quit.\n");

        printf("Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                // Add a new contact
                char firstname[21];
                char lastname[21];
                char phonenumber[14];

                printf("Enter the first name: ");
                scanf("%20s", firstname);
                printf("Enter the last name: ");
                scanf("%20s", lastname);
                printf("Enter phone number: ");
                scanf("%13s", phonenumber);

                addContact(firstname, lastname, phonenumber);
                break;
            }
            case '2': {
                // Update an existing contact
                char firstname[21];
                char lastname[21];
                char phonenumber[14];
                char oldfirstname[21];

                printf("Enter the current first name of the contact to update: ");
                scanf("%20s", oldfirstname);
                printf("Enter the new first name: ");
                scanf("%20s", firstname);
                printf("Enter the new last name: ");
                scanf("%20s", lastname);
                printf("Enter the new phone number: ");
                scanf("%13s", phonenumber);

                updateContact(firstname, lastname, phonenumber, oldfirstname);
                break;
            }
            case '3':
                // View all contacts
                viewContacts();
                break;
            case '4':
                // Delete a contact by index
                printf("Enter the index to be deleted (1 to %d): ", MAX_CONTACTS);
                scanf("%d", &index);
                deleteContact(index - 1);  // Adjust for 0-based index
                break;
            case 'Q':
            case 'q':
                // Quit the application
                printf("Thank you for using our services.\n\n");
                exit(0);
            default:
                printf("You entered an invalid option!!\n\n");
        }
    }

    return 0;
}

// Initialize contacts to empty strings
void initializeContacts() {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        strcpy(usercontacts[i].firstname, "");
        strcpy(usercontacts[i].lastname, "");
        strcpy(usercontacts[i].phonenumber, "");
    }
}

// Add a new contact
void addContact(const char *firstname, const char *lastname, const char *phonenumber) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(usercontacts[i].firstname, "") == 0) {
            strcpy(usercontacts[i].firstname, firstname);
            strcpy(usercontacts[i].lastname, lastname);
            strcpy(usercontacts[i].phonenumber, phonenumber);
            printf("Contact added successfully.\n");
            return;
        }
    }
    printf("Contact list is full.\n");
}

// Update an existing contact
void updateContact(const char *firstname, const char *lastname, const char *phonenumber, const char *oldfirstname) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(usercontacts[i].firstname, oldfirstname) == 0) {
            strcpy(usercontacts[i].firstname, firstname);
            strcpy(usercontacts[i].lastname, lastname);
            strcpy(usercontacts[i].phonenumber, phonenumber);
            printf("Contact updated successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

// View all contacts
void viewContacts() {
    bool empty = true;
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(usercontacts[i].firstname, "") != 0) {
            printf("Contact %d:\n", i + 1);
            printf("First Name: %s\n", usercontacts[i].firstname);
            printf("Last Name: %s\n", usercontacts[i].lastname);
            printf("Phone Number: %s\n", usercontacts[i].phonenumber);
            printf("\n");
            empty = false;
        }
    }
    if (empty) {
        printf("No contacts available.\n");
    }
}

// Delete a contact by index
void deleteContact(int index) {
    if (index >= 0 && index < MAX_CONTACTS && strcmp(usercontacts[index].firstname, "") != 0) {
        strcpy(usercontacts[index].firstname, "");
        strcpy(usercontacts[index].lastname, "");
        strcpy(usercontacts[index].phonenumber, "");
        printf("Contact deleted successfully.\n");
    } else {
        printf("Invalid contact index.\n");
    }
}
