#include <bits/stdc++.h>
using namespace std;

void construct_segment_tree(vector<int>& segtree, vector<int>& a, int n) {
    for (int i = 0; i < n; i++)
        segtree[n + i] = a[i];

    for (int i = n - 1; i >= 1; i--)
        segtree[i] = max(segtree[2 * i], segtree[2 * i + 1]);
}

void update(vector<int>& segtree, int pos, int value, int n) {
    pos += n;
    segtree[pos] = value;

    while (pos > 1) {
        pos >>= 1;
        segtree[pos] = max(segtree[2 * pos], segtree[2 * pos + 1]);
    }
}

int range_query(vector<int>& segtree, int left, int right, int n) {
    left += n;
    right += n;
    int ma = INT_MIN;

    while (left < right) {
        if (left & 1) {
            ma = max(ma, segtree[left]);
            left++;
        }
        if (right & 1) {
            right--;
            ma = max(ma, segtree[right]);
        }
        left /= 2;
        right /= 2;
    }
    return ma;
}

int main() {
    int n; cin>>n;
    vector<int> a;
    int x;
    for (int i=0;i<n;i++){
    	cin>>x;
    	a.push_back(x);
	}
    
    vector<int> segtree(2 * n);
    construct_segment_tree(segtree, a, n);
	int m;
	cin >>m;
	string k;
	int u,v;
	while (m--){
		cin>>k;
		if(k=="get-max"){
			cin>>u>>v;
			    cout<<range_query(segtree, u, v + 1, n) <<endl;

		}
		else if (k=="update"){
			cin>>u>>v;
			 update(segtree, u, v, n);
		}
	}
	return 0;
}
