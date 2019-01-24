/* Abstract dictionary class to inherit when implementing your
 * BST MyMap class and your Hash Table MyUnorderedMap class.
 * Do not edit this file.
 * 
 * Instructions:
 * Implement the MyUnorderedMap class, which should implement a hash table of MyPair objects.
 * You can choose a type of in-table closed hashing for collision management, 
 * and chose how to manage delete (e.g., tombstones).
 *
 * To figure out what the below functions should do, consult the following links.
 * http://en.cppreference.com/w/cpp/container/unordered_map
 * http://www.cplusplus.com/reference/unordered_map/unordered_map/
 * Many of the functions will be simplified single-parameter versions of the multiple std:: options
 * Where they differ, we have made a brief note in these source files here.
 *
 * We give you a working pa08.cpp for some idea of what to run/test.
 * We also give you a similar file pa08_std.cpp with the std:: versions of the unordered_map functions.
 * 
 * Now that you have learned unit testing with Catch and basic C++, 
 * I suggest writing your own unit tests for each function! 
 * Perhaps you should write your unit tests first using the std::unordered_map for some functions
 * Remember: Test with multiple value (V) types!
 *
 * Files you should submit:
 * MyUnorderedMap.hpp
 * 
 * Never edit the h files.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "MyPair.h"


template <typename K, typename V>
class Dictionary
{
    public:
        // Should only update, but not insert
        // Should throw std::out_of_range exception
        virtual V & at(const K &key) = 0;
    
        // Updates or inserts
        virtual V & operator[](const K &key) = 0;

        virtual bool empty() const = 0;

        virtual int size() const = 0;

        virtual void clear() = 0;

        virtual void insert(const MyPair<K, V> &init_pair) = 0;

        // The version that removes by key
        virtual void erase(const K &key) = 0;

        // Not exactly like the std:: version, but similar.
        virtual MyPair<K, V> * find(const K &key) const = 0; 

        // Not actually std:: (see h file)
        virtual void print() const = 0;
        
        virtual int count(const K &key) const = 0;
};

#endif

