//
// Created by zeal on 2023/1/24.
//

#include "FnpMessage.h"

FnpMessage::FnpMessage() {
    printf(" Fn-p消息被构造\n");
    data.reset(0);
    data.reset(2);
}

FnpMessage::FnpMessage(const std::string &msg, int N, int P) {
    if (N != 1 && N != 4 && N != 5) return;
    if (P != 0 && P != 1) return;
    if (msg.length() < 0 || msg.length() > 61) return;

    setN(N);
    setP(P);
    setLength(msg.length());
    setMessage(msg);
    printf("构造了 F%d-%d 消息：%s\n",N,P,getBitsetData());
}

std::string FnpMessage::getStrData() {
    std::string res = "0";
    res += this->n.to_string();
    res += this->p.to_string();
    res += this->length.to_string();
    res += this->message.to_string();
    return res;
}

std::bitset<72> FnpMessage::getBitsetData() {
    std::string s = getStrData();
    std::bitset<72> res(s);
    return res;
}

void FnpMessage::setN(int N) {
    this->n = std::bitset<3>(N);
}

void FnpMessage::setP(int P) {
    this->p = std::bitset<1>(P);
}

void FnpMessage::setLength(int LEN) {
    this->length = std::bitset<6>(LEN);
}

void FnpMessage::setMessage(const std::string &msg) {
    this->message = std::bitset<61>(msg);
}
