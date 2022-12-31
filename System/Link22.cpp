//
// Created by zeal on 2022/12/2.
//

#include "Link22.h"
using namespace std;

Link22::Link22() {
    cout << "Link22被构造" << endl;
    data.reset();
}

Link22::Link22(const std::string &msg) {
    data = std::bitset<72>(msg);
    cout << "Link22被构造：" << data << endl;
}

std::string Link22::getStrData() {
    return data.to_string();
}

std::bitset<72> Link22::getBitsetData() {
    return data;
}