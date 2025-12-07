#include <iostream>
#include <string>

int main(){
    unsigned int number;
    std::cout << "Input number: " ; std::cin >> number;

    std::string binaryFormat{""};
    size_t bitsCount = sizeof(number) * 8; 

    bool started = false;
    for(int i = bitsCount - 1; i >= 0; --i){
        int currentBit = (number >> i) & 1;

        // skip 0 value bits before higher 1 bit
        if(!started && currentBit == 0){
            continue;
        }
        started = true;

        binaryFormat += currentBit + '0';
    }

    std::cout << "Binary format of number: " << binaryFormat;
}