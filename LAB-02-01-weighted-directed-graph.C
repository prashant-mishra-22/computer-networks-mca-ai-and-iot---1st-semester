/*****************************************************************************
program name :- weighted directed graph
authour name :- prashant kumar mishra
roll number :- 2447021
date of creation :- 4-09-2024
date of modification :- 12-09-2024
organization :- National institute of technology patna
******************************************************************************/

#include <stdio.h>
#include <conio.h>

void main() {
    int i, j ,row,col;
    int ver = 8;
    int edge = 15;
    int adj[11][11];
    int edges[15][3] = {
	{1,3,5},
	{1,2,9},
	{2,1,3},
	{2,4,18},
	{3,4,12},
	{4,2,2},
	{4,8,8},
	{5,4,9},
	{5,8,3},
	{5,7,5},
	{5,6,2},
	{6,7,1},
	{7,5,4},
	{7,8,6},
	{8,5,3}
    };

    clrscr();

    // Initialize the adjacency matrix
    for (i = 0; i <= ver; ++i) {
	for (j = 0; j <= ver; ++j) {
	    if (i == 0 && j == 0) {
		adj[i][j] = 32; // 32 is ASCII value of space
	    } else if (i == 0 && j != 0) {
		adj[i][j] = j; // Initializing first row for printing
	    } else if (j == 0 && i != 0) {
		adj[i][j] = i; // Initializing first column for printing
	    } else {
		adj[i][j] = 0; // Initializing the edges values
	    }
	}
    }


    printf("\nthe edges of the network are :\n");
    printf("\nsource\t------>\tdestination\t:     weight\n");


    for(i=0;i<edge;++i){
	printf("\n%d\t------>\t\t%d\t:\t%d",edges[i][0],edges[i][1],edges[i][2]);
    }
    printf("\n\nenter any number to continue : ");
    scanf("%d");

    /* adding edges of network into matrix representation */
     for(i=0;i<edge;++i){
	row=edges[i][0];
	col=edges[i][1];
	adj[row][col]=edges[i][2];
    }

    printf("\nthe matrix representation for this representation is :\n") ;


    for (i = 0; i <= ver; ++i) {
	for (j = 0; j <= ver; ++j) {
	    if (i == 0 && j == 0) {
		printf("%c  ", adj[i][j]);
	    } else if (i == 0 && j != 0) {
		printf("%d  ", adj[i][j]); // Printing header row
	    } else if (j == 0 && i != 0) {
		printf("%d  ", adj[i][j]); // Printing header column
	    } else {
		printf("%d  ", adj[i][j]); // Printing weights values
	    }
	}
	printf("\n\n");
    }
    getch();
}


