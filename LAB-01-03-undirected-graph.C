/*****************************************************************************
program name :- undirected graph
authour name :- prashant kumar mishra
roll number :- 2447021
date of creation :- 28-09-2024
date of modification :- 12-09-2024
organization :- National institute of technology patna
******************************************************************************/

#include <stdio.h>
#include <conio.h>

int main() {
    int i, j ,row,col;
    int ver = 10;
    int edge = 12;
    int adj[11][11];
    char edges[12][2] = {
	{'A','J'},
	{'B','J'},
	{'D','C'},
	{'D','E'},
	{'G','F'},
	{'H','A'},
	{'I','H'},
	{'I','G'},
	{'I','F'},
	{'J','I'},
	{'J','F'},
	{'J','D'}
    };

    //clrscr();

    // Initialize the adjacency matrix
    for (i = 0; i <= ver; ++i) {
	for (j = 0; j <= ver; ++j) {
	    if (i == 0 && j == 0) {
		adj[i][j] = 32; // 32 is ASCII value of space
	    } else if (i == 0 && j != 0) {
		adj[i][j] = 64 + j; // Initializing first row for printing
	    } else if (j == 0 && i != 0) {
		adj[i][j] = 64 + i; // Initializing first column for printing
	    } else {
		adj[i][j] = 0; // Initializing the edges values
	    }
	}
    }


    printf("\nthe edges of the network are :\n");
    for(i=0;i<edge;++i){
	printf("\n %c  ----->  %c",edges[i][0],edges[i][1]);
    }
    printf("\npress any key to continue : ");
    scanf("%d");

    /* adding edges of network into matrix representation */
     for(i=0;i<edge;++i){
	row=edges[i][0];
	col=edges[i][1];
	adj[row-64][col-64]=1;
    }

    printf("\nthe matrix representation for this representation is :\n") ;


    for (i = 0; i <= ver; ++i) {
	for (j = 0; j <= ver; ++j) {
	    if (i == 0 && j == 0) {
		printf("%c  ", adj[i][j]);
	    } else if (i == 0 && j != 0) {
		printf("%c  ", adj[i][j]); // Printing header row
	    } else if (j == 0 && i != 0) {
		printf("%c  ", adj[i][j]); // Printing header column
	    } else {
		printf("%d  ", adj[i][j]); // Printing matrix values
	    }
	}
	printf("\n\n");
    }
    getch();
    return 0;
}


