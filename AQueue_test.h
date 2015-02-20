/*
  AQueue_test.h
  Unit tests for HW07, AQueue.
  
*/

#include "AQueue.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class AQueueTest : public CxxTest::TestSuite {
public:

  void testSize1() {
    AQueue<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testSize2() {
    AQueue<int> a;
    a.enqueue(5);
    a.enqueue(7);
    a.enqueue(3);
    a.enqueue(4);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testSize3() {
    AQueue<char> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testEnqueuePeek1() {
    AQueue<int> a;
    a.enqueue(5);
    TS_ASSERT_EQUALS(a.peek(), 5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testEnqueuePeek2() {
    AQueue<int> a;
    a.enqueue(5);
    a.enqueue(7);
    TS_ASSERT_EQUALS(a.peek(), 5);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testEnqueuePeek3() {
    AQueue<char> a;
    a.enqueue('m');
    a.enqueue('h');
    TS_ASSERT_EQUALS(a.peek(), 'm');
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testEnqueuePeek4() {
    AQueue<float> a;
    a.enqueue(1);
    a.enqueue(2);
    TS_ASSERT_EQUALS(a.peek(), 1);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testEnqueuePeek5() {
    AQueue<string> a;
    a.enqueue("m");
    a.enqueue("h");
    TS_ASSERT_EQUALS(a.peek(), "m");
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testDequeue1() {
    AQueue<int> a;
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
    AQueue<int> a;
    a.enqueue(5);
    a.dequeue();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testEmpty1() {
    AQueue<int> a;
    TS_ASSERT_EQUALS(a.empty(), true);
  }
  
  void testEmpty2() {
    AQueue<int> a;
    a.enqueue(5);
    TS_ASSERT_EQUALS(a.empty(), false);
  }
  
  void testEmpty3() {
    AQueue<int> a;
    a.enqueue(5);
    a.enqueue(5);
    a.dequeue();
    a.dequeue();
    TS_ASSERT_EQUALS(a.empty(), true);
  }
  
  void testBadPeek(){
		AQueue<int> a;
		try{
			a.peek();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }
  
  void testBadDequeue(){
		AQueue<int> a;
		try{
			a.dequeue();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }

  
 
};
