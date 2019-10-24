#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *start=NULL;

void create();
void display();
void duplicacy();
struct node* createNode();

struct node* createNode()
{
struct node *tdx;
tdx=(struct node*)malloc(sizeof(struct node));
return tdx;
}

void create()
{
	struct node *temp,*t;
	temp=createNode();
	printf("Enter data:");
	scanf("%d",&temp->data);	
	temp->next=NULL;
	
	if(start==NULL)
	start=temp;
		
	
	else
	{
        t=start;
		while(t->next!=NULL)
		t=t->next;
		t->next=temp;
	}
	
}


void display()
{
struct node *t;

	t=start;
	while(t!=NULL)
	{
	printf("%d ",t->data);
	t=t->next;
  	}
}


void duplicacy()
{
struct node *t1;
struct node *t2;
struct node *dup;
t1=start;
t2=start;
while(t1!=NULL)
{
t2=t1;
	while(t2->next!=NULL)
	{
	if(t1->data==t2->next->data)
		{
		dup = t2->next;
		t2->next=t2->next->next;
		free(dup);
		}
	else
	t2=t2->next;
	}
t1=t1->next;
}
}

int main()
{
display();
printf("\n");
create();
create();
create();
create();
create();
create();
create();

printf("\nDisplaying elements before deletion of dupliactes\n");
display();
duplicacy();
printf("\nDisplaying elements after deletion of dupliactes\n");
printf("\n");

display();

return 0;
}
