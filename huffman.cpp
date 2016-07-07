/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    <your letter>
 *    
 * Summary: This program will implement the huffman() function
 ************************************************************************/

#include "huffman.h"       // for HUFFMAN() prototype

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cassert>
 
using namespace std;



template<class T> 
class Q {
   int array_size, heap_size;
   T** A; // pointer for the array

public:
   Q(int s);
   ~Q();
   
   T* extractMin();
   bool insert(T*);

private:
   int left(int i);
   int right(int i);
   int parent(int i);
   void decreaseKey(int, T*);
   
};

template<class T> 
Q<T>::Q(int s) {
   array_size = s;
   heap_size = -1;
   A = new T*[s];
}

template<class T> 
Q<T>::~Q() {
   delete A;
}


template<class T> 
int Q<T>::left(int i) {
   return 2 * (i + 1) - 1;
}

template<class T> 
int Q<T>::right(int i) {
   return 2 * (i + 1);
}

template<class T> 
int Q<T>::parent(int i) {
   return max((i + 1) / 2 - 1, 0);
}

template<class T> 
T* Q<T>::extractMin() {
 
      T* min = A[0];
      A[0] = A[heap_size];
      heap_size--;
    //  minHeapify(0);
      return min;
   
}


template<class T> 
bool Q<T>::insert(T* key) {
   
      heap_size++;
      decreaseKey(heap_size, key);
      return true;
   }

template<class T> 
void Q<T>::decreaseKey(int i, T* key) {
   A[i] = key;
   while ((i > 0) && ((*(A[parent(i)])) > (*(A[i])))) {
      T* t = A[i];
      A[i] = A[parent(i)];
      A[parent(i)] = t;
      i = parent(i);
   }
}



class Node {
public:
   string name;
   int f;
   Node *left, *right;
   string code;

   Node() {
      name = "";
      code = "";
      f = 100;
      left = right = 0;
   }

   Node(int ff, string n = "") {
      name = n;
      f = ff;
      left = right = 0;
      code = "";
   }

   ~Node() {
      delete left;
      delete right;
   }

   bool operator<(Node &param) {
      return f < param.f;
   }

   bool operator>(Node &param) {
      return f > param.f;
   }

   bool operator==(Node &param) {
      return f == param.f;
   }

   static void display(Node*, bool);
   static void encode(Node*);

   friend ostream& operator <<(ostream&, Node&);
};

void Node::display(Node* node, bool leavesOnly = 1) {
   if (node == 0) {
      return;
   }
   display(node->left, leavesOnly);
   if (leavesOnly) {
      if (node->left == 0 && node->right == 0) {
         cout << *node << endl /*", "*/;
      }
   } else {
      cout << *node << ", ";
   }
   display(node->right, leavesOnly);
}

void Node::encode(Node* node) {
   if (node == 0) {
      return;
   }
   if (node->left != 0) {
      node->left->code = node->code + "0";
   }
   if (node->right != 0) {
      node->right->code = node->code + "1";
   }
   encode(node->left);
   encode(node->right);
}

ostream& operator <<(ostream &out, Node &node) {
   out << node.name   << " = " << node.code;
   return out;
}

void HuffmanCode(float *freqs, string* names, int length) {
   Q<Node> *q = new Q<Node > (length);
   for (int i = 0; i < length; i++) {
      q->insert(new Node(freqs[i], names[i]));
   }

   for (int i = 0; i < length - 1; i++) {
      Node *x = q->extractMin();
      Node *y = q->extractMin();
      Node *z = new Node(x->f + y->f, x->name + y->name);
      z->left = x;
      z->right = y;
      q->insert(z);
   }
   Node *root = q->extractMin();
  
   //cout << "\nHuffman Code:\n";
   Node::encode(root);
   Node::display(root);
}
 

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const std::string& input)
{

string line;

  string str[100];
size_t size = 0;
float frequency[100];
size_t sizef = 0;
int count = 0;
	

   ifstream filein (input.c_str());//file to open
   
   
    
   //open file and get frequency
   if (filein.is_open())
   {
      while ( getline (filein,line) )
      {
		  count++;
         string letter;
         float quency;
         stringstream ss;
         ss.str(line);
         ss >> letter >> quency;
        //cout << frequency << endl;
		// Add characters:
str[size++] = letter;
frequency[sizef++] = quency;
		 
		 //insert frequency into an array using vector class? 
		 
		  
	
		 
		 
      }
      filein.close();
   }

    HuffmanCode(frequency, str, count);
  
}
