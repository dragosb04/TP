#include <stdio.h>
#define N 10

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

int backtracking(int q[][N], int col){
    if (col == N)
        return 1;

    for (int i = 0; i < N; i++){
        if (is_valid(q, i, col)){
            q[i][col] = 1;

            if(backtracking(q, col + 1))
                return 1;

            q[i][col] = 0;
        }
    }
    return 0;
}

int main (void){

    int q[N][N] = {0};

    if (backtracking(q, 0) == 0){
        printf("Nu exista solutie.\n");
    }
    else
        printSolution(q);

    return 0;
}
