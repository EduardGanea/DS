#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <iostream>

#define Infinit 90000

void initialcost (int cost[100][100], int &n, int &m);

void displaymatrix (int cost[100][100], int n);

void runRoyFloyd (int cost[100][100], int n);

void printpath (int first, int last, int cost[100][100], int n);

void computepath (int node1, int node2, int n, int cost[100][100]);

#endif;
