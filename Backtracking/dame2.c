#include <stdio.h>
#define N 4

void printSolution(int board[][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j])
                printf("X ");
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid (int q[][N], int row, int col){
    
    for (int i = 0; i < col; i++)
        if (q[row][i])
            return 0;
    
    for (int i = row, j = col; j >= 0 && i >= 0; i--, j--){
        if (q[i][j])
            return 0;
    }

    for (int i = row, j = col; j >= 0 && i < N; i++, j--){
        if (q[i][j])
            return 0;
    }

    return 1;
}

void backtracking(int q[][N], int col){
    if (col == N){
        printSolution(q);
        return;
    }

    for (int i = 0; i < N; i++){
        if (is_valid(q, i, col)){
            q[i][col] = 1;
            backtracking(q, col + 1);
            q[i][col] = 0;
        }
    }

}

int main (void){

    int q[N][N] = {0};

    backtracking(q, 0);

    return 0;
}
