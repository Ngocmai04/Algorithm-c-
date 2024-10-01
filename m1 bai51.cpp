#include<stdio.h>
int main (){
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for (int i=n-1;i>=0;i--){
		printf("%d ",a[i]);
	}
		printf("\n");
	for (int i=0;i<n;i+=2){
		 printf("%d ",a[i]);
	}
	printf("\n");
	for (int i=1;i<n;i+=2){
		 printf("%d ",a[i]);
	}
	printf("\n");
	for (int i=0;i<n-1;i++){
		printf ("%d ",a[i]+a[i+1]);
	}
	printf("\n");
	
		
}