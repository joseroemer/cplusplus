#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

template<typename T>
class node
{
	public:
		node(T data)
		{
			this->data = data;
			next = back = NULL;
		}
		T data;
		node *next;
		node *back;
};

template<typename T>
class Stack
{
	private:
		int numNodes;
		node<T> *ini;
		node<T> *top;
		
	public:
		Stack()
		{
			numNodes = 0;
			ini = top = NULL;
		}
		~Stack()
		{
			node<T> *p = ini;
			node<T> *pa;
			while(p)
			{	
				pa = p;
				p = p->next;
				delete pa;
			}
		}
		void push(T data);
		void pop();
		T peek();
		void printStack();
		void printStackBackward();
		int size()
		{
			return numNodes;
		}
};

template<typename T>
void Stack<T>::push(T data)
{
	node<T> *n = new node<T>(data);
	if(top)
	{
		top->next = n;
		n->back = top;
		top = top->next;
	}
	else
	{
		ini = top = n;
	}
	
	numNodes++;
}

template<typename T>
void Stack<T>::pop()
{
	node<T> *pa;
	if(top)
	{
		pa = top;
		top = top->back;
		cout<<"pop: "<<pa->data<<endl;
		delete pa;
		top->next = NULL;
	}
}

template<typename T>
T Stack<T>::peek()
{
	return top->data;
}

template<typename T>
void Stack<T>::printStack()
{
	cout<<"Stack: "<<endl;
	node<T> *p = ini; 
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

template<typename T>
void Stack<T>::printStackBackward()
{
	cout<<"Stack backward: "<<endl;
	node<T> *p = top; 
	while(p)
	{
		cout<<p->data<<" ";
		p = p->back;
	}
	cout<<endl;
}

int main(int argc, char** argv) {
	
	Stack<int> stackInt;
	stackInt.push(10);
	stackInt.push(11); 
	stackInt.push(12);
	stackInt.push(13);
	
	stackInt.printStack();
	cout << "peek: "<<stackInt.peek()<<endl;
	stackInt.printStackBackward();
	
	stackInt.pop();
	stackInt.pop();
	
	cout << "peek: "<<stackInt.peek()<<endl;
	//cout << "peek: "<<stackInt.peek()<<endl;
	stackInt.printStack();
	stackInt.printStackBackward();
	
	return 0;
}
