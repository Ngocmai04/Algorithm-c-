#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int LOG = 20; 
int a[N], st[N][LOG];

void buildSparseTable(int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int j = log2(r - l + 1);
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

void solve(){
	 int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	buildSparseTable(n);
	int m;
    cin >> m;
    int Q = 0;
    while (m--) {
        int u, v;
        cin >> u >> v;
        Q += query(u, v);
    }
    cout << Q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;

   
}
