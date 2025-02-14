#include <bits/stdc++.h> 
using namespace std;

const int N = 1e6 + 5;
int n, Q;
int res = 0, S = 0;
int a[N];

void input() {
	cin >> n >> Q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
 
void solve() {
	int L = 1;
	for (int R = 1; R <= n; R++) {
		S += a[R];
		while (S > Q) {
			S -= a[L]; L++;
		}
		res = max(res, R - L + 1);
	}
	cout << res;
}

int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solve();
	return 0;
}