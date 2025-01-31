
#include <cstdio>
#include <climits>
#include <iomanip>
#include <iostream>
#define MAX_NODES 10
using namespace std;
class graph{
	public :
		int edges;
		int vertices ;
		int nexthop[MAX_NODES][MAX_NODES];
		int distance[MAX_NODES][MAX_NODES];
		int adjmat[MAX_NODES][MAX_NODES];
		void input(int v,int e)
		{
			edges =e;
			vertices =v;
			for(int i=0;i<v;i++)
			{
				for(int j=0;j<v;j++)
				{
					adjmat[i][j]=0;
				}
			}
			int src,dst,weg;
			for(int i=0;i<e;i++)
			{
				cout<<"enter edge "<<i+1<<" : \n";
				cout<<"source : ";
				cin>>src;
				cout<<"destination : ";
				cin>>dst;
				cout<<"weight : ";
				cin>>weg;
				adjmat[src-1][dst-1]=weg;
				adjmat[dst-1][src-1]=weg;
			}
		}
		void display()
		{
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					cout<<setw(5)<<adjmat[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
		void dvr()
		{
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					if(i==j)
					{
						distance[i][j]=0;
					}
					else if(adjmat[i][j]==0)
					{
						distance[i][j]=INT_MAX/2;
					}
					else
					{
						distance[i][j]=adjmat[i][j];
					}
					nexthop[i][j]=-1;
				}
			}
			cout<<"initial distance matrix \n\n";
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					if(distance[i][j]==INT_MAX/2)
					{
						cout<<setw(5)<<right<<"INF";
					}
					else
					{
						cout<<setw(5)<<distance[i][j];
					}
				}
				cout<<"\n";
			}
			
			bool flag;
			do{
				flag =false;
				for(int i=0;i<vertices;i++)
				{
					for(int j=0;j<vertices;j++)
					{
						for(int k=0;k<vertices;k++)
						{
							if(distance[i][j]>distance[i][k]+distance[k][j])
							{
								distance[i][j]=distance[i][k]+distance[k][j];
								distance[j][i]=distance[i][k]+distance[k][j];
								nexthop[i][j]=nexthop[j][i]=k;
								flag =true;
							}
						}
					}
				}
			}
			while(flag);
			cout<<"final distance matrix \n\n";
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					cout<<setw(5)<<distance[i][j];
				}
				cout<<"\n";
			}
			for(int i=0;i<vertices;i++)
			{
				cout<<"routing table for router "<<i+1<<" : \n";
				cout<<"dest router \t via \t distance \n";
				for(int j=0;j<vertices;j++)
				{
					if(i==j)
						continue;
					cout<<(j+1)<<"\t \t";
					if(nexthop[i][j]==-1)
						cout<<"-\t ";
					else
						cout<<nexthop[i][j]<<"\t";
					cout<<distance[i][j]<<"\n";
				}
			
			}
		}
};
int main()
{
	int v,e;
	graph g;
	cout<<"enter number of vertices and edges \n";
	cin>>v>>e;
	g.input(v,e);
	cout<<"graph is \n\n";
	g.display();
	g.dvr();
}
