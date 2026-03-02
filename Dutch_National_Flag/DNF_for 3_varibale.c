//DNF FOR 3 VARIABLES

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dnf(int arr[], int n){
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high){
        if(arr[mid] < 0){
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
		else if(arr[mid] == 0){
            mid++;
        }
		else {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

void display(int arr[], int n){
	int i;
    printf("The desired output is: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n, i;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    dnf(arr, n);
    display(arr, n);
    return 0;
}
