#include<stdio.h>

int dfs(int grid[][100], int rows, int cols, int i, int j){
    if(i < 0 || j < 0 || i >= rows || j >= cols){
        return 1;
    }
    if(grid[i][j] == 0){
        return 1;
    }
    if(grid[i][j] == -1){
        return 0;
    }
    grid[i][j] = -1;
    int p = 0;
    p += dfs(grid, rows, cols, i+1, j);
    p += dfs(grid, rows, cols, i-1, j);
    p += dfs(grid, rows, cols, i, j+1);
    p += dfs(grid, rows, cols, i, j-1);
    return p;
}

int islandPerimeter(int grid[][100], int rows, int cols){
	int i, j;
    for(i=0;i<rows;i++){
        for(j = 0;j < cols;j++){
            if(grid[i][j] == 1){
                return dfs(grid, rows, cols, i ,j);
            }
        }
    }
    return 0;
}

int main(){
    int rows, cols, i, j;
    printf("Enter No. of rows: ");
    scanf("%d",&rows);
    printf("Enter No. of columns: ");
    scanf("%d",&cols);
    int grid[100][100];
    printf("Enter matrix:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    printf("Perimeter of the Island is: %d",
           islandPerimeter(grid, rows, cols));
    return 0;
}
