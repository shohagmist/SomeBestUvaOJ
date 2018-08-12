#include<stdio.h>
#include<math.h>
#define MAX 1000000
#define MAXH MAX/2
char pr[MAX/16+10];

int digitprm[32124];

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
    if(n<2)return 0;
    if(n==2) return 1;
    if(n%2==0)return 0;
    if(!(pr[n>>4]&(1<<((n>>1)&0x7)))) return 1;
    return 0;
}
int digitprme()
{

    int n=1000000,count=0,i,sm,j=0,z;
    for(i=2;i<=n;i++)
    {
        sm=0;
        z=i;
        if(isprime(i))
        {
            while(i!=0)
            {
                sm=sm+i%10;
                i/=10;
            }
            if(isprime(sm))
            {
                digitprm[j]=z;
                j++;
            }
        }
        i=z;

    }
return 0;
}
int binarySearch(int sortedArray[], int first, int last, int key)
{

    while (first <= last) {
        int mid = (first + last) / 2;

        if (key > sortedArray[mid])
            first = mid + 1;

        else if (key < sortedArray[mid])
            last = mid - 1;

        else
        {
            while(digitprm[mid]==digitprm[mid-1])
                mid--;
            return mid;
        }
    }
    return first;
}
int main()
{

    int i,h,j,k,l,p;
    seive();
    digitprme();
    scanf("%d",&l);
    while(l--)
    {
        scanf("%d %d",&i,&j);

        if(j>999983)
            j=999983;

        if(i>999983)
        {
            printf("0\n");
            continue;
        }

        k=binarySearch(digitprm,0,30123,i);
        h=binarySearch(digitprm,0,30123,j);

        k=k-2;
        h=h+2;

        if(k<0)
            k=0;

        if(h>30122)
            h=30122;

        while(i>digitprm[k])
			k++;

        while(j<digitprm[h])
            h--;

        p=h-k+1;

        printf("%d\n",p);
    }

    return 0;
}
