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
                directory[j] = directory[j+1];  // delete by mov abonents left after current pos
            }
            --currentQuantity;
            
            // delete/clean last abonent, cuz he dooblicated n-1 now (n == n-1)
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

Directory::Abonent &Directory::findAbonentByName(const char *_name) const
{
    if(isEmpty()) {
        throw std::runtime_error("Directory is empty");
    }

    Abonent sameAbonents[MAX_ABONENT];
    int sameAbonentCount = 0;
    bool isFinded = false;

    for(int i = 0; i < currentQuantity; ++i){
        if(strcmp(directory[i].name, _name) == 0){
            isFinded = true;
            sameAbonents[sameAbonentCount] = directory[i];
            ++sameAbonentCount;
            isFinded = true;
        }
    }
    if(isFinded) {
        std::cout << "\nFinded abonents:" << std::endl;
        for(int i = 0; i < sameAbonentCount; ++i){
            std::cout << sameAbonents[i].name << " " 
                    << sameAbonents[i].second_name << " - " << sameAbonents[i].tel << std::endl;
        }
        return sameAbonents[0];
    }

    throw std::runtime_error("Didnt find abonent");
}

bool Directory::isFull() const
{
    return currentQuantity >= capacity;
}

bool Directory::isEmpty() const
{
    return currentQuantity == 0;
}
