#include<bits/stdc++.h>
using namespace std;

/*
========================================================
                C++ STL QUICK SUMMARY
========================================================

STL (Standard Template Library) provides ready-made
data structures and algorithms to make programming easier.

Main Components of STL
----------------------
1. Containers   -> Store data
2. Iterators    -> Traverse containers
3. Algorithms   -> Perform operations on data
4. Functors     -> Custom comparison functions


--------------------------------------------------------
1. PAIR
--------------------------------------------------------
pair<T1,T2>
- Stores two values together.
- Access using .first and .second
Example: pair<int,int> p = {1,2}


--------------------------------------------------------
2. VECTOR
--------------------------------------------------------
vector<T>
- Dynamic array (size grows automatically)
- Elements stored in contiguous memory
- Fast random access O(1)

Common Functions
push_back()     -> insert element at end
emplace_back()  -> faster insert
begin()         -> iterator to first element
end()           -> iterator after last element
erase()         -> remove element
insert()        -> insert element
size()          -> number of elements

Example
vector<int> v = {1,2,3}


--------------------------------------------------------
3. LIST
--------------------------------------------------------
list<T>
- Doubly linked list
- Fast insertion/deletion anywhere
- No random access like vector

Functions
push_front()
push_back()
pop_front()
pop_back()


--------------------------------------------------------
4. STACK
--------------------------------------------------------
stack<T>

- LIFO (Last In First Out)
- Last inserted element comes out first

Functions
push()
pop()
top()
size()
empty()


--------------------------------------------------------
5. QUEUE
--------------------------------------------------------
queue<T>

- FIFO (First In First Out)
- First inserted element removed first

Functions
push()
pop()
front()
back()


--------------------------------------------------------
6. PRIORITY QUEUE
--------------------------------------------------------
priority_queue<T>

- Heap data structure
- Default = MAX HEAP
  (largest element comes first)

Max Heap
priority_queue<int>

Min Heap
priority_queue<int, vector<int>, greater<int>>


--------------------------------------------------------
7. SET
--------------------------------------------------------
set<T>

- Stores UNIQUE elements
- Elements are automatically SORTED
- Implemented using Balanced BST

Time Complexity
Insert  : O(log n)
Delete  : O(log n)
Search  : O(log n)


--------------------------------------------------------
8. MULTISET
--------------------------------------------------------
multiset<T>

- Same as set but allows DUPLICATES
- Elements remain SORTED


--------------------------------------------------------
9. UNORDERED SET
--------------------------------------------------------
unordered_set<T>

- Unique elements
- NOT sorted
- Implemented using HASH TABLE

Average Time Complexity
Insert/Search/Delete = O(1)


--------------------------------------------------------
10. MAP
--------------------------------------------------------
map<Key,Value>

- Stores key-value pairs
- Keys are UNIQUE
- Keys are automatically SORTED

Example
map<int,string> mp;


--------------------------------------------------------
11. UNORDERED MAP
--------------------------------------------------------
unordered_map<Key,Value>

- Key-value pairs
- Keys are UNIQUE
- NOT sorted
- Uses HASH TABLE

Average complexity O(1)


--------------------------------------------------------
IMPORTANT STL ALGORITHMS
--------------------------------------------------------
sort(v.begin(), v.end())        -> sort elements
reverse(v.begin(), v.end())     -> reverse elements
max_element()                   -> find maximum
min_element()                   -> find minimum
count()                         -> count occurrences
accumulate()                    -> sum of elements
next_permutation()              -> next lexicographic permutation
find()                          -> search element


--------------------------------------------------------
MOST USED STL IN DSA PROBLEMS
--------------------------------------------------------
1. vector
2. unordered_map
3. set / unordered_set
4. priority_queue


--------------------------------------------------------
TIP FOR INTERVIEWS
--------------------------------------------------------
vector + unordered_map + set + priority_queue
can solve almost 80% of coding interview problems.

========================================================
*/



void explainPair(){

    // pair stores two values together
    // pair<datatype1, datatype2>

    pair<int,int> pr1 = {2,8};   // stores (2,8)
    cout<<pr1.first<<" "<< pr1.second<<endl;

    pair<int,char> pr2 = {2,'b'};
    cout<<pr2.first<<" "<< pr2.second<<endl;

    // nested pair
    pair<pair<int,char>,int> pr3 = {{4,'h'},8};

    // accessing nested pair
    cout<<pr3.first.second<<endl;
}

