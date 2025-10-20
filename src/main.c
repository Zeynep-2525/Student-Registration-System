#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
    Student *head = NULL;
    int choice;
    do
    {
        printf("\n-----Student Management System-----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case (1):
        {
            head = addStudent(head);
            break;
        }
        case (2):
        {
            displayStudents(head);
            break;
        }
        case (3):
        {
            int id;
            printf("Enter student ID to search: ");
            scanf("%d", &id);
            Student *found = searchStudentByID(head, id);
            if (found != NULL)
            {
                printf("Found:%s \t GPA:%d\n", found->name, found->GPA);
            }
            else
            {
                printf("Student not found");
            }
            break;
        }
        case (4):
        {
            int id;
            printf("Enter student ID to update: ");
            scanf("%d", &id);
            updateStudent(head, id);
            break;
        }
        case (5):
        {
            int id;
            printf("Enter student ID to delete: ");
            scanf("%d", &id);
            deleteStudent(&head, id);
            break;
        }
        case (0):
        {
            printf("Exiting Program\n");
            break;
        }
        default:
            printf("Invalid choice.Try again");
        }

    } while (choice != 0);

    return 0;
}