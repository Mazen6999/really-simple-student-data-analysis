#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Mazen Ahmed Ramzy, 6999
//Mazen Ahmed Mohamed Ghanem, 6896
//Question 1

typedef struct
{
    int day;
    int month;
    int year;

} date;

typedef struct
{
    int ID;
    float GPA;
    char name[20];
    date DOB;

} student;

void readStudents(student s[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Enter student %d ID: ",i);
        scanf("%d",&s[i].ID);

        printf("Enter student %d GPA: ",i);
        scanf("%f",&s[i].GPA);

        printf("Enter student %d name(day month year): ",i);
        scanf("%s",s[i].name);

        printf("Enter student %d Date of birth: ",i);
        scanf("%d %d %d",&s[i].DOB.day,&s[i].DOB.month,&s[i].DOB.year);
    }
}
float averagegpa (student s[],int n)
{
    int i;
    float sum=0.0;
    for(i=0; i<n; i++)
        sum+=s[i].GPA;
    return sum/n;
}
void printMoreAverage(student s[],int n)
{
    int i;
    float average=averagegpa(s,n);
    printf("Average GPA is %f\n",average);
    for(i=0; i<n; i++)
    {
        if(s[i].GPA>average)
            printf("%s got above average GPA.\n",s[i].name);
    }
}
void printStudents (student s[],int n,int year)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(s[i].DOB.year==year)
            printf("%s was born in %d\n",s[i].name,year);
    }
}


int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    student s[n];
    readStudents(s,n);
    printMoreAverage(s,n);
    int year;
    printf("Enter year of birth: ");
    scanf("%d",&year);
    printStudents(s,n,year);


    return 0;
}
    