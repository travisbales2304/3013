Name: Travis Bales
Date: 1/25/2018
Assignment: Program1
Description: a program that creates a linked list and has added insert sort functionality

Code:

#include <iostream>
#include <ctime>

using namespace std;

//Create a container for our list data
struct node{
  int data;
  node* next;
};

/**
* Class: intLinkedList
* Purpose:
*     Implements a singly linked list that holds integers. 
* Methods:
*     void  frontSert(int x)
*     node* find(int key)
*     node* remove(int key)
*     void  print()
*/
class intLinkedList{
  private:
  node* Head;
  public:
  intLinkedList(){
    Head = NULL;
  }
  void frontSert(int x){
    //empty list case
    if(!Head){
      Head = new node;
      Head->data = x;
      Head->next = NULL;
    }else{//not empty list
      node* T = new node;
      T->data = x;
      T->next = Head;
      Head = T;
    }
  }
  
  node* Find(int key){
    node* temp = Head;
    while(temp){
      if(temp->data == key){
        return temp;
      }
      temp = temp->next;
    }
    return NULL;
  }
  
  void Remove(int key){
    node* result = Find(key);
    if(result){
      node* temp = Head;
      while(temp->next != result){
        temp = temp->next;
      }
      temp->next = result->next;
      delete result;
    }
  }
  
  void orderedsert(int key)
  {
    bool runagain = 1;
    bool inserted = 0;
    int holder = 0;
    node* prev = Head;
    node* temp = Head;
    node* middle = Head;
    node* forward = Head;
    
    while (forward->next != NULL && runagain == 1)
    {
      forward = forward->next;
      //cout << endl << middle->data << " " << forward->data << endl;
      while(forward->next != NULL)
      {
       // cout << endl << middle->data << " " << forward->data << endl;
      if(middle->data > forward->data)
      {
        runagain = 1;
        holder = forward->data;
        forward->data = middle->data;
        middle->data = holder;
      }
      forward = forward->next;
      }
      middle = middle->next;
      forward = middle;
    }
      forward = Head;
      middle = Head;
      temp = Head;
      
    while(inserted == 0)
    {
      int counter = 0;
      if(counter != 0)
      {
        prev = prev->next;
      }
      if(temp->data == key || temp->data >= key)
      {
        if(temp == Head)
        {
          node* n = new node;
          n->data = key;
          n->next = temp;
          Head = n;
          inserted = 1;
        }
        
        else
        {
        node* n = new node;
        n->data = key;
        prev->next = n;
        n->next = temp;
        inserted = 1;
        }
        
        
      }
      temp = temp->next;
      counter++;
    }
  }
  
  void print(){
    node* p = Head;
    while(p){
      cout<<p->data<<endl;
      p = p->next;
    }
  }
};

int main() {
  // seed random number generator
  srand(8734587);
  
  // ummmm
  cout << "Hello World!\n";
  
  // declare instance of intLinkedList turning
  // a class definition into an "object"
  intLinkedList mylist;
  
  //Load 10 random ints into our list
  for(int i=0;i<10;i++){
    mylist.frontSert(rand()%100);
  }
  
  //print the list
  mylist.print();
  //mylist.orderedsort(3);
  
  //find some value
  cout<<mylist.Find(99)<<endl;
  
  //remove some value 
  mylist.Remove(58);
  
  //print the list again
  cout << endl;
  mylist.print();
  cout << endl << endl;
  mylist.orderedsert(15);
  mylist.print();

  system("pause");
}
