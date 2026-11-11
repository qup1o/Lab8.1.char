// Lab 8.1 (standard C functions for char[])
// Пошук та заміна символів у літерному рядку
// Варіант 28

// Дано літерний рядок, який містить послідовність символів
// s[0], ..., s[n], ...
// 1.   Вияснити, чи є серед цих символів всі букви,
//      що входять в слово "while".
// 2.   Замінити кожну групу букв "while" парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)   // для підключення з unit-тесту (pch.h)
#include <iostream>
#include <cstring>

using namespace std;

bool IsAllLettersPresent(const char* s, const char* letters);
char* Change(char* s);

int main()
{
    const char letters[] = "while";   // букви для перевірки

    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (IsAllLettersPresent(str, letters))
        cout << "All letters of \"while\" are present" << endl;
    else
        cout << "Not all letters of \"while\" are present" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    return 0;
}

// чи є в рядку s усі символи з рядка letters
bool IsAllLettersPresent(const char* s, const char* letters)
{
    for (size_t k = 0; k < strlen(letters); k++)
        if (strchr(s, letters[k]) == NULL)   // пошук символу в рядку
            return false;

    return true;
}

// заміна кожної групи букв "while" парою зірочок "**";
// результат записується і в s, і в новий рядок, який повертається
char* Change(char* s)
{
    char* t = new char[strlen(s) + 1];
    char* p;
    size_t pos = 0;                          // pos = позиція початку пошуку
    *t = '\0';

    while ((p = strstr(s + pos, "while")) != NULL)   // p - на "while"
    {
        strncat(t, s + pos, p - (s + pos));  // копіюємо символи до "while"
        strcat(t, "**");
        pos = (p - s) + strlen("while");     // pos = позиція після "while"
    }
    strcat(t, s + pos);                      // залишок рядка

    strcpy(s, t);

    return t;
}
