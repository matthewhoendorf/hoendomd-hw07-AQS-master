#ifndef AQUEUE_H
#define AQUEUE_H 
/**   @file AQueue.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 10.14.14
      @version 0.01   
      
      This AQueue class implements a templated queue class using a vector.
      
      Various class members need to be implemented.
      
**/
#include <stdexcept>
#include <vector>

using namespace std;

template <class T> class AQueue{

public:
  AQueue(){
    my_size = 0;
  };
  
  ~AQueue(){}
  
  void enqueue(T value){
    qVec.push_back(value);
    my_size++;
  }
  
  T peek(){
    if(my_size == 0){
      throw logic_error("The queue is empty - cannot peek.");
    }
    else{
      return qVec[0];
    }
  }
  
  void dequeue(){
    if(my_size == 0){
      throw logic_error( "The queue is empty - nothing to dequeue." );
    }
    else{
      qVec.erase(qVec.begin());
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
  vector<T> qVec;
  unsigned int my_size;

};

#endif
