#include <iostream>
using namespace std;
class node		//create the node
{
 public:
 int data;
 node *next;
};
class QueuesLL		//make a queue, linked list
{
 private:
 node *head,*tail;
 public:
 QueuesLL()		
 {
  head=NULL;
  tail=NULL;
 }
 void enqueue(int data)		//enqueue=add an element
 {
  node *temp=new node;		
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)		//check if the queue is empty
  {
   head=temp;
   tail=temp;
  }
  else
  {
   tail->next=temp;
   tail=temp;
  }
 }
 int dequeue()		//return the last element
 {
  int p=head->data;
  head=head->next;
  return p;
 }
 void display()		//display the queue
 {
  node *temp=new node;
  temp=head;
  while(temp!=NULL)		//go to the last element
  {//display everything you pass by
   if(temp==tail)
   cout<<temp->data<<"\n";
   else
   cout<<temp->data<<"->";
   temp=temp->next;
  }
 }
};
int main()
{ 
 int data,n;
//ask the user what to do
 QueuesLL obj;
 cout<<"Enter the number of entries you want to make\n";
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cout<<"Enter data\n";
  cin>>data;
  obj.enqueue(data);
 }
 cout<<"The Queue is\n";
 obj.display();
 cout<<"Enter the data you want to enqueue\n";
 cin>>data;
 obj.enqueue(data);
 cout<<"After adding to the queue\n";
 obj.display();
 cout<<"Dequeueing\n"<<obj.dequeue()<<"\n";
 cout<<"After dequeueing\n";
 obj.display();
}
