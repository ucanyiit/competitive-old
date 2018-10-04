#include <bits/stdc++.h>

using namespace std;

/*  easy  */

int sumarray(int arr[], int n, int k){
    int sum=0, tmp;
    for(int i=0;i<n;i++){
        tmp=arr[i]/k;
        if(arr[i]%k==0){
            sum+=tmp;
        }
        else{
            tmp++;
            sum+=tmp;
        }
    }
    return sum;
}

int main(){
    int n, h;
    cin>>n>>h;
    int arr[n], max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>max){
            max=arr[i];
        }
    }

    sort(arr, arr+n);
    int l=0, r=max, m, msum;

    while(l<r){
        m=l+(r-l)/2;
        if(l==0){
            l++;
        }
        msum=sumarray(arr, n, m);
        if(msum>h){
            l=m+1;
        }
        else if(msum>=h && sumarray(arr,n,m-1)<h){
            break;
        }
        else{
            r=m;
        }
    }
    assert(r==l);
    cout<<r;
    




}