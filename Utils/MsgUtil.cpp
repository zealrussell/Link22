//
// Created by zeal on 2022/12/8.
//

#include "MsgUtil.h"

std::string MsgUtil::StrToBitStr(const std::string &str) {

    size_t len = str.length();
    std::string res;
    for (int i = 0; i < len; i++) {
        std::bitset<8> bits = std::bitset<8>(str[i]);
        res += bits.to_string();
    }
    return res;
}

std::string MsgUtil::BitStrTosStr(const std::string &bitstr) {
    size_t len = bitstr.length();
    std::string res;
    for (int i = 0; i < len; i = i + 8) {
        std::string tmp;
        for (int j = 0; j < 8; j++) {
            tmp += bitstr[i + j];
        }
       std::bitset<8> ch = std::bitset<8>(tmp);
        res += (char)ch.to_ulong();
    }
    return res;
}
