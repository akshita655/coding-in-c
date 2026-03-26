//SELECTION SORT

#include <stdio.h>

void selection_sort(int nums[], int numsSize){
	int temp, pos, min, k, j;
	for(k = 0; k < numsSize - 1; k++){
		min = nums[k];
		pos = k;
		for(j = k + 1; j < numsSize; j++){		
			if(min > nums[j]){					
				min = nums[j];			
				pos = j;
			}
		}
		temp = nums[k];
		nums[k] = nums[pos];
		nums[pos] = temp;
	}
}

int main(){
	int size, i;
	printf("Enter the size of array: ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the elements:\n");
	for(i = 0; i < size; i++){
		printf("Enter Element - %d: ",i);
		scanf("%d",&arr[i]);
	}
	selection_sort(arr, size);
	printf("Sorted array: ");
	for(i = 0; i < size; i++){
		printf("%d ",arr[i]);	
	}
	return 0;
}

