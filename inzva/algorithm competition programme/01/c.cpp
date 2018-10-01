#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[50];
    char t;
    string a;
    for(int i=0;i<30;i++){
        arr[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>a;
        t=a[0];
        arr[t-'a']++;
    }
    bool f=true;
    for(int i=0;i<30;i++){
        if(arr[i]>=5){
            cout<<char('a'+i);
            f=false;
        }
    }
    if(f)cout<<"inzva";
    
}