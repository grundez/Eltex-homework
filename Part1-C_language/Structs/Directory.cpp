#include "Directory.h"

void Directory::addAbonent(Abonent &abonent)
{
    if(isFull()){
        std::cout << "Directory is full" << std::endl;
        return;
    }

    directory[currentQuantity] = abonent;
    ++currentQuantity;
    std::cout << "Abonent added" << std::endl;
}

void Directory::deleteAbonent(Abonent &abonent)
{
    if(isEmpty()) {
        std::cout << "Directory is empty" << std::endl;
        return;
    }

    for(int i = 0; i < currentQuantity; ++i){
        if(strcmp(directory[i].tel, abonent.tel) == 0){
            for(int j = i; j < currentQuantity - 1; ++j){
                directory[j] = directory[j+1];  // сдвигаем абонентов, тк удалили найденного
            }
            --currentQuantity;
            
            ///< зануляем последнего абонента, тк он дублируется после сдвига 
            directory[currentQuantity].name[0] = '\0';
            directory[currentQuantity].second_name[0] = '\0';
            directory[currentQuantity].tel[0] = '\0';

            std::cout << "Abonent deleted" << std::endl;
            return;
        }
    }
}

void Directory::printDirectory() const
{
    std::cout << "Abonent Directory (" << currentQuantity << " abonents)" << std::endl;

    for(int i = 0; i < currentQuantity; ++i){
        std::cout << directory[i].name << " " << directory[i].second_name << " - " << directory[i].tel << std::endl;
    }
}

Directory::Abonent *Directory::findAbonentByName(const char *_name) const
{
    if(isEmpty()) {
        return nullptr;
    }

    int idSameAbonents[MAX_ABONENT];
    int sameAbonentCount = 0;
    bool isFound = false;

    for(int i = 0; i < currentQuantity; ++i){
        if(strcmp(directory[i].name, _name) == 0){
            isFound = true;
            idSameAbonents[sameAbonentCount] = i;
            sameAbonentCount++;
        }
    }

    if(isFound) {
        std::cout << "\nFinded abonents:" << std::endl;
        for(int i = 0; i < sameAbonentCount; ++i){
            std::cout << directory[idSameAbonents[i]].name << " " 
                    << directory[idSameAbonents[i]].second_name << " - " << directory[idSameAbonents[i]].tel << std::endl;
        }
        return &directory[idSameAbonents[0]]; // возврат первого найденного
    }

    return nullptr;
}

bool Directory::isFull() const
{
    return currentQuantity >= capacity;
}

bool Directory::isEmpty() const
{
    return currentQuantity == 0;
}

int Directory::getCapacity() const
{
    return currentQuantity; 
}