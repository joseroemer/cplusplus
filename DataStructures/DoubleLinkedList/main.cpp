#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//DubleLinkedList
using namespace std;
template<typename T>
class nodo
{
	public:
		nodo(T data)
		{
			//std::cout<<"creating a nodo"<<std::endl;
			this->data = data;
			next = back = NULL;
		}
		T data;
		nodo *next;
		nodo *back;
};

template<typename T>
class DLList
{
	int numNodos;
	
	public:
		DLList()
		{ 
			//std::cout<<"creating a list empty"<<std::endl;
			iniList = NULL; 
			numNodos = 0;
		}
		DLList(T data){ 
			//std::cout<<"creating a list with a element"<<std::endl;
			iniList = new nodo<T>(data);
			iniList->data = data;
			numNodos = 0;
		}
		
		~DLList()
		{ 
			//std::cout<<"destroying a list"<<std::endl;
			nodo<T> *p = iniList;
			nodo<T> *n;
			while(p)
			{
				n = p->next;
				//std::cout<<"destroying nodo: "<<p->data<<std::endl;
				delete p;
				p = n;
			}
		}
		
		DLList operator + (DLList list2)
		{
			DLList<T> newDLList;
			nodo<T> *p1 = this->iniList;
			if(p1)
			{
				while(p1)
				{
					newDLList.insertLast(p1->data);
					p1 = p1->next;
				}
			}
			nodo<T> *p2 = list2.iniList;	
			if(p2)
			{
				while (p2)
				{
					newDLList.insertLast(p2->data);
					p2 = p2->next;
				}
			}
			return (newDLList);
		}
		
		void insertLast(T data);
		void insertBegin(T data);
		//void insertLast(string data);
		void removeLast();
		void removeBegin();
		void printList();
		void printListBackward();
		int size();
		
		nodo<T> *iniList;
};

template<typename T>
int DLList<T>::size()
{
	return numNodos;
}
template<typename T>
void DLList<T>::insertLast(T data)
{
	//std::cout<<"inserting a node in last list"<<std::endl;
	nodo<T> *n = new nodo<T>(data);
	nodo<T> *p = iniList;
	if (p)
	{
		while(p->next)
		{
			p = p->next;
		}
		p->next = n;
		n->back = p;
	}
	else
	{
		iniList = n;
	}
	numNodos++;
}

template<typename T>
void DLList<T>::insertBegin(T data)
{
	nodo<T> *n = new nodo<T>(data);
	n->next = iniList;
	iniList->back = n; 
	iniList = n;
	numNodos++;
}

template<typename T>
void DLList<T>::removeLast()
{
	nodo<T> *p = iniList;
	nodo<T> *pa = iniList;
	if (p)
	{
		while (p->next)
		{
			p = p->next;
		}
		pa = p->back;
		std::cout<<"removing Begin: "<<p->data<< endl;
		delete p;
		pa->next = NULL;
		numNodos--;
	}
	else
	{
		std::cout<<"list EMPTY"<<endl;
	}	
}

template<typename T>
void DLList<T>::removeBegin()
{
	nodo<T> *p = iniList;
	if (p)
	{
		iniList = iniList->next;
		std::cout<<"removing Begin: "<<p->data<< endl;
		delete p; 
		numNodos--;		
	}
	else
	{
		std::cout<<"list EMPTY"<<endl;
	}
}

template<typename T>
void DLList<T>::printList()
{
	std::cout<<"printing a list forward"<<std::endl;
	nodo<T> *p = iniList;
	if (p)
	{
		while(p)
		{
			std::cout<<p->data<< " ";
			p=p->next;
		}
		std::cout<<std::endl;
	}
	else
	{
		std::cout<<"list EMPTY"<<endl;
	}
}

template<typename T>
void DLList<T>::printListBackward()
{
	std::cout<<"printing a list backward"<<std::endl;
	nodo<T> *p = iniList;
	if (p)
	{
		// move to the last
		while (p->next)
		{
			p = p->next;
		}
		
		// move to the Begin
		do
		{
			std::cout<<p->data<< " ";
			p = p->back;
		}while(p);
		std::cout<<std::endl;  
	}
	else
	{
		std::cout<<"list EMPTY"<<endl;
	}

}

int main(int argc, char** argv) {
	
	DLList<int> list1;
	list1.insertLast(10);
	list1.printList();
	
	list1.insertLast(15);
	list1.insertLast(20);
	list1.printList();
	list1.printListBackward();
	
	DLList<string> listString;
	listString.insertLast("hola");
	listString.insertLast("mundo");	
	listString.insertLast("cruel");	
	listString.insertBegin("Hellow");
	cout<<"listString with size: "<<listString.size()<<endl;
	 
	listString.printList();
	listString.printListBackward();
	
	listString.printList();
	
	listString.removeBegin();
	listString.printList();
	listString.removeLast();
	listString.printList();
	
	cout<<"listString with size: "<<listString.size()<<endl;
	
	DLList<string> listString1;
	listString1.insertLast("que");
	listString1.insertLast("onda");	
	listString1.insertLast("buey");	
	listString1.printList();
	DLList<string> listString2 = listString + listString1;
	listString2.printList();
	
	
	
	return 0;
}
