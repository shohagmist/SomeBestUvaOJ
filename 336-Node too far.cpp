#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;

#define white 1
#define gray 2
#define black 3

#define INF pow(2, 30)
#define NIL -1000

#define MAX 110

int adj[MAX][MAX];
int color[MAX];
int parent[MAX];
int dist[MAX];
int vertex[MAX];
int num_e, iter, num_v, src;

queue<int> q;


int SeqSearch(int low, int high, int key)
{
    int i = low;
    vertex[high + 1] = key;

    while(vertex[i] != key) i++;

    if(i > high) return -1;

    else return i;
}

void build_adj_mat()
{
	int i, u, v, j, a, b;

	iter = 0;

	for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++) adj[i][j] = 0;

	for(i = 0; i < MAX; i++) vertex[i] = NIL;

	for(i = 0; i < num_e; i++)
	{
		scanf("%d %d",&u, &v);

		a = SeqSearch(0, iter - 1, u);

        if(a == -1)
        {
            vertex[iter] = u;

            a = iter++;
        }

        b = SeqSearch(0, iter - 1, v);

        if(b == -1)
        {
            vertex[iter] = v;

            b = iter++;
        }

        adj[a][b] = 1;
		adj[b][a] = 1;
	}
}

void BFS(int source)
{
    int s = SeqSearch(0, iter - 1, source);
    src = s;
    int i;
	for(i = 0; i < num_v; i++)
	{
        color[i] = white;
        dist[i] = INF;
        parent[i] = NIL;
	}

	color[s] = gray;
	dist[s] = 0;
	parent[s] = NIL;

	q.push(s);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(i=0; i < num_v; i++)
		{
			if(adj[u][i] == 1)
			{
				if(color[i] == white)
				{
					color[i] = gray;
					dist[i] = dist[u] + 1;
                    parent[i] = u;
					q.push(i);
				}
			}
		}

		color[u] = black;
	}
}


int main()
{
	freopen("bfs.txt","r",stdin);

	int ttl, source, res, j, cas = 1;

	scanf("%d",&num_e);

	while(num_e != 0)
	{

	    build_adj_mat();

	    num_v = iter;

	    scanf("%d %d",&source, &ttl);

	    while(source != 0 || ttl != 0)
	    {
			res = 0;

	        BFS(source);

	        for(j = 0; j < num_v; j++)
	        {
	            if(j != src && dist[j] > ttl) res++;
	        }

	        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cas++, res, source, ttl);

	        scanf("%d %d",&source, &ttl);
	    }

	    scanf("%d",&num_e);
	}

	return 0;
}
