//
// Created by zeal on 2022/12/2.
//

#ifndef LINKSYSTEM_CONSTRUCTCENTER_H
#define LINKSYSTEM_CONSTRUCTCENTER_H

#include "Link22.h"

class ConstructCenter {
    public:
        ConstructCenter();
        void beginCrc(std::bitset<75> *data);
        void beginRs();
        void beginAes();
};


#endif //LINKSYSTEM_CONSTRUCTCENTER_H
