#include<bits/stdc++.h>
using namespace std;

int main (){
	cout<<"nhap 2 so a va b cho bai toan ax+b=0\n";
	int a,b;
	cin>>a>>b;
	if(a==0&&b!=0) {
		cout<<"invalid";
		
	}
	else if(a==0&&b==0){
		cout<<"pt vo so nghiem";
	}
	else cout<<(-b*1.0/a);
}