#include<iostream>
using namespace std;

class node{
	public:
	int coef;
	int expo;
	node *next;
};
 	 node *head1=NULL;
 	 node *head2=NULL;
     node *head3=NULL;
     node *head4=NULL;
 node *temp=NULL;

void create(node **head,int x,int y=0)
{
node *newnode=new node();
newnode->coef=x;
newnode->expo=y;
newnode->next=NULL;
if(*head==NULL)
*head=temp=newnode;
else{
temp->next=newnode;
temp=newnode;
}
}

void display(node **head){
	temp=*head;
	while(temp!=NULL)
	{
		cout<<temp->coef<<"x^"<<temp->expo<<" + ";
		temp=temp->next;	
	}
	cout<<endl;
}

void sumPoly(node **head1,node **head2)
{
    node *p1,*p2;
    p1=*head1;
    p2=*head2;
    
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expo==p2->expo)
        {
            create(&head3,p1->coef+p2->coef,p1->expo);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expo>p2->expo)
        {
           create(&head3,p1->coef,p1->expo);
           p1=p1->next;
        }
        else
        {
           create(&head3,p2->coef,p2->expo);
           p2=p2->next;            
        }
    }
}

void mulPoly(node **head1,node **head2)
{
    node *p1,*p2;

    
    for(p1=*head1;p1!=NULL;p1=p1->next)
    {
        for(p2=*head2;p2!=NULL;p2=p2->next)
        {
            create(&head4,(p1->coef*p2->coef),(p1->expo+p2->expo));
        }
    }
    
}

int main(){

	create(&head1,1,3);
	create(&head1,2,1);
	create(&head1,3);
	display(&head1);
	
	create(&head2,2,2);
	create(&head2,3,1);
	create(&head2,4);
	display(&head2);
	
	sumPoly(&head1,&head2);
	display(&head3);
	
	mulPoly(&head1,&head2);
	display(&head4);
	
	return 0;	
}
