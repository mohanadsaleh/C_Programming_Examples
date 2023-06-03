#include <stdio.h>

struct student {
    int number;
    char name[20];
    float midterm_grade, final_grade;
};

void createFile() {
    struct student info;
    FILE *p = fopen("notlar.txt", "w");

    if (p == NULL)
        printf("Could not open the file");
    else {
        printf("Enter name: ");
        scanf("%s", info.name);
        printf("Enter number: ");
        scanf("%d", &info.number);
        printf("Enter grade: ");
        scanf("%f", &info.final_grade);

        fprintf(p, "%s %d %f %f", info.name, info.number, info.midterm_grade, info.final_grade);
    }
    fclose(p);
    printf("Data successfully written in file notlar.txt\n");
    printf("The file is now closed.");
}

void readFile() {
    struct student info;
    FILE *ptr = fopen("notlar.txt", "r");

    if (ptr == NULL)
        printf("Could not open the file");
    else {
        fscanf(ptr, "%s%d%f%f", info.name, &info.number, &info.final_grade, &info.midterm_grade);
        while (!feof(ptr)) {
            printf("Student information:\n");
            printf("Name: %s\n", info.name);
            printf("Number: %d\n", info.number);
            printf("Midterm Grade: %f\n", info.midterm_grade);
            printf("Final Grade: %f\n", info.final_grade);
            fscanf(ptr, "%s%d%f%f", info.name, &info.number, &info.final_grade, &info.midterm_grade);
        }
    }

    fclose(ptr);
    printf("All information in the file has been read.\n");
    printf("The file is now closed.");
}

void filter() {
    struct student info;
    FILE *ptr = fopen("notlar.txt", "r");

    if (ptr == NULL)
        printf("Could not open the file");
    else {
        fscanf(ptr, "%s%d%f%f", info.name, &info.number, &info.final_grade, &info.midterm_grade);
        while (!feof(ptr)) {
            if ((0.4 * info.midterm_grade + 0.6 * info.final_grade) > 60) {
                printf("Student information:\n");
                printf("Name: %s\n", info.name);
                printf("Number: %d\n", info.number);
                printf("Midterm Grade: %f\n", info.midterm_grade);
                printf("Final Grade: %f\n", info.final_grade);
            }
            fscanf(ptr, "%s%d%f%f", info.name, &info.number, &info.final_grade, &info.midterm_grade);
        }
    }

    fclose(ptr);
    printf("All information in the file has been read.\n");
    printf("The file is now closed.");
}

void transfer() {
    struct student bilgi;
    FILE *myptr = fopen("notlar.txt", "r");
    FILE *ptr1 = fopen("gecenler.txt", "w");
    FILE *ptr2 = fopen("kalanlar.txt", "w");

    if (myptr == NULL)
        printf("Could not open the file");
    else {
        fscanf(myptr, "%s%d%f%f", bilgi.name, &bilgi.number, &bilgi.midterm_grade, &bilgi.final_grade);
        while (!feof(myptr)) {
            if ((bilgi.midterm_grade * 0.4 + bilgi.final_grade * 0.6) >= 60)
                fprintf(ptr1, "%s %d %f %f", bilgi.name, bilgi.number, bilgi.midterm_grade, bilgi.final_grade);
            else
                fprintf(ptr2, "%s %d %f %f", bilgi.name, bilgi.number, bilgi.midterm_grade, bilgi.final_grade);

            fscanf(myptr, "%s%d%f%f", bilgi.name, &bilgi.number, &bilgi.midterm_grade, &bilgi.final_grade);
        }
    }
    fclose(myptr);
    fclose(ptr1);
    fclose(ptr2);

    printf("Operation completed successfully.");
}

void sizeofFile() {
    FILE *pointer = fopen("notlar.txt", "r");
    int counter = 0;
    char c;

    if (pointer == NULL)
        printf("File could not be opened\n");
    else {
        c = fgetc(pointer);
        while (!feof(pointer)) {
            counter++;
            c = fgetc(pointer);
        }
    }

    printf("Size of the file: %d BYTES\n", counter);
    fclose(pointer);
}

int main(void) {
    int chois;

    printf("1 - Create and enter data into file\n");
    printf("2 - Read and list content of file\n");
    printf("3 - List students with a grade greater than 60\n");
    printf("4 - Copy students with a grade greater than or equal to 60 to 'pass.txt', others to 'fail.txt'\n");
    printf("5 - Print the size of the file\n");
    printf("6 - Exit\n");
    scanf("%d", &chois);

    while (chois != 6) {
        switch (chois) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                filter();
                break;
            case 4:
                transfer();
                break;
            case 5:
                sizeofFile();
                break;
            case 6:
                printf("Program terminated\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }

        printf("Enter your choice: ");
        scanf("%d", &chois);
    }

    return 0;
}

