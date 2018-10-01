#include <bits/stdc++.h>

using namespace std;

/*  medium  */

int arr[300][300];

void draw(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotate(int i, int r, int n, int m){
    while(r--){
        int lx=n-i, ly=m-i;
        int a=i, b=i;
        int t=arr[a][b], t2;
        
        a++;
        while(true){
            t2=arr[a][b];
            arr[a][b]=t;
            t=t2;
            if(a==lx-1) break;
            else a++;
        }

        b++;
        while(true){
            t2=arr[a][b];
            arr[a][b]=t;
            t=t2;
            if(b==ly-1) break;
            else b++;
        }

        a--;
        while(true){
            t2=arr[a][b];
            arr[a][b]=t;
            t=t2;
            if(a==i) break;
            else a--;
        }

        b--;
        while(true){
            t2=arr[a][b];
            arr[a][b]=t;
            t=t2;
            if(b==i) break;
            else b--;
        }
    }
}



int main(){
    int n, m, r;
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int a=min(m, n), b=max(m, n);
    int c=1;

    for(int i=0;i<a/2;i++){
        c=(n+m)*2-4-8*i; // rotation number = ( rotation number ) % ( a whole tour )
        rotate(i, r%c, n, m);
    }
    draw(n, m);
}