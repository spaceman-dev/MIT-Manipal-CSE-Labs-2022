#include <stdio.h>
#include<string.h>
#define MAX 10
typedef struct
{
    char data[MAX][MAX];
    int f;
    int r;
    int size;
}QUEUE;
void insert(QUEUE *q,char *arr){
    if (q->size==5)
    {
        printf("Over Flow\n");
        return;
    }
    printf("Inserting %s\n",arr);
    q->r = (q->r + 1) % 5;
    printf("%d\n",q->r );
    for (int i = 0; i < strlen(arr); i++)
    {
        q->data[q->r][i]=*(arr+i);
    }
    q->size++;
    if (q->f==-1)
    {
        q->f=0;
    }
}
void delete(QUEUE *q){
    if (q->size==0){
        printf("Empty QUEUE\n");
        return;
    }
    printf("Deleting %s \n",q->data[q->f] );
    q->f = (q->f + 1) % 5;
    q->size--;
}
void display(QUEUE *q){
    if (q->size==0){
        printf("Empty QUEUE\n");
        return;
    }
for (int i = q->f; i <=q->r; i++)
{
    printf("%s\n",q->data[i] );
}
}
int main()
{
    QUEUE p;
    p.f=-1;
    p.r=-1;
    int flag=1,ch;
    char x[10];
    while (flag){
        printf("Enter 1.Insert,2.delete,3.display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the string to be inserted\n");
                scanf("%s",x);
                insert(&p,x);
                break;
            case 2:
                delete(&p);
                break;
            case 3:
                display(&p);
                break;
            default:
                flag=0;
                break;
        }
    }
    return 0;
}