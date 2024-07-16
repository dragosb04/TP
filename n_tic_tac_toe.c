#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char** create_table(int size){
    char** table = (char**) malloc(sizeof(char*) * size);
    if (table == NULL)
        return NULL;
    
    for (int i = 0; i < size; i++){
        table[i] = (char*) malloc(sizeof(char) * size);
        for (int j = 0; j < size; j++)
            table[i][j] = '-';
    }
    return table;
}

void players_pick_symbols(char* ply1, char* ply2){
    printf("Player 1 symbol: ");
    if (scanf(" %c", ply1) != 1)
        return;
    *ply1 = toupper(*ply1);
    *ply2 = (*ply1 == 'X') ? 'O' : 'X';
}

void print_table(char** table, int size, char player1, char player2){
    printf("\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (table[i][j] != player1 && table[i][j] != player2)
                printf("-  ");
            else if (table[i][j] == player1)
                printf("%-2c ", player1);
            else
                printf("%-2c ", player2);
        }
        printf("\n");
    }
}

int game_not_over(char** table, int row, int col, int size, char symbol) {
    
	int count;
    
    count = 0;
    for (int j = 0; j < size; j++) {
        if (table[row][j] == symbol)
            count++;
        else
            count = 0;
        if (count == size)
            return 1;
    }
    
    count = 0;
    for (int i = 0; i < size; i++) {
        if (table[i][col] == symbol)
            count++;
        else
            count = 0;
        if (count == size)
            return 1;
    }
    
    count = 0;
    for (int i = 0, j = 0; i < size && j < size; i++, j++) {
        if (table[i][j] == symbol)
            count++;
        else
            count = 0;
        if (count == size)
            return 1;
    }
    
    count = 0;
    for (int i = 0, j = size - 1; i < size && j >= 0; i++, j--) {
        if (table[i][j] == symbol)
            count++;
        else
            count = 0;
        if (count == size)
            return 1;
    }

    return 0;
}

void game_on (char** table, int size, char player1, char player2){
    int i, j, is_in_range = 0, turn = 0;
    char play;
    do {
        is_in_range = 0;
        do {
            if (turn % 2 == 0)
                printf("Player 1, set the coordinates (row col). Must be > 0.\n(Ex: 2 1, 3 2)\nSet: ");
            else
                printf("Player 2, set the coordinates (row col). Must be > 0.\n(Ex: 2 1, 3 2)\nSet: ");        
            
            scanf("%d %d", &i, &j);

            is_in_range = 1;
            if (i > size || i <= 0 || j > size || j <= 0 || table[i-1][j-1] != '-') {
                is_in_range = 0;
                printf("Invalid coordinates. Please try again.\n");
        		print_table(table, size, player1, player2);				
            }

        } while (is_in_range == 0);

        i--;
        j--;

        if (turn % 2 == 0){
            table[i][j] = player1;
            play = player1;
        }
        else{
            table[i][j] = player2;
            play = player2;
        }
        print_table(table, size, player1, player2);
        turn++;
    } while (game_not_over(table, i, j, size, play) == 0);

    printf("Player %d wins!\n", (turn % 2 == 0) ? 2 : 1);
}

int main (int argc, char** argv) {
    if (argc != 2)
        return 1;
    
    char ply1, ply2;
    int size = atoi(argv[1]);

    if (size < 3)
        return 1;

    char** table = create_table(size);
    if (table == NULL)
        return 1;

    players_pick_symbols(&ply1, &ply2);

    printf("\nPlayer 1 symbol: %c\nPlayer 2 symbol: %c\n", ply1, ply2);

    print_table(table, size, ply1, ply2);

    game_on(table, size, ply1, ply2);


    for (int i = 0; i < size; i++)
        free(table[i]);
    free(table);

    return 0;
}
