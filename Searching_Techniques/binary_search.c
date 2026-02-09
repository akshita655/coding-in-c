//Binary Search
int binary_search(int nums[], int numsSize, int element){
	int left = 0, right = numsSize - 1;
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(nums[mid] == element){
			return mid;
		}
		else if(nums[mid] < element){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return -1;
}
int main(){
	int size, i, element;
	printf("Enter size of the array : ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter %d elements: ",size);
	for(i = 0; i < size; i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter elemnt to search in the array: ");
	scanf("%d",&element);
	int result = binary_search(arr, size, element);
	if(result == -1){
		printf("Element not found!");
		return 0;
	}
	printf("Element found at %d position.",result+1);
	return 0;
}
