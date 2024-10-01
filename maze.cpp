#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int main() {
	int n,m, xp1,xp2;
   cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i=0;i<n;i++){
    	for (int j=0;j<m;j++){
    		cin>>v[i][j];
		}
	}
    

    cout << maze(v,xp1,xp2) << endl;

    return 0;
}


