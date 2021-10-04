//
// Created by adries on 2021-02-04.
//

#ifndef URL_DEQUEUE_WEBSITE_H
#define URL_DEQUEUE_WEBSITE_H

#include <string>

class Website {
private:
    std::string _url_name;
    std::string _url;

public:
    Website();

    Website(const std::string &url_name, const std::string &url);

    // Get the UrlName
    std::string getUrlName() const;

    // Get the Url
    std::string getUrl() const;

    // Print the website info
    void print() const;
};


#endif //URL_DEQUEUE_WEBSITE_H
