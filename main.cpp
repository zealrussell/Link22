#include <iostream>
#include "Utils/CrcUtil.h"
int main() {
    CrcUtil ut;

    uint data[] = {0xb48c, 0x2316, 0x1033};
    const int len = sizeof(data) / sizeof(data[0]);
    std::bitset<9> set = CrcUtil::crc9(data, len);
    return 0;

}