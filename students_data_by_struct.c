#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printStudentData(struct student *ptr);
void getStudentData(struct student *ptr);
struct student {
    char name[20];
    char surname[20];
    int number;
    float midtermGrade;
    float finalGrade;
    float averageGrade;
};


int main(void) {
    int i, j, n;
    printf("How many students? ");
    scanf("%d", &n);

    struct student *ptr;
    ptr = (struct student *)malloc(n * sizeof(struct student));

    for (i = 0; i < n; i++)
	 {
        printf("\nStudent %d:\n", i + 1);
        getStudentData(ptr + i);
    }

    // Sort students by name
    for (i = 0; i < n; i++)
	 {
        for (j = i + 1; j < n; j++)
		 {
            if (strcmp((ptr + i)->name, (ptr + j)->name) > 0) 
			{
                struct student temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }

    printf("\nStudents sorted by name:\n");
   for ( i=0 ; i<n ; i++ )
    printStudentData( ptr+i );

    // Search by name
    char searchName[20];
    printf("Enter name to search for: ");
    scanf("%s", searchName);

    for (i = 0; i < n; i++) {
        if (strcmp((ptr + i)->name, searchName) == 0) {
            printStudentData( ptr+i );
            break;
        }
    }

    if (i == n) {
        printf("\nStudent not found.\n");
    }

    free(ptr);
    return 0;
}

void printStudentData(struct student *ptr) {
    printf("Name: %s\n", ptr->name);
    printf("Surname: %s\n", ptr->surname);
    printf("Number: %d\n", ptr->number);
    printf("Average grade: %.2f\n", ptr->averageGrade);
    printf("\n");
}
void getStudentData(struct student *ptr) {
    printf("Enter student information:\n");
    printf("Name: ");
    scanf("%s", ptr->name);

    printf("Surname: ");
    scanf("%s", ptr->surname);

    printf("Number: ");
    scanf("%d", &(ptr->number));

    printf("Midterm grade: ");
    scanf("%f", &(ptr->midtermGrade));

    printf("Final grade: ");
    scanf("%f", &(ptr->finalGrade));

    ptr->averageGrade = (ptr->midtermGrade * 0.4) + (ptr->finalGrade * 0.6);
}


