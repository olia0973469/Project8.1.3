// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Вияснити, чи є серед цих символів всі букви, що входять в слово “while”.
// 2. Замінити кожну групу букв “while” парою зірочок “**”.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s) 
{
	int k = 0,
		pos = 0; 
	char* t;
	while (t = strchr(s + pos, 'w')) 
	{
		pos = t - s + 1; 
		if (s[pos + 1] == 'h')
			k++;
		pos = t - s + 2; 
		if (s[pos + 2] == 'i')
			k++;
		pos = t - s + 3; 
		if (s[pos + 3] == 'l')
			k++;
		pos = t - s + 4; 
		if (s[pos + 4] == 'e')
			k++;
	}
	return k;
}
char* Change(char* s) 
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0, 
		pos2 = 0,
		pos3 = 0,
		pos4 = 0,
		pos5 = 0,
		pos6 = 0;
	*t = 0;
	while (p = strchr(s + pos1, 'w')) 
	{
		if (s[p - s + 1] == 'h')
		{
			pos2 = p - s + 2; 
			strncat(t, s + pos1, pos2 - pos1 - 1);
			strcat(t, "**");
			pos1 = pos2;
		}
		if (s[p - s + 2] == 'i')
		{
			pos3 = p - s + 3;
			strncat(t, s + pos2, pos3 - pos2 - 2);
			strcat(t, "**");
			pos2 = pos3;
		}
		if (s[p - s + 3] == 'l')
		{
			pos4 = p - s + 4; 
			strncat(t, s + pos3, pos4 - pos3 - 3);
			strcat(t, "**");
			pos3 = pos4;
		}
		if (s[p - s + 4] == 'e')
		{
			pos5 = p - s + 5; 
			strncat(t, s + pos4, pos5 - pos4 - 4);
			strcat(t, "**");
			pos4 = pos5;
		}
		else
		{
			pos6 = p - s + 6; 
			strncat(t, s + pos5, pos6 - pos5);
			pos6 = pos5;
		}
	}
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}
int main()
{
	char str[101];
		cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of 'while'" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}
