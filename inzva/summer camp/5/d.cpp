#include <bits/stdc++.h>

using namespace std;
bool lock1[10000];
bool lock2[10000];
int arr1[10000];
int arr2[10000];
int mat[10000][10000];
int v[10000];


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[i][j]=0;
        }
    }
    int mx;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) mx=0;
            else if(j==0) mx=mat[i-1][j];
            else if(i==0) mx=mat[i][j-1];
            else mx=max(mat[i][j-1], mat[i-1][j]);
            if(arr1[i]==arr2[j] && !lock1[j] && !lock2[i]){
                mx++;
                lock1[j]=true;
                lock2[i]=true;
            }
            mat[i][j]=mx;
        }
    }

    int l=0;
    int a=n-1, b=m-1;
    while(a>0 || b>0){        
        if(mat[a][b-1]==mat[a][b] && b>0){
            b--;
        }
        else if(mat[a-1][b]==mat[a][b] && a>0){
            a--;
        } 
        else if(mat[a-1][b]==mat[a][b]-1 && a-1>-1){
            v[l]=mat[a][b];
            l++;
            a--;
        }
        else if(mat[a][b-1]==mat[a][b]-1 && b-1>-1){
            v[l]=mat[a][b];
            l++;
            b--;
        }
        
    }

    for(int i=l-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
}