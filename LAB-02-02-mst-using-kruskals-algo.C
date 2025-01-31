/*****************************************************************************
program name :- kruskals algorithm for minimum spanning tree 
authour name :- prashant kumar mishra
roll number :- 2447021
date of creation :- 12-09-2024
date of modification :- 14-09-2024
organization :- National institute of technology patna
******************************************************************************/

#include <stdio.h>
//#include<conio.h
//variable declaration 
int i,j;
int ver,edge;
int check;
int temp;
int min_src;
int min_des;
int min_wgt;c
int mst_wt;

//array and matrix declarations
int visited[100];
int adj[100][100];
int mst_adj[100][100];


int main() {
    
    mst_wt = 0;
    check = 0;
    //clrscr();

    /* getting input for the number of vertices */
    printf("\nEnter the number of vertices of the graph: ");
    scanf("%d", &ver);
    printf("\n");

    /* Initialize adjacency matrices with node labels */
    for (i = 0; i <= ver; ++i) {
	    for (j = 0; j <= ver; ++j) {
		    if(i==0 && j==0){
		    	adj[i][j]=32;
			    mst_adj[i][j]=32;
		    }
    		else if(i==0 && j!=0){
    			adj[i][j]=j+96;
    			mst_adj[i][j]=j+96;
    		}
    		else if(i!=0 && j==0){
    			adj[i][j]=i+96;
    			mst_adj[i][j]=i+96;
    		}
    		else{
    			adj[i][j]=0;
    			mst_adj[i][j]=0;
    		}

	    }
    }

    /* Taking input for the weighted adjacency matrix */
    printf("\n\nEnter the adjacency matrix of the weighted undirected graph:\n");
    for (i = 1; i <= ver; ++i) {
    	for (j = i; j <= ver ; ++j) {
    	    if (i != j) {
    		printf("\n Enter the weight of edge between node %c and node %c \n",i+96,j+96);
    		printf("(enter 0 if there is no edge)\n\t\t: ");
    
    		scanf("%d", &temp);
    		adj[i][j] = temp;
    		adj[j][i] = temp;
    	    }
    	}
    }
    
    //starting krushkals algo
    for(i=1;i<=ver;i++){
        visited[i]=0;
    }
    while(check<ver-1){//algo loop
        min_src=-1;
        min_des=-1;
        min_wgt=9999;
        for(i=1;i<=ver;++i){//finfding least weight edge
            for(j=1;j<=ver;++j){
                if(i != j && adj[i][j] < min_wgt && adj[i][j]!=0) {
                    if((visited[i] && !visited[j]) || (!visited[i] && visited[j]) || check == 0) {
                        min_src = i;
                        min_des = j;
                        min_wgt = adj[i][j];
                    }
                }
            }
        }
        if(min_src != -1 && min_des != -1){//adding edge to mst
            if(!visited[min_src] && !visited[min_des]){
                visited[min_src]=1;
                visited[min_des]=1;
                
            }else if(visited[min_src] && !visited[min_des]){
                visited[min_des]=1;
            }else if (!visited[min_src] && visited[min_des]){
                visited[min_src]=1;
            }
            mst_adj[min_src][min_des]=min_wgt;
            mst_adj[min_des][min_src]=min_wgt;
            check=check+1;
            mst_wt=mst_wt+min_wgt;
            adj[min_src][min_des]=9999;
            adj[min_des][min_src]=9999;
        }
    }
    
    //printing mst matrix 
    printf("\n\nthe adjacency matrix of the mst created :\n");
    for (i = 0; i <= ver; ++i) {
    	for (j = 0; j <= ver; ++j) {
    	    if(i==0 && j==0){
		    	printf("%c ",mst_adj[i][j]);
		    }
    		else if(i==0 && j!=0){
    			printf("%c ",mst_adj[i][j]);
    		}
    		else if(i!=0 && j==0){
    			printf("%c ",mst_adj[i][j]);
    		}
    		else{
    			printf("%d ",mst_adj[i][j]);
    		}
    	}
    	printf("\n");
    }
    printf("\n the weight of mst is : %d",mst_wt);
    //getch();

}
