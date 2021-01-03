#pragma once
#include <iostream>
#include <string>

std::string* init(int*);							//ввод строк
void encrypt_array(std::string*, int);				//зашифровать строки в массиве
void print_array(std::string*, int);				//вывод массива
void delete_double(std::string*, int);				//удалить повторяющиеся символы
int find_letter(std::string*, int, char);			//найти, есть ли буква в матрице
void sort_array(std::string*, int);					//сортировка массива
void lower_counter(std::string*, int);				//посчитать кол-во строчных букв
std::string* get_table(std::string*, int, int*);	//получить таблицу (6 задание)
int unique_letters_counter(std::string*, int);		//подсчитать кол-во уникальных букв