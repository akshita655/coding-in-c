#include<stdio.h>
int linear_search(int nums[], int numsSize, int element){
	int i;
	for(i = 0; i < numsSize; i++){
		if(nums[i] == element){
			return i;
		}
	}
	return -1;
}
int main(){
	int size;
	printf("Enter Size of Array: ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter %d elements: ",size);
	int i;
	for(i = 0; i < size; i++){
		scanf("%d",&arr[i]);
	}
	int element;
	printf("Enter element to search: ");
	scanf("%d",&element);
	int result = linear_search(arr, size, element);
	if(result == -1){
		printf("Element not found!");
	}
	else{
		printf("Element found at %d position.",result + 1);
	}
	return 0;
}
