#include<stdio.h>
#include<stdlib.h>
#include <math.h>
void merge(int arr[],int lb, int q,int ub){
	int i, j, k;
	int n = q-lb+1;
	int m = ub-q;
	int z[n+1],x[m+1];
	for(i=1;i<=n;i++){
		z[i] = arr[lb+i-1];
	}
	for(j=1;j<=m;j++){
		x[j] = arr[j+q];
	}
	z[n+1] = INFINITY;
	x[m+1] = INFINITY;
	int l = 1;
	int r = 1;
	for(k=lb;k<=ub;k++){
		if(z[l]<=x[r]){
			arr[k] = z[l];
			l = l + 1;
		}
		else{
			arr[k] = x[r];
			r = r + 1;
		}
	}
}
void merge_sort(int arr[],int lb,int ub){
	if(lb<ub){
		int q = (lb+ub)/2;
		merge_sort(arr,lb,q);
		merge_sort(arr,q+1,ub);
		merge(arr,lb,q,ub);
	}
}
int main(){
	int arr[100], size, i;
	printf("Enter the size of array: ");
	scanf("%d",&size);
	printf("Enter %d elements: ",size);
	for(i=1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	int lb = 1;
	int ub = size;
	merge_sort(arr,lb,ub);
	printf("Sorted array: ");
	for(i=1;i<=size;i++){
		printf("%d ",arr[i]);	
	}
	return 0;
}
