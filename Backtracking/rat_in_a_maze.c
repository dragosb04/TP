#include <stdio.h>
#define SIZE_COL 5

int sol[SIZE_COL][SIZE_COL];

int is_validPlace(int map[][SIZE_COL], int x, int y) {
   if (x >= 0 && x < SIZE_COL && y >= 0 && y < SIZE_COL && map[x][y] == 1)
      return 1;
   return 0;
}

int rat_in_a_maze (int map[][SIZE_COL], int x, int y){
    if (x == SIZE_COL - 1 && y == SIZE_COL - 1 && map[x][y] == 1){
        sol[x][y] = 1;
        return 1;
    }

    if (is_validPlace(map, x, y) == 1){
        sol[x][y] = 1;

        if (rat_in_a_maze(map, x + 1, y))
            return 1;
        if (rat_in_a_maze(map, x, y + 1))
            return 1;
        
        sol[x][y] = 0;
        return 0;
    }
    return 0;
}

void print_sol(int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

int main (void){

    int map[][SIZE_COL] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {1, 1, 1, 0, 1}
    };

    if(rat_in_a_maze(map, 0, 0))
        print_sol(SIZE_COL);
    else
        printf("Nu exista cale.\n");

    return 0;
}
