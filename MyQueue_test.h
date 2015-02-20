/*
  MyQueue_test.h
  Unit tests for HW07, MyQueue.
  
*/

#include "MyQueue.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class MyQueueTest : public CxxTest::TestSuite {
public:

  void testSize1() {
    MyQueue<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testSize2() {
    MyQueue<int> a;
    a.enqueue(5);
    a.enqueue(7);
    a.enqueue(3);
    a.enqueue(4);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testSize3() {
    MyQueue<char> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testEnqueuePeek1() {
    MyQueue<int> a;
    a.enqueue(5);
    TS_ASSERT_EQUALS(a.peek(), 5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testEnqueuePeek2() {
    MyQueue<int> a;
    a.enqueue(5);
    a.enqueue(7);
    TS_ASSERT_EQUALS(a.peek(), 5);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testEnqueuePeek3() {
    MyQueue<char> a;
    a.enqueue('m');
    a.enqueue('h');
    TS_ASSERT_EQUALS(a.peek(), 'm');
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testEnqueuePeek4() {
    MyQueue<float> a;
    a.enqueue(1);
    a.enqueue(2);
    TS_ASSERT_EQUALS(a.peek(), 1);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testEnqueuePeek5() {
    MyQueue<string> a;
    a.enqueue("m");
    a.enqueue("h");
    TS_ASSERT_EQUALS(a.peek(), "m");
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testDequeue1() {
    MyQueue<int> a;
    a.enqueue(5);
    a.enqueue(7);
    a.enqueue(3);
    a.enqueue(4);
    a.dequeue();
    a.dequeue();
    TS_ASSERT_EQUALS(a.peek(), 3);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testDequeue2() {
    MyQueue<int> a;
    a.enqueue(5);
    a.dequeue();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testEmpty1() {
    MyQueue<int> a;
    TS_ASSERT_EQUALS(a.empty(), true);
  }
  
  void testEmpty2() {
    MyQueue<int> a;
    a.enqueue(5);
    TS_ASSERT_EQUALS(a.empty(), false);
  }
  
  void testEmpty3() {
    MyQueue<int> a;
    a.enqueue(5);
    a.enqueue(5);
    a.dequeue();
    a.dequeue();
    TS_ASSERT_EQUALS(a.empty(), true);
  }
  
  void testBadPeek(){
		MyQueue<int> a;
		try{
			a.peek();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }
  
  void testBadDequeue(){
		MyQueue<int> a;
		try{
			a.dequeue();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }


};
