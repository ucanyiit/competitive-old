#include <bits/stdc++.h>

using namespace std;

bool flag=false;
void draw(string tgrid[]){
    if(flag){
        return;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(tgrid[i][j]=='-'){
                return;
            }
        }
    }
    flag=true;
    for(int i=0;i<10;i++){
        cout<<tgrid[i]<<endl;
    }
}

void insert(string grid[], string words[], int wordi){
    if(flag){
        return;
    }
    string tgrid[10];
    int it;
    bool f;
    for(int i=0;i<10;i++){
        for(int z=0;z<10;z++){
            tgrid[z]=grid[z];
        }
        it=0;
        f=false;
        for(int j=0;j<10;j++){
            if(tgrid[i][j]==words[wordi][it]){
                it++;
                f=true;
            }
            else if(tgrid[i][j]=='-' &&(it==0 || f)){
                tgrid[i][j]=words[wordi][it];
                it++;
                f=true;
                draw(tgrid);
            }
            else{
                f=false;
                it=0;
                for(int z=0;z<10;z++){
                    tgrid[z]=grid[z];
                }
            }
            if(it==words[wordi].size()){
                draw(tgrid);
                insert(tgrid, words, wordi+1);
            }
        }
    }

    for(int i=0;i<10;i++){
        for(int z=0;z<10;z++){
            tgrid[z]=grid[z];
        }
        it=0;
        f=false;
        for(int j=0;j<10;j++){
            if(tgrid[j][i]==words[wordi][it]){
                it++;
                f=true;
            }
            else if(tgrid[j][i]=='-'&&(it==0 || f)){
                tgrid[j][i]=words[wordi][it];
                it++;
                f=true;
                draw(tgrid);
            }
            else{
                f=false;
                it=0;
                for(int z=0;z<10;z++){
                    tgrid[z]=grid[z];
                }
            }
            if(it==words[wordi].size()){
                draw(tgrid);
                insert(tgrid, words, wordi+1);
            }
        }   
    }
}


int main(){
    string grid[10];
    for(int i=0;i<10;i++){
        cin>>grid[i];
    }
    string str, strs[10];
    cin>>str;
    int strnumb=0, lastpoint=0;
    for(int i=0;i<str.size();i++){
        if(!(str[i] >= 'A' && str[i] <= 'Z')){
            strs[strnumb]=str.substr(lastpoint,i-lastpoint);
            strnumb++;
            lastpoint=i+1;
        }
    }
    strs[strnumb]=str.substr(lastpoint, str.size());
    insert(grid, strs, 0);
}