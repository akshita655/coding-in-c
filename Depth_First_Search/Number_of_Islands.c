#include<stdio.h>

void dfs(int grid[][100], int rows, int cols, int i, int j){
    if(i < 0 || j < 0 || i >= rows || j >= cols)
        return;
    if(grid[i][j] == 0)
        return;
    grid[i][j] = 0;
    dfs(grid, rows, cols, i+1, j);
    dfs(grid, rows, cols, i-1, j);
    dfs(grid, rows, cols, i, j+1);
    dfs(grid, rows, cols, i, j-1);
}

int numIslands(int grid[][100], int rows, int cols){
    int count = 0, i, j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(grid[i][j] == 1){
                count++;
                dfs(grid, rows, cols, i, j);
            }
        }
    }
    return count;
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
    printf("Number of Islands are: %d",
           numIslands(grid, rows, cols));
    return 0;
}
