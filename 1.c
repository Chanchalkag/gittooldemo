#include<stdio.h>
struct node
{
int data;
struct node *next;
}*start=NULL,*current=NULL;
struct node *creatMemory(int n)
{
 struct node * temp=NULL;
 temp=(struct node*)malloc(sizeof(struct node));
 temp->data=n;
 temp->next=NULL;
 return temp;
}
void showData(struct node *temp)
{
 clrscr();
 temp=start;
 while(temp!=NULL)
 {
  printf("%d ->",temp->data);
  temp=temp->next;
 }
}
 void linkDataAtFirst()
 {
  int n;
  struct node * temp=NULL;
  clrscr();
  printf("Enter A Number:");
  scanf("%d",&n);
  temp=creatMemory(n);
  if(start==NULL)
  {
   start=temp;
  }
  else
  {
   temp->next=start;
   start=temp;
  }
  showData(temp);
 }

 void linkDataAtLast()
 {
  int n;
  struct node * temp=NULL;
  clrscr();
  printf("Enter A Number:");
  scanf("%d",&n);
  temp=creatMemory(n);
  if(start==NULL)
  {
   start=temp;
  }
  else
   {
     current=start;
     while(current->next!=NULL)
     {
	  current=current->next;
     }
      current->next=temp;
      current=temp;
   }
    showData(temp);
 }
  void linkDataNthLast()
 {
  int n,c=1,pos;
  struct node * temp=NULL;
  clrscr();
  printf("Enter A Number:");
  scanf("%d",&n);
  printf("Enter A Possion");
  scanf("%d",&pos);
  temp=creatMemory(n);
  if(start==NULL)
  {
   linkDataAtFirst();
  }
  else
  {  
    current=start;
    while(c<pos-1)
    {
     current=current->next;
     c++;
    }
    temp->next=current->next;
    current->next=temp;
     showData(temp);
  }
 }

 void deleteAtFirst()
 {
  clrscr();
 if(start->next==NULL)
 {
  free(start);
  current=NULL;
 }
 else
 {
  current=start;
  start=current->next;
  free(current);
  current->next=NULL;
 }
 showData(start);
}
 void deleteAtLast()
 {
  clrscr();
  current=start;
  while(current->next->next!=NULL)
  {
     current=current->next;
  }
    free(current->next);
    current->next=NULL;
    showData(start);
 }

void deleteAtNth()
{
 struct node*tempStart=NULL;
 int c=1,p;
 clrscr();
 printf("Enter A Possion:");
 scanf("%d",&p);
 if(start==NULL)
 {
  free(start);
  start=NULL;
 }
 else
 {
   current=start;
   while(c<p-1)
   {
    current=current->next;
    c++;
   }
    tempStart=current->next->next;
    free(current->next);
    current->next=NULL;
    current->next=tempStart;
 }
 showData(start);
}

 void main()
 {
    clrscr();
    linkDataAtFirst();
    linkDataAtFirst();
    linkDataAtFirst();
    linkDataAtLast();
    linkDataAtLast();
    linkDataNthLast();
    deleteAtNth();
    deleteAtFirst();
    deleteAtLast();
    getch();

 }