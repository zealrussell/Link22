//
// Created by zeal on 2022/12/2.
//

#ifndef LINKSYSTEM_CONSTRUCTCENTER_H
#define LINKSYSTEM_CONSTRUCTCENTER_H

#include "Link22.h"

#include "../Utils/MsgUtil.h"
#include "../Utils/CrcUtil.h"
#include "../Utils/AES.h"
#include "../Utils/RSInclude/rs.hpp"

class ConstructCenter {
    public:
        ConstructCenter();
        void beginConstruct(std::string message);

        void print(const unsigned char* state, int len);

    private:
        void initCenter();
        uint8_t *beginAes(const std::bitset<72> *data, int arrayNum);
        uint8_t *beginCrc(const uint8_t *data, int arrayNum);
        uint8_t *beginRs(const uint8_t *crcCode, const uint8_t *msgCode, int arrayNum);

        uint8_t *beginDeAes(const uint8_t *data);
        bool beginDeCrc(const uint8_t *crcCode, const uint8_t *data);
        uint8_t *beginDeRs(const uint8_t *rsCode, int num);

        MsgUtil msgUtil;
        AESModeOfOperation aes;
        CrcUtil crcUtil;
        RS::ReedSolomon<21, 15> rs;

};


#endif //LINKSYSTEM_CONSTRUCTCENTER_H
