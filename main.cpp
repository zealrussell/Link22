#include <iostream>

#include "System/ConstructCenter.h"

using namespace std;

int main() {
//    string s = "000111101011";
//    cout << s.substr(1,3);
//    bitset<10> t("1110");
//    t.set(0);
//    cout << t.to_string();
    ConstructCenter con;
    uint8_t *res = con.constructMessage();
    con.crackMessage(res);
    return 0;
}
