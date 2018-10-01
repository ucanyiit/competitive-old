#include <bits/stdc++.h>

using namespace std;
#define NORM(x) if(x>=mod)x-=mod;

int mod = 1e9+7;


int memo[100001][2][2]; // birlikte mi? // kirmizi mi?
vector<int> adj[100001];
bool done[100001][2][2];

long long g(int i, int baba, int index, int cur, int ally){
    if(index==adj[i].size()) return ally;
    int now=adj[i][index];
    if(now==baba) return g(i, baba, index+1, cur, ally);
    if(done[now][cur][ally]) return memo[now][cur][ally];
    done[now][cur][ally]=true;
    long long ans=g(now, i, 0, cur, 1) * g(i, baba, index+1, cur, 1);
    ans%=mod;
    long long tmp=g(now, i, 0, 1-cur, 0) * g(i, baba, index+1, cur, ally);
    tmp%=mod;
    ans+=tmp;
    NORM(ans)
    memo[now][cur][ally]=ans;
    return ans;
}

int main(){
    int n, a1, a2;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a1>>a2;
        adj[a1].push_back(a2);
        adj[a2].push_back(a1);
    }
    for(int i=0;i<=10000;i++){
        done[i][0][0]=done[i][1][0]=done[i][0][1]=done[i][1][1]=false;
    }
    int a=g(1,0,0,0,0);
    int b=g(1,0,0,1,0);
    a+=b;
    NORM(a) 
    cout<<a;

}