#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

#define MAX 1000000
#define MAXH MAX/2
char pr[MAX/16+10];

int prime[78500];
bool primeStatus[1000000];
int primeSize;
vector<int> circular;

class mycmp
{
	bool reverse;

public:
	mycmp(const bool& revparam = false)
	{
		reverse = revparam;
	}

	bool operator () (const int& p, const int& q)
	{
		if(reverse) return (p > q);

		else return (p < q);
	}
};

typedef priority_queue< int, vector<int>, mycmp > mypq;

mypq q(true);


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

void GenPrime()
{
	int n = 3;

	primeSize = 0;

	prime[primeSize++] = 2;

	primeStatus[1] = true;

	for( ; n <= 1000000; n += 2)
		if(!(pr[n>>4]&(1<<((n>>1)&0x7)))) prime[primeSize++] = n, primeStatus[n - 1] = true;

}

int BinarySearch(int low, int high, int key)
{
	int mid;

	while(low <= high)
	{
		mid = (low + high) / 2;

		if(prime[mid] > key) high = mid - 1;

		else if(prime[mid] < key) low = mid + 1;

		else return mid;
	}

	return -1;
}

void GenCircular()
{
	int k, digit, b, t, factor, i;

	int temp[15], tempSize;

	bool flag;

	for(k = 25; k < primeSize; k++)
	{
		if(primeStatus[prime[k] - 1] == true)
		{
			tempSize = 0;
			flag = true;

			digit = (int) ceil(log10(prime[k]));

			factor = pow(10, digit - 1);

			b = prime[k];

			while(--digit)
			{
				t = b%10;

				b /= 10;

				b += t*factor;

				temp[tempSize++] = b;

				if(BinarySearch(0, primeSize - 1, b) < 0)
				{
					flag = false;
					break;
				}

			}

			if(flag)
			{
				q.push(prime[k]);

				for(i = 0; i < tempSize; i++)
				{
					q.push(temp[i]);
					primeStatus[temp[i] - 1] = false;
				}
			}
		}
	}
}

int SeqSearch(int low, int high, int key)
{
	int i = low;

	while(circular[i] < key) i++;

	return i;
}


int main()
{
	int x, y, freq, k, h;
	vector<int>::iterator it1, it2;

    seive();
	GenPrime();

	GenCircular();

	while(!q.empty())
	{
		circular.push_back(q.top());
		q.pop();
	}

	scanf("%d", &x);

	while(x > 0)
	{
		scanf("%d", &y);

		it1 = lower_bound(circular.begin(), circular.end(), x);
		it2 = lower_bound(circular.begin(), circular.end(), y);

		k = (int)(it1 - circular.begin());
		h = (int)(it2 - circular.begin());

		if(h > 41) h = 41;

		while(circular[h] > y) h--;

		if(h < 0) h = 0;

		if(y < circular[h]) freq = 0;

		else freq = h - k + 1;


		if(freq == 0) printf("No Circular Primes.\n");

		else if(freq == 1) printf("1 Circular Prime.\n");

		else printf("%d Circular Primes.\n", freq);

		scanf("%d", &x);
	}


    return 0;
}
