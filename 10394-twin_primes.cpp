#include<stdio.h>
#include<math.h>

#define MAX 20000000
#define MAXH MAX/2
char pr[MAX/16+10];

int prime[MAXH], j;
int fir[200010], sec[200010];

void seive()
{
    int l=(int) sqrt(MAX),i,j;
    for(i=3;i<l;i +=2)
    {

        if(!(pr[i>>4]&(1<<((i>>1)&0x7))))
        {
            for(j=i*i/2;j<=MAXH;j +=i) pr[j>>3] |=(1<<(j&0x7));
        }
    }
}
int isprime(int n)
{
    if(n < 2)return 0;
    if(n == 2) return 1;
    if( n%2 == 0)return 0;
    if(!(pr[n>>4]&(1<<((n>>1)&0x7)))) return 1;
    return 0;
}

void gen_prime()
{
	int i;

	for(i = 2; i <= 20000000; i++)
	{
		if(isprime(i))
			prime[j++] = i;
	}

}

void gen_twin()
{
	int k = 0, i;

	for( i = 0; i < 1270606; i++)
	{
		if(prime[i] + 2 == prime[i+1])
		{
			fir[k] = prime[i];
			sec[k] = prime[i+1];
			k++;
		}
	}
}

int main()
{
	int n;

	seive();

	gen_prime();

	gen_twin();

	while(scanf("%d",&n) != EOF)
	{
		printf("(%d, %d)\n", fir[n-1], sec[n-1]);
	}
	return 0;
}