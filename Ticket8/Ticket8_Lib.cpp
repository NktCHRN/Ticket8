#include "Ticket8_Lib.h"

std::string* init(int* quantity) {
	std::cout << "Введите количество строк: ";
	do {
		std::cin >> *quantity;				//вводим количество строк по указателю
		if (*quantity <= 0) {
			std::cout << "Вы ввели число, меньшее или равное нулю. Перевведите число." << std::endl;
			std::cin.clear();
			std::cin.ignore(8192, '\n');    //пропускает до 8192 символов после введенного вплоть до перехода на новую строку
		}
	} while (*quantity <= 0);
	std::string* str_array = new std::string[*quantity];		//создаем массив строк
	std::cout << "Введите строки (латиницей): " << std::endl;
	std::cin.ignore(8192, '\n');			//пропускает до 8192 символов после введенного вплоть до перехода на новую строку
	for (int i = 0; i < *quantity; i++)
		getline(std::cin, str_array[i]);						//вводим строки
	return str_array;
}

void encrypt_array(std::string* s, int size) {
	std::string temp_start;								//начало строки-результата
	std::string temp_end;								//конец строки-результата
	bool odd;											//нечетное?
	for (int i = 0; i < size; i++) {
		temp_start = "";
		temp_end = "";
		odd = true;										//новая строка
		for (int j = 0; j < s[i].size(); j++) {
			if (odd) {
				temp_end = s[i][j] + temp_end;			//нечетное - записываем первым символом в конец строки-результата (для обратного порядка)
				odd = false;
			}
			else {
				temp_start += s[i][j];					//четное - записываем в начало строки-результата
				odd = true;
			}
			if (s[i][j] == ' ' && j < s[i].size() - 1 && s[i][j+1] != ' ')			//если начало слова
				odd = true;
		}
		s[i] = temp_start + temp_end;					//объединяем строку-результат
	}
}

void print_array(std::string* s, int size) {							//вывод массива строк
	for (int i = 0; i < size; i++)
		std::cout << s[i] << std::endl;
}

void delete_double(std::string* s, int size) {
	std::string temp;
	for (int i = 0; i < size; i++) {
		temp = s[i][0];										//новая строка без повторов
		for (int j = 1; j < s[i].size(); j++)
			if (s[i][j] != s[i][j - 1])
				temp += s[i][j];							//записываем только неповторяющиеся
		s[i] = temp;										//меняем старую строку на новую, без повторов
	}
}

void lower_counter(std::string* s, int size) {
	int total_lower = 0;									//маленьких букв всего
	int temp;												//маленьких букв в данной строке
	std::cout << "Маленьких букв в строках: " << std::endl;
	for (int i = 0; i < size; i++) {
		temp = 0;
		for (int j = 0; j < s[i].size(); j++)
			if (islower(s[i][j]))							//ищем маленькие буквы
				temp++;
		std::cout << "В строке " << i + 1 << " маленьких букв всего: " << temp << std::endl;
		total_lower += temp;
	}
	std::cout << "Всего маленьких букв: " << total_lower << std::endl;
}

void sort_array(std::string* s, int size) {
	std::string temp;
	for (int i = 0; i < size - 1; i++) {											//проходы алгоритма
		for (int j = 0; j < size - i - 1; j++) {									//цикл для перебора элементов массива
			if (s[j].size() > s[j + 1].size()) {									//сравниваем кол-во символов в строках
				temp = s[j];														//меняем строки местами
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

std::string* get_table(std::string* s, int size, int* rows) {
	*rows = unique_letters_counter(s, size);										//находим кол-во уникальных букв
	std::string* table = new std::string[*rows];										//создаем массив строк-таблицу
	for (int i = 0; i < *rows; i++)
		table[i] = "";
	int found, temp, k;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			if (isalpha(s[i][j])) {
				found = find_letter(table, *rows, s[i][j]);							//ищем, есть ли уже новая буква в таблице
				if (found != -1) {													//да - меняем конец этой строки таблицы
					temp = stoi((table[found]).substr(table[found].find('\t', 2)+1));
					table[found].erase(table[found].find('\t', 2) + 1);
					table[found] += std::to_string(temp+1);
				}
				else {
					for (k = 0; k < *rows; k++)										//нет - ищем пустую строку в таблице
						if (table[k] == "")
							break;
					table[k] = std::string(1, s[i][j]);								//пишем букву и информацию о ней в найденную строку
					table[k] += "\t" + std::to_string(s[i][j]) + "\t" + std::to_string(1);
				}
			}
		}
	}
	return table;																	//возвращаем массив строк-таблицу
}

int unique_letters_counter(std::string* s, int size) {
	int unique_letters = 0;
	std::string temp_s = "";
	char temp;
	for (int i = 0; i < size; i++)
		temp_s += s[i];
	for (int i = 0; i < temp_s.size() - 1; i++) {											//сначала отсортируем строку для упрощения поиска уникальных букв
		for (int j = 0; j < temp_s.size() - i - 1; j++) {									//цикл для перебора элементов массива
			if (temp_s[j] > temp_s[j + 1]) {
				temp = temp_s[j];															//меняем символы местами
				temp_s[j] = temp_s[j + 1];
				temp_s[j + 1] = temp;
			}
		}
	}
	if (isalpha(temp_s[0]))																	//для первого символа
		unique_letters++;
	for (int i = 1; i < temp_s.size(); i++)
		if (isalpha(temp_s[i]) && temp_s[i] != temp_s[i - 1])								//находим неодинаковые буквы
			unique_letters++;
	return unique_letters;
}

int find_letter(std::string* s, int rows, char letter) {
	int found = -1;
	for (int i = 0; i < rows; i++) {
		if (s[i][0] == letter) {															//ищем нужную букву среди первых букв массива строк
			found = i;
			break;
		}
	}
	return found;
}
