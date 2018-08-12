#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

#define happy 1
#define unhappy 2

int hap[15000];
int iteration[101000];
int status[101000];
int save[2000];
int j = 1;

inline int square(int a) { return a*a; }

void made_easy(int k)
{
	int y;

	for(y = k*10; y < 100000; y *= 10)
	{
		if(status[y] == happy) continue;

		status[y] = happy;

		iteration[y] = iteration[k];

		hap[j++] = y;
	}
}

void GoBack(int limit)// limit is the size of "save" array
{
	int i;

	for(i = 0; i < limit; i++)
	{
		if(status[save[i]] == happy) continue;

		status[save[i]] = happy;

		iteration[save[i]] = limit - i;

		hap[j++] = save[i];

		made_easy(save[i]);
	}
}

int digitsquare_sum(int n)
{
	int sum = 0;

	for( ; n != 0; n /= 10) sum += square(n%10);

	return sum;
}

void HappySeive(int a)
{
	int t, i = 0, flag = 0;

	t = a;

	while(1)
	{
		t = digitsquare_sum(t);

		save[i++] = t;// this holds the num in the sequence and simulate it using GoBack() func

		if(t == 1 || t == a || status[t] == unhappy) break;
	}

	if(t == 1)
	{
		hap[j++] = a;

		status[a] = happy;

		iteration[a] = i + 1;

		made_easy(a); // if 10 is happy then 1000, 10000, 100000... is also happy

		GoBack(i); // if a num is happy, all num in this sequence r also happy
	}

	else status[a] = unhappy;
}

void gen_happy()
{
	int i;

	iteration[1] = 1;

	hap[0] = 1;

	status[1] = 1;

	status[2] = status[3] = status[4] = status[5] = status[6] = status[8] = status[9] = unhappy;

	for(i = 2; i <= 99987; i++)
	{

		if(status[i] == 0)
		{
			HappySeive(i);
		}
	}
}

int main()
{
	gen_happy();

	sort(hap, hap + j);

	vector<int> v(hap, hap + j);

	int L, H, k, h, i, flag = 0;

	while(scanf("%d %d",&L, &H) != EOF)
	{
		if(flag) printf("\n");

		flag = 1;

		if(L > 99987)
		{
			continue;
		}

		vector<int>::iterator low1, low2;

        low1 = lower_bound(v.begin(), v.end(), L);
        low2 = lower_bound(v.begin(), v.end(), H);

        k = int(low1 - v.begin());
        h = int(low2 - v.begin());

		if(h > 14375) h = 14375;

        while(k <= 14375 && hap[k] < L) k++;

		if(k > 14375) k = 14375;

        while(h >= 0 && hap[h] > H) h--;

		if(h < 0) h = 0;

		for(i = k; i <= h; i++)
			printf("%d %d\n",hap[i], iteration[hap[i]]);
	}
	return 0;
}
