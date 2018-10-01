#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
vector<int> parents[100001];
int babas[100001];

void findnode(int i, int k){
    if(k==0){
        cout<<i<<endl;
    }
    else if(k<0 || log2(k)>=parents[i].size()){
        cout<<0<<endl;
    }
    else{
        int tmp=log2(k);
        i=parents[i][tmp];
        k=k-pow(2,tmp);
        findnode(i, k);
    }
}

void addbaba(int i, int baba, int index){
    if(parents[baba].size()>index){
        parents[i].push_back(parents[baba][index]);
        addbaba(i, parents[baba][index], index+1);
    }
}


void dfs(int i, int baba){
    if(baba!=0) parents[i].push_back(baba);
    addbaba(i, baba, 0);
    for(auto u: adj[i]){
        if(baba!=u) dfs(u, i);
    }
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int p, start;
        cin>>p;
        for(int i=0;i<100001;i++){
            parents[i].clear();
            adj[i].clear();
            babas[i]=0;
        }
        int a1,a2;
        for(int i=0;i<p;i++){
            cin>>a1>>a2;
            adj[a1].push_back(a2);
            adj[a2].push_back(a1);
            babas[a1]=a2;
            if(a2==0){
                start=a1;
            }
        }

        dfs(start, 0);
        int q;
        cin>>q;
        int tmp;
        for(int i=0;i<q;i++){
            cin>>tmp;
            if(tmp==0){
                cin>>a1>>a2;
                if(a1!=0) parents[a2].push_back(a1);
                addbaba(a2, a1, 0);
            }
            else if(tmp==1){
                cin>>a1;
                parents[a1].clear();
            }
            else if(tmp==2){
                cin>>a1>>a2;
                findnode(a1,a2);
            }
        }

    }
    
}