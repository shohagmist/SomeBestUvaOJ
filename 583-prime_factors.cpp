#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

#define MAX 60000
#define MAXH MAX/2
#define MAX_RANGE 2147483647
char pr[MAX/16 + 10];
int prime[5000], j;
int list[100], listsize;


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
void gen_prime()
{
    int n;
    j = 0;

    prime[j++] = 2;

    for(n = 3; n <= (int) sqrt(MAX_RANGE)+200; n += 2)
        if(!(pr[n>>4]&(1<<((n>>1)&0x7)))) prime[j++] = n;
}

void Find_Prime_Factor(int n)
{
    int sqrtN = (int) sqrt(n);
    int i;
    listsize = 0;

    for(i = 0; prime[i] <= sqrtN; i++)
    {
        if(n%prime[i] == 0)
        {
            do {

                n /= prime[i];
                list[listsize++] = prime[i];

            }while(n%prime[i] == 0);

            sqrtN = (int) sqrt(n);
        }
    }

    if(n > 1) list[listsize++] = n;
}



int main()
{
    seive();
    gen_prime();

    int n;

    scanf("%d",&n);

    while(n != 0)
    {
        printf("%d = ",n);
        if(n < 0)
        {
            n *= (-1);
            printf("-1 x ");
        }

        Find_Prime_Factor(n);

        for(int i = 0; i < listsize; i++)
        {
            printf("%d",list[i]);

            if(i < listsize - 1) printf(" x ");
        }

        printf("\n");

        scanf("%d",&n);
    }
	return 0;
}
