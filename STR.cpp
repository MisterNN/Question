#include <iostream>
#include <cstring>
using namespace std;

class Str
{
	int length;
public:
	char* string;

	Str(): length(), string()
	{
	}

	Str(char symbol)
	{
		length=1;
		string=new char[1];
		*string=symbol;
		cout << strlen(string) << endl;
	}

	Str(Str& obj)
	{
		length=1;
		string=new char(*obj.string);
	}

	char* Str::operator+=(Str& obj)
	{
		int size;
		size=strlen(string) + strlen(obj.string);
		cout << size << endl;
		char* helper=new char[size];
		strcpy(helper,string);
		strcpy(helper + strlen(string),obj.string);
		return helper;
	}

	~Str()
	{
		delete[]string;
	}
};

int main()
{
	Str name1('u');
	Str name2('h');
	for (int i=0;i < strlen(name1+=name2);i++)
		cout << *((name1+=name2) + i) << endl;
}