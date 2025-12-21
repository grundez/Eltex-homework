#include <iostream>
#include <string>
#include <bitset>

int main(){
    int number;
    do{
        std::cout << "Input positive number: "; 
        std::cin >> number;
    }while(number < 0);

    std::cout << "Input byte to change number: "; 
    int inputByte;
    std::cin >> inputByte;

    ///< Чистим 3 байт через исключающее или(XOR) и ставим туда новый введеный
    int byteIdx = 2;
    int currentByte = (number >> (byteIdx * 8)) & 1;
    int clearedByte = number ^ (currentByte << (byteIdx * 8));
    int result = clearedByte ^ (inputByte << (byteIdx * 8));

    ///< Вывод  результата
    std::cout << "Number ffter XOR: " << std::dec << result << " =";
    for(int i = sizeof(result) * 8 - 1; i >= 0; --i){
        if((i+1) % 8 == 0) std::cout << ' ';

        char currentByte = (result >> i) & 1 ? '1' : '0';
        std::cout << currentByte;
    }
    
    return 0;
}