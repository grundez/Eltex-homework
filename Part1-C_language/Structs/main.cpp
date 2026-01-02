#include <iostream>
#include <cstring>
#include "Directory.h"

int main() {
    Directory dir; 
    
    while(true) {
        std::cout << "\nChoose option: " << std::endl;
        std::cout << "1: Add abonent" << std::endl;
        std::cout << "2: Delete abonent" << std::endl;
        std::cout << "3: Find abonent by name" << std::endl;
        std::cout << "4: Check abonent directory" << std::endl;
        std::cout << "5: Exit" << std::endl;
        std::cout << "Choose: ";
        int choose; std::cin >> choose;

        switch(choose) {
        case 1: {
            if(dir.isFull()){
                std::cout << "Directory is full" << std::endl;
                break;
            }

            char name[10];
            char second_name[10];
            char tel[15];
            
            std::cout << "Abonent name: "; 
            std::cin >> name;
            std::cout << "Abonent second name: "; 
            std::cin >> second_name;
            std::cout << "Abonent telephone: "; 
            std::cin >> tel;
            
            Directory::Abonent abonent(name, second_name, tel);
            dir.addAbonent(abonent);
            break;
        }
        
        case 2: {
            if(dir.isEmpty()){
                std::cout << "Directory is empty" << std::endl; 
                break;
            }

            char name[10];
            std::cout << "Abonent name to delete: "; 
            std::cin >> name;

            Directory::Abonent* found = dir.findAbonentByName(name);
            if(found) dir.deleteAbonent(*found);
            else std::cout << "Abonent " << name << " not found"; 
            break;
        }
        
        case 3: {
            if(dir.isEmpty()){
                std::cout << "Directory is empty" << std::endl; 
                break;
            }

            char name[10];
            std::cout << "Abonent name to find: "; 
            std::cin >> name;
            Directory::Abonent* found = dir.findAbonentByName(name);
            if(!found) std::cout << "Abonent " << name << " not found";
            break;
        }
        
        case 4:
            dir.printDirectory();
            break;
            
        case 5:
            std::cout << "Goodbye!" << std::endl;
            return 0;
            
        default: 
            std::cout << "Invalid choice!\n";
            break;
        }
    }
    return 0;
}