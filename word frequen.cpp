#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> mp;
    string x;
    set<string> se;
    while(cin >> x) {
    	if (mp.count(x)){
    		mp[x]++;
		}
		else {
			se.insert(x);
			mp[x]++;
			}
			}
	for (string it : se){
		cout << it << " " << mp[it] << "\n";
	}
	
    return 0;
}