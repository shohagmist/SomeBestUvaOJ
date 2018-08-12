#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int len;
char y[100000];

bool div_4()
{
	int sum = 0;

	sum = 10*(y[len-2] - 48) + (y[len-1] - 48);

	if(sum % 4 == 0) return true;

	return false;
}

bool div_5()
{
    if(y[len-1] == '0' || y[len-1] == '5') return true;

	return false;
}

bool div_3()
{
	int i, sum = 0, t;

	for(i = 0; y[i] != NULL; i++)
		sum += (y[i] - 48);

    t = sum;

    while( t/10 != 0 )
    {
        sum = 0;

        for( ; t != 0; t /= 10) sum += t%10;

        t = sum;
    }

	if(t % 3 == 0) return true;

	return false;
}

bool div_11()
{
	int sum1 = 0, i;

	for(i = 0; i < len; i += 2) sum1 += y[i] - 48;

	for(i = 1; i < len; i += 2) sum1 -= y[i] - 48;

	if(sum1 % 11 == 0) return true;

	return false;
}

bool div_15()
{
	if(div_5() && div_3()) return true;

	return false;
}

bool div_55()
{
	if( div_5() && div_11()) return true;

	return false;
}

bool div_100()
{
	if(y[len-2] == '0' && y[len-1] == '0') return true;

	return false;
}

bool div_400()
{
    int s;
	if(div_100())
	{
	    s = 10*(y[len - 4] - 48) + (y[len - 3] - 48);

	    if(s%4 == 0) return true;

	    else return false;
	}

	return false;
}

bool Leap_year()
{
	if(!div_4()) return false;

	else if(!div_100()) return true;

	else if(!div_400()) return false;

	else return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	bool f1, f2, line = true;


	while(gets(y))
	{
		if(!line) printf("\n");

		len = strlen(y);

		f1 = f2 = true;

		if(Leap_year())
		{
			f1 = false;

			printf("This is leap year.\n");
		}

		if(div_15())
		{
			printf("This is huluculu festival year.\n");

			f2 = false;
		}

		if(!f1 && div_55()) printf("This is bulukulu festival year.\n");

		if(f1 && f2) printf("This is an ordinary year.\n");

		line = false;
	}
	return 0;
}
