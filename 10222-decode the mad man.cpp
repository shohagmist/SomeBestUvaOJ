#include<stdio.h>
#include<ctype.h>
#include<string.h>


int main()
{
	char arr[] = {"qwertyuiop[]asdfghjkl;'\\zxcvbnm,./"};

	char input[100];

	int i, j, flag,len;

	gets(input);

	len = strlen(input);

	for(i=0;i<len;i++)
	{
		if(isupper(input[i]))
			input[i] = tolower(input[i]);

		flag = 0;

		for(j = 0; j< 35; j++)
		{
			if(arr[j] == input[i])
			{
				flag = 1;
				break;
			}
		}

		if(flag && j != 0 && j != 1)
		{
			input[i] = arr[j-2];
		}

		if(j == 0)
			input[i] = '[';

		if(j == 1)
			input[i] = ']';

	}

	puts(input);

	
	return 0;
}
