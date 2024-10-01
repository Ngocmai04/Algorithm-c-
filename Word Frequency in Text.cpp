#include <bits/stdc++.h>

using namespace std;
int main() {
    map<string, int> m;
    string k;
    while(cin>>k){
    	m[k]++;
    	if (k==" ") break;
	}
	for (const auto& p : m) {
        cout << p.first << " " << p.second << endl;
    }

    

}
