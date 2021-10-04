//
// Created by adries on 2021-02-04.
//
#include <iostream>
#include "Website.h"


Website::Website(const std::string &url_name, const std::string &url) {
    _url_name = url_name;
    _url = url;
}

Website::Website() {
    _url_name = "";
    _url = "";
}

std::string Website::getUrlName() const {
    return _url_name;
}

std::string Website::getUrl() const {
    return _url;
}

void Website::print() const {
    std::cout << _url_name << " " << _url << std::endl;
}