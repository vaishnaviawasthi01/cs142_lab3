#include <iostream>
using namespace std;


	class node{
	  public:
		int data;
		// Pointer to the next Node
		node * next;
		// Constructor that makes the pointer to NULL
		node(int value){
		    next = NULL;
		    data = value;
		}
	};

	class circularlinkedlist
	{
	  public:
		node * head;
		//declaring head to be null
		circularlinkedlist(){
		    head = NULL;
		}


		// Insert circle to the end of the linked list.
		void insert(int value)
		{

		    // Create a new node
		    node * temp = new node(value);
		    // CHeck if the linkedlist is empty
			if (head == NULL)
		    {head = temp;}
			else
		    {Node *current = head;
				while (current->next != head)
					current = current->next;
					current->next = temp;
			}
			temp->next = head;
		}
		

// Displays the linked list.

		void display(){
		node *	current = head;
		if (current == NULL)
		{cout << "No elements in linked list. " << endl;
			return;}
		while (current->next != head)
			{cout << current->data << "->";
			current = current->next;}
        
		cout << current->data;
		cout << endl;
		}


	void insertat(int value, int pos)
	{
	// Create a new node
		node * temp = new node(value);
        // Check if linked list is empty
		if (head == NULL)
		{
			head = temp;
			temp->next = head;
		}
        
		else

        {
			node * current = head;
            int i = 1;
            while (i < pos-1)
			{
				current = current->next;
				i++;
			}
			temp->next = current->next;
			current->next = temp;
		}
	}
	

	void deleteat(int pos)
		{
		if (pos < count())
		{
			node * current = head;
			int i = 1;
			while (i < pos-1)
			{
				current = current->next;
				i++;
			}
		current->next = current->next->next;
		}
		else
		{
			cout << "can't perform the task. ";
		}
	}
    void delet()
	{
		node *current = head;
		while (current->next->next != head)
		{
			current = current->next;
		}
		current->next = head;
	}


	int count()
	{
		int i = 1;
		node * current = head->next;
		while (current != head)
		{
			current = current->next;
			i++;
		}
		return i;
	}
};

int main()
{
   circularlinkedlist csll1;
    for (int i = 1; i < 11; i++)
    {csll1.insert(i);}
	csll1.insert(11);
	csll1.display();
	csll1.insertat(3,8);
	csll1.display();
	csll1.delet();
	csll1.display();
	csll1.deleteat(4);
	csll1.display();
	csll1.count();
}
