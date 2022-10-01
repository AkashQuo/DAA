//Floyd-Warshall Algorithm

#include <stdio.h>
#include<limits.h>

#define INF 9999
#define SIZE 10
#define NIL -1	//-1 because 0 is a vertex number

void floyd_warshall(int d[][SIZE], int p[][SIZE], int
n)
{
	int i, j, k, temp;

	for (k=0; k<n; k++)
	{
		for (i=0; i<n; i++)
			if (d[i][k] < INF)
				for (j=0; j<n; j++)
				{
					temp = d[i][k] + d[k][j];
					if (temp < d[i][j])
					{
						d[i][j] = temp;
						p[i][j] = p[k][j];
					}
				}
	}
}

void print_all_pairs_shortest_path(int p[][SIZE], int i, int j)
{
	if(i == j)
		printf("%d\t", i);
	else if(p[i][j] == NIL)
		printf("No path from %d to %d exists.", i, j);
	else
	{
		print_all_pairs_shortest_path(p, i, p[i][j]);
		printf("%d\t", j);
	}
}

void transitive_closure(int d[][SIZE], int t[][SIZE],
int n)
{
	int i, j, k;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if((i == j) || (d[i][j] < INF))
				t[i][j] = 1;
			else
				t[i][j] = 0;

	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				t[i][j] = t[i][j] || (t[i][k] && t[k][j]);

	printf("\n\nThe transitive closure of the input graph is as follows:\n\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%8d", t[i][j]);
		printf("\n");
	}
}

int main()
{
	int d[SIZE][SIZE], t[SIZE][SIZE], p[SIZE][SIZE], n,i, j, w, k=1;
		/* d[i][j] stores adjacnecy matrix, p[i][j] stores parent of edges*/

//	clrscr();
	printf("\n\nEnter the no. of vertices: ");
	scanf("%d", &n);

	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
			p[i][j] = NIL;


	printf("\n\nEnter the vertices that are connecterd with wts:");
	printf("\n(Vertex numbering starts from 0, Enter -1 to terminate.)\n");
	while (1)
	{
		printf("\nEgde %d with its weight: ",t);
		scanf("%d\t", &i);
		if (i == (-1))
			break;
		scanf("%d %d",&j, &w);
		d[i][j] = w;
		if(i != j)
			p[i][j] = i;
		k++;
	}

	floyd_warshall(d, p, n);
	printf("\n\nThe matrix of shortest path weights computed by Floyd-Warshall algo. is as follows:\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			printf("%8d", d[i][j]);
		printf("\n");
	}

	printf("\n\nAll-pairs shortest paths constructed by Floyd-Warshall algo. are as follows:\n");
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
		{
			printf("\nPath from %d to %d: ", i, j);
			print_all_pairs_shortest_path(p, i, j);
		}
	transitive_closure(d, t, n);

	return 0;
}
