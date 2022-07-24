#include <iostream>
#include <stack>
using namespace std;

// Stack (LIFO container) - Container Adadpter: 
// puts constraints on storage and retrieval procecss
// Doestnt provide actual ds implement or iterators. 
// j contains mem functs to insert/retrieve elements
// in cpp, stack auto implemented as deque

stack<string> st;

// push() -> add 
    st.push(10);  // 
// pop() | remove top element (last element inputted),
        //  resizes down by 1
    st.pop();
// top ()
    st.top(5);  // access top element (last element inputted)

// empty()
// back(), push_back, pop_back

  while ( !st.empty() ) {
    cout << st.top() << " ";
    st.pop();
  }



