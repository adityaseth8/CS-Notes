#include <iostream>
#include <vector>
using namespace std;

// declare int vector of size 10
vector<int> v(10);

// 2 ways to print contents of vector
    // Method 1: Iterator (type of ptr)
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter << endl;
    }
    // Method 2: regular 
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;  // if empty, prints 0
    }

// remove last element in vector
v.pop_back();

// insert elements in vector
iter = v.begin()+5;  
v.insert(iter, 7);  // insert 7 at pos v.begin() + 5

// insert function for range
int ar[] = {1,2,3,4,5,6};
iter = v.end();

// insert before *iter1, the elements from range iter2 to iter3
// range inclusive of endpoints
//v.insert(iter1, iter2, iter3);

v.insert(iter, ar, ar+5);  // ar[0], ar[6] doesnt work?
 
// add element to end of vector, auto++ vector size
v.push_back(9);

// resize vector to size 5 (elements 0 - 4 kept)
v.resize(5);

// erase element 3 in vector
// 10 11 12 13 14 15
// 0  1  2  3  4  5
iter = v.begin() + 3;
v.erase(iter);  // 13 erased
// *iter still at pos 3, val tho now is 14 

// iterators may be invalidated by an erase iteration
    // ex if erase element at end, iter points beyond vector
    // undefined behavior

// erase elements 5 to 7 included
vector<int>::iterator iter1 = v.begin() + 5;
vector<int>::iterator iter2 = v.begin() + 8;
v.erase(iter1,iter2);

// Conceptual Vector Info
    // Only add info from back (push_back)
    // no push_front allowed b/c O(n) complexity 
    // Random Access allowed 
    // Memory stored contigiously 



contiguous