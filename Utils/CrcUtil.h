//
// Created by zeal on 2022/12/2.
//

#ifndef LINKSYSTEM_CRCUTIL_H
#define LINKSYSTEM_CRCUTIL_H
#include <iostream>
#include <bitset>
typedef unsigned short int uint;

class CrcUtil {
    public:
        static std::bitset<9> crc9(uint data[], int len);
        std::bitset<16> crc16(uint data[], int len);
        static void printf();
};


#endif //LINKSYSTEM_CRCUTIL_H
