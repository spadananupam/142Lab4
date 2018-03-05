#include<iostream>
#include<string>
using namespace std;
struct details //Structure of the data in the node
{
	int phone;
	char name[50];
	char des[100];
	void input() //deatils in
	{
		cout<<"\nEnter your name : ";
		cin>>name;
		cout<<"\nEnter your contact number : ";
		cin>>phone;
		cout<<"\nEnter the details of the complaint : ";
		cin>>des;
	}
	void details() //Print details.
	{
		cout<<"\nName : ";
		cout<<name;
		cout<<"\nContact number : ";
		cout<<phone;
		cout<<"\nDetails of the complaint : ";
		cout<<des;
	}
	int pal() //palindrome check
	{
		int i=0,j=0;
		for(;name[i]!='\0';i++);
		char ch[50];
		for(;j<i;j++) ch[j]=name[i-1-j]; //Make another array which is in the reverse order.
		int flag=0;
		for(j=0;flag==0&&j<i;j++) flag=ch[j]-name[j]; //Check is the elements match
		if(flag) return 1; //if it is not
		return 0; 
	}
};
struct node //Def. of node
{
	details data;
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
	 void push(details data);
	 void pop();
}; //Create a Queue
void queueLL::print() //Print the stuff out. Duh.
{
	if(head==NULL) cout << "\n\nNo Complaints!";
	 else 
	 {
	 	cout<<endl<<endl;
	 	node *temp=head;
	 	while(temp)
	 	{
	 		(temp->data).details();
			temp=temp->next;	
		}
	 }
}
void queueLL::push(details data)
{
	node *temp= new node;
	if(!temp) cout<<"\n\nOverflow!"; //No space to create a node
	 else
	 {
	 	temp->data=data; 
	 	temp->next=NULL;
	 	if(head==NULL) //If nothing is present, this is the new head and tail
		 {
		 	head=temp;
		 	tail=temp;
		 }
	 	else if(data.pal()==0) //If its palindrome, go to front
	 		 {
	 		 	temp->next=head;
	 		 	head=temp;
			 }
			 else //else, add at back
			 {
			  	tail->next=temp;			  					
	 		  	tail=temp;
	 	     }
	 	cout<<"\n\nComplaint added!";
	 }
}
void queueLL::pop() //Address the first complaint
{
	if(head==NULL) cout<<"\n\nNo Complaints!";
	 else
	 {
	 	node *temp=head;
	 	head=head->next;
	 	temp=NULL;
	 	cout<<"\n\nComplaint adressed!";
	 }
}
int main()
{
	int ch=1;
	details data;
	while (ch)
	{
		cout<<"\n\nEnter 1 to Add Complaint, 2 to Address Complaint , 3 to List the Complaints and 0 to Exit. : "; //User input
		cin>>ch;
		switch(ch)
		{
			case 1 : data.input();ob.push(data);break;
			case 2 : ob.pop();break;
			case 3 : ob.print();break;
			case 0 : cout<<"\n\nThanks!";break;
			default : cout<<"\n\nIncorrect option!"; 
		}
	}
	return 0;
}
