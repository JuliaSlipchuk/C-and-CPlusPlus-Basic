#include <stdio.h>
#include <stdbool.h>

int main()
{
    // first part
    int day = 20;
    int month = 2;
    int year = 2016;
    printf("%04d-%02d-%02d - YYYY-MM-DD format - ISO 8601\n", year, month, day);
    printf("%02d-%02d-%04d - MM-DD-YYYY format\n", month, day, year);
    printf("%02d-%02d-%04d - DD-MM-YYYY format\n", day, month, year);
    printf("%d-%d-%d - D-M-Y format\n", day, month, year);

    // second part
    float studentAYear1 = 4.2;
    float studentAYear2 = 4.5;
    float studentAYear3 = 4.2;

    float studentBYear1 = 4.3;
    float studentBYear2 = 4.4;
    float studentBYear3 = 4.7;

    float studentCYear1 = 4.3;
    float studentCYear2 = 4.8;
    float studentCYear3 = 4.9;

    printf("Student name: 1stYGrade 2ndYGrade 3rdYGrade\t  Avg \n");
    printf("Student A \t\t   %.2f \t %.2f \t   %.2f   %.2f\n", studentAYear1, studentAYear2, studentAYear3, (studentAYear1 + studentAYear2 + studentAYear3) / 3);
    printf("Student B \t\t   %.2f \t %.2f \t   %.2f   %.2f\n", studentBYear1, studentBYear2, studentBYear3, (studentBYear1 + studentBYear2 + studentBYear3) / 3);
    printf("Student C \t\t   %.2f \t %.2f \t   %.2f   %.2f\n", studentCYear1, studentCYear2, studentCYear3, (studentCYear1 + studentCYear2 + studentCYear3) / 3);

    // third part
    printf("   ^   \n");
    printf("  / \\  \n");
    printf(" /   \\ \n");
    printf("<     >\n");
    printf(" \\   / \n");
    printf("  \\ /  \n");
    printf("   ν   \n");


    return 0;
}
