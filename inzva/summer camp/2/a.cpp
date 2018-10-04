#include <bits/stdc++.h>

using namespace std;

/*  very easy  */

int main(){
    int n, m, max=0;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum=0, j=0;
    for(int i=0;i<n;i++){
        while(j<n){
            if(sum+arr[j]>m){
                break;
            }
            else{
                sum=sum+arr[j];
                j++;
                if(max<j-i){
                    max=j-i;
                }
            }
        }
        if(j==n){
            break;
        }
        sum-=arr[i];
    }
    cout<<max;
}