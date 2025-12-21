#include <iostream>
#include <string>

int main(){
    int input;
    do{
        std::cout << "Input number positive: "; 
        std::cin >> input;
    }while(input < 0);

    ///< Безнаковый целочисленный 8 бит тип
    uint8_t number = static_cast<uint8_t>(input);

    size_t numberSize = sizeof(number) * 8;
    std::string result{""};
    for(int i = numberSize-1; i >= 0; --i){
        char currentByte = ((number >> i) & 1) ? '1' : '0';
        result += currentByte;
    }   
    std::cout << "Binary format: " << result;
    return 0;
}