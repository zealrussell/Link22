//
// Created by zeal on 2022/12/2.
//

#include "ConstructCenter.h"

static unsigned char iv[] = {103,35,148,239,76,213,47,118,255, 222,123,176,106,134,98,92};
static unsigned char key[] = {143,194,34,208,145,203,230,143,177,246,97,206,145,92,255,84};




ConstructCenter::ConstructCenter(){
    printf("开始构造\n");
    initCenter();
}
void ConstructCenter::beginConstruct(std::string message) {
    std::bitset<72> bitset1(message);
    std::bitset<72> bitset2(message);
    std::bitset<72> p[2];
    p[0] = bitset1;
    p[1] = bitset2;
    uint8_t *aesCode = beginAes(p, 2);
    uint8_t *crcCode = beginCrc(aesCode, 18);
    uint8_t *rsCode = beginRs(crcCode, aesCode,18);

}

void ConstructCenter::initCenter() {
    aes.set_key(key);
    aes.set_mode(MODE_OFB);
    aes.set_iv(iv);
}

/**
 * 进行aes
 *
 * @param data
 * @return 18个uint
 */
uint8_t *ConstructCenter::beginAes(const std::bitset<72> *data ,int arrayNum) {
    std::cout << "-------------------------------------------begin AES--------------------------------" << std::endl;

    uint8_t *input =  msgUtil.BitsetToCharArray(data,arrayNum);
    uint8_t temp[100];
    int inlen = sizeof(uint8_t) * 9 * arrayNum;
    printf("AES::before aes: ");
    print(input, inlen);
    int outlen = aes.Encrypt(input, inlen, temp);

    uint8_t *output = new uint8_t [outlen];
    memcpy(output, temp, outlen);
    printf("AES::after aes %d : ",outlen);
    print(output, outlen);

    std::cout << "-------------------------------------------end AES-------------------------------------" << std::endl << std::endl;
    return output;
}

/**
 * 生成16位crc码
 * @param msg 待编码的消息
 * @param arrayNum uint8个数
 * @return crc码
 */
uint8_t *ConstructCenter::beginCrc(const uint8_t *msg, int arrayNum) {
    std::cout << "------------------------------------------begin CRC16----------------------------------" << std::endl;
    uint8_t *data;
    memcpy(data, msg, arrayNum * sizeof(uint8_t));
    uint8_t *crcCode = new uint8_t[2];
    crcUtil.get_crc16(data,arrayNum, crcCode);

    printf("Crc code is: ");
    print(crcCode,2 * sizeof(uint8_t));
    std::cout << "------------------------------------------end CRC16------------------------------------" << std::endl << std::endl;
    return crcCode;
}


/**
 * https://github.com/mersinvald/Reed-Solomon
 * RS<36,21>
 * @param crcCode
 * @param msgCode
 * @param arrayNum
 * @return 36个
 */
uint8_t *ConstructCenter::beginRs(const uint8_t *crcCode, const uint8_t *msgCode, int arrayNum) {
    std::cout << "-------------------------------------------begin RS--------------------------------------" << std::endl;

    // 1.合并消息
    uint8_t data[21] = {0};
    memcpy(data, crcCode, 2 * sizeof(uint8_t));
    memcpy(data + 3, msgCode, 18 * sizeof(uint8_t));

    printf("RS::code before: ");
    print(data,21);
    // 2.rs编码
    uint8_t *output;
    rs.Encode(data, output);
    printf("RS::code after: ");
    print(output,36);
    std::cout << "-------------------------------------------end RS--------------------------------------" << std::endl << std::endl;
    return output;
}

/**
 * rs解码
 * @param rsCode
 * @param arrayNum
 * @return 返回21个
 */
uint8_t *ConstructCenter::beginDeRs(const uint8_t *rsCode, int arrayNum) {
    std::cout << "-------------------------------------------begin DeRS--------------------------------------" << std::endl;
    uint8_t *output;
    rs.Decode(rsCode,output);
    printf("Code after ders\n");
    print(output, 21);
    std::cout << "-------------------------------------------end DeRS--------------------------------------" << std::endl << std::endl;
    return output;
}

bool ConstructCenter::beginDeCrc(const uint8_t *crcCode, const uint8_t *data) {
    std::cout << "-------------------------------------------begin DeCrc--------------------------------------" << std::endl;
    uint8_t *code = new uint8_t[2];
    crcUtil.get_crc16(const_cast<uint8_t *>(data), 18,code);

    int res = memcmp(code, crcCode, 2 * sizeof(uint8_t));
    std::cout << "-------------------------------------------end DeCrc--------------------------------------" << std::endl;
    if (res != 0) return false;
    else return true;
}

/**
 * 解aes
 * @param data
 * @return
 */
uint8_t *ConstructCenter::beginDeAes(const uint8_t *data) {
    std::cout << "-------------------------------------------begin DeAes--------------------------------------" << std::endl;
    uint8_t output[18] = {0};
    aes.Decrypt(const_cast<unsigned char *>(data), 18, output);
    printf("Code after deaes::\n");
    print(output, 18);
    std::cout << "-------------------------------------------end DeAes--------------------------------------" << std::endl;
    return output;
}

void ConstructCenter::print(const uint8_t *state, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("%x  ", state[i]);
    }
    printf("\n");
}