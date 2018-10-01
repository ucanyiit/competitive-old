#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, t;
    cin>>n;
    pair<int, int> arr[n];
    for(int i=1;i<=n;i++){
        cin>>t;
        arr[i-1]={t,i};
    }

    sort(arr, arr+n);

    int f=0, s, e;
    bool anaf=true;
    for(int i=1;i<=n;i++){
        if(arr[i-1].second!=i){
            if(f==0){
                f=1;
                s=i;
            }
            else if(f==1 && arr[i-2].second!=i-1) f=2;
            else if(f==1) f=20; // 2 only
            else if(f==20) f=2;
            else if(f==2 && arr[i-2].second!=i-1) f=2;
            e=i;
            anaf=false;
        }
    }
    if(anaf){
        cout<<"yes";
        return 1;
    }       
    if(f==2){
        bool flag = false;
        for(int i=0;i<=e-s;i++){
            if(arr[s+i-1].second!=e-i) flag=true;
        }

        if(flag) f=10;
        else if(e-s<3) f=20;
        else f=30;
    }
    if(f==30){
        cout<<"yes"<<endl;
        cout<<"reverse "<<s<<" "<<e;
    }
    if(f==20){
        cout<<"yes"<<endl;
        cout<<"swap "<<s<<" "<<e;
    }
    if(f==10){
        cout<<"no";
        return 1;
    }
}