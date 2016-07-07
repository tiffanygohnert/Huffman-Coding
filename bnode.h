#ifndef  NODE_H
#define NODE_H
#include <cassert>
#include <iostream>

using namespace std;

//node class
template <class T>
class BinaryNode
{

public:
	//default constructor
	BinaryNode() : pRight(NULL), pLeft(NULL), pParent(NULL), data(0x00000000)/*, numItems(1)*/ {}

	//non-default constructor 
	BinaryNode(const T & t) : pRight(NULL), pLeft(NULL), pParent(NULL), data(t)/*, numItems(1)*/ {} /*throw (const char *)*/

	void addLeft(const T & t)
	{
		BinaryNode <T> * tempBNode = new BinaryNode <T>(t);
		this->pLeft = tempBNode;
		tempBNode->pParent = this;
		//numItems++;
	}

	void addLeft(BinaryNode <T> * bNode)
	{
		if (!bNode)
		{
			this->pLeft = NULL;
			return;
		}
		this->pLeft = bNode;
		bNode->pParent = this;
		//numItems++;
	}

	void addRight(const T & t)
	{
		BinaryNode <T> * tempBNode = new BinaryNode <T>(t);
		this->pRight = tempBNode;
		tempBNode->pParent = this;
		//numItems++;
	}

	void addRight(BinaryNode <T> * bNode)
	{
		if (!bNode)
		{
			this->pRight = NULL;
			return;
		}
		this->pRight = bNode;
		bNode->pParent = this;
		//numItems++;
	}

	int size() const
	{ 
		if (this == NULL)
			return 0;
		else
		{
			int count = 1;
			count += this->pLeft->size();
			count += this->pRight->size();
			return count;
		}
	}
  
	/*int countNodes(BinaryNode <T> * bNode)
	{
		unsigned count = 0;
		if (bNode->pLeft)
		{
			countNodes(bNode->pLeft);
			if (bNode->pRight)
				countNodes(bNode->pRight);
			count++;
		}
	}*/

  // member variables 
  BinaryNode <T> * pRight;
  BinaryNode <T> * pLeft;
  BinaryNode <T> * pParent;
  T data;
  //int numItems;
};

/*
deleteBinaryTree(): Takes a BinaryNode as a parameter and 
deletes all the children and itself. This is a recursive 
function.
*/
template <class T>
void deleteBinaryTree(BinaryNode <T> * &bNode)
{
	if (bNode->pLeft)
	{
		deleteBinaryTree(bNode->pLeft);
		if (bNode->pRight)
			deleteBinaryTree(bNode->pRight);
		delete bNode;
		bNode = NULL;
	}
}

/*
Insertion operator: Takes a constant BinaryNode * as a 
parameter and displays the tree under the passed parameter. 
This is a recursive function traversing the tree in infix 
order. A single space will be displayed after every element.
*/

template <class T>
ostream & operator << (ostream & out, BinaryNode <T> * rhs)
{
	// prints R, L, R, LL, LR, RL, RR... incorrect
	/*if (rhs != NULL)
	{
		out << rhs->data << " ";
		out << (rhs->pLeft);
		out << (rhs->pRight);
	}
	return out;*/
	
	// Postorder
	//if (rhs != NULL)
	//{
	//	out << (rhs->pLeft);
	//	//out << rhs->data << " ";
	//	out << (rhs->pRight);
	//	out << rhs->data << " ";
	//}
	//return out;

	// Inorder!! YAY!
	if (rhs != NULL)
	{
		out << (rhs->pLeft);
		out << rhs->data << " ";
		out << (rhs->pRight);
		//out << rhs->data << " ";
	}
	return out;
}

#endif
