
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int vertices;
    cout<<"enter number of vertices : ";
    cin>>vertices;
    cout<<"\n";
    
    int num;
    cout<<"enter number of routing table recieved : ";
    cin>>num;
    cout<<"\n";
    
    int adj[num+1][vertices];
    for(int i=0;i<=num;i++){
        for(int j=0;j<vertices;j++){
            if(i==j) adj[i][j]=0;
            else adj[i][j]=INT_MAX;
        }
    }
    
    cout<<"enter initial routing table for c \n";
    for(int i=0;i<vertices;i++){
        
        cout<<"enter weight between c and "<<char(97+i);
    }
    return 0;
}
