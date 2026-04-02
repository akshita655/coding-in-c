//BINARY SEARCH USING RECURSION:

#include<stdio.h>
#include<stdlib.h>

int binary(int arr[],int low,int high,int target){
	if(low > high){
		return -1;
	}
	else{
		int mid = (low + high) / 2;
		if(arr[mid] == target){
			return mid;
		}
		else if(arr[mid] > target){
			return binary(arr, low, mid - 1, target);
		}
		else{
			return binary(arr, mid + 1, high, target);
		}
	}
}
int main(){
	int n, arr[100], i;
	int target;
	int low = 0,high;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	high = n - 1;
	for(i=0;i<n;i++){
		printf("Enter element - %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter the number to be searched: ");
	scanf("%d",&target);
	int result = binary(arr,low,high,target);
	if(result == -1){
		printf("Element not found!!");
	}
	else{
		printf("Element found at position: %d",result + 1);
	}
	return 0;
}
