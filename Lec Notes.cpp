lambda expression: express predicate w/o defning additional bool f or funct object
A lambda expression constructs a closure: an 
unnamed function object capable of capturing 
variables in scope

sort(v.begin(),v.end(),
      [](const Person& p1, const Person& p2)
      { return p1.first_name < p2.first_name; } );

sort(v.begin(), v.end(), [](int& a,int& b){return a*a < b*b;} );

[] part of the lambda expression 
specifies how variables are captured
 capture specify how local vars accessible from within lambda

 []: no variables captured
•[=]: all local variables captured by value
•[&]: all local variables captured by reference
•[x]: local variable x captured by value
•[&x]: local variable x captured by reference

ex:
int threshold = 10;
  auto iter = stable_partition(v.begin(),v.end(),
              [threshold](int& i) { return i > threshold; } );

---
c++ streams are type-safe unlike printf

typesafe can be overriden

cin.good(): ok
cin.eof():  found end of file
cin.fail(): error has occurred in I/O
cin.bad():  unrecoverable error in I/O

// choose fixed point representation
  cout.setf(ios_base::fixed,ios_base::floatfield);
    --> fixed (decimal) or scientific notation
    --> floatfield set to fixed 
// cout.precision() affects all following operations
  cout.precision(5);

  // cout.width() only affects the next operation. Must be repeated.
  cout.width(12);
  cout << a << endl;

  cout.width(12);
  cout << b << endl;
  cout.setf(ios_base::right, ios_base::adjustfield);  <-- default

#include <iomanip> //manipulators 
 cout << setprecision(5) << setw(12) << fixed << a << endl;
persistent manipulators: setprecision, fixed, adjustfield
manipulators to be repeated: setw 

use #include <cstdio> to use C-style I/O functions
    printf included in <iostream> 

-------------------

#include<fstream>
ifstream myfile("not_there.conf");
  int i;
  myfile >> i;  // i = 0 if file not present 
// or

ifstream myfile("not_there.conf");
  if (!myfile) {
    cout << "error opening file" << endl;
    return 1; }

//  create new file, write to it
 ofstream myfile("myofstream.txt");
  myfile << " hello " << endl;
  myfile.close();

--------------------------------

Ostream iterators are output iterators that write
    sequentially to an output stream (such as cout)
    #include<iterator>

      for ( int i = 0; i < 5; i++ )
    v.push_back(i);

  ostream_iterator<int> iter(cout);
  copy(v.begin(), v.end(), iter); // this is printing the shit

  ostream_iterator<string> os_iter (cout, "\n");
  copy(s,s+6,os_iter)

  ---

    basic_ostream& put(char c)
    basic_ostream& write(const char *p, size_t n)
  char a[] = { 'a', 'b', 'c', 'd' }; 
  cout.put(a[0]); 
  cout.put(a[1]); 
  cout.put(a[2]); 

  cout.write(a,4); (index: 0-3)

unformatted binary data is most compact representation of
    numeric data
unformatted read/write is the fastest form of I/O

read(): read bytes, unformatted
istream& read(char *p, size_t n)

// write 4 unformatted integers
int buf[4];
char *p = reinterpret_cast<char*>(&buf[0]);
cin.read(p,4*sizeof(int));

--
 shape of binary tree depends on order of elements added

}