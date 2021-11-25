#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int man, i = 0, l = 0, j, p = 0, k;
	double s, s1 = 0;
	struct tec
		{
		char name2[19];
		char name1[19];
		int m[4];
		} t[12];
	
	scanf("%d", &man);

	for (k = 0; k < 12; k++)//Instead of all the characters in the lines, we make spaces.
		{
		for (i = 0; i < 19; i++)
			{
			t[k].name1[i] = ' ';
			t[k].name2[i] = ' ';
			}
		}
	for (k = 0; k < man; ++k)//Input. 
		{
		i = 0;
		l = 0;
		while (l != 1)//Input surname.
			{
			t[k].name2[i] = getchar();
			if (t[k].name2 [i] == ' ')
				{
				t[k].name2 [i] = '\0';
				l = 1;
				}
			else i++;
			}

		i = 0;
		l = 0;
		while (l != 1)//Input name.
			{
			t[k].name1[i] = getchar();
			if (t[k].name1[i] == ' ')
				{
				t[k].name1[i] = '\0';
				l = 1;
				}
			else i++;
			}
		for (j = 0; j < 4; j++)//Input the course and grades in the subjects.
			scanf("%d", &t[k].m[j]);

		if (t[k].m[0] == 1)//Determination of the highest average score in the 1st year.
			{
			s = (t[k].m[1] + t[k].m[2] + t[k].m[3]) / 3;
			if (s > s1) s1 = s;
			}
		}
	
	for (k = 0; k < man; k++)//Output of surnames, first names, etc.
		{
		for (i = 0; i < 16; i++) printf("%c", t[k].name2[i]);
		for (i = 0; i < 15; i++) printf("%c", t[k].name1[i]);
		for (i = 0; i < 4; i++) printf("%5d", t[k].m[i]);
		}
	printf("\n");

	for (k = 0; k <= man; k++)//The output of the names of people from the 1st year with the highest average score.
		{
		if (t[k].m[0] == 1)
			{
			s = (t[k].m[1] + t[k].m[2] + t[k].m[3]) / 3;
			if (s == s1)
				{
				i = 0;
				while(isblank(t[k].name2[i]) == 0)
					{
					putchar(t[k].name2[i]);
					i++;
					}
				i = 0;
				while(isblank(t[k].name1[i]) == 0)
					{
					putchar(t[k].name1[i]);
					i++;
					}
				p++;
				}
			}
		}
	printf("\n");

	for (k = 0; k <= man; k++)//The output of the names of people not from the 1st year with a high average score.
		{
		if (t[k].m[0] != 1)
			{
			s = (t[k].m[1] + t[k].m[2] + t[k].m[3]) / 3;
			if (s >= s1)
				{
				i = 0;
				while(isblank(t[k].name2[i]) == 0)
					{
					putchar(t[k].name2[i]);
					i++;
					}
				i = 0;
				while(isblank(t[k].name1[i]) == 0)
					{
					putchar(t[k].name1[i]);
					i++;
					}
				}
			}
		}
	printf("\n");
	return 0;
}
