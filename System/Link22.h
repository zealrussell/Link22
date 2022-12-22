//
// Created by zeal on 2022/12/2.
//

#ifndef LINKSYSTEM_LINK22_H
#define LINKSYSTEM_LINK22_H
#include <bitset>
#include <iostream>

class Link22 {
    public:
        Link22();
        Link22(char const *);
        std::string getData();
    private:
        std::bitset<72> data;
};


#endif //LINKSYSTEM_LINK22_H
