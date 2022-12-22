//
// Created by zeal on 2022/12/2.
//

#include "Link22.h"
using namespace std;

Link22::Link22() {
    cout << "Link22被构造" << endl;
    data.reset();
}

Link22::Link22(char const * data) {

}

string Link22::getData() {
    string s = "";
    for (int i = 0; i = data.size(); ++i) {
        if (data[i] == 0)
            s += '0';
        else
            s += '1';
    }
    return s;
}