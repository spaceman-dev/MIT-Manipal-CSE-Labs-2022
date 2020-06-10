#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *l,*r;
}*NODE;

//insert front
NODE ins_f(NODE f)
{
    NODE n=(NODE)malloc(sizeof(struct node));
    printf("Input data: ");
    scanf("%d",&(n->data));
    n->l=NULL;
    n->r=NULL;
    if(f==NULL)
    {
        return n;
    }
    n->l=NULL;
    n->r=f;
    f->l=n;
    return n;
}

//insert rear
NODE ins_r(NODE f)
{
    NODE n=(NODE)malloc(sizeof(struct node));
    printf("Input data: ");
    scanf("%d",&(n->data));
    n->l=NULL;
    n->r=NULL;
    if(f==NULL)
    {
        return n;
    }
    NODE t=f;
    while(t->r!=NULL)
    {
        t=t->r;
    }
    t->r=n;
    n->r=NULL;
    n->l=t;
    return f;
}
NODE del_f(NODE f)
{
	//when the list is already empty
    if(f==NULL)
    {
        printf("\nEMPTY!!\n");
        return f;
    }
    //when there is only one node in list
    if(f->r==NULL)
    {
        printf("DELETED: %d",f->data);
        free(f);
        return NULL;
    }
    //more than one node
    NODE t=f;
    printf("DELETED: %d\n",t->data);
    f=t->r;
    f->l=NULL;
    free(t);
    return f;
}
NODE del_r(NODE f)
{	
	//when the list is already empty
    if(f==NULL)
    {
        printf("\nEMPTY LIST\n");
        return f;
    }
    //only one node in the list
    if(f->r==NULL)
    {
        printf("DELETED: %d",f->data);
        free(f);
        return NULL;
    }

    NODE t=f;
    NODE p=f;
    while(t->r!=NULL)
    {
        p=t;
        t=t->r;
    }
    printf("DELETED: %d\n",t->data);
    p->r=NULL;
    free(t);
    return f;
}
void display(NODE f)
{	
    if(f==NULL)
    {
        printf("\nEMPTY LIST\n");
        return;
    }
    printf("ELEMENTS: ");
    while(f!=NULL)
    {
        printf("%d ",f->data);
        f=f->r;
    }
    printf("\n");
}
int main()
{
    NODE f=NULL;
    int ch;
    int c;
    do{
    	printf("1:Insert Front\t2:Insert Rear\t3:Delete Front\t4:Delete Rear\t5:Display\t6:Exit\n");
    	scanf("%d", &ch);
    	switch(ch){
    		case 1: f=ins_f(f); break;
    		case 2:	f=ins_r(f); break;
    		case 3:	f=del_f(f); break;
    		case 4:	f=del_r(f); break;
    		case 5:	display(f); break;
    		default: printf("\nExiting!!\n");
		}
    }while(ch<6);
    return 0;
}
