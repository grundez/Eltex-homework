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

        /// @brief Конструктор абонента
        /// @param _name - имя 
        /// @param _secondName - фамилия 
        /// @param _tel - номер телефона
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

    /// @brief Функция добавления абонента 
    /// @param abonent - абонент, которого необходимо добавить 
    void addAbonent(Abonent& abonent);

    /// @brief Функция поиска абонента по имени
    /// @param _name - имя абонента, которого ищем 
    /// @return возвращает ссылку на найденного абонента 
    Abonent* findAbonentByName(const char* _name) const;

    /// @brief Функция удаления абонента 
    /// @param abonent - абонент, которого необходимо удалить 
    void deleteAbonent(Abonent& abonent);

    /// @brief Вывести текущую директорию
    void printDirectory() const;

    bool isEmpty() const;
    bool isFull() const;

private:
    Abonent* directory;
    const size_t capacity;
    size_t currentQuantity; 
};

