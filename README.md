## Прога, билет №8
### Задача
Билет номер 8 на ОП:  
1. Вводишь кучу строк, где слова разделены двумя пробелами  
2. Потом каждую строку надо зашифровать так, чтобы сначала шли символы, которые стоят на парных позициях, а после них те, которые стоят на непарных, но в обратном порядке  
3. Из того что получится удалить идущие подряд повторы  
4. Посчитать сколько маленьких букв, потом сколько раз встречается каждая буква и написать ее ASCII код (это в отдельную таблицу)  
5. И отсортировать массив строк по возрастанию количества символов в ней  
6. Создаешь массив, первый столбец буква, второй ее ASCII код, третий, сколько раз он встречается  
### Инструкции, подробности, корректировки и пр.
Файлы проекта находятся в папке **Ticket8** (заголовочный, исходный библиотеки и исходный Main)  
*Как я понял подзадачу2 (шифрование):*  
Допустим, есть строка  
`home  sweet  home`  
Сначала, запишем четные символы. Четность/нечетность считаем не от начала строки, а от начала слова, т.е.:  
```
home  sweet  home
12345612345671234
12121212121211212
```  
Пробелы считаем принадлежащими слову перед ними. Видим, что, например, пробел перед символом **h** нечетный, однако,
символ **h** тоже нечетный, т.е. считаем от начала слова, а не строки. Как результат, получаем:  
`oe we oemh tes mh`  
*Подзадачи 4 и 6 частично объединены.*  
*Остальное четко по билету.*  
### Пример выполнения
![alt text](https://github.com/NktCHRN/Ticket8/raw/master/Test_Screenshot.png)
