#include <bits/stdc++.h>

using namespace std;

/*  easy  */

int main(){
    int n1, tmp;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    pair<int,bool> all[n1+n2], tmpp;
    for(int i=0;i<n2;i++){
        cin>>tmp;
        tmpp.first=tmp;
        tmpp.second=false;
        all[i]=tmpp;
    }
    for(int i=n2;i<(n1+n2);i++){
        tmpp.first=arr1[i-n2];
        tmpp.second=true;
        all[i]=tmpp;
    }
    sort(all, all+n1+n2);

    int t1=n1*3, t2=n2*3, max=t1-t2, maxt1=t1, maxt2=t2; 
    for(int i=0;i<(n1+n2);i++){
        while(all[i+1].first==all[i].first){
            if(all[i].second){
                t1--;
            }
            else{
                t2--;
            }
            i++;
        }
        if(all[i].second){
            t1--;
        }
        else{
            t2--;
        }
        if(t1-t2>max){
            max=t1-t2;
            maxt1=t1;
            maxt2=t2;
        }
    }
    
    cout<<maxt1<<":"<<maxt2;

}