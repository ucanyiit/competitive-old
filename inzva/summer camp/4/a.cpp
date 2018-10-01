#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    int a1,a2,a3; 
    int mat[n+1][n+1];
    vector<pair<int, int>> adj[n+1]; // w, to
    for(int i=0;i<m;i++){
        cin>>a1>>a2>>a3;
        adj[a1].push_back({a3,a2});
        adj[a2].push_back({a3,a1});
        mat[a1][a2]=a3;
        mat[a2][a1]=a3;
    }

    bool processed[n+1];
    pair<int,int> distance[n+1]; // uzaklik, onceki node
    priority_queue<pair<pair<int,int>,pair<int,int>>> q;
    for (int i = 1; i <= n; i++){
        distance[i] = {INT_MAX/2, -1};
        processed[i] = false;
    }

    int sum=0;
    distance[1] = {0, 0};
    q.push({{0, 0}, {1, 0}});
    while (!q.empty()) {
        
        int a = q.top().second.first; 
        int c = q.top().second.second; 
        q.pop();                

        if (processed[a]) continue;
        if(a!=1) sum+=mat[c][a];
        processed[a] = true;

        for (auto u : adj[a]) {
            int b = u.second, w = u.first;
            distance[b] = {min(distance[b].first, max(w, distance[a].first)), a};
            q.push({{-(w),-(w+a+b)},{b,a}});
        }

    }
    cout<<sum;
    
}