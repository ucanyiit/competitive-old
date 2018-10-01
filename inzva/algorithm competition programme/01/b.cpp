#include <bits/stdc++.h>

using namespace std;

/*  easy  */

pair<char,int> arr[200][200];

void incAll(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]={arr[i][j].first,arr[i][j].second+1}; 
        }
    }
}

void plantAll(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j].first=='.') arr[i][j]={'O',0};
        }
    }
}

void boomAll(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j].second==3 && arr[i][j].first=='O') {
                if(j<m-1) if(arr[i][j+1].second!=3 && arr[i][j+1].first=='O') arr[i][j+1]={'.',0};
                if(i<n-1) if(arr[i+1][j].second!=3 && arr[i+1][j].first=='O') arr[i+1][j]={'.',0};
                if(j>0) arr[i][j-1]={'.',0};
                if(i>0) arr[i-1][j]={'.',0};
                arr[i][j]={'.',0};
            }
        }
    }
}

void draw(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<arr[i][j].first;
        cout<<endl;
    }
}

int main(){
    int n, m, c;
    cin>>n>>m>>c;   
    char t;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>t;
            arr[i][j]={t,1};
        }
    }

    c--;
    c=c%24;

    bool ceven;
    if(c%2==0) ceven=true;
    else ceven=false;

    while(c--){
        incAll(n, m);
        if((ceven && c%2==1) || (!ceven && c%2==0)) plantAll(n, m);
        else boomAll(n,m);
    }   
    
    draw(n, m);

}