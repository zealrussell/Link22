//
// Created by zeal on 2022/12/2.
//

#include "CrcUtil.h"

#define DATA_SIZE 16
#define CRC_SIZE 9

using namespace std;

static const int PATTERN = 0x1; // g(x) = x^9 + 1

bitset<9> CrcUtil::crc9(uint data[], int len) {
    cout<< "---------------------------------begin CRC-------------------------------" << endl;
    cout <<"CRC- the datas are: ";
    for (int i = 0; i < len; ++i) {
        cout << hex << data[i] << " ";
    }
    cout << endl;

    uint remainder = 0;
    int nremainder = 0;
    int j,k;
    uint bit,lb;
    uint fb,cb;
    for (int i = 0; i < len; i++) {

        for (j = DATA_SIZE - 1; j >= 0; j--) {
            bit = (data[i] & (1 << j)) > 0;
            lb = (remainder & (1 << (CRC_SIZE - 1))) > 0;
            fb = lb ^ bit;
            nremainder = fb;
            for (k = 1; k < CRC_SIZE; k++) {
                cb = (remainder & (1 << (k - 1))) >> k - 1;
                if (PATTERN & (1 << k)) {
                    nremainder |= (cb ^ fb) << k;
                } else {
                    nremainder |= cb << k;
                }
            }
            remainder = nremainder;
        }
    }
    remainder &= 0x1FF;
    bitset<9> crcSet(remainder);

    cout << "CRC- code is: "  << crcSet.to_string() << endl;
    cout<< "---------------------------------end CRC-------------------------------" << endl;

    return crcSet;
}

void CrcUtil::printf() {
    cout << "zhllloaojmdf";
}
