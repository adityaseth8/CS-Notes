/*
 - used to manipulate containers: (find, search, copy, sort, remove)
 - algo's defined separately from containers
   - interacted with container only through iter
   - algo can copy elements, but not directly add/rm/resize
*/
#include <algorithm>

1. Find (element)
    find (first, last, value)
    returns iterator pointing to first instance
    //   if ( (iter = find(l.begin(),l.end(),14)) != l.end() )
    // cout << 14 << " was found" << endl;

2. for_each
    calls function for each element in a range
    for_each(l.begin(),l.end(),funct);  // funct is function pointer (store address of funct)
    void funct (int i) { .. }

predicates : T/F statement abt elemment properties
    used by algorithms to select elements from container 
    define predicate -> define bool f

bool gt_10 (int i) {return i>10;}
  // find first element greater than 10
  iter = find_if(l.begin(), l.end(), gt_10);
  cout << " the first element larger than 10 is " << *iter << endl;

// function object - clas/struct containing function. Passed as parameter
    // to algo's

// function object for predicate "greater than 10"
struct Gt_10
{ //   i think dis overloading function call
  bool operator() (int i) { return i > 10; }
};
  // find first element greater than 10
  it = find_if(l.begin(), l.end(), Gt_10() );
  cout << " the first element larger than 10 is " << *it << endl;

3. Sort Algo 
    sort(first,last)
    sort(first,last,binary_predicate) -> predef or user-defined
        bool function | true if arg1 < arg2
    predef binary predicate ex: less<int> , greater<double>
          sort(v.begin(), v.end(), less<int>());
          sort(v.begin(), v.end(), greater<int>());
    predicate must define strict weak ordering
        basically less than rules. a < b and b < c, a < c
        '<' defines S.W.O if has following properties:
            1. Antisymmetry: if x<y true then y<x is false
            2. Transitivity: if x<y and y<z then x<z
            3. Irreflexive: x<x is false
            4. Transitivity of Equivalence: x & y == if x<y and y<x both F
            ("<=" doesnt define a S.W.O)

    if user defined binary predicate is j bool function:
        // smaller compares absolute values only
        bool smaller(int i, int j) {
        return i*i < j*j; }
        --->   sort(v.begin(), v.end(), smaller);
    if user def binary predicate is class:
        // smaller compares absolute values
        class smaller {
        public:
        bool operator()(int i, int j) {
            return i*i < j*j;
        } };
        ---> sort(v.begin(), v.end(), smaller());

3a. Stable-Sort Algo 
    default sort by norm: (random order if 2 are equiv)
    // sort(pts.begin(), pts.end());
        (0,1)
        (1,0)
        (-1,0)
        (0,-1)
    pt a, sort by xless, sort(pts.begin(), pts.end(), xless);
    then:
    pt b, stable_sort by norm (in each group with same norm,
        x-values ordered in increasing order)
            //     stable_sort(pts.begin(), pts.end());
            //     where:
            //     int norm2(void) const { return x*x + y*y; }
            // bool operator<(const Point& p) const
            // { return norm2() < p.norm2(); }
        (-1,0)
        (0,1)
        (0,-1)
        (1,0)

4. Search Algorithm: find sequence in a container
    search(first1, last1, first2, last2)
        find 1st occur of [first2,last2) in [first1, last1)
        f1, l1 is like list1 (longer), f2 l2 like list2 (subseq)
            returns last1 if no occur found (rem: past l1)
            returns first2 is found occur
     list<int>::iterator first2 = l2.begin();
    list<int>::iterator last2 = l2.end();

    it = search(l1.begin(),l1.end(),first2,last2);
    if ( it != l1.end() ) {
        cout << "sequence l2 found" << endl;}
    
5. Random Stuff 
    max(val1,val2) -> returns largest of 2
    min(val1,val2)
    max_element(first,last) -> returns iter pointing to 1st instance of largest elment
        list<int>::iterator imax;
        imax = max_elements(l.begin(),l.end());
            *imax -> is largest value 
    min_element(first,last)

    fill(first,last,value); -> fill a container with same value
    fill (myvector.begin(),myvector.begin()+4,5);   
        // myvector: 5 5 5 5 0 0 0 0
        // remember: [first, last)
   
    partition algorithm: reorders elements to beg of container if predicate satisfied
        1 2 3 5 7 11 13 17
        partition(l.begin(), l.end(), gt_10);
            -> 17 13 11 5 7 3 2 1
    stable partition: preserves original relative order in l when reordering
        stable_partition(l.begin(),l.end(),gt_10);
            -> 11 13 17 1 2 3 5 7
    
5. Copy algorithm
    copy(first,last,dest) -> returns iter pointing one past end of dest range
        ranges specified by iters
        copy to diff container: copy(a_first,a_last,b_dest) 
        or same container: copy(a_first,a_last,a_dest)

    use copy_backwards is i/o ranges overlap in same container
      ex scenario: 
        -----------------------------
            ^       ^       ^
            |       |       |
        a_first   a_dest   a_last 
            ------->  -------->

6. Remove Algorithm
    remove (first, last, value);
    reorders elements in container. Stuff to keep is at beg
    does NOT resize container.
    Use only for sequential containers, not associative ones
    TIP: follow up remove with erase()
    ex:
        v: 1 2 3 4 1 2 3 4 1 2 3 4
    iter = remove (v.begin(), v.end(), 3);
        v: 1 2 4 1 2 4 1 2 4 2 3 4  // note: 3 rm'd, last 3 elements unchanged from orig v
        iter points to first irrelevant element 
    for ( vector<int>::iterator i = v.begin(); i != iter; i++ ) cout << *i;
        -> 1 2 4 1 2 4 1 2 4
    v.erase(iter,v.end());  --> to erase 2,3,4 (index 9-11)

    Set Operations;
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
