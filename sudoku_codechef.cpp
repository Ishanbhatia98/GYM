#include<bits/stdc++.h>
using namespace std;
//not working!


bool check_row(int **grid, int x, int row){
    for(int col=0;col<9;col++){
        //if x is already present in the row
        if(grid[row][col]==x) return false;
    };
    //if x is not present in the row
    return true;
}

bool check_col(int **grid, int x, int col){
    for(int row=0;row<9;row++){
        //if x is already present in the column
        if(grid[row][col]==x) return false;
    };
    //if x is not present in column
    return true;
}

bool check_sub_grid(int **grid, int start_row, int end_row, int start_col, int end_col, int x){
    for(int row=start_row;row<=end_row;row++){
        for(int col=start_col;col<=end_col;col++){
            //if x is already present in the 3X3 subgrid
            if(grid[row][col]==x) return false;
        };
    };
    //if x is not present in the subgrid
    return true;
}

bool check_grid(int **grid, int row, int col, int x){
    if(row>=0 && row<=2){
        //if coors are of a subgrid made of the first three rows
        if(col>=0 && col<=2){
            //first subgrid
            return check_sub_grid(grid, 0, 2, 0, 2, x);
        }else if(col>=3 && col<=5){
            //second subgrid
            return check_sub_grid(grid, 0, 2, 3, 5, x);
        }else{
            //third subgrid
            return check_sub_grid(grid, 0, 2, 6, 8, x);
        }
    }else if(row>=3 && row<=5){
        //if coors are of a subgrid made of the middle three rows
        if(col>=0 && col<=2){
            //fourth subgrid
            return check_sub_grid(grid, 3, 5, 0, 2, x);
        }else if(col>=3 && col<=5){
            //fifth subgrid
            return check_sub_grid(grid, 3, 5, 3, 5, x);
        }else{
            //sixth subgrid
            return check_sub_grid(grid, 3, 5, 6, 8, x);
        }
    }else{
        //if coors are of a subgrid made of the last three rows
        if(col>=0 && col<=2){
            //seventh subgrid
            return check_sub_grid(grid, 6, 8, 0, 2, x);
        }else if(col>=3 && col<=5){
            //eighth subgrid
            return check_sub_grid(grid, 6, 8, 3, 5, x);
        }else{
            //ninth subgrid
            return check_sub_grid(grid, 6, 8, 6, 8, x);
        }

    }
}

void fillSudoku(int **grid, int row, int col){
    //checking if coors exist
    //if(row>=9||col>=9) return;
    if(row==8 && col==8){
        //check if 0s are present
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(grid[row][col]==0) return;
            };
        };
        //reached a valid solution
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                cout << grid[r][c] <<" ";
            };
            cout << endl;
        };

        cout << endl;
        return;
    }
   
    if(row!=8 && col!=8){
         //check if number is 0 or not
        if(grid[row][col]!=0){
                //calling function to fill position below the current coors
                fillSudoku(grid, row+1, col);
                //calling function to fill position to the right of current coors
                fillSudoku(grid, row, col+1);
        }

        //checking which number can be inserted at coors ie at row, col
        for(int i=1;i<=9;i++){
            if(check_col(grid, i, col) && check_row(grid, i, row) && check_grid(grid, row, col, i)){
                //number i can be inserted at this postion
                grid[row][col] = i;
                //calling function to fill position below the current coors
                fillSudoku(grid, row+1, col);
                //calling function to fill position to the right of current coors
                fillSudoku(grid, row, col+1);
                //removing i from current position to check other possibilities
                grid[row][col] = 0;
            }
        };
    }else if(row==8){
         //check if number is 0 or not
        if(grid[row][col]!=0){
                //calling function to fill position to the right of current coors
                fillSudoku(grid, row, col+1);
        }
        //checking which number can be inserted at coors ie at row, col
        for(int i=1;i<=9;i++){
            if(check_col(grid, i, col) && check_row(grid, i, row) && check_grid(grid, row, col, i)){
                //number i can be inserted at this postion
                grid[row][col] = i;
                //calling function to fill position to the right of current coors
                fillSudoku(grid, row, col+1);
                //removing i from current position to check other possibilities
                grid[row][col] = 0;
            }
        };
    }else{
         //check if number is 0 or not
        if(grid[row][col]!=0){
                //calling function to fill position below the current coors
                fillSudoku(grid, row+1, col);
        }
        //checking which number can be inserted at coors ie at row, col
        for(int i=1;i<=9;i++){
            if(check_col(grid, i, col) && check_row(grid, i, row) && check_grid(grid, row, col, i)){
                //number i can be inserted at this postion
                grid[row][col] = i;
                //calling function to fill position below the current coors
                fillSudoku(grid, row+1, col);
                //removing i from current position to check other possibilities
                grid[row][col] = 0;
            }
        };
    }
    //return ?
    return;
}

int main(){
    int **grid = new int*[9];
    for(int i=0;i<9;i++){
        grid[i] = new int[9];
    };
    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){
            cin >> grid[r][c];
        };
    };
    
    fillSudoku(grid, 0, 0);
    return 0;


}