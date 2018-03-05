#include<iostream>
using namespace std;
struct node //Def. of node
{
	int data;
	node *next;
};
class queueLL
{
	node *head;
	node *tail; 
	public:
	 queueLL()
	 {
	 	head=tail=NULL;
	 }
	 void print();
	 void push(int data);
	 void pop();
};
//Create a Queue
void queueLL::print() //display all the elements
{
	if(head==NULL) cout << "\n\nNo Queue!";
	 else 
	 {
	 	cout<<endl<<endl;
	 	node *temp=head;
	 	while(temp)
	 	{
	 		cout<<temp->data<<" ";
			temp=temp->next;	
		}
	 }
}
void queueLL::push(int data)
{
	node *temp= new node;
	if(!temp) cout<<"\n\nOverflow!"; //If there is no space to create another node
	 else
	 {
	 	temp->data=data;
	 	temp->next=NULL;
	 	if(head==NULL) head=temp; //no elements earlier
	 	else tail->next=temp;
	 	tail=temp; //Make this the new tail after linking this and the pre node 
	 	cout<<"\n\nPushed into the Queue!";
	 }
}
void queueLL::pop()
{
	if(head==NULL) cout<<"\n\nNo Queue!";
	 else
	 {
	 	node *temp=head;
	 	head=head->next; //Move the head back
	 	temp=NULL;
	 	cout<<"\n\nPopped out of the Queue!";
	 }
}
int main()
{
	int i=1,data;
	while (ch)
	{
		cout<<"\n\nEnter 1 to Push, 2 to Pop, 3 to Print and 0 to Exit. : ";//wait for user response
		cin>>i;
		switch(i)
		{
			case 1 : cout<<"\n\nEnter the data to be added : ";cin>>data;ob.push(data);break;
			case 2 : ob.pop();break;
			case 3 : ob.print();break;
			case 0 : cout<<"\n\nThanks!";break;
			default : cout<<"\n\nIncorrect option!"; 
		}
	}
	return 0;
}
