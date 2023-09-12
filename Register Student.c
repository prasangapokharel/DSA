#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct student {
    int id;
    char name[50];
    int roll;
    char phone[12]; // Increased phone size to accommodate 11 digits + null terminator
    char grade[20];
};

struct student list[MAX];
int counter = 0; // Initially no student is there

void addStudent() {
    printf("Welcome to Student Registration Part:\n");
    printf("Enter your Id: ");
    scanf("%d", &list[counter].id);
    fflush(stdin);
    printf("Enter your name: ");
    getchar(); // Clear newline left in the input buffer
    fgets(list[counter].name, sizeof(list[counter].name), stdin);
    list[counter].name[strcspn(list[counter].name, "\n")] = '\0'; // Remove trailing newline
    printf("Enter your roll number: ");
    scanf("%d", &list[counter].roll);
    printf("Enter your phone number: ");
    scanf("%s", list[counter].phone);
    fflush(stdin);
    printf("Enter your grade: ");
    getchar(); // Clear newline left in the input buffer
    fgets(list[counter].grade, sizeof(list[counter].grade), stdin);
    list[counter].grade[strcspn(list[counter].grade, "\n")] = '\0'; // Remove trailing newline
    counter++;
    printf("\nRegistration successful.\n");
}

void removeStudent() {
    int id, i, j;
    printf("Enter the Id to remove: ");
    scanf("%d", &id);
    for (i = 0; i < counter; i++) {
        if (list[i].id == id) {
            for (j = i + 1; j < counter; j++) {
                list[j - 1] = list[j];
            }
            counter--;
            printf("Student record removed successfully.\n");
            return;
        }
    }
    printf("Student record with the given id does not exist.\n");
}

void editStudent() {
    int id, i;
    printf("Enter the Id to update: ");
    scanf("%d", &id);
    for (i = 0; i < counter; i++) {
        if (list[i].id == id) {
            printf("Enter name: ");
            getchar(); // Clear newline left in the input buffer
            fgets(list[i].name, sizeof(list[i].name), stdin);
            list[i].name[strcspn(list[i].name, "\n")] = '\0'; // Remove trailing newline
            printf("Enter roll no.: ");
            scanf("%d", &list[i].roll);
            printf("Student record updated successfully.\n");
            return;
        }
    }
    printf("Student record with the given id does not exist.\n");
}

void listStudents() {
    int i;
    if (counter == 0)
        printf("List is empty.\n");
    else {
        printf("List of Students\n\n");
        printf("Id\tName of Student\tRoll No.\tPhone No.\tGrade\n");
        for (i = 0; i < counter; i++) {
            printf("%d\t%s\t%d\t%s\t\t%s\n", list[i].id, list[i].name, list[i].roll, list[i].phone, list[i].grade);
        }
    }
}

void saveStudent() {
    FILE *fp;
    fp = fopen("stdlist", "wb");
    if (fp != NULL) {
        fwrite(list, sizeof(struct student), counter, fp);
        fclose(fp);
    }
}

void readStudent() {
    FILE *fp;
    fp = fopen("stdlist", "rb");
    if (fp != NULL) {
        while (feof(fp) == 0) {
            if (fread(&list[counter], sizeof(struct student), 1, fp) == 1)
                counter++;
        }
        fclose(fp);
    }
}

int main() {
    char choice;
    readStudent(); // Read everything from the file just before showing anything
    while (1) {
        system("cls"); // Clear the console (for Windows, use "clear" for Linux)
        printf("Select an option:\n");
        printf("1. Register New Student\n2. Update Student Record\n");
        printf("3. Remove A Student\n4. List All Students\n5. Exit\n");
        choice = getchar();
        switch (choice) {
            case '1':
                addStudent();
                break;
            case '2':
                editStudent();
                break;
            case '3':
                removeStudent();
                break;
            case '4':
                listStudents();
                break;
            case '5':
                printf("Are you sure you want to quit? (Y/N): ");
                choice = getchar();
                if (choice == 'Y' || choice == 'y') {
                    saveStudent(); // Save everything to disk before closing
                    return 0;
                }
                break;
        }
    }
}
