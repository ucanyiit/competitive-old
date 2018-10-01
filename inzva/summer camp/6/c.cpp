#include <bits/stdc++.h>

using namespace std;

int arr[15][15];

int mex(vector<int> v){
    int m = 0;
    while (find(v.begin(), v.end(), m) != v.end()) m++;

    return (m);
}

int getmex(int x, int y){
    vector<int> v;
    if(x>14 || y>14) return 0;
    if(x-2>=0 && y-1>=0)v.push_back(arr[x-2][y-1]);
    if(x-2>=0 && y+1<15)v.push_back(arr[x-2][y+1]);
    if(y-2>=0 && x-1>=0)v.push_back(arr[x-1][y-2]);
    if(y-2>=0 && x+1<15)v.push_back(arr[x+1][y-2]);
    return mex(v);
}

int main(){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            arr[i][j]=0;
        }
    }
    for(int i=2;i<29;i++){
        for(int j=0;j<=i;j++){
            if(j>14 || i-j>14) continue;
            arr[i-j][j]=getmex(i-j,j);
            if(i-j==1 && j==1) arr[i-j][j]=0;
        }
    }





    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a=0, x, y;
        while(n--){
            cin>>x>>y;
            a^=arr[x-1][y-1];
        }
        if(a==0) cout<<"Second";
        else cout<<"First";
        cout<<endl;
    }
    
}