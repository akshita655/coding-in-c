//DNF FOR 5 VARIABLES

#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dnf5(int arr[], int n){
    int low1 = 0, low2 = 0, mid = 0,high1 = n - 1, high2 = n - 1;

    while(mid <= high1){
        if(arr[mid] == 1){
            swap(&arr[mid], &arr[low1]);
            low1++;
            if(low2 < low1) low2 = low1;
            if(mid < low2) mid = low2;
        }
        else if(arr[mid] == 2){
            swap(&arr[mid], &arr[low2]);
            low2++;
            if(mid < low2) mid = low2;
        }
        else if(arr[mid] == 3){
            mid++;
        }
        else if(arr[mid] == 4){
            swap(&arr[mid], &arr[high1]);
            high1--;
        }
        else{
            swap(&arr[mid], &arr[high2]);
            high2--;
            if(high1 > high2) high1 = high2;
        }
    }
}

int display(int arr[],int n){
	int i;
    printf("The desired output is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

int main(){
    int n, i;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    dnf5(arr,n);
    display(arr,n);
    return 0;
}

