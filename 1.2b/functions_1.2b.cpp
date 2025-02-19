#include "Header1.2b.h"

char* CreateText()
{
	const int MAX = 1000;
	static char str[MAX] = { 0 };
	
	std::cout << "Enter a string : ";
	std::cin.get(str, MAX);

	return &str[0];
}

void FillStringWithWordsGivenLength(char* str, char* razd, char* result, int length_word, int size_string)
{
	char* context = nullptr;
	char* Ptr = strtok_s(str, razd, &context);

	int word_len = 0;
	int min_len = INT_MAX;
	int index = 0;
	

	while (Ptr != nullptr)
	{
		word_len = strlen(Ptr);
		if (word_len < min_len)
		{
			min_len = word_len;
		}
		if (strlen(Ptr) == length_word)
		{
			strcat_s(result, size_string, Ptr);				//	производим конкатенацию, если длина слова совпадает с заданной
			strcat_s(result, size_string, " ");				//	добавляем пробелы между словами новой строки
		}

		Ptr = strtok_s(nullptr, razd, &context);	//	вызов функции для выделения следующей лексемы 

	}
}