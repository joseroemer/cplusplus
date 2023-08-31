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
class Queue
{
	private:
		int numNodes;
		node<T> *front;
		node<T> *roar;
		
	public:
		Queue()
		{
			numNodes = 0;
			front = roar = NULL;
		}
		~Queue()
		{
			node<T> *p = front;
			node<T> *pa;
			while(p)
			{	
				pa = p;
				p = p->next;
				delete pa;
			}
		}
		void enqueue(T data);
		void dequeue();
		void printQueue();
		int size()
		{
			return numNodes;
		}
		T getFront()
		{
			T bRet;
			if(front)
			{
				bRet = front->data;
			}
			return (bRet);
		}
		T getRoar()
		{
			T bRet;
			if(roar)
			{
				bRet = roar->data;
			}
			return (bRet);
		}
};

template<typename T>
void Queue<T>::enqueue(T data)
{
	node<T> *n = new node<T>(data);
	if(roar==NULL)
	{
		//first
		front = roar = n;  
	}
	else
	{
		roar->next = n;
		n->back = roar;
		roar = n;
	}
	numNodes++;
}

template<typename T>
void Queue<T>::dequeue()
{
	if (front!=NULL)	
	{
		node<T> *n = front;
		cout<<"enqueing: "<<n->data<<endl;
		front = front->next;
		delete n;
		numNodes--;
	}
}

template<typename T>
void Queue<T>::printQueue()
{
	cout<<"Queue: ";
	node<T> *p = front;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
} 
int main(int argc, char** argv) {
	
	Queue<int> queueInt;
	queueInt.enqueue(10);
	queueInt.enqueue(11);
	queueInt.enqueue(12);
	queueInt.enqueue(13);
	queueInt.enqueue(14);
	queueInt.enqueue(15);
	queueInt.enqueue(16);
	
	queueInt.printQueue();
	cout<<"front: "<<queueInt.getFront()<<endl;
	cout<<"roar: "<<queueInt.getRoar()<<endl;
	cout<<"size: "<<queueInt.size()<<endl;

	queueInt.dequeue();	
	queueInt.dequeue();	
	queueInt.printQueue();
	cout<<"front: "<<queueInt.getFront()<<endl;
	cout<<"roar: "<<queueInt.getRoar()<<endl;
	cout<<"size: "<<queueInt.size()<<endl;
	
	return 0;
} 

