#include <bits/stdc++.h>

using namespace std;

int n, max=0;

int ci(vector<int> &t, int l, int r, int i){
    while(r-l>1){
        int m=l+(r-l)/2;
        if(t[m]>=i) r=m;
        else l=m;
    }
    return r;
}

int lis(vector<int> &v){
    if(v.size()==0) return 0;
    vector<int> tail(v.size(), 0);
    int l=1;

    tail[0]=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]<tail[0]) tail[0] = v[i];
        else if(v[i]>tail[l-1]) tail[l++] = v[i];
        else tail[ci(tail, -1, l-1, v[i])]=v[i];
    }
    return l;
}

int main(){
    cin>>n;
    int tmp;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<lis(v);
}