/*
  MyStack_test.h
  Unit tests for HW07, MyStack.
  
*/

#include "MyStack.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class MyStackTest : public CxxTest::TestSuite {
public:

  void testSize1() {
    MyStack<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testSize2() {
    MyStack<int> a;
    a.push(5);
    a.push(7);
    a.push(3);
    a.push(4);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testSize3() {
    MyStack<char> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testpushPeek1() {
    MyStack<int> a;
    a.push(5);
    TS_ASSERT_EQUALS(a.peek(), 5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testpushPeek2() {
    MyStack<int> a;
    a.push(5);
    a.push(7);
    TS_ASSERT_EQUALS(a.peek(), 7);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpushPeek3() {
    MyStack<char> a;
    a.push('m');
    a.push('h');
    TS_ASSERT_EQUALS(a.peek(), 'h');
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpushPeek4() {
    MyStack<float> a;
    a.push(1);
    a.push(2);
    TS_ASSERT_EQUALS(a.peek(), 2);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpushPeek5() {
    MyStack<string> a;
    a.push("m");
    a.push("h");
    TS_ASSERT_EQUALS(a.peek(), "h");
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testpop1() {
    MyStack<int> a;
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
    MyStack<int> a;
    a.push(5);
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testEmpty1() {
    MyStack<int> a;
    TS_ASSERT_EQUALS(a.empty(), true);
  }
  
  void testEmpty2() {
    MyStack<int> a;
    a.push(5);
    TS_ASSERT_EQUALS(a.empty(), false);
  }
  
  void testEmpty3() {
    MyStack<int> a;
    a.push(5);
    a.push(5);
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS(a.empty(), true);
  }
  
  void testBadPeek(){
		MyStack<int> a;
		try{
			a.peek();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }
  
  void testBadpop(){
		MyStack<int> a;
		try{
			a.pop();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }

};
