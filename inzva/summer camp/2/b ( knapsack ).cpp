#include <bits/stdc++.h>

using namespace std;

/*  easy ( knapsack )  */

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        int arr[a];
        bool e[b+1];
        for(int i=0;i<a;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=b;i++){
            e[i]=false;
        }
        e[0]=true;

        for(int i=0;i<a;i++){ // PARA
            for(int j=0;j<=b;j++){ // SATIR
                if(e[j] && j+arr[i]<=b){
                    e[j+arr[i]]=true;
                }
            }
        }

        for(int i=b;i>=0;i--){ // PARA
            if(e[i]){
                cout<<i<<endl;
                break;
            }
        }
        
    }

}