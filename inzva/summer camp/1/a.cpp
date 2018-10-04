#include <bits/stdc++.h>

using namespace std;

/*  easy  */

int main(){
    int n,k, tmp;
    cin>>n>>k;
    bool c[n];
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==1){
            c[i]=true;
        }
        else{
            c[i]=false;
        }
    }

    int point=k, lastpoint=-1, sum=0;

    while((point-1)>lastpoint){ 
        point--;
        if(point>=n){
            continue;
        }
        if(c[point]){
            sum++;
            lastpoint=point;
            if((point+k)>=n){
                cout<<sum;
                return 1;
            }
            point=point+k+k;
        }
    }

    
    cout<<-1;

}