#ifndef ASTACK_H
#define ASTACK_H 
/**   @file AStack.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 10.14.14
      @version 0.01   
      
      This AStack class implements a templated stack class using a vector.
      
      Various class members need to be implemented.
      
**/
#include <stdexcept>
#include <vector>

using namespace std;

template <class T> class AStack{

public:
  AStack(){
    my_size = 0;
  };
  
  ~AStack(){}
  
  void push(T value){
    sVec.push_back(value);
    my_size++;
  }
  
  T peek(){
    if(my_size == 0){
      throw logic_error("The stack is empty - cannot peek.");
    }
    else{
      return sVec[my_size-1];
    }
  }
  
  void pop(){
    if(my_size == 0){
      throw logic_error( "The stack is empty - nothing to pop." );
    }
    else{
      sVec.pop_back();
      my_size--;
    }
  }
  
  unsigned int size() const{
    return my_size;
  }
  
  bool empty() const{
    if(my_size == 0){
      return true;
    }
    else{
      return false;
    }
  }
  
private:
  vector<T> sVec;
  unsigned int my_size;

};

#endif
