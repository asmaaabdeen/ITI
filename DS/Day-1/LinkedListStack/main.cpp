#include <iostream>

using namespace std;
struct employee {
int id;
int age;
float salary;
};

struct Node {
	employee data;
	struct Node* prev;
	struct Node* next;
};


class MyStack {
private :
    Node* start = NULL;
    Node* tos = NULL;

public:

    bool isFull(){
    return false;
    }
bool isEmpty()
{
	return (start == NULL);
}


void push(employee E)
{
	 Node* n;
	n = new Node();
	n->data = E;
	if (isEmpty()) {
		n->prev = NULL;
		n->next = NULL;
		start = n;
		tos = n;
	}
	else {
		tos->next = n;
		n->next = NULL;
		n->prev = tos;
		tos = n;
	}
}

employee pop()
{
    Node temp = *tos;
	 Node* n;
	n = tos;
	if (isEmpty())
		cout<<"Stack is empty";
	else {

            if (tos == start) {
		tos = NULL;
		start = NULL;
		free(n);
		  return temp.data;
	}
	else {
		tos->prev->next = NULL;
		tos = n->prev;
		free(n);
		  return temp.data;
	}
	}
}

employee Peak()
{
	if (isEmpty())
		cout<<"Stack is empty";
	else

		return	tos->data;
}

void stackCount()
{
	int c = 0;
	if (isEmpty())
		cout<<"Stack is empty";
	else {
		 Node* ptr = start;
		while (ptr != NULL) {
			c++;
			ptr = ptr->next;
		}
	}
	cout<<"Size of the stack is : "<< c <<endl;
}


void ViewContent()
{
	if (isEmpty())
		cout<<"Stack is empty";
	else {
		 Node* ptr = start;
		cout<<"Stack is : \n";
		while (ptr != NULL) {
				cout <<" id is "<< ptr->data.id <<endl;
			cout <<" age is  "<< ptr->data.age<<endl;;
			cout <<" salary is "<< ptr->data.salary;
			ptr = ptr->next;
			cout <<"\n------------------------------- \n";
		}

	}
}
};

int main()
{
	employee E1;
	E1.age = 22;
	E1.id=1;
	E1.salary= 25000;

	employee E2;
	E2.age = 50;
	E2.id=207;
	E2.salary= 29850;

	employee E3;
	E3.age = 35;
	E3.id=2;
	E3.salary= 16000;

	MyStack stk;
	stk.push(E1);
	stk.push(E2);
	stk.push(E3);

	stk.ViewContent();

	cout <<" poped " << stk.pop().id << endl <<  endl;

	stk.ViewContent();
	cout <<" last element id is " << stk.Peak().id << endl ;

	return 0;
}

