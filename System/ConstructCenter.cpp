//
// Created by zeal on 2022/12/2.
//

#include "ConstructCenter.h"
#include "../Utils/CrcUtil.h"

ConstructCenter::ConstructCenter(){
    std::cout << "开始构造";
}

void ConstructCenter::beginCrc(std::bitset<75> *msg) {
    std::bitset<216> tempData;
    CrcUtil crcUtil;
    for (int i = 0; i < tempData.size(); ++i) {
        tempData[i] = msg[i/75][i%75];
    }
    char *data = const_cast<char *>(tempData.to_string().c_str());

    std::bitset<3> crcCode2;
    std::bitset<3> crcCode3;
    // std::bitset<9> tempCode = crcUtil.crc9(data, 216);

}

void ConstructCenter::beginAes() {

}