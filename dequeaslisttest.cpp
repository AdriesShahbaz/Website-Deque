//
// Created by adries on 2021-02-04.
//

#include <iostream>
#include <string.h>
#include <string>
#include <boost/algorithm/string.hpp>

#include "Node.h"
#include "Website.h"
#include "Deque.h"
#include "Linked_List.h"

int main() {
    std::string line;

    Deque d;

    while (true) {
        if (std::cin.eof()) {
            break;
        }

        getline(std::cin, line);

        if (line == "exit") {
            break;
        }

        int pos = line.find(" ");
        std::string cmd = line.substr(0, pos);
        std::string obj = line.substr((pos + 1));

        if (cmd == "push_front" || cmd == "push_back") {
            int second = 0;
            int pos2 = 0;
            int pos3 = 0;
            for (int i = 1; i < obj.length() - 1; i++) {
                if (obj[i] == '\"') {
                    if (second == 0) {
                        pos2 = i-1;
                        second++;
                    } else {
                        pos3 = i+1;
                    }
                }
            }
            std::string url_name = obj.substr(1, pos2);
            std::string url = obj.substr(pos3, obj.length() - pos3 - 1);
            if (cmd == "push_front") {
                d.push_front(url_name, url);
            } else {
                d.push_back(url_name, url);
            }
        } else if (cmd == "pop_front") {
            d.pop_front();
        } else if (cmd == "pop_back") {
            d.pop_back();

        } else if (cmd == "size") {
            std::cout << "size is " << d.size() << std::endl;
        } else if (cmd == "front") {
            Node *front = d.front();
            if (front == NULL) {
                std::cout << "failure" << std::endl;
            } else {
                std::cout << "front is " << front->getWebsite().getUrlName() << " " << front->getWebsite().getUrl()
                          << std::endl;
            }

        } else if (cmd == "back") {
            Node *back = d.back();
            if (back == NULL) {
                std::cout << "failure" << std::endl;
            } else {
                std::cout << "back is " << back->getWebsite().getUrlName() << " " << back->getWebsite().getUrl()
                          << std::endl;
            }
        } else if (cmd == "empty") {
            std::cout << "empty " << d.empty() << std::endl;
        } else if (cmd == "clear") {
            d.clear();
        } else if (cmd == "find") {
            int pos = obj.find('\"');
            obj.erase(remove( obj.begin(), obj.end(), '\"'), obj.end());
            Website found = d.find(obj);
            if (found.getUrlName() == "") {
                std::cout << "not found " << obj << std::endl;
            } else {
                std::cout << "found " << found.getUrlName() << " " << found.getUrl() << std::endl;
            }
        } else if (cmd == "print") {
            d.print();
        } else {
            std::cout << "Not a valid command" << std::endl;
        }
    }
    return 0;
}
