/*    @file benchmark.cpp    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 10.14.14 

			@description benchmark evaluates the speed of various implementations of
			              queues and stacks and prints the results to the screen
			              via tab-delimed values.
			              
			              If no paramters are set, or -h, print usage to the screen.
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <iomanip>

#include <stack>
#include <queue>

#include "MyStack.h"
#include "MyQueue.h"
#include "AStack.h"
#include "AQueue.h"

using namespace std;

int main(int argc, char* argv[]){
  
  setw(5);
  string u="Usage: ./benchmark -m <int> -x <int> -s <int> -c [0,1] -a [0,1]\n";
  int m = 0, x = 100, s = 1, c = 0, a = 0;
  //opterr = 0;
  
  int i = 0;
  while ((i = getopt (argc, argv, "m:x:s:c:a:h")) !=-1){
    switch (i){
        case 'm':
        m = atoi(optarg);
        break;
      case 'x':
        x = atoi(optarg);
        break;
      case 's':
        s = atoi(optarg);
        break;
      case 'c':
        c = atoi(optarg);
          if(c == 0 || c == 1){
            break;
          }
          else{
            return 0;
          }
      case 'a':
        a = atoi(optarg);
          if(a == 0 || a == 1){
            break;
          }
          else{
            return 0;
          }
      case 'h':
        cout << u << endl;
        return 0;
    }
  }
  
  for(int i = m; i < x; i+=s){
    if(c == 0){ // User selects Stack
      if(a == 0){ // User selects Grow
        
        AStack<int> a;        
        clock_t starta = clock();        
        for(int j = 0; j < i; j++){
          a.push(1);
        }        
        clock_t stopa = clock();
        
        MyStack<int> b;        
        clock_t startb = clock(); 
        for(int j = 0; j < i; j++){
          b.push(1);
        }
        clock_t stopb = clock();
        
        stack<int> c;
        clock_t startc = clock();
        for(int j = 0; j < i; j++){
          c.push(1);
        }
        clock_t stopc = clock();
        
        cout << i << " ";
        cout << (float)(stopa-starta)*1000.0/(float)CLOCKS_PER_SEC << " ";
        cout << (float)(stopb-startb)*1000.0/(float)CLOCKS_PER_SEC << " ";
        cout << (float)(stopc-startc)*1000.0/(float)CLOCKS_PER_SEC << endl;
      }
      else if(a == 1){ // User selects Shrink
        
        // Load the stacks with the values
        AStack<int> a;
        MyStack<int> b;
        stack<int> c;
        for(int j = 0; j < i; j++){
          a.push(1);
        }
        for(int j = 0; j < i; j++){
          b.push(1);
        }
        for(int j = 0; j < i; j++){
          c.push(1);
        }
        
        // Time the operation
        clock_t starta = clock();
        for(int k = 0; k < i; k++){
          a.pop();
        }
        clock_t stopa = clock();
        
        clock_t startb = clock();
        for(int k = 0; k < i; k++){
          b.pop();
        }
        clock_t stopb = clock();
      
        clock_t startc = clock();
        for(int k = 0; k < 1; k++){
          c.pop();
        }
        clock_t stopc = clock();
        
        cout << i << " ";
        cout << (float)(stopa-starta)*1000.0/(float)CLOCKS_PER_SEC << " ";
        cout << (float)(stopb-startb)*1000.0/(float)CLOCKS_PER_SEC << " ";
        cout << (float)(stopc-startc)*1000.0/(float)CLOCKS_PER_SEC << endl;
      }
    }
    else if(c == 1){ // User selects Queue
      if(a == 0){ // User selects Grow
        
        AQueue<int> d;
        clock_t startd = clock();
        for(int j = 0; j < i; j++){
          d.enqueue(1);
        }
        clock_t stopd = clock();
        
        MyQueue<int> e;
        clock_t starte = clock();
        for(int j = 0; j < i; j++){
          e.enqueue(1);
        }
        clock_t stope = clock();
        
        queue<int> f;
        clock_t startf = clock();
        for(int j = 0; j < i; j++){
          f.push(1);
        }
        clock_t stopf = clock();
        
        cout << i << " ";
        cout << (float)(stopd-startd)*1000.0/(float)CLOCKS_PER_SEC << " ";
        cout << (float)(stope-starte)*1000.0/(float)CLOCKS_PER_SEC << " ";
        cout << (float)(stopf-startf)*1000.0/(float)CLOCKS_PER_SEC << endl;
      }
      else if(a == 1){ // User selects Shrink
        
        // Load the Queues with values
        AQueue<int> d;
        MyQueue<int> e;
        queue<int> f;
        for(int j = 0; j < i; j++){
          d.enqueue(1);
        }
        for(int j = 0; j < i; j++){
          e.enqueue(1);
        }
        for(int j = 0; j < i; j++){
          f.push(1);
        }
       
        // Time the operation
        clock_t startd = clock();
        for(int j = 0; j < i; j++){
          d.dequeue();
        }
        clock_t stopd = clock();
       
        clock_t starte = clock();
        for(int j = 0; j < i; j++){
          e.dequeue();
        }
        clock_t stope = clock();
       
        clock_t startf = clock();
        for(int j = 0; j < i; j++){
          f.pop();
        }
        clock_t stopf = clock();
       
        cout << i << " ";
        cout << (float)(stopd-startd)*1000.0/(float)CLOCKS_PER_SEC << " ";
        cout << (float)(stope-starte)*1000.0/(float)CLOCKS_PER_SEC << " ";
        cout << (float)(stopf-startf)*1000.0/(float)CLOCKS_PER_SEC << endl;
      }
    }   
  }
  
  return 0;
  
}
