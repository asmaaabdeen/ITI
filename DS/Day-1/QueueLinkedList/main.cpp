#include <iostream>

using namespace std;
struct employee {
int id;
int age;
float salary;
};


struct Node
{
	employee data;
	Node *prev, *next;


};
 Node* getnode(employee data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->prev = newNode->next = NULL;
		return newNode;
	}

class MyQue
{
    public:
	Node* front;
	Node* rear;
	int Size;

public:
	MyQue()
	{
		front = rear = NULL;
		Size = 0;
	}

bool isEmpty()
{
	return (front == NULL);
}
bool isFull()
{
	return false;
}

int size()
{
	return Size;
}


void EnQue(employee data)
{

   	Node* newNode = getnode(data);
	if (newNode == NULL)
		cout << "OverFlow\n";
	else
	{
		if (rear == NULL)
			front = rear = newNode;
		else
		{
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}

		Size++;
	}
}

void DeQue()
{
    if (isEmpty())
        cout << "Can't Deque .. Queue is Empty\n";
    else
    {
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);
        Size--;
    }
}

void printQ(){

	if (isEmpty())
		cout << "Queue is empty";
	else {
		 Node* ptr = front;
		cout <<"Queue is : \n\n";
		while (ptr != NULL) {
			cout <<" id is "<< ptr->data.id <<endl;
			cout <<" age is  "<< ptr->data.age<<endl;;
			cout <<" salary is "<< ptr->data.salary;
			ptr = ptr->next;
			cout <<"\n------------------------------- \n";
		}
}
}

employee Peak()
{

    if (!isEmpty())

    return front->data;
}
};

int main()
{
	MyQue Q;
	employee E1;
	E1.age =22;
	E1.id=1;
	E1.salary=2000;

		employee E2;
	E2.age =82;
	E2.id=8;
	E2.salary=2550;

		employee E3;
	E3.age =888;
	E3.id=85;
	E3.salary=44560;

	Q.EnQue(E1);
	Q.EnQue(E2);
	Q.EnQue(E3);

	Q.printQ();

	cout <<"-----------------deque1---------------------" << endl;
	Q.DeQue();

	Q.printQ();

	cout <<"-----------------deque2---------------------" << endl;
	Q.DeQue();

	Q.printQ();




	return 0;
}
