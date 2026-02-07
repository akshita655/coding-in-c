#include <stdio.h>
int bubble_sort(int nums[], int numsSize){
	int i, j, temp, swap_count = 0;
	for(i=0;i<numsSize-1;i++){
		for(j=0;j<numsSize-1;j++){
			if(nums[j]>nums[j+1]){
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
				swap_count++;
			}	
		}
		if(swap_count == 0){
			return swap_count;
			
		}
	}
}
int main(){
	int i, size;
	printf("Enter the size of array:");
	scanf("%d",&size);
	int arr[size];
	printf("Enter %d Element: ",size);
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int result = bubble_sort(arr, size);
	if(result == 0){
		printf("Array is alraedy sorted!");
		return 0;
	}
	printf("Sorted array: ");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);	
	}
	return 0;
}
