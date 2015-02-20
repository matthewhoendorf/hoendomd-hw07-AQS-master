#ifndef MYQUEUE_H
#define MYQUEUE_H 
/**   @file MyQueue.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu
      @date 10.17.14
      @version 0.01   
      
      This MyQueue class implements a templated queue
      
      Various class members need to be implemented.
      
**/
#include <stdexcept>

using namespace std;



template <class T> class MyQueue{

template <class G> class Node{
  public:
  G value;
  Node<G>* next;
  Node(G val, Node* n = NULL): value(val), next(n){};
};

public:
  MyQueue(){
    head = NULL; 
    tail = NULL;
    my_size = 0;
  };
  
  ~MyQueue(){
    while(my_size>0){
      dequeue();
    }
  }
  
  void enqueue(T value){
    if(head == NULL){
      head = new Node<T>(value);
      tail = head;
      my_size++;
    }
    else{
      tail->next = new Node<T>(value);
      tail = tail->next;
      my_size++;
    }
  }
  
  T peek(){
    if(my_size == 0){
      throw logic_error("The queue is empty - cannot peek.");
    }
    else{
      return head->value;
    }
  }
  
  void dequeue(){
    if(my_size == 0){
      throw logic_error( "The queue is empty - nothing to dequeue." );
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
