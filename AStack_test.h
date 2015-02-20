/*
  AStack_test.h
  Unit tests for HW07, AStack.
  
*/

#include "AStack.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class AStackTest : public CxxTest::TestSuite {
public:

  void testSize1() {
    AStack<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testSize2() {
    AStack<int> a;
    a.push(5);
    a.push(7);
    a.push(3);
    a.push(4);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testSize3() {
    AStack<char> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testpushPeek1() {
    AStack<int> a;
    a.push(5);
    TS_ASSERT_EQUALS(a.peek(), 5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testpushPeek2() {
    AStack<int> a;
    a.push(5);
    a.push(7);
    TS_ASSERT_EQUALS(a.peek(), 7);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpushPeek3() {
    AStack<char> a;
    a.push('m');
    a.push('h');
    TS_ASSERT_EQUALS(a.peek(), 'h');
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpushPeek4() {
    AStack<float> a;
    a.push(1);
    a.push(2);
    TS_ASSERT_EQUALS(a.peek(), 2);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpushPeek5() {
    AStack<string> a;
    a.push("m");
    a.push("h");
    TS_ASSERT_EQUALS(a.peek(), "h");
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpop1() {
    AStack<int> a;
    a.push(5);
    a.push(7);
    a.push(3);
    a.push(4);
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS(a.peek(), 7);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpop2() {
    AStack<int> a;
    a.push(5);
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testEmpty1() {
    AStack<int> a;
    TS_ASSERT_EQUALS(a.empty(), true);
  }
  
  void testEmpty2() {
    AStack<int> a;
    a.push(5);
    TS_ASSERT_EQUALS(a.empty(), false);
  }
  
  void testEmpty3() {
    AStack<int> a;
    a.push(5);
    a.push(5);
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS(a.empty(), true);
  }
  
  void testBadPeek(){
		AStack<int> a;
		try{
			a.peek();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }
  
  void testBadpop(){
		AStack<int> a;
		try{
			a.pop();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }
 
};
