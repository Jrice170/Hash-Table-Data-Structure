#ifndef MYUNORDEREDMAP_H
#define MYUNORDEREDMAP_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "Dictionary.h"

using std::cout;
using std::endl;


void get_identity(std::string &my_id);


template <typename K, typename V>
class MyUnorderedMap: public Dictionary<K, V>
{
    private:
        MyPair<K, V> *m_data = nullptr;
        
        int data_size = 0;
        int reserved_size = 0;

        // To make it easier on you (rather than use void pointers or crazy new C++ templating) 
        // we'll only test with std::string keys (remember values can be any type)
        int hash(const K &key) const;
        
    public:
        // Should start data_size and reserved_size at 0, m_data to nullptr
        MyUnorderedMap();
        
        ~MyUnorderedMap();
        
        MyUnorderedMap(const MyUnorderedMap<K, V> &source);

        MyUnorderedMap<K, V> & operator=(const MyUnorderedMap<K, V> &source);
    
        V & at(const K &key);
    
        V & operator[](const K &key);

        bool empty() const;
        
        int size() const;

        // data_size and reserved_size should be 0 after this, 
        // and m_data should be nullptr.
        void clear();

        void insert(const MyPair<K, V> &init_pair);

        void erase(const K &key);

        // Should return nullptr for key not in HT
        MyPair<K, V> * find(const K &key) const;

        // Not actually std:: 
        // Backwards in order traversal print (for BST)
        // For Hash table, just print all elements in any order, 
        // so that it looks like this when you print(unordereded_map_obj):
        // ([K0]=V0, 
        //  [K1]=V1, 
        //  [K2]=V2)
        // With a newline at the end
        // Like in sample_output.txt
        // Do not modify the table.
        // Only print valid current data elements.
        void print() const;

        int count(const K &key) const;

        // This one was not in the BST, but is in the HT
        // Grows or shrinks reserved_size and size of dynamic array to be new_cap large,
        // and nothing else.
        // Other functions, like insert, erase, or [], should decide how large to make the new cap
        // and call reserve themselves with that size.
        // Those other functions should choose to double the reserved size when the HT becomes 60% full,
        // and to shrink the HT when it becomes 10% full, to a resulting 30%.
        // Remember to re-hash!
        void reserve(int new_cap);

};

// Should accept a source code file (.cpp for example) via std in
// Should build a dictionary of the counts of the words in the code file
// Only count the words that contain the word "virus" (not case sensitive) as a substring
// so that a list of the amount of viruses in the code can be tracked
// Do not add newlines (\n) to the dictionary (they'll mess up print)
// Most symbols should be excluded to isolate the actual keywords and 
// variable names in the code
// ./a.out <sample_code.cpp should be the form of input
void get_virus_frequency(MyUnorderedMap<std::string, int> &in_tree);


#include "MyUnorderedMap.hpp"

#endif

