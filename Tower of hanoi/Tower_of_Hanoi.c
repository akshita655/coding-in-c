/*TOWER OF HANOI*/

#include<stdio.h>
#include<stdlib.h>

void toh(int n,int a,int b,int c){
	if(n>0){
		toh(n-1,a,c,b);
		printf("From %d to %d\n",a,c);
		toh(n-1,b,a,c);
	}
}

int main(){
	int n;
	printf("Enter the number of disk: ");
	scanf("%d",&n);
	int a = 1;
	int b = 2;
	int c = 3;
	toh(n,a,b,c);
	return 0;
}
