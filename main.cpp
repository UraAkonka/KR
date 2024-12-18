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
        file.seekg(0,ios::end);
        int filesize = file.tellg();
        cout << "filesize: " << filesize << endl;

        vector<char> chunk(filesize,0);

        file.seekg(0,ios::beg);

        file.read(chunk.data(),filesize);


        file.seekg(8,ios::beg);

        int pos = file.tellg();

        while (pos < filesize){
            pngfile* p_png = reinterpret_cast<pngfile*>(&chunk[pos]);
            cout << "lenght: " <<Reverse_DWord(int(p_png -> lenght)) << endl;
            cout << "Type: " <<Reverse_DWord(int(p_png -> type)) << endl;




    }

    else{
        cout << "fail";
    }


    return 0;
}
