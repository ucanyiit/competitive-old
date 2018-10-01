#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    int a1,a2;
    while(t--){
        vector<pair<int,int>> adj[101];
        bool forbid[101];
        for(int i=1;i<101;i++){
            forbid[i]=false;
        }
        int laddernum;
        cin>>laddernum;
        for(int i=0;i<laddernum;i++){
            cin>>a1>>a2;
            adj[a1].push_back({0, a1});
            for(int j=1;j<7;j++){
                if(a1-j>0) adj[a1-j].push_back({1,a2});
            }
            forbid[a1]=true;
        }
        int snakenum;
        cin>>snakenum;
        for(int i=0;i<snakenum;i++){
            cin>>a1>>a2;
            adj[a1].push_back({0, a1});
            for(int j=1;j<7;j++){
                if(a1-j>0) adj[a1-j].push_back({1,a2});
            }
            forbid[a1]=true;
        }


        for(int i=1;i<101;i++){
            if(!forbid[i]){
                for(int j=1;j<7;j++){
                    if(!forbid[i+j] && i+j<101) adj[i].push_back({1, i+j});
                }
            }
        }

        priority_queue<pair<int,int>> q;
        bool processed[101];
        int distance[101];
        for (int i = 1; i <= 100; i++){ 
            distance[i] = INT_MAX; 
            processed[i] = false;
        }

        distance[1] = 0;
        q.push({0, 1});
        
        while (!q.empty()) {
            int a = q.top().second; 
            q.pop();
            if (processed[a]) continue;
            processed[a] = true;
            for (auto u : adj[a]) {
                int b = u.second, w = u.first;
                if (distance[a]+w < distance[b]) {
                    distance[b] = distance[a]+w;
                    q.push({-distance[b],b});
                }
            }
        }

        int ans=distance[100];
        if(ans>=INT_MAX)cout<<-1;
        else cout<<ans;
        cout<<endl;
    }
}