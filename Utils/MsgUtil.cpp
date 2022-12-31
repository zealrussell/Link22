//
// Created by zeal on 2022/12/8.
//

#include "MsgUtil.h"

//输入字符串str_data长度必须为8的整数倍
//功能：将二进制字符串“0000000100000010”按8bit一组合并转化{ "1", "2" }的字符数组
uint8_t *MsgUtil::StrToCharArray(std::string &str_data, int char_length) {
    size_t len = str_data.length();
    if (len % 8 != 0) {
        std::cout << "输入字符串长度有误，需8bit整数倍";
        return nullptr;
    }
    uint8_t* data = new uint8_t[char_length]();
    for (int i = 0; i < char_length; i++) {
        std::bitset<8> tmp = std::bitset<8>(str_data.substr(i * 8, 8));
        data[i] = static_cast<uint8_t>(tmp.to_ulong());
    }
    return data;
}

/**
 * 将char转换成bitset<72>，每9个转换成一个
 * @param charArray
 * @param arraySize
 * @return
 */
std::bitset<72> *MsgUtil::CharArrayToBitset(const uint8_t *charArray, int arraySize) {
    if (arraySize % 9 != 0) {
        std::cout << "";
        return nullptr;
    }
    std::bitset<72> *data = new std::bitset<72>[arraySize / 9];
    for(int i = 0; i < arraySize; i++) {
    }
    return data;
}