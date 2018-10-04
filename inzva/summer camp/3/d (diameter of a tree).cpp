#include <bits/stdc++.h>

using namespace std;

/*  easy  */

/*  this question might seem harder, but it's actually very easy. i have a lot of unnecessary code here.
    all i have done is bfs twice from a random node and finding the farthest node from starting node. and then i got the diameter ( distance between farthests 2 points ) of the tree.
*/

int main(){
    int n, k, a1, a2;
    cin>>n>>k;
    vector<int> adj[n+1];
    bool stations[n+1];
    for(int i=0;i<n-1;i++){
        cin>>a1>>a2;
        adj[a1].push_back(a2);
        adj[a2].push_back(a1);
    }    
    for(int i=0;i<k;i++){
        cin>>a1;
        stations[a1]=true;
    }

    queue<int> q;
    bool visited[n+1];
    int distance[n+1];
    for(int i=0;i<=n;i++){
        visited[i]=false;
    }
    visited[1] = true;
    distance[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int s = q.front(); 
        q.pop();
        // process node s
        for (auto u : adj[s]) {
            if (visited[u]) continue;            
            q.push(u);
            visited[u] = true;
            distance[u] = distance[s]+1;
        }
    }
    
    pair<int,int> max={1,0};
    for(int i=1;i<=n;i++){
        if(max.second < distance[i] && stations[i]){
            max.first=i;
            max.second=distance[i];
        }
    }    

    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    visited[max.first] = true;
    distance[max.first] = 0;
    q.push(max.first);
    
    while (!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s]+1;
            q.push(u);
        }
    }
    
    max={0,0};
    for(int i=1;i<=n;i++){
        if(max.second < distance[i] && stations[i]){
            max.first=i;
            max.second=distance[i];
        }
    }  

    cout<<max.second;
}