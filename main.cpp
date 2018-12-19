#include <stdio.h>

#include <iostream>
#include <conio.h>
#include "roy-floyd.h"

int main()

{
    char ch;
    int x, y, n, m;
	int cost[100][100];

	int i, j, a, b, c;

	FILE *f;
	f = fopen("roy_in.txt", "rt");
    if(f)
		printf("The file has been successfuly opened! ");
    else
		printf("Error opening file! ");

	printf("\n");
    fscanf(f, "%d", &n);
    fscanf(f, "%d\n", &m);

    for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
		{
			if(i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = 9000;
		}

    for(i = 1; i <= m; i++)
    {
		fscanf(f,"%d%d%d\n", &a, &b, &c);
		cost[a][b] = c;
    }

    fclose(f);

    printf("\n The weight matrix is:\n");
    displaymatrix(cost, n);
    runRoyFloyd(cost, n);

    printf("\n The minimum cost matrix is:\n");
    displaymatrix(cost, n);

    do
    {
        printf("\n\nDetermine which is the minimum cost path between two nodes of the graph\n");
        printf("x= ");
        scanf("%d", &x);

		printf("y= ");
        scanf("%d", &y);
        printpath(x, y, cost, n);

		printf("\n\n\n Do you want to find a path between other nodes from the graph? <y/n>");
        ch = getch();
    }
    while(ch == 'y' ||ch == 'Y');

    getch();
    return 0;
}
