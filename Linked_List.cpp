//
// Created by adries on 2021-02-04.
//


#include "Linked_List.h"
#include "Node.h"

Linked_List::Linked_List() {
    head = NULL;
    tail = NULL;
}

void Linked_List::setHead(Node *new_head) {
    head = new_head;
}

void Linked_List::setTail(Node *new_tail) {
    tail = new_tail;
}

Node *Linked_List::getHead() const {
    return head;
}

Node *Linked_List::getTail() const {
    return tail;
}

Linked_List::~Linked_List() {
    tail = NULL;

    while (head != NULL) {
        Node *tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

