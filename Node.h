//
// Created by adries on 2021-02-04.
//

#ifndef URL_DEQUEUE_NODE_H
#define URL_DEQUEUE_NODE_H

#include <string>
#include "Website.h"

class Node {

private:
    Website _website;
    Node *next;
    Node *prev;

public:
    Node(const Website &website);

    Node();

    // Get next node
    Node *getNext() const;

    // Get previous node
    Node *getPrev() const;

    // Get Website (data, url_name and url)
    Website getWebsite() const;

    // Set the next node
    void setNext(Node *next_node);

    // Set the previous node
    void setPrev(Node *prev_node);
};


#endif //URL_DEQUEUE_NODE_H
