#include<stdio.h>
#include<stdlib.h>

void swap(int arr[],int x,int y){
	int temp;
	temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int arr[],int lb,int ub){
	int piv = arr[lb];
	int start = lb;
	int end = ub;
	while(start < end){
		while(arr[start] <= piv && start < ub){
			start++;
		}
		while(arr[end] > piv){
			end--;
		}
		if(start < end){
			swap(arr,start,end);
		}
	}
	swap(arr,lb,end);
	return end;
}

void quick_sort(int arr[],int lb, int ub){
	if(lb < ub){
		int loc = partition(arr,lb,ub);
		quick_sort(arr,lb,loc-1);
		quick_sort(arr,loc+1,ub);
	}
}

int main(){
	int size, i;
	printf("Enter the size of array:");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the elements:\n");
	for(i = 0; i < size; i++){
		printf("Enter Element - %d: ",i);
		scanf("%d",&arr[i]);
	}
	int lb = 0;
	int ub = size-1;
	quick_sort(arr,lb,ub);
	printf("Sorted array: ");
	for(i = 0; i < size; i++){
		printf("%d ",arr[i]);	
	}
	return 0;
}



