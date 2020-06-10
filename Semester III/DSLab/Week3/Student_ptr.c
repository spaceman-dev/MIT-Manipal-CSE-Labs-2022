#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
char name[100];
int rno;
double cgpa;
}Student;
void sort(Student *s,int n);
void read(Student *s,int i);
void display(Student *s,int i);
void read(Student *s,int i)
{
printf("Enter the Name of the Student : \n");
scanf("%s",s[i].name);
printf("Enter the Roll Number of the Student : \n");
scanf("%d",&s[i].rno);
printf("Enter the CGPA of the Student : \n");
scanf("%lf",&s[i].cgpa);
}
void display(Student *s,int i)
{
printf("Name = %s\n",s[i].name);
printf("Roll Number = %d\n",s[i].rno);
printf("CGPA = %lf\n",s[i].cgpa);
}
void sort(Student *s,int n)
{
Student temp;
int i,j;
for(i = 0 ; i < n-1 ; i ++)
{
for(j = 0 ; j < n-i-1 ; j++)
{
if(s[j].rno > s[j+1].rno)
{
temp = s[j];
s[j] = s[j+1];
s[j+1] = temp;
}
}
}
}
void main()
{
Student *s;
int n,i;
printf("Enter the Number of Students : \n");
scanf("%d",&n);
s = (Student *)calloc(n,sizeof(Student));
for(i = 0 ; i < n ; i ++)
    read(s,i);
sort(s,n);
printf("\nAfter Sorting we get,\n");
for(i = 0 ; i < n ; i ++)
    display(s,i);
}