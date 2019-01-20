//dll assignment.


#include <iostream>
using namespace std;

	//declaring a class for circle.
	class Node {
		public:
			Node * next;
			Node * prev;
			int data;
			   Node(){
				next=NULL;
				prev=NULL;
			   }
		};
	//declaring a class for dlinklist
	class dlinklist {
		Node * head;
		Node * tail;
		public:
		dlinklist()
		 {
			head=NULL;
			tail=NULL;
		 }

	//insert node,delete node,count and display


		void insert(int value);
		void insertat(int pos,int value);
		void del();
		void delat(int pos);
		int count();
		void display();
	 
       };

	//insert node(generally)
	

	void dlinklist::insert(int value){
		Node *current=new Node;
		current->data=value;
			if (head==NULL)
				{head=current;}
			else
				{current->prev=tail;
				 tail->next=current;}
				tail=current;
		}
	//insert node at certain position
	

	void dlinklist::insertat(int pos,int value){
		if( pos>this->count() )
			cout<<"Linklist doesnot have this many elements"<<endl;
		else{
			Node * temp = new Node;
			temp->data = value;
		if (pos==1)
		{
			head->prev=temp;
			temp->next=head;
			temp->prev=NULL;
			head=temp;
		}
		else
		{	
			int i=1;
			Node *current=head;
			while(i<pos-1)
			{current=current->next;i++;}
			temp->prev=current;
			temp->next=current->next;
			current->next=temp;
			if(temp->next!=NULL)
			temp->next->prev=temp;
		}
	}
	

	//delete node
	

		void dlinklist::del(){
			Node *current=head;
			while(current->next!=tail)
				{current=current->next;}
				tail=current;
				current=current->next;
				tail->next=NULL;
				current->prev=NULL;
				delete current;
		}
	

	//delete node at specific position
	

	void dlinklist::delat(int pos){
		if( pos>this->count() )
			cout<<"Linklist Does not have that many elements"<<endl;
		else
			{
				Node *current=head;int i=1;
				while(i<pos)
					{current=current->next;i++;}
			
				if (current!=head)
					{current->prev->next=current->next;}
			
				if (current!=tail)
					{current->next->prev=current->prev;}
				
				current->next=NULL;
				current->prev=NULL;
				delete current;
			
			}
		
		
	}
	

	//count the elements of dlinklist
	

		int dlinklist::count(){
		Node *current=head;int i=0;
		while(current!=NULL)
			{
				i+=1;
				current=current->next;
			}
		return i;
		}
	

	//display of elements
	

	void dlinklist::display()
		{
		Node *current=head;
			while(current!=NULL)
			{
				cout<<current->data<<"->";
				current=current->next;
			}
			cout<<"NULL"<<endl;
		}
	
	int main()
	{
		dlinklist dl;
		dl.insert(1);dl.insert(2);dl.insert(3);dl.insert(4);dl.insert(5);
		dl.display();
		dl.insertat(4,8);
		dl.display();
		dl.insertat(8,8);
		dl.del();
		dl.display();
		dl.delat(4);dl.display();	
		return 0;
	}
