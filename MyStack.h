#ifndef MYSTACK_H
#define MYSTACK_H 
/**   @file MyStack.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu
      @date 10.17.14
      @version 0.01   
      
      This MyStack class implements a templated stack
      
      Various class members need to be implemented.
      
**/
#include <stdexcept>

using namespace std;



template <class T> class MyStack{

template <class G> class Node{
  public:
  G value;
  Node* next;
  Node(T val, Node* n = NULL): value(val), next(n){};
};

public:
  MyStack(){
    head = NULL; 
    tail = NULL;
    my_size = 0;
  };
  
  ~MyStack(){
    while(my_size>0){
      pop();
    }
  }
  
  void push(T value){
    if(head == NULL){
      head = new Node<T>(value);
      tail = head;
      my_size++;
    }
    else{
      Node<T> *temp = new Node<T>(value);
      temp->next = head;
      head = temp;
      my_size++;      
    }
  }
  
  T peek(){
    if(my_size == 0){
      throw logic_error("The stack is empty - cannot peek.");
    }
    else{
      return head->value;
    }
  }
  
  void pop(){
    if(my_size == 0){
      throw logic_error( "The stack is empty - nothing to pop." );
    }
    else if(tail != NULL){
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      temp = NULL;
      my_size--;
    }
  }
  
  unsigned int size() const{
    return my_size;
  }
  
  bool empty() const{
    if(head == NULL){
      return true;
    }
    else{
      return false;
    }
  }

private:
  unsigned int my_size;
  Node<T> *head;
  Node<T> *tail;

};

#endif
