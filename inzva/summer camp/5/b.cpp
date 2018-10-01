#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        pair<int,int> a{0,0};
        pair<int,int> b{n-1,0};
        while(a.first<b.first){
            if(a.second>b.second){
                b.second+=arr[b.first];
                b.first--;
            }
            else{
                a.second+=arr[a.first];
                a.first++;
            }
        }
        
        if(a.second==b.second){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;

    }
}