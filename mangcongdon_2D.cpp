#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5; // Adjusted size to avoid issues
const int M = 1e3 + 5; // Adjusted size to avoid issues
int n, m, Q;
vector<vector<int>> a(N, vector<int>(M, 0));
vector<vector<int>> S(N, vector<int>(M, 0));

void preCompute() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j];
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    preCompute();
    cin >> Q;
    int a, b, c, d;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> c >> d;
        cout << S[c][d] - S[c][b-1] - S[a-1][d] + S[a-1][b-1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
