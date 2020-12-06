#include <iostream>
using namespace std;

struct node* create_linked_list(int n,struct node *newnode,struct node *head,struct node *temp);
void print_LL(struct node *head,struct node *temp,int n);
void insert_at_begin(struct node *newnode,struct node *head,struct node *temp,int n);
void insert_at_end(struct node *newnode,struct node *head,struct node *temp,int n);
void insert_before_position(struct node *newnode,struct node *head,struct node *temp,int n);
void insert_after_position(struct node *newnode,struct node *head,struct node *temp,int n);

struct node
{
    int data;
    struct node *next;
};

struct node* create_linked_list(int n,struct node *newnode,struct node *head,struct node *temp)
{
    head=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        cout<<"\nENTER ELEMENT : ";
        cin>>newnode->data;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
    }

    return head;
}

void print_LL(struct node *head,struct node *temp,int n)
{
    cout<<"\nELEMENTS OF THE LINKED LIST : \t";
    temp=head;
    for(int j=0;j<n;j++)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}


void insert_at_begin(struct node *newnode,struct node *head,struct node *temp,int n)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    cout<<"\nENTER THE VALUE TO BE INSERTED AT THE BEGINNING : ";
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;

    n++;
    print_LL(head,temp,n);


}

void insert_at_end(struct node *newnode,struct node *head,struct node *temp,int n)
{
    temp=head;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    newnode=(struct node *)malloc(sizeof(struct node));
    cout<<"\nENTER THE VALUE TO BE INSERTED AT THE END: ";
    cin>>newnode->data;
    newnode->next=NULL;

    temp->next=newnode;
    n++;
    print_LL(head,temp,n);
}

void insert_before_position(struct node *newnode,struct node *head,struct node *temp,int n)
{
    int position;
    cout<<"ENTER THE POSITION : ";
    cin>>position;
    temp=head;
    struct node *prev;
    for(int i=1;i<position;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    newnode=(struct node *)malloc(sizeof(struct node));
    cout<<"\nENTER THE VALUE TO BE INSERTED : ";
    cin>>newnode->data;

    newnode->next=prev->next;
    prev->next=newnode;
    n++;
    print_LL(head,temp,n);

}
void insert_after_position(struct node *newnode,struct node *head,struct node *temp,int n)
{
    int position;
    cout<<"ENTER THE POSITION : ";
    cin>>position;
    temp=head;
    for(int j=1;j<position;j++)
    {
        temp=temp->next;
    }
    newnode=(struct node *)malloc(sizeof(struct node));
    cout<<"\nENTER THE VALUE TO BE INSERTED : ";
    cin>>newnode->data;

    newnode->next=temp->next;
    temp->next=newnode;
    n++;
    print_LL(head,temp,n);

}


int main()
{
    int n,choice;
    cout<<"\nENTER THE TOTAL ELEMENTS IN LL: ";
    cin>>n;
    struct node *newnode,*head,*temp;
    head=create_linked_list(n,newnode,head,temp);
    print_LL(head,temp,n);

    cout<<"\n 1 INSERT AT BEGINNING";
    cout<<"\n 2 INSERT AT END";
    cout<<"\n 3 INSERT BEFORE POSITION";
    cout<<"\n 4 INSERT AFTER POSITION";

     cout<<"\nENTER YOUR CHOICE : ";
    cin>>choice;

    switch(choice)
        {
        case 1:
             insert_at_begin(newnode,head,temp,n);
             break;

        case 2:
            insert_at_end(newnode,head,temp,n);
            break;

        case 3:
            insert_before_position(newnode,head,temp,n);
            break;

        case 4:
            insert_after_position(newnode,head,temp,n);
            break;

        default:
            cout<<"\nINVALID NUMBER";

        }

    return 0;
}
