#include "stdafx.h"
#include "iostream"
#include <string>
#include <set>
#define MAXLEN 100
using namespace std;

int number = 0;
char result[MAXLEN];
set<string> s;

int LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
	int i, j;

	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (j = 0; j <= n; j++)
		c[0][j] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else if (c[i - 1][j] > c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else if (c[i - 1][j] < c[i][j - 1])
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
			else {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
		}
	}
	return c[m][n];
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j, int now, int length)
{
	if (i == 0 || j == 0) {
		s.insert(result);
		number++;
		return;
	}
	if (b[i][j] == 0)
	{
		now--;
		result[now] = x[i - 1];
		PrintLCS(b, x, i - 1, j - 1, now, length);
	}
	else if (b[i][j] == 1)
		PrintLCS(b, x, i - 1, j, now, length);
	else if (b[i][j] == -1)
		PrintLCS(b, x, i, j - 1, now, length);
	else {
		PrintLCS(b, x, i - 1, j, now, length);
		PrintLCS(b, x, i, j - 1, now, length);
	}
}

int main()
{
	char x[MAXLEN] = { "whereismybackpack" };
	char y[MAXLEN] = { "isthisbigbackpack" };
	int b[MAXLEN][MAXLEN];
	int c[MAXLEN][MAXLEN];
	int m, n;

	m = strlen(x);
	n = strlen(y);

	int length = LCSLength(x, y, m, n, c, b);
	PrintLCS(b, x, m, n, length, length);

	for (set<string>::iterator p = s.begin(); p != s.end(); p++)
		cout << (*p) << endl;
	return 0;
}
