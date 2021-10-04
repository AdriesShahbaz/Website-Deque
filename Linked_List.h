//
// Created by adries on 2021-02-04.
//

#ifndef URL_DEQUEUE_DEQUE_H
#define URL_DEQUEUE_DEQUE_H

#include "Node.h"
#include "Website.h"
#include "Linked_List.h"

class Linked_List {

private:
    Node *head;
    Node *tail;

public:
    Linked_List();

    ~Linked_List();

    Node *getHead() const;

    Node *getTail() const;

    void setHead(Node *new_head);

    void setTail(Node *new_tail);

};

#endif //URL_DEQUEUE_DEQUE_H
