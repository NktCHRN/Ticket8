#include <iostream>
#include <string>
#include "Ticket8_Lib.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");
    cout << "Билет №8" << endl;
    int size;
    string* s = init(&size);
    encrypt_array(s, size);
    cout << "Зашифрованные строки: " << endl;
    print_array(s, size);
    delete_double(s, size);
    cout << "Измененные строки (повторы удалены): " << endl;
    print_array(s, size);
    lower_counter(s, size);
    sort_array(s, size);
    cout << "Отсортированные строки: " << endl;
    print_array(s, size);
    get_table(s, size);
    delete[] s;
    system("pause");
}
