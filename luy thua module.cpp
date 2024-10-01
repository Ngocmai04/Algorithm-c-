#include<stdio.h>
#include<math.h>

void powmod(int x, int y, int m){
	long long res =1;
	while(y){
		if(y%2==1){
			res*=x;
			res%=m;
		}
		x*=x;
		x%=m;
		y/=2;
		printf("%d %d %d\n",x,y,res);
	}
	
}

int main(){
	int x,y,m;
	scanf("%d %d %d",&x,&y,&m);
	powmod(x,y,m);
}