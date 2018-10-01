#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, a1, a2, a3;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1]; // uzaklik, node
    for(int i=0;i<m;i++){
        cin>>a1>>a2>>a3;
        adj[a1].push_back({a3, a2});
        adj[a2].push_back({a3, a1});
    }

    bool processed[n+1];
    pair<int,int> distance[n+1]; // uzaklik, onceki node
    priority_queue<pair<int,int>> q;
    q.push({0, 1});
    for (int i = 1; i <= n; i++){
        distance[i] = {INT_MAX/2, -1};
        processed[i] = false;
    }

    distance[1] = {0, 0};
    q.push({0, 1});
    while (!q.empty()) {
        int a = q.top().second; 
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.second, w = u.first;
            distance[b] = {min(distance[b].first, max(w, distance[a].first)), a};
            q.push({-(distance[b].first),b});
        }
    }
    if(distance[n].first==INT_MAX/2){
        cout<<"NO PATH EXISTS";
        return 0;
    }
    cout<<distance[n].first;
}