void explainVector(){

    // vector is a dynamic array
    // size can grow automatically

    vector<int> vec;

    // push_back adds element at end
    vec.push_back(1);
    vec.push_back(2);

    // emplace_back is faster version of push_back
    vec.emplace_back(3);

    // access using index
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }

    cout<<endl;

    // iterator points to memory location of element
    vector<int>::iterator it = vec.begin();

    // begin() -> first element
    cout<<"First element "<<*it<<endl;

    // end() -> address after last element
    auto endItr = vec.end();

    // iterator traversal
    for(auto i = vec.begin(); i!=vec.end(); i++){
        cout<< *i << " ";
    }

    cout<<endl;

    // range based loop
    for(auto x : vec){
        cout<<x<<" ";
    }

    cout<<endl;

    // reverse iterator
    // rbegin -> last element
    // rend -> before first element
    for(auto i = vec.rbegin(); i!=vec.rend(); i++){
        cout<< *i << " ";
    }

    cout<<endl;

    // vector<int> vec(5)
    // creates vector of size 5 filled with 0

    vector<int> vec2(5);

    // copying vector
    vector<int> dupVec(vec);

    // erase element
    vec.erase(vec.begin()+1);

    // insert element
    vec.insert(vec.begin()+1,100);
}

void explainList(){

    // list is a doubly linked list
    // fast insertion and deletion

    list<int> ls = {6,7};

    // insert at front
    ls.push_front(1);

    // insert at back
    ls.push_back(10);

    for(auto it:ls){
        cout<< it <<" ";
    }

    cout<<endl;
}

void explainStack(){

    // stack follows LIFO
    // Last In First Out

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    // top() returns last inserted element
    cout<<"Top "<<st.top()<<endl;

    // remove top element
    st.pop();

    cout<<"Top after pop "<<st.top()<<endl;

    cout<<"Size "<<st.size()<<endl;

    // check empty
    cout<<"Empty "<<st.empty()<<endl;
}

void explainQueue(){

    // queue follows FIFO
    // First In First Out

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    // first element
    cout<<"Front "<<q.front()<<endl;

    // last element
    cout<<"Back "<<q.back()<<endl;

    q.pop();

    cout<<"Front after pop "<<q.front()<<endl;
}

void explainPQ(){

    // priority_queue is a heap

    // by default it is MAX HEAP
    // largest element comes first

    priority_queue<int> pq;

    pq.push(5);
    pq.push(3);
    pq.push(50);

    cout<<"Max heap top "<<pq.top()<<endl;

    // MIN HEAP
    // smallest element comes first

    priority_queue<int, vector<int>, greater<int>> minpq;

    minpq.push(5);
    minpq.push(3);
    minpq.push(50);

    cout<<"Min heap top "<<minpq.top()<<endl;
}

void explainSet(){

    // set stores UNIQUE elements
    // automatically SORTED in ascending order
    // implemented using balanced BST

    set<int> st;

    st.insert(1);
    st.insert(2);
    st.insert(2);  // duplicate ignored
    st.insert(4);

    for(auto it:st){
        cout<<it<<" ";
    }

    cout<<endl;

    // find element
    auto it = st.find(2);

    if(it!=st.end()){
        cout<<"Found "<<*it<<endl;
    }

    // count returns 0 or 1
    cout<<"Count "<<st.count(2)<<endl;

    // erase element
    st.erase(2);

    // lower_bound -> first element >= value
    auto lb = st.lower_bound(1);

    // upper_bound -> first element > value
    auto ub = st.upper_bound(4);
}

void explainMultiSet(){

    // multiset is same as set
    // but it allows DUPLICATE elements
    // elements remain SORTED

    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(2);

    for(auto x:ms){
        cout<<x<<" ";
    }

    cout<<endl;

    // count duplicates
    cout<<"Count "<<ms.count(1)<<endl;
}

void explainUnorderedSet(){

    // unordered_set stores UNIQUE elements
    // but NOT sorted

    // implemented using HASH TABLE

    unordered_set<int> st;

    st.insert(10);
    st.insert(20);
    st.insert(10);

    for(auto x:st){
        cout<<x<<" ";
    }

    cout<<endl;
}

void explainMap(){

    // map stores KEY VALUE pairs

    // keys are UNIQUE
    // keys are automatically SORTED

    map<int,string> mp;

    mp[1] = "Ajay";
    mp[2] = "DSA";

    mp.insert({3,"STL"});

    for(auto it: mp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    auto it = mp.find(2);

    if(it!=mp.end()){
        cout<<"Found "<<it->second<<endl;
    }
}

void explainUnorderedMap(){

    // unordered_map stores key value pairs

    // keys are UNIQUE
    // order is NOT sorted

    // implemented using HASH TABLE
    // average time complexity O(1)

    unordered_map<int,string> mp;

    mp[1] = "One";
    mp[2] = "Two";

    for(auto it: mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){

    explainPair();
    explainVector();
    explainList();
    explainStack();
    explainQueue();
    explainPQ();
    explainSet();
    explainMultiSet();
    explainUnorderedSet();
    explainMap();
    explainUnorderedMap();

    return 0;
}