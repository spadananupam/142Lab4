#include<iostream>
using namespace std;
 
class node{
public:
int data;
node *next;
};

class stack{
node *top;
public:
stack(){
top=NULL;
}

void push(int data){
node *temp=new node;//take input from the user, make new node
temp->data=data;
temp->next=NULL;
if(top!=NULL){
temp->next=top;
}
top=temp;
}

void pop(){
if(top==NULL){
cout<<"Stack is empty\n";  //If everything is empty
}
else
{//make the next thing the top and pop out the previous top
top=top->next;
cout<<top->data<<"\n";	
}
}

void show(){
node *temp=top;
while(temp!=NULL){	//display the stack
cout<<temp->data<<"->";
temp=temp->next;
}
cout<<"NULL"<<"\n";
}

};

int main(){
stack s;
int choice;
int x;
cout<<"\n\t So we will implement stack using linked lists\n";	//asking user what to do
cout<<"\n1-PUSH\n2-POP\n3-DISPLAY\n4-EXIT\nEnter choice\n";
cin>>choice;
switch(choice)//choices for the user
{
case 1:
cout<<"Enter the number to push\n";
cin>>x;
s.push(x);
break;
case 2:
s.pop();
break;
case 3:
s.show();
break;
case 4:
return 0;
break;
default:
cout<<"\n Please enter correct choice\n";
break;
}
return 0;
}
