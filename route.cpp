#include <bits/stdc++.h>
using namespace std;

const int N=15;
int n,K; //n so khach 
int C[2*N+1][2*N+1], x[2*N+1],xOpt[2*N+1]
const int oo=1e9;
int fcur=0,load=0,fOpt = oo;
bool visited[2*N+1];    

// kiem tra ung vien v cho vi tri k

bool check(int v, int k){
    if (visited[v]) return false;
    // muon tra kahch thi phai don truoc
    if(v>n){
        if (!visited[v-n]) return false;
    }
    else{
        // day cho thi khong don them khach
        if(load==k) return false;
    }
    return true;

}
int TRY(int k){
    for( int v=1;v<=2*n;v++){
        if(check(v,k)){
            x[k]=v;
            visited[v]=true;
            fCur+=C[x[k-1]][v];
            load+=(v>n?-1:1);
            if(k==2*n) updateSol();
            else {
            if(fCur+(2*n+1-k)+ cmin < fOpt){
                TRY(k+1);
            }
            
        }
        visited[v]=false;
        fCur-=C[x[k-1]][v];
        load-=(v>n?-1:1);
        
        }
    }
}
void updateSol(){

}


void input(){
    cin>>n>>K;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin>>C[i][j];
            if(i!=j) cmin=min(cmin,C[i][j]);
        }
    }
}

int main (){
    x[0]=0;
    visited[0]=true;
    TRY(1);
    cout<<fOpt<<endl;
}

