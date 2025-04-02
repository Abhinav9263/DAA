#include <stdio.h>
int max(int a,int b){
	if(a>b){
		return a;
	} else{
		return b;
	}
}
int k(int W, int wt[], int val[], int n){
	int i,w;
	int knap[n+1] [w+1];
	for(i=0;i<=n;i++){
	for(w=0;w<=W;w++){
		if (i==0||w==0)
		knap[i][w]=0;
		else if (wt[i-1]<=w)
		knap[i][w]=max(val[i-1]+knap[i-1][w-wt[i-1]], knap[i-1][w]);
		else if (wt[i-1]<=w)
		knap[i][w]=knap[i-1][w];
	}
}
return knap[n] [w];
}
int main() {
	int val[]={10,15,10,20,8};
	int wt[]={3,3,2,5,1};
	int w =10;
	int n= sizeof(val)/sizeof(val[0]);
	printf("The sol is : %d",w,k(w,wt,val,n));
	return 0;
}
