#include <bits/stdc++.h>

using namespace std;
int matrix[1000000][30]={{0}};
bool words[1000000]={false};

int main(){
    int n;
    cin>>n;

    string tmp;

    int yeninod=0;
    for(int i=0;i<30;i++){
        matrix[1000000][i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>tmp;            
        int index=0;
        for(int j=0;j<tmp.size();j++){        
            int pos=tmp[j] - 'a';
            
            if(words[index]){
                cout<<"BAD SET"<<endl;
                cout<<tmp;
                return 0;
            }

            if(matrix[index][pos]==0){
                yeninod+=1;
                matrix[index][pos]=yeninod;
                index=yeninod;
            }
            else if(j==tmp.size()-1){
                cout<<"BAD SET"<<endl;
                cout<<tmp;
                return 0;
            }
            else{
                index=matrix[index][pos];
            }
            if(j==tmp.size()-1){
                words[index]=true;
            }
            

        }
    }
    cout<<"GOOD SET";
}