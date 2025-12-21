#include <iostream>
#include <string>

int main(){
    int input;
    do{
        std::cout << "Input number positive: "; 
        std::cin >> input;
    }while(input < 0);

    ///< Целочисленный 8 бит тип
    int8_t number = static_cast<int8_t>(input);

    size_t numberSize = sizeof(number) * 8;
    std::string result{""};
    size_t count = 0;
    for(int i = numberSize-1; i >= 0; --i){
        if((number >> i) & 1){
            result += '1';
            count++;
        }
        else result += '0';
    }   
    std::cout << "Binary format: " << result << ", '1' in number = " << count;
    return 0;
}