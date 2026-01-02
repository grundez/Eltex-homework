//#include <gmock/gmock.h>  // TODO: нужен интерфейс к классу директории, чтобы тестить моками большую часть логики
                            // например, чтобы проверить удаление абонента:
                            // сейчас оно происходит через поиск абонента доп. методом и тд.

#include <gtest/gtest.h>
#include "../Directory.h"

// case: Добавление абонента
TEST(DirectoryTest, addAbonentTest){
    Directory dir;
    Directory::Abonent abonent("Name", "Surname", "123");
    dir.addAbonent(abonent);

    EXPECT_FALSE(dir.isEmpty());
    EXPECT_FALSE(dir.isFull());
    EXPECT_EQ(dir.getCapacity(), 1);   
}

// case: Поиск абонента
TEST(DirectoryTest, findAbonentTest){
    Directory dir;
    Directory::Abonent abonent1("Name1", "Surname1", "1");
    Directory::Abonent abonent2("Name2", "Surname2", "2");
    Directory::Abonent abonent3("Name3", "Surname3", "3");
    
    dir.addAbonent(abonent1);
    dir.addAbonent(abonent2);
    dir.addAbonent(abonent3);

    Directory::Abonent* found = dir.findAbonentByName("Name2");
    ASSERT_STREQ(found->tel, "2");
}

// case: Удаление абонента
TEST(DirectoryTest, deleteAbonentTest){
    Directory dir;
    Directory::Abonent abonent1("Name1", "Surname1", "1");
    Directory::Abonent abonent2("Name2", "Surname2", "2");
    
    dir.addAbonent(abonent1);
    dir.addAbonent(abonent2);

    // TODO: добавить mock класс
    // Не могу проверить логику метода

    // DirectoryMock dm;
    // EXPECT_CALL(dm, findAbonentByName("Name1")).WillOnce(Return(&abonent1));
    // EXPECT_CALL(dm, deleteAbonent(&abonent1)).WillOnce(Return());

    // Временная иммитация
    Directory::Abonent* found = dir.findAbonentByName(abonent2.name);
    EXPECT_NE(found, nullptr);      
    dir.deleteAbonent(abonent2);
    ASSERT_EQ(dir.getCapacity(), 1);
    ASSERT_FALSE(dir.isEmpty());
}

// case: Удаление абонента в пустом справочнике
TEST(DirectoryTest, deleteAbonentInEmptyDirectoryTest){
    Directory dir;
    Directory::Abonent abonent1("Name1", "Surname1", "1");

    // Аналогичная ситуация как и в тесте выше - нужен мок
    // Временная иммитация
    Directory::Abonent* found = dir.findAbonentByName(abonent1.name);
    EXPECT_EQ(found, nullptr);
    dir.deleteAbonent(abonent1);
    ASSERT_EQ(dir.getCapacity(), 0);
    ASSERT_TRUE(dir.isEmpty());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}