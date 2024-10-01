#include <bits/stdc++.h>
using namespace std;
int main() {
 queue<int> Q;
 string k;
 
 while (1){
 	cin>>k;
 	if(k=="#") break;
 	else if (k=="PUSH"){
 		int v;
 		cin>>v;
 		Q.push(v);
	 }
	 else if (k=="POP"){
	 	if (Q.empty()) cout<<"NULL"<<endl;
	 	else {
	 		int e = Q.front(); Q.pop();
	 		cout<<e<<endl;
		 }
	 	
	 }
 }
 return 0;
}
 
