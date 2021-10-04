//
// Created by adries on 2021-02-04.
//

#include <iostream>
#include "Node.h"
#include "Website.h"


Node::Node(const Website &website) {
    _website = website;
    prev = NULL;
    next = NULL;
}

Node::Node() {
    prev = NULL;
    next = NULL;
}

Node *Node::getNext() const {
    return next;
}

Node *Node::getPrev() const {
    return prev;
}

Website Node::getWebsite() const {
    return _website;
}

void Node::setPrev(Node *prev_node) {
    prev = prev_node;
}

void Node::setNext(Node *next_node) {
    next = next_node;
}