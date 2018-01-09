#include <iostream>
#include <cstring>>
// do not get confused with 
// #include <string>
using namespace std;

int mingap(char*, char*);
int gap(char* s, char* t);
int main()
{
	char text[80];
	char word[80];

	cout << "enter text:";
	cin >> text;
	cout << "enter word:";
	cin >> word;

	//int result = mingap(text, word);
	int result = gap(text, word);
	cout << "size of jump: " << result << endl;
	//Press any key to continue...
	system("pause");
}

int gap(char* s, char* t)
{
	int leg = -1;
	int i = 0;
	char* str=nullptr, *kodem ;
	while (*t)
	{
		kodem = str;
		str = strchr(s, *t);
		if (str == nullptr)
		{
			return -1;
		}
		if (!kodem)
		{
			leg = (str - kodem);
		}
		t++;
	}
	return leg;
}
int mingap(char* sentence, char* what)
{
	bool yeshdilug;
	yeshdilug = true;
	int i = 0;
	int dilug;
	char * ptr = sentence;
	char* ptr2;
	//while (*ptr )
	//{
	//	if (*ptr == what[0])
	//	{
	//		ptr2 = ptr + i;
	//		if()
	//		

	//	}
	//	++sentence;
	//}
	//strchr(sentence,what[0])
	return -1;
}