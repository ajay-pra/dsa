/*
========================================================
                C++ STRING FUNCTIONS
========================================================

string is a sequence of characters.

Declaration
-----------
string s = "hello";


--------------------------------------------------------
1. size() / length()
--------------------------------------------------------
Returns number of characters in string.

string s = "hello";
cout << s.size();      // 5
cout << s.length();    // 5


--------------------------------------------------------
2. push_back()
--------------------------------------------------------
Adds character at the end.

string s = "hello";
s.push_back('!');
Result: "hello!"


--------------------------------------------------------
3. pop_back()
--------------------------------------------------------
Removes last character.

string s = "hello";
s.pop_back();
Result: "hell"


--------------------------------------------------------
4. append()
--------------------------------------------------------
Adds another string.

string s = "hello";
s.append(" world");

Result: "hello world"


--------------------------------------------------------
5. substr(start, length)
--------------------------------------------------------
Returns substring.

string s = "programming";

s.substr(3,4)

Output: "gram"


--------------------------------------------------------
6. find()
--------------------------------------------------------
Finds first occurrence of substring.

string s = "hello world";

s.find("world")

Output: 6


If not found → returns string::npos


--------------------------------------------------------
7. erase()
--------------------------------------------------------
Removes part of string.

string s = "hello world";

s.erase(5,1)

Result: "helloworld"


--------------------------------------------------------
8. insert()
--------------------------------------------------------
Insert string at position.

string s = "hello";

s.insert(5," world")

Result: "hello world"


--------------------------------------------------------
9. replace()
--------------------------------------------------------
Replace part of string.

string s = "hello world";

s.replace(6,5,"C++")

Result: "hello C++"


--------------------------------------------------------
10. compare()
--------------------------------------------------------
Compares two strings.

string a = "abc";
string b = "abc";

if(a.compare(b)==0)
    cout<<"Equal";


--------------------------------------------------------
11. stoi()
--------------------------------------------------------
Convert string → integer.

string s = "123";

int x = stoi(s);

x = 123


--------------------------------------------------------
12. to_string()
--------------------------------------------------------
Convert number → string.

int x = 100;

string s = to_string(x);

s = "100"


--------------------------------------------------------
13. reverse()
--------------------------------------------------------
Reverse string.

string s = "hello";

reverse(s.begin(), s.end());

Result: "olleh"


--------------------------------------------------------
14. sort()
--------------------------------------------------------
Sort characters.

string s = "dcba";

sort(s.begin(), s.end());

Result: "abcd"


--------------------------------------------------------
15. transform() (case conversion)
--------------------------------------------------------
Convert to lowercase or uppercase.

string s = "Hello";

transform(s.begin(), s.end(), s.begin(), ::tolower);

Result: "hello"


transform(s.begin(), s.end(), s.begin(), ::toupper);

Result: "HELLO"


========================================================
MOST COMMON STRING FUNCTIONS USED IN DSA
========================================================

s.size()
s.substr()
s.find()
reverse()
sort()
stoi()
to_string()

These are used in most coding interview problems.

========================================================
*/