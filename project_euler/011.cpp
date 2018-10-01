#include <bits/stdc++.h>

using namespace std;



int main() {
    int m;
    long long int max=0;
    int grid[20][20];
    for(int i=0;i<20;i++){
      for(int j=0;j<20;j++){
        cin>>m;
        grid[i][j]=m;
      }
    }
    for(int i=0;i<20;i++){
      for(int j=0;j<20;j++){
        // sol ust sag alt
        if(i<17 && j<17 && grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]>max){
          max=grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
        }
        // soldan saga
        if(j<17 && grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3]>max){
          max=grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
        }
        // üstten assa
        if(i<17 && grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j]>max){
          max=grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
        }
        // sag ust sol alt
        if(j>2 && i<17 && grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3]>max){
          max=grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
        }
      }
    }
    cout<<max<<endl;
    return 0;
}
