// Set : Associative Container (objects referenced by key, not value)
#include <iostream>
#include <set>
using namespace std;

//In set, the value is the key
// value has to be unique, gets auto sorted (l to h)
// vals not modified, but vals can be inserted & removed
// sets used in binary search tree

int main () {
    set<int> s;

    s.insert(54);
    s.insert(12);
    s.insert(36);

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " " << endl;
            // set -> 12, 36, 54. printed in increasing order
    }


// Multiset -> numbers can be repeated
multiset<int> s;
}

Set Operations
    set_union : return sorted range formed by elements present in either one of 
                sets or present in both ranges (remember set - no duplicates)
        set_union(first1,last1,first2,last2,result);
        
        ar1: 5, 10, 15, 20, 25
        ar2: 50, 20, 30, 40, 10   & vector v of size 10
        iter = set_union(ar1,ar1+5, ar2, ar2+5, v.begin());
            --> 5 10 15 20 25 30 40 50 0 0
                (union has 8 elements, v of size 10)
            ---< iter points to end of constructed range 
    
    set_intersection : return sorted range with elements present in both sets
        set_intersection(first1,last1,first2,last2,result);
            iter = set_union(ar1,ar1+5, ar2, ar2+5, v.begin());
                --> 10 20 0 0 0 0 0 0 0 0
            v.resize(iter-v.begin());
                --> 10 20

    set_difference : return sorted range with unique elements only found in set1
        set_difference(first1,last1,first2,last2,result);
        iter = set_difference(a1,ar+5,ar2,ar2+5,v.begin());
            --> 5 15 25 0 0 0 0 0 0 0
            iter points to first 0. 
    
    set_symmetric_difference : elements present in one set, but not other
    iter = set_symmetric_difference (first, first+5, second, second+5, v.begin());
        --> 5 15 25 30 40 50 0 0 0 0
    
