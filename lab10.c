#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 100

typedef struct student
{
    char ID[SIZE];
    char fullName[SIZE];
    char dateOfBirth[SIZE];
    char department[SIZE];
    float math;
    float english;
    float programming;
    float average;
    int rank;
    bool delete;
} Student;

void swap(int *a, int *b);
void input(Student *dataOfStudent, int i);
void output(Student *dataOfStudent, int i);
void swapStruct(Student *a, Student *b);
void sortAverage(Student *dataOfStudent, int n);
void sortALphabetical(Student *dataOfStudent, int n);
void searchID(Student *dataOfStudent, int n, char *ID);
void searchName(Student *dataOfStudent, int n, char *Name);
void decreaseRank(Student *dataOfStudent, int p, int n);

int main()
{
    int option;
    int n;
    float sum = 0;
    int rank = 0;
    int size = 0;
    Student *dataOfStudent = (Student *)malloc(sizeof(Student));
    do
    {
        printf("=====\nStudent Management\n");
        printf("1. Input data\n2. Output student list\n3. Sort student list\n");
        printf("4. Search student\n5. Edit student info");
        printf("\n6. Remove student from list\n7. Export data to file (optional)\n8. Import data from file (optional)\n0. Exit program");
        printf("\nYour option: ");
        scanf("%d", &option);
        printf("=====\n");
        switch (option)
        {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            getchar();
            size = size + n;
            dataOfStudent = (Student *)realloc(dataOfStudent, size * sizeof(Student));
            for (int i = size - n; i < size; i++)
            {
                printf("\nEnter student (%d):\n", i + 1);
                input(dataOfStudent, i);
            }
            break;

        case 2:
            printf("\n___ LIST OF STUDENT ___\n");
            for (int i = 0; i < size; i++)
            {
                if (!dataOfStudent[i].delete)
                {
                    output(dataOfStudent, i);
                }
            }
            break;

        case 3:
            printf("Sort in alphabetical order (press 0) \n  or in decreasing order of Average (press 1): ");
            int order;
            scanf("%d", &order);
            getchar();
            if (order)
                sortAverage(dataOfStudent, n);
            else
                sortALphabetical(dataOfStudent, n);
            printf("\nSorted!\n");
            break;

        case 4:
            printf("Search student using name (press 0) or ID (press 1): ");
            int search;
            scanf("%d", &search);
            getchar();
            if (search)
            {
                char ID[SIZE];
                printf("Enter ID: ");
                scanf("%s", ID);
                getchar();
                searchID(dataOfStudent, n, ID);
            }
            else
            {
                char name[SIZE];
                printf("Enter name: ");
                scanf("%[^\n]s", name);
                getchar();
                searchName(dataOfStudent, n, name);
            }
            break;

        case 5:
            printf("Enter the order number of student: ");
            int edit;
            scanf("%d", &edit);
            getchar();
            printf("Enter data: \n");
            input(dataOfStudent, edit - 1);
            printf("\nUpdated!\n\n");
            break;

        case 6:
            char ID[SIZE];
            printf("Enter ID: ");
            scanf("%s", ID);
            getchar();
            int sig = 0;
            for (int i = 0; i < size; i++)
            {
                if (strcmp(ID, dataOfStudent[i].ID) == 0)
                {
                    dataOfStudent[i].delete = 1;
                    decreaseRank(dataOfStudent, i, size);
                    i--;
                    sig = 1;
                    break;
                }
            }
            if (sig)
            {
                printf("\nRemove successful!\n\n");
            }
            else
                printf("\nCan not find out\n\n");
            break;

        case 7:
            FILE *outputFile;
            outputFile = fopen("StudentInfo.dat", "w"); //'w' means write mode
            // Check whether or not file descriptor can get any value
            if (outputFile == NULL)
            {
                fprintf(stderr, "Error while creating file");
                exit(1);
            }

            for (int i = 0; i < size; i++)
            {
                fwrite(&dataOfStudent[i], sizeof(Student), 1, outputFile);
            }
            // check for any error
            if (fwrite != 0)
            {
                printf("\nData were written to the file\n");
            }
            else
                printf("Error writing to the file");

            fclose(outputFile);
            break;

        case 8:
            FILE *inputFile;
            inputFile = fopen("StudentInfo.dat", "r"); //'r' means read mode
            // check for any error
            if (inputFile == NULL)
            {
                printf("\nError while opening file\n");
                exit(1);
            }
            int i = 0;
            while (fread(&dataOfStudent[i], sizeof(Student), 1, inputFile))
            {
                printf("Student (%d):\n", i + 1);
                printf("\tID: %s\n", dataOfStudent[i].ID);
                printf("\tFull Name: %s\n", dataOfStudent[i].fullName);
                printf("\tDate of birth: %s\n", dataOfStudent[i].dateOfBirth);
                printf("\tDepartment: %s\n", dataOfStudent[i].department);
                printf("\tMath score: %.2f\n", dataOfStudent[i].math);
                printf("\tEnglish score: %.2f\n", dataOfStudent[i].english);
                printf("\tProgramming score: %.2f\n", dataOfStudent[i].programming);
                printf("\tAverage score: %.2f\n", dataOfStudent[i].average);
                printf("\tRank: %d\n\n", dataOfStudent[i].rank);
                i++;
            } 
            fclose(inputFile);
            break;

        default:
            break;
        }
    } while (option != 0);
    free(dataOfStudent);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void input(Student *dataOfStudent, int i)
{
    int sum = 0;
    static int rank = 0;
    rank++;
    printf("\tID: ");
    scanf("%[^\n]s", &dataOfStudent[i].ID);
    getchar();

    printf("\tFull name: ");
    scanf("%[^\n]s", &dataOfStudent[i].fullName);
    getchar();

    printf("\tDate of birth: ");
    scanf("%[^\n]s", &dataOfStudent[i].dateOfBirth);
    getchar();

    printf("\tDepartment: ");
    scanf("%[^\n]s", &dataOfStudent[i].department);
    getchar();

    printf("\tScore of Math: ");
    scanf("%f", &dataOfStudent[i].math);
    getchar();

    sum += dataOfStudent[i].math;
    printf("\tScore of English: ");
    scanf("%f", &dataOfStudent[i].english);
    getchar();

    sum += dataOfStudent[i].english;
    printf("\tScore of Programming: ");
    scanf("%f", &dataOfStudent[i].programming);
    getchar();

    sum += dataOfStudent[i].programming;

    // calculate average
    dataOfStudent[i].average = sum / 3.0;

    // calculate rank
    dataOfStudent[i].rank = rank;

    for (int j = 0; j < i && i != 0; j++)
    {
        if (dataOfStudent[i].average > dataOfStudent[j].average)
        {
            dataOfStudent[i].rank--;
            dataOfStudent[j].rank++;
        }
    }
    dataOfStudent[i].delete = 0;
}

void output(Student *dataOfStudent, int i)
{
    printf("Student (%d):\n", i + 1);
    printf("\tID: %s\n", dataOfStudent[i].ID);
    printf("\tFull Name: %s\n", dataOfStudent[i].fullName);
    printf("\tDate of birth: %s\n", dataOfStudent[i].dateOfBirth);
    printf("\tDepartment: %s\n", dataOfStudent[i].department);
    printf("\tMath score: %.2f\n", dataOfStudent[i].math);
    printf("\tEnglish score: %.2f\n", dataOfStudent[i].english);
    printf("\tProgramming score: %.2f\n", dataOfStudent[i].programming);
    printf("\tAverage score: %.2f\n", dataOfStudent[i].average);
    printf("\tRank: %d\n\n", dataOfStudent[i].rank);
}

void swapStruct(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortAverage(Student *dataOfStudent, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dataOfStudent[i].average < dataOfStudent[j].average)
                swapStruct(&dataOfStudent[i], &dataOfStudent[j]);
        }
    }
}

void sortALphabetical(Student *dataOfStudent, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(dataOfStudent[i].fullName, dataOfStudent[j].fullName) > 0)
                swapStruct(&dataOfStudent[i], &dataOfStudent[j]);
        }
    }
}

void searchID(Student *dataOfStudent, int n, char *ID)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ID, dataOfStudent[i].ID) == 0)
        {
            printf("Information:\n");
            output(dataOfStudent, i);
            return;
        }
    }
    printf("Not found.\n\n");
}

void searchName(Student *dataOfStudent, int n, char *Name)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(Name, dataOfStudent[i].fullName) == 0)
        {
            printf("Information:\n");
            output(dataOfStudent, i);
            return;
        }
    }
    printf("Not found.\n\n");
}

void decreaseRank(Student *dataOfStudent, int p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (dataOfStudent[i].rank > dataOfStudent[p].rank)
            dataOfStudent[i].rank--;
    }
}