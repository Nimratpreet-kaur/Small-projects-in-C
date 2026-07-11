// student record management system
#include <stdio.h>
typedef struct student
{
    int roll;
    char name[50];
    float cgpa;
} stu;
stu s[100]; // 100 max students;
int count = 0;
void addstudent();
void displayAllStudents();
void searchStudent();
void update();
void deleteStu();
int main()
{
    int todo;
    printf("Hello!\n");
    printf("What do you want to do?\n");
    for (int i = 0;; i++)
    {
        printf("To add a new student enter 1,\nTo display all students enter 2,\nTo search a student enter 3,\nTo update information of any student enter 4,\nTo delete information of a student enter 5\nTo exit enter 6.\n");
        scanf("%d", &todo);
        if (todo == 1)
        {
            addstudent();
        }
        else if (todo == 2)
        {
            displayAllStudents();
        }
        else if (todo == 3)
        {
            searchStudent();
        }
        else if (todo == 4)
        {
            update();
        }
        else if (todo == 5)
        {
            deleteStu();
        }
        else if (todo == 6)
        {
            break;
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
    return 0;
}

void addstudent()
{

    printf("Name:");
    scanf("%s", &s[count].name);

    printf("Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("CGPA :");
    scanf("%f", &s[count].cgpa);

    count++;
    printf("Student added successfully! \n");
}

void displayAllStudents()
{
    printf("\t ***Student records*** \n");
    printf("\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name:%s \n", s[i].name);
        printf("Roll Number:%d \n", s[i].roll);
        printf("CGPA:%f \n", s[i].cgpa);
        printf("\n");
    }
}

void searchStudent()
{
    int searchRoll;
    int found = 0;
    printf("Enter Roll Number:\n");
    scanf("%d", &searchRoll);
    for (int i = 0; i < count; i++)
    {
        if (searchRoll == s[i].roll)
        {
            printf("***Student Found*** \n");
            printf("Name: %s \n", s[i].name);
            printf("Roll Number: %d \n", s[i].roll);
            printf("CGPA: %f \n", s[i].cgpa);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Invalid Roll Number\n");
    }
}

void update()
{
    int up, found;
    printf("Enter Roll number to update: \n");
    scanf("%d", &up);
    for (int i = 0; i < count; i++)
    {
        if (up == s[i].roll)
        {
            printf("Enter new name:");
            scanf("%s", &s[i].name);
            printf("Enter new CGPA:");
            scanf("%f", &s[i].cgpa);
            found = 1;
            printf("*** Record updated successfully ***\n");
            break;
        }
    }
    if (found == 0)
    {
        printf("Roll number not found.\n");
    }
}

void deleteStu()
{
    int del, found = 0;
    printf("Enter roll number you want to delete:");
    scanf("%d", &del);
    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == del)
        {
            for (int j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }
            count--;
            found = 1;
            printf("\t ***Record deleted successfully *** \n");
            break;
        }
    }
    if (found == 0)
    {
        printf("Roll number not found!\n");
    }
}