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
			left = right = NULL;
		}
		
		T data;
		node *right;
		node *left;
};

template<typename T>
class BinaryTree
{
	node<T> *root;
	void insertNode(node<T> *nodeRoot, node<T> *nodeNew);
	void inorder(node<T> *pNode);
	void preorder(node<T> *pNode);
	void postorder(node<T> *pNode);
	
	public:
		BinaryTree()
		{
			root = NULL;
		}
		void insert(T data);	
		void runInorder();
		void runPreorder();
		void runPostorder();
};

template<typename T>
void BinaryTree<T>::insertNode(node<T> *nodeRoot, node<T> *nodeNew)
{
	if(nodeRoot->data>nodeNew->data)
	{
		if(nodeRoot->left)
		{
			insertNode(nodeRoot->left, nodeNew);
		}
		else
		{
			nodeRoot->left = nodeNew;
		}
	}
	else
	{
		if(nodeRoot->right)
		{
			insertNode(nodeRoot->right, nodeNew);
		}
		else
		{
			nodeRoot->right = nodeNew;
		}
	}
}
template<typename T>
void BinaryTree<T>::insert(T data)
{
	node<T> *p = root;
	node<T> *n = new node<T>(data);
	if (p==NULL)
	{
		root = n;
	}
	else
	{
		insertNode(p, n);
	}
	
}

template<typename T>
void BinaryTree<T>::inorder(node<T> *pNode)
{
	if (pNode!=NULL)
	{
		inorder(pNode->left);
		cout<<pNode->data<<",";
		inorder(pNode->right);
	}

}

template<typename T>
void BinaryTree<T>::runInorder()
{
	node<T> *p = root;
	cout<<"Inorder: ";
	if (p==NULL)
	{
		cout<<"Tree empty";
	}
	else
	{
		inorder(p);
	}
	cout<<endl;
}

template<typename T> 
void BinaryTree<T>::preorder(node<T> *pNode)
{
	if (pNode)
	{
		cout<<pNode->data<<",";
		preorder(pNode->left);
		preorder(pNode->right);
	}
}
template<typename T> 
void BinaryTree<T>::runPreorder()
{
	cout<<"Preorder: ";
	if(root==NULL)
	{
		cout<<"Tree empty";
	}
	else
	{
		preorder(root);
	}
	cout<<endl;
}

template<typename T> 
void BinaryTree<T>::postorder(node<T> *pNode)
{
	if (pNode)
	{
		postorder(pNode->left);
		postorder(pNode->right);
		cout<<pNode->data<<",";
	}
}
template<typename T> 
void BinaryTree<T>::runPostorder()
{
	cout<<"Postorder: ";
	if(root==NULL)
	{
		cout<<"Tree empty";
	}
	else
	{
		postorder(root);
	}
	cout<<endl;
}

int main(int argc, char** argv) {
	
	BinaryTree<int> binaryT;
	binaryT.insert(20);
	binaryT.insert(8);
	binaryT.insert(10);
	binaryT.insert(9);
	binaryT.insert(7);
	binaryT.insert(40);
	binaryT.insert(25);
	
	binaryT.runInorder();
	binaryT.runPreorder();
	binaryT.runPostorder();	
	
	
	return 0;
}
