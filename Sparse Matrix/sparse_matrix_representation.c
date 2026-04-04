//Array representation of a sparse matrix

#include <stdio.h>
#define MAX 100

int main() {
	int c=0;
	int arr[4][5] = {{0,0,3,0,4},{0,0,5,7,0},{0,0,0,0,0},{0,2,6,0,0}}; 
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			if(arr[i][j]!=0){
				c++;
			}
		}
	}
	int row[c],column[c],value[c];
	int k=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			if(arr[i][j]!=0){
				row[k]=i;
				column[k]=j;
				value[k]=arr[i][j];
				k++;
			}
		}
	}
	printf("Array representation of a sparse matrix:\n");
	printf("----------------------------------------\n");
	printf("Row\tColumn\tValue\n");
	for(int i=0;i<c;i++){
		printf("%d\t%d\t%d\n",row[i],column[i],value[i]);
	}
	return 0;
}






