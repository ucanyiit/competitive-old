#include <bits/stdc++.h>

using namespace std;

/*  easy  */

/*  as the name suggests it can be solved easily with floyd-warshall */

int main(){
    int n, m, a1, a2, a3;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a1>>a2>>a3;
        adj[a1][a2]=a3;
    }
    int distance[n][n];
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            if(i==j) distance[i][j]=0;
            else if (adj[i][j]) distance[i][j] = adj[i][j];
            else distance[i][j] = 10000000;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distance[i][j] = min(distance[i][j],
                distance[i][k]+distance[k][j]);
            }
        }
    }
    int q;
    cin>>q;
    vector<int> tra[q];
    for(int i=0;i<q;i++){
        cin>>a1>>a2;
        if(distance[a1][a2]>=10000000){
            cout<<-1<<endl;
            continue;
        }
        cout<<distance[a1][a2]<<endl;
    }


}