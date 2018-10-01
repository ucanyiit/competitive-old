#include <bits/stdc++.h>

using namespace std;

int segment[1000000];
int n,mx;


int f(int s, int e, int k, int res, int ls, int le){
    if(k>2*mx){
        return 0;
    }
    if(ls==le && (ls==s || le==e)){         
        return segment[k];
    }
    if(s<=ls && e>=le){         
        return segment[k];
    }
    if(e<ls || s>le){
        return 0;
    }   
    
    
    int mid=(ls+le)/2;    
    int a=(f(s, e, k*2, res, ls, mid));
    int b=(f(s, e, k*2+1, res, mid+1, le));
    return a^b;
}

int main(){
    cin>>n;

    mx=int(ceil(log2(n)));
    mx=pow(2,mx);
    for(int i=0;i<(2*mx)+1;i++) segment[i]=0;
    for(int i=0;i<n;i++) cin>>segment[i+mx];

    for(int i=mx-1;i>0;i--){
        segment[i]=segment[i*2]^segment[i*2+1];
    }

    int q,a,b;
    cin>>q;
    while(q--){
        cin>>a>>b;
        cout<<f(a, b, 1, 0, 1, mx)<<endl;
    }
}