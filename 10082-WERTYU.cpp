#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char key[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
	char input[100000];
	int i, j;

	while(gets(input))
	{
		for(i = 0; input[i] != NULL; i++)
		{
			if(!isspace(input[i]))
				for(j = 0; key[j] != NULL; j++)
				{
					if(input[i] == key[j] && j != 0 && key[j] != 'Q' && key[j] != 'A' && key[j] != 'Z' )
						input[i] = key[j-1];
				}
		}

		puts(input);
	}
	return 0;
}