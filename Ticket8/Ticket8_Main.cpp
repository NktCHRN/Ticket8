#include <iostream>
#include <string>
#include "Ticket8_Lib.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");
    cout << "Билет №8" << endl;
    int size;                                               //размер массива строк
    int rows;                                               //размер таблицы
    string* s = init(&size);                                //ввод массива строк
    encrypt_array(s, size);                                 //зашифровка массива строк
    cout << "Зашифрованные строки: " << endl;
    print_array(s, size);
    delete_double(s, size);                                 //удаляем повторы
    cout << "Измененные строки (повторы удалены): " << endl;
    print_array(s, size);
    lower_counter(s, size);                                 //выводим количество маленьких букв
    sort_array(s, size);                                    //сортируем массив строк
    cout << "Отсортированные строки: " << endl;
    print_array(s, size);
    string* table = get_table(s, size, &rows);              //получаем таблицу строк
    cout << "Таблица букв: " << std::endl;
    print_array(table, rows);
    delete[] s;                                             //удаляем динамический массив строк
    delete[] table;                                         //удаляем динамический массив строк-таблицу
    system("pause");
}
