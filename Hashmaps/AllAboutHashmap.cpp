//  Hashmap Introduction
// -->>In computer science, a hash map, often called a hash table, 
//    is a common data structure that offers effective key-value pair storing and retrieval.
// -->>In C++, the STL unordered_map is an unordered associative container
//      that provides the functionality of an unordered map or dictionary data structure.
// -->>In contrast to a regular map, the order of keys in an unordered map is undefined.
// -->>Also, the unordered map is implemented as a hash table data structure 
//     whereas the regular map is a binary search tree data structure.
//  CREATING A HASHMAP unordered_map
// import hader file-->>#include<unorderd_map>
#include<iostream>
using namespace std;
#include<unordered_map>
int main(){
// CREATING AN unordered map 
// syntax -->> unordered_map<key type,value type> mapname
// key_type indicates the data type for the key
// value_type indicates the data type for the value
// intialising an unordered map
unordered_map<string,int>map1={
    {"One", 1},
  {"Two", 2},
  {"Three", 3}
};
// second way of intialising a map
// mapname[keyname]=valuename
unordered_map<string,int>map2;
map2["sumit"]=1;
map2["rawat"]=2;
// printing the map traversed
// x.first - gives the key
// x.second - gives the value
cout<<"the map is "<<endl;
for(auto x: map1) {
    string key = x.first;
    int value = x.second;
    
    cout << key << " - " << value << endl;
  }
  cout<<endl<<endl;
//     C++ Unordered Map Methods

 //   Methods	Description

// insert()	insert one or more key-value pairs
// count()	returns 1 if key exists and 0 if not
// find()	returns the iterator to the element with the specified key
// at()	returns the element at the specified key
// size()	returns the number of elements
// empty()	returns true if the unordered map is empty
// erase()	removes elements with specified key
// clear()	removes all elements


//  find size of the map
cout<<"the size of the map is "<<map1.size()<<endl<<endl;
//     Insert Key-Value Pairs to an Unordered Map
// method 1
map1["Tupac"]=1;
// method 2
map1.insert({"thuglife",2});

cout<<"new map after inserting new element is"<<endl;
for(auto x: map1) {
    string key = x.first;
    int value = x.second;
    
    cout << key << " - " << value << endl;
  }
  cout<<endl<<endl;

//      Access Values of Unordered Maps
// method 1
cout<<map1["Tupac"];
// method 2
cout<<endl;
cout<<map1.at("Tupac")<<endl<<endl;;
// Note: While we can use the [] operator to access the elements, it is preferable to use the at() method.

// This is because at() throws an exception whenever the specified key doesn't exist, 
// while [] pairs the key with a garbage value.

//    Change Values of an Unordered Map
// method 1
map1["Tupac"]=7;
// method 2
map2.at("thuglife")=6;
cout<<"map after changing value of map"<<endl;
for(auto x: map1) {
    string key = x.first;
    int value = x.second;
    
    cout << key << " - " << value << endl;
  }
  cout<<endl<<endl;


// Remove Elements From an Unordered Map
//  remove element with key
map1.erase("Thuglife");
cout<<"new map after removing a key"<<endl;
for(auto x: map1) {
    string key = x.first;
    int value = x.second;
    
    cout << key << " - " << value << endl;
  }
  cout<<endl<<endl;

// Check if a Key Exists in the Unordered Map
// find() - returns the iterator to the element if the key is found, else returns the end() iterator
// count() - returns 1 if the key exists and 0 if not
 if (map1.find("thuglife") != map1.end()) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }
//   The find() method returns an iterator pointing to the element if it exists. 
// If the key doesn't exist, it points to the end() iterator.
// count method
if (map1.count("thuglife")) {
  cout << "Yes";
}
else {
  cout << "No";
}
return 0;

}