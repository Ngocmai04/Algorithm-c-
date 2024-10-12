#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int maxN=999+100;
const int oo=1e6;

int a[maxN][maxN],m,n,r,c,d[maxN][maxN];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
queue<ii>qe;


int solve(){
	qe.push(ii(r,c));
	d[r][c]=0;
	a[r][c]=1;
	
	
	while(!qe.empty()){
		ii u=qe.front();
		qe.pop();
		
		for (int i=0;i<=3;i++){
			int x=dx[i]+u.first;
			int y=dx[i]+u.second;
			if(x<1||x>m||y>n||y<1){
				return d[u.first][u.second]+1;
			}
			if(a[x][y]!=1){
				d[x][y]=d[u.first][u.second]+1;
				qe.push(ii(x,y));
				a[x][y]=1;
			}
		}
	}
	return -1;
}

int main() {
	
   cin >> n >> m>>r>>c;
    vector<vector<int>> v(n+1, vector<int>(m+1));
    for (int i=0;i<n;i++){
    	for (int j=0;j<m;j++){
    		cin>>v[i][j];
    		a[i][j] = v[i][j];
		}
	}
    int result=solve();

    cout << result << endl;
}



