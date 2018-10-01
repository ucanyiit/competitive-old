#include <bits/stdc++.h>

using namespace std;
    

int main(){
    int n, start;
    cin>>n;
    
    vector<int> adj[1000001];
    set<int> nodes;
    int sizes[1000001];
    bool processed[1000001];
    vector<int> starts;
    for(int i=0;i<1000001;i++){
        processed[i]=false;
        sizes[i]=0;
    }
    while(n--){
        int now=0, last=0, k;
        cin>>k;
        while(k--){
            last=now;
            cin>>now;
            nodes.insert(now);
            if(last!=0){
                adj[last].push_back(now);
                sizes[now]=sizes[now]+1;
            }
        }
    }

    for(auto x: nodes){
        if(sizes[x]==0) starts.push_back(x); 
    }
    priority_queue<int> q; // node
    for(auto x: starts){
        q.push(-x);
    }

    while(!q.empty()){
        int a = -(q.top()); 
        q.pop(); 
        if (processed[a]) continue;
        cout<<a<<" ";
        processed[a]=true;
        
        for (auto u : adj[a]) {
            sizes[u]=sizes[u]-1;
            if(sizes[u]==0) q.push(-u);
        }

    }
}