//
// Created by adries on 2021-02-05.
//

#include "Deque.h"
#include "Linked_List.h"
#include "Node.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

Deque::Deque() {
    _deque = Linked_List();
    _size = 0;
}

Node *Deque::front() const {
    return _deque.getHead();
}

Node *Deque::back() const {
    return _deque.getTail();
}

int Deque::size() const {
    return _size;
}

int Deque::empty() const {
    if (_size != 0) {
        return 0;
    } else {
        return 1;
    }
}

void Deque::clear() {
    _deque.setTail(NULL);

    while (_deque.getHead() != NULL) {
        Node *tmp = _deque.getHead();
        _deque.setHead(_deque.getHead()->getNext());
        delete tmp;
    }
    _size = 0;
    std::cout << "success" << std::endl;
}

void Deque::print() const {
    Node *traverse = _deque.getTail();
    while (traverse != NULL) {
        std::cout << traverse->getWebsite().getUrlName() << " " << traverse->getWebsite().getUrl() << std::endl;
        traverse = traverse->getPrev();
    }
}

void Deque::push_front(const std::string &url_name, const std::string &url) {
    Node *new_node = new(std::nothrow) Node(Website(url_name, url));
    if (!new_node) {
        std::cout << "Failed to allocate memory for new_node node" << std::endl;
    } else {
        // If there is only one element
        if (_deque.getHead() == NULL) {
            _deque.setHead(new_node);
            _deque.setTail(new_node);
        } else {
            _deque.getHead()->setPrev(new_node);
            new_node->setNext(_deque.getHead());
            _deque.setHead(new_node);
        }
        _size++;
        std::cout << "success" << std::endl;
    }
}

void Deque::push_back(const std::string &url_name, const std::string &url) {
    Node *new_node = new(std::nothrow) Node(Website(url_name, url));
    if (!new_node) {
        std::cout << "Failed to allocated memory for new_node node" << std::endl;
    } else {
        // If there is only one element
        if (_deque.getTail() == NULL) {
            _deque.setHead(new_node);
            _deque.setTail(new_node);
        } else {
            _deque.getTail()->setNext(new_node);
            new_node->setPrev(_deque.getTail());
            _deque.setTail(new_node);
        }
        _size++;
        std::cout << "success" << std::endl;
    }
}

void Deque::pop_front() {
    if (empty() == 1) {
        std::cout << "failure" << std::endl;
    } else {
        Node *current = _deque.getHead();
        _deque.setHead(_deque.getHead()->getNext());
        // If there is only one element
        if (_deque.getHead() == NULL) {
            _deque.setTail(NULL);
        } else {
            _deque.getHead()->setPrev(NULL);
        }
        delete current;
        _size--;
        std::cout << "success" << std::endl;
    }
}

void Deque::pop_back() {
    if (empty() == 1) {
        std::cout << "failure" << std::endl;
    } else {
        Node *current = _deque.getTail();
        _deque.setTail(_deque.getTail()->getPrev());
        // If there is only one element
        if (_deque.getTail() == NULL) {
            _deque.setHead(NULL);
        } else {
            _deque.getTail()->setNext(NULL);
        }
        delete current;
        _size--;
        std::cout << "success" << std::endl;
    }
}

Website Deque::find(const std::string &url_name) const {
    Node *current = _deque.getHead();
    Node *next;
    std::string cpy = boost::algorithm::to_lower_copy(url_name);
    while (current != NULL) {
        std::string tmp = current->getWebsite().getUrlName();
        boost::algorithm::to_lower(tmp);
        if (cpy == tmp) {
            return current->getWebsite();
        }
        next = current->getNext();
        current = next;
    }
    return Website();
}



