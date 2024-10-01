#include <bits/stdc++.h>
using namespace std;
int main() {
	 set<int> S;
	 int n;
	 cin>>n;
	 for (int i=0;i<n;i++){
	 	int k;
	 	cin>>k;
	 	S.insert(k);
 }
 while (1){
 	string k;
 	cin>>k;
 	int v;
 	if (k=="#") break;
 	else if (k=="min_greater"){
 		
 		cin>>v;
 		set<int>::iterator p = S.upper_bound(v);
 		p = S.upper_bound(v);
 		if (p==S.end()) cout<<"NULL"<<endl;
 		else {
 			cout <<*p << endl;
		 }	
	 }
	 else if (k=="insert"){
	 	cin>>v;
	 	S.insert(v);
	 }
	 else if (k=="min_greater_equal"){
	 	cin>>v;
 		set<int>::iterator p = S.lower_bound(v);
 		p = S.lower_bound(v);
 		if (p==S.end()) cout<<"NULL"<<endl;
 		else {
 			cout <<*p << endl;
		 }	
	 }
	 else if (k=="remove"){
	 	cin>>v;
	 	S.erase(v);
	 }
	 
 }
 
 return 0;
}