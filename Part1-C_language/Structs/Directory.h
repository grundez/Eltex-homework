#define MAX_ABONENT 100
#include <iostream>
#include <cstring>

class Directory
{
public:
    struct Abonent {
        char name[10];
        char second_name[10];
        char tel[15];

        Abonent(const char* _name = "", const char* _secondName = "", const char* _tel = "")
        {
            std::strcpy(name, _name);
            std::strcpy(second_name, _secondName);
            std::strcpy(tel, _tel);    
        }

        // comparator 
        bool operator==(Abonent& other){
            return strcmp(tel, other.tel) == 0;
        }
    };

    Directory() : capacity(MAX_ABONENT), currentQuantity(0) {
        directory = new Abonent[capacity];
    }

    ~Directory(){
        delete[] directory;
    }

    Abonent& createAbonent(const char* _name = "", const char* _second_name= "", const char* _tel = "");
    void addAbonent(Abonent& abonent);
    Abonent& findAbonentByName(const char* _name) const;
    void deleteAbonent(Abonent& abonent);
    void printDirectory() const;

    bool isEmpty() const;
    bool isFull() const;

private:
    Abonent* directory;
    const size_t capacity;
    size_t currentQuantity; 
};

