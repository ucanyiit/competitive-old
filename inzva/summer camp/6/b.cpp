#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0, tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            sum^=tmp;
        }

        if(sum){
            cout<<"First"<<endl;
        }
        else{
            cout<<"Second"<<endl;
        }
    }
}   