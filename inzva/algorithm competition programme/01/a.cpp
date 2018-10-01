#include <bits/stdc++.h>

using namespace std;
    

int main(){
    int n, m;
    cin>>n>>m;
    int t1;
    if(n%2==1) t1 = (n-m)/2;
    else t1=(n-m+1)/2;
    if((m)/2 < t1) cout<<(m)/2;
    else cout<<t1;
    
}