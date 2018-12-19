#include "roy-floyd.h"

#include <stdio.h>
#include <conio.h>
#include <iostream>




void displaymatrix(int cost[100][100], int n)

{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
			if(cost[i][j] == 9000)
				printf("   -");
			else
				printf("%4d", cost[i][j]);
           printf("\n");
    }
}


void runRoyFloyd(int cost[100][100], int n)

{

    for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
}


void printpath (int first, int last, int cost[100][100], int n)
{
    if(cost[first][last] < 9000)
    {
        printf("\n The path from %d to %d has the weight %d", first, last, cost[first][last]);
        printf("\n The minimum cost path is: %d", first);
        computepath(first,last, n, cost);
    }
    else
		printf("\n There is no path between %d to %d", first, last);
}


void computepath(int i, int j, int n, int cost[100][100])
{
    int ok = 0, k = 1;

    while(k <= n && !ok)
    {
        if(i != k && j != k)
			if(cost[i][j] == cost[i][k] + cost[k][j])
			{
				computepath(i, k, n, cost);
				computepath(k, j, n, cost);
				ok = 1;
			}
        k++;
    }
    if(!ok)
    {
        printf("%d", j);
    }
}
