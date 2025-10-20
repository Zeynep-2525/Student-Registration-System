#ifndef STUDENT_H //header dosyası birden fazla include edilse bile tekrar tekrar tanımlanmasını önler.
#define STUDENT_H

typedef struct Student{
    int id;
    char name[50];
    float Gano;
    struct Student* next; //Linked List
}Student;

//Fonksiyon Prototipleri
Student* addStudent(Student *head);
void displayStudents(Student *head);
Student* searchStudentByID(Student* head, int id);
void updateStudent(Student *head, int id);
Student* deleteStudent(Student *head, int id);
void saveToFile(Student *head);
Student* loadFromFile();


#endif