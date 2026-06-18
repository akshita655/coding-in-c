#include<stdio.h>

int dfs(int grid[][100], int rows, int cols, int i, int j){
    if(i < 0 || j < 0 || i >= rows || j >= cols){
        return 0;
    }
    if(grid[i][j] == 0 || grid[i][j] == -1){
        return 0;
    }
    grid[i][j] = -1;
    int area = 1;
    area += dfs(grid, rows, cols, i + 1, j);
    area += dfs(grid, rows, cols, i, j + 1);
    area += dfs(grid, rows, cols, i - 1, j);
    area += dfs(grid, rows, cols, i, j - 1);
    return area;
}

int maxAreaOfIsland(int grid[][100], int rows, int cols){
    int val, maxVal = 0, i, j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(grid[i][j] == 1){
                val = dfs(grid, rows, cols, i, j);
                if(val > maxVal){
                    maxVal = val;
                }
            }
        }
    }
    return maxVal;
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
    printf("Max area in the given Island is: %d", maxAreaOfIsland(grid, rows, cols));
    return 0;
}
