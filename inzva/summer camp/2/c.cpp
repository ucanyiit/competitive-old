#include <bits/stdc++.h>

using namespace std;

int sum;
void recur(int lim, int i){

    if(lim<=i){
        return;
    }
    if(lim>=i+4){
        ::sum++;
        recur(lim, i+4);
        recur(lim, i+1);
    }
}

bool prime[10000000];
int primesunder(int a){
    int k=0;
    for(int i=a;i>1;i--){
        if(prime[i]){
            k++;
        }
    }
    return k;
}

int main(){
    
    int n, max=0;
    cin>>n;
    int tmp=n;
    int arr[n];
    while(n--){
        sum=1;
        int a;
        cin>>a;
        recur(a, 0);
        arr[n]=sum;
        if(arr[n]>max){
            max=arr[n];
        }
    }

    for(int i=2;i<=max;i++){
        prime[i]=true;
    }
    for(int i=4;i<=max;i++){
        for(int j=2;j<=sqrt(i);j++){
            if(prime[j] && i%j==0){
                prime[i]=false;
            }
        }
    }

    while(tmp--){
        cout<<primesunder(arr[tmp])<<endl;
    }

}