/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <string>      // for STRING

void huffman(const std::string& input);


#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

//stack class
template <class T>
class Stack
{

  public:

   //default constructor
  Stack():  Size(0),Capacity(0), vector(0x00000000){}

   //destructor
   ~Stack(){};
   // { if (Size) delete [] vector; }

   //non-default constructor Needed for test 1
   Stack(int capacity) throw (const char *);

   //copy constructor
   Stack(const Stack& rhs)throw (const char *);


   //operator=
   // assignment operator
   Stack & operator = (const Stack & rhs)throw (const char *)
   {
           try
           {  Stack temp = rhs;
              Capacity = temp.Capacity;
              vector = temp.vector;
              Size = temp.Size;
              return *this;
           }
           catch (std::bad_alloc)
           {
              throw "ERROR: Unable to allocate a new buffer for Stack";
           }

   }

   //empty()
   bool empty()const {return Size ==0;  }
   //clear()
   void clear(){Size =0; }

   //size()
   int size()const{return Size; }
   //capacity()
   int capacity()const {   return Capacity;}
   
   int clear() const {Size =0; return Size; }; 

   //push_back
   void push(const T & t) throw (const char *);
   void pop() throw (const char *);
   T top() throw (const char *); 
   

   // return an iterator to the beginning of the list
   //StackIterator <T> begin() { return StackIterator<T>(vector); }

   // return an iterator to the end of the list
   // StackIterator <T> end() { return StackIterator<T>(vector + Size);};



   // operators[]
   T & operator [](int& index) const throw(const char *)
   {
      if (Capacity < 0 || Capacity < Size)
         throw "ERROR: Invalid index\n";
      return vector[index];
   }

   T & operator [](int& index) throw(const char *)
   {
      if (Capacity < 0 || Capacity < Size)
         throw "ERROR: Invalid index\n";
      return vector[index];
   }




  private:

   int Size;
   T * vector;
   int Capacity;
  


};

/**********************************************
 * Stack : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Stack to "capacity"
 **********************************************/
template <class T>
Stack <T> :: Stack(int capacity) throw (const char *)
{
   assert(capacity >= 0);

   // do nothing if there is nothing to do
   if (capacity == 0)
   {
      this->Capacity = this->Size = 0;
      this->vector = 0x00000000;
      return;
   }

   // attempt to allocate
            try
            {
               vector = new T[capacity];

            }
            catch (std::bad_alloc)
            {
               //problem for test 1
               throw "ERROR: Unable to allocate buffer";


            }


            // copy over the stuff
            this->Capacity = capacity;
            this->Size = 0;

}

/*******************************************
 * Stack:: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Stack <T> :: Stack(const Stack <T> & rhs) throw (const char *)
{
   assert(rhs.Capacity >= 0);

   // do nothing if there is nothing to do
   if (rhs.Capacity == 0)
   {
      Capacity = Size = 0;
      vector = 0x00000000;
      return;
   }

   // attempt to allocate
          try
          {
             vector = new T[rhs.Capacity];
          }
          catch (std::bad_alloc)
          {
             throw "ERROR: Unable to allocate buffer";
          }

          // copy over the stuff
          assert(rhs.Size >= 0 && rhs.Size <= rhs.Capacity);
          Capacity = rhs.Capacity;
          Size = rhs.Size;
          for (int i = 0; i < Size; i++)
             vector[i] = rhs.vector[i];
}

/***************************************************
 * Stack :: push
 * Insert an item on the end of the Stack
 **************************************************/
template <class T>
void Stack <T> :: push(const T & t) throw (const char *)
{
// try
//{
//if (Capacity==0 || Capacity ==Size)
//{
//if (Capacity==0)
//{
//Capacity=1;
//vector = new T[Capacity]; }
//else
//Capacity *=2;
//
//}
//}
//catch (std::bad_alloc)
//{
//throw "ERROR: Unable to allocate buffer\
//";
//}
//vector[Size++] = t;
	if (Size == 0)
	{
		delete[] vector;
		Capacity = 1;
		vector = new T[Capacity];
	}
	if (Capacity == Size)
	{
		Capacity *= 2;
		T * tempArray = new T[Capacity];
		for (int i = 0; i < Size; i++)
			tempArray[i] = vector[i];
		delete[] vector;
		vector = tempArray;
	}
	// add an item to the end
	try
	{
		vector[Size++] = t;
	}
	catch (std::bad_alloc)
	{
		throw "ERROR: Unable to allocate a new buffer for Vector";
	}
}

//pop()
/***************************************************
 * Stack :: pop
 * Removes an item from the end of the stack
 **************************************************/
template <class T>
 void Stack <T> :: pop() throw (const char *)
{
	if (empty())
		throw "ERROR: Unable to pop from an empty Stack";
	vector[Size--]; 
}


//top()
/***************************************************
 * Stack :: top
 * Returns the item currently at the end of the stack
 **************************************************/
template <class T>
T Stack <T> :: top() throw (const char *)
{
	if (empty())
		throw "ERROR: Unable to reference the element from an empty Stack";
	return vector[Size - 1];   
}

#endif // HUFFMAN_h
