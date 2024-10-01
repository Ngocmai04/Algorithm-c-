#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n,Q;
int a[N];
int S[N];
void preCompute(){
	S[0]=0;
	for (int i=1;i<=n;i++){
		S[i]=S[i-1]+a[i];
	}
}

void solve(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	preCompute();
	cin>>Q;
	int u,v;
	for (int i=0;i<Q;i++){
		cin>>u>>v;
		cout<<S[v]-S[u-1]<<endl;
	}
}


int main(){
	freopen("data.inp","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}