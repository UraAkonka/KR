#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>

using namespace std;

#pragma pack(push,1)

struct pngfile{
    uint32_t lenght;
    uint32_t type;
};

#pragma pack(pop)

uint32_t Reverse_DWord(uint32_t value) {
    return ((value >> 24) & 0xff) |
           ((value >> 8) & 0xff00) |
           ((value << 8) & 0xff0000) |
           ((value << 24) & 0xff000000);
}


int main()
{
    ifstream file("D:\\zachet\\PNG\\promo.png",ios::binary);
    if (file.is_open()){
    }
    else{
        cout << "fail";
    }


    return 0;
}
