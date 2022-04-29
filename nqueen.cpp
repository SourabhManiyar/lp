#include<bits/stdc++.h>
using namespace std;

#define n 4

void printSolution(int board[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//to check we can place queen or not at row,col on board
bool isSafe(int board[n][n],int row,int col){
    int i,j;
    //to check this row on left side
    for(i=0;i<col;i++){
        if(board[row][i]) return false;
    }

    //to check left side upper diagonal squares
    for(i=row,j=col;i>=0 && j>=0; i-- ,j--){
        if(board[i][j]) return false;
    }

    //to check left side lower diagonal squares
    for(i=row,j=col;i<n && j>=0;i++,j--){
        if(board[i][j]) return false;
    }

    return true;
}

//to solve n queen problem using backtracking.
//if solved return true else return false.
bool solveProblem(int board[n][n],int col){
    if(col>=n) return true; //base condition
    
    for(int i=0;i<n;i++){

        if(isSafe(board,i,col)){
            board[i][col]=1;

            if(solveProblem(board,col+1)){
                return true;
            }

            board[i][col]=0; //backtrack
        }
    }
    return false;
}

void solve(){
    int board[n][n]={ {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if(solveProblem(board,0)==false){
        cout<<"Solution doesn't exist\n";
        return;
    }

    printSolution(board);
}

int main(){
    solve();
    return 0;
}