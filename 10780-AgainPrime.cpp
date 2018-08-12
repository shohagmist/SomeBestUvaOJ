#include<stdio.h>
#include<math.h>

#define MAX 10000
#define MAXH MAX/2
#define MAX_RANGE 5000
char pr[MAX/16 + 10];
int prime[5000], j;
struct factlist
{
    int num;
    int freq;
};
int listsize;
factlist list[100];


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

    for(n = 3; n <= (int) sqrt(MAX_RANGE)+ 50; n += 2)
        if(!(pr[n>>4]&(1<<((n>>1)&0x7)))) prime[j++] = n;
}

void initialize()
{
	int i;
	for(i = 0; i < 100; i++)
		list[i].freq = 0;
}

void Find_Prime_Factor(int n)
{
    int sqrtN = (int) sqrt(n);
    int i;
    listsize = 0;
	initialize();

    for(i = 0; prime[i] <= sqrtN; i++)
    {
        if(n%prime[i] == 0)
        {
            list[listsize].num = prime[i];
            do {

                n /= prime[i];
                list[listsize].freq++;

            }while(n%prime[i] == 0);

            sqrtN = (int) sqrt(n);
			 listsize++;
        }
    }

    if(n > 1)
    {
        list[listsize].num = n;
        list[listsize].freq++;
        listsize++;
    }
}


int frequency(int n, int p)
{
    int sum = 0, k, i;
    double t;

    t = (double)log10(n)/(double)log10(p);
    k = (int) t;

    i = 1;

    while(i <= k)
    {
        sum += floor(n / pow(p, i));
        i++;
    }

    return sum;
}

int main()
{
    int n, p, t, i, m, a, min;
    int flag;
    seive();
    gen_prime();

    scanf("%d",&t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d %d",&m, &n);
        Find_Prime_Factor(m);

		flag = 0;

        for(a = 0; a < listsize; a++)
            if(list[a].num > n)
            {
                flag = 1;
                break;
            }

        if(flag == 0)
        {
            min = 100000;
            for(a = 0; a < listsize; a++)
            {
                p = frequency(n, list[a].num);

                p /= list[a].freq;

                if(min > p) min = p;
            }

            printf("Case %d:\n%d\n", i, min);
        }

        else printf("Case %d:\nImpossible to divide\n", i);
    }
    return 0;
}
