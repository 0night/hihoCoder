#include <iostream>

using namespace std;

//char (*f(char *s))[5]
char **f(char *s)
{
	//char res[5][5];
	char **res = new char*[5];
	for (int i = 0; i < 5; i++)
	{
		res[i] = new char[5];
	}
	int flg[26];
	char tmp[25];
	for (int i = 0; i < 26; i++)
		flg[i] = 1;
	
	int i = 0;
	int jj = 0;

	while (s[i])
	{
		if (s[i] == 'J')
			s[i] = 'I';
		if (flg[s[i] - 'A'] == 1)
		{
			flg[s[i] - 'A'] = 0;
			tmp[jj] = s[i];
			jj++;
		}
		i++;
	}
	flg['J' - 'A'] = 0;
	for (int i = 0; i < 26; i++)
	{
		if (flg[i] == 1 && jj < 25)
		{
			tmp[jj] = 'A' + i;
			jj++;
		}
	}
	jj = 0;
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
			res[i][j] = tmp[jj];
			jj++;
		}
	}
		
	return res;
}

int main()
{
	char a[] = "HIHOCODER";
	//char (*s)[5] = f(a);
	char **s = f(a);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << s[i][j];

		}
		cout << endl;
	}
	system("pause");
	return 0;
}