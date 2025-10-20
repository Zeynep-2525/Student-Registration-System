#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student *addStudent(Student *head)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    Student *temp = head;

    if (newStudent == NULL)
    {
        printf("Memory allocation failed");
        return head;
    }

    printf("Enter student ID:");
    scanf("%d", &(newStudent->id));

    printf("Enter student's name:");
    scanf("%s", newStudent->name);

    printf("Enter student's GPA");
    scanf("%f", &(newStudent->GPA));

    if (head == NULL)
    {
        newStudent->next = NULL;
        return newStudent; 
    }

    Student *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newStudent;
    newStudent->next = NULL;
    return head;
}

void displayStudents(Student *head)
{
    Student *temp = head;
    while (temp != NULL)
    {
        printf("Student's ID:%d\nStudent's Name:%s\nStudent's GPA:%.2f", temp->id, temp->name, temp->GPA);
        printf("-----------------------\n");
        temp = temp->next;
    }
}

Student *searchStudentByID(Student *head, int id)
{
    Student *matchingStudent = NULL;
    Student *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            matchingStudent = temp;
            return matchingStudent;
        }
        temp = temp->next;
    }
    return NULL;
}

void updateStudent(Student *head, int id)
{
    int x;
    Student *targetStudent = head;
    while (targetStudent != NULL && targetStudent->id != id)
    {
        targetStudent = targetStudent->next;
    }
    if (targetStudent == NULL)
    {
        printf("Student not found.\n");
        return;
    }

    do
    {
        printf("Please select an option\n1:change student's name\n2:change student's GPA\nIf you want to quit PRESS 5");
        scanf("%d", &x);
        switch (x)
        {
        case (1):
            printf("Please enter a new name for student {%d}", targetStudent->id);
            scanf("%s", targetStudent->name);
            break;
        case (2):
            printf("Change the student's GPA with the ID {%d}", targetStudent->id);
            scanf("%f", &(targetStudent->GPA));
            break;
        default:
            printf("You didn't enter a valid option");
        }
    } while (x != 5);
}

void deleteStudent(Student **head, int id)
{
    Student *temp = *head, *prev;
    if (temp != NULL && temp->id == id)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

void saveToFile(Student *head)
{
    FILE *file = fopen("data/students.txt", "w");

    if (file == NULL)
    {
        printf("Failed to open file for writing.\n");
        return;
    }

    Student *temp = head;
    while (temp != NULL)
    {
        fprintf(file, "%d %s %.2f\n", temp->id, temp->name, temp->GPA);
        temp = temp->next;
    }
    fclose(file);
}

Student* loadFromFile()
{
    FILE *file = fopen("data/students.txt", "r");
    if(file == NULL){
        printf("No saved data found.\n");
        return NULL;
    }

    Student* head = NULL;
    int id;
    char name[50];
    float GPA;

    while(fscanf(file, "%d %s %f", &id, name, &GPA) != EOF){
        Student* newStudent = (Student*)malloc(sizeof(Student));
        newStudent->id = id;
        strcpy(newStudent->name, name);
        newStudent->GPA = GPA;
        newStudent->next = NULL;

        if(head == NULL){
            head = newStudent;
        } else {
            Student* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newStudent;
        }
    }

    fclose(file);
    return head;
}
