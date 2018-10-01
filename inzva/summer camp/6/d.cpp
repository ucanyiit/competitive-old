#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s;
    cin>>s;
    int n=s.size(), q=0;
    int tail[n+1], tails[n+1];
    tail[0]=0, tails[0]=0;
    for(int i=1;i<n;i++){
        while(q>0 && s[q]!=s[i]){
            q=tails[q];
            if(q==1){
                q=0;
                break;
            }
        }
        if(s[q]==s[i]){
            q++;
        }
        tails[i]=q;
    }
    while(q>0){
        for(int i=1;i<n-1;i++){
            if(q==tails[i]){
                cout<<s.substr(0, q);
                return 0;
            }
        }
        if(q==1) break;
        else q=tails[q-1];
    }
    cout<<-1;
}