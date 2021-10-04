//
// Created by adries on 2021-02-05.
//

#ifndef DEQUE_URL_DEQUE_H
#define DEQUE_URL_DEQUE_H
#include "Linked_List.h"

class Deque {

private:
    Linked_List _deque;
    int _size;

public:
    Deque();

    //Inserts a new element at the beginning of the deque, right before its current first element.
    void push_front(const std::string &url_name, const std::string &url);

    // Adds a new element at the end of the deque, after its current last element.
    void push_back(const std::string &url_name, const std::string &url);

    // Removes the first element in the deque, reducing its size by one.
    void pop_front();

    // Removes the last element in the deque, reducing its size by one.
    void pop_back();

    // Returns the number of elements in the deque.
    int size() const;

    // Returns the first element in the deque.
    Node *front() const;

    // Returns the last element in the deque.
    Node *back() const;

    // Returns whether the deque is empty (i.e., whether its size is 0).
    int empty() const;

    // Removes all elements from the deque, leaving the container with a size of 0.
    void clear();

    // Finds if URL-name is in the deque.
    Website find(const std::string &url_name) const;

    // Prints all the entries in the deque starting at the back
    void print() const;
};


#endif //DEQUE_URL_DEQUE_H
