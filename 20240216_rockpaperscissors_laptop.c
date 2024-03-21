#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define TIE 0
#define PLAYER1_WINS 1
#define PLAYER2_WINS 2

//Determines the winner of a rock, paper, scissors game
//Inputs: player1_move {char} - player 1's move, 'r' (rock), 'p' (paper) or 's'
//(scissors)
//Return: {int} - 0 if there is a tie, 1 if player 1 wins, 2 if player 2 wins, -1 if failure
int determine_winner(char player1_move, char player2_move) {

    if (player1_move != 'r' && player1_move != 'p' && player1_move != 's') {
        return -1;
    }

    if (player2_move != 'r' && player2_move != 'p' && player2_move != 's') {
        return -1;
    }

    if (player1_move == 'r' && player2_move == 'r') {
        return 0;
    } else if (player1_move == 'r' && player2_move == 's') {
        return 1;
    } else if (player1_move == 'r' && player2_move == 'p') {
        return 2;
    } else if (player1_move == 's' && player2_move == 'r') {
        return 2;
    } else if (player1_move == 's' && player2_move == 's') {
        return 0;
    } else if (player1_move == 's' && player2_move == 'p') {
        return 1;
    } else if (player1_move == 'p' && player2_move == 'r') {
        return 1;
    } else if (player1_move == 'p' && player2_move == 's') {
        return 2;
    } else if (player1_move == 'p' && player2_move == 'p') {
        return 0;
    }

    //We should not get here 
    return -1;
}

//Asks the user to type in a move
//Inputs: player_name {string} - the player's name
//Return: move {char} - the user's move
char prompt_for_move(char* player_name) {
    player_name[strlen(player_name) - 1] = '\0';
    char move;
    printf("Type r for rock, p for paper, s for scissors\n");
    printf("%s, enter your move: ", player_name);
    scanf(" %c", &move);;
    return move;
}

int main() {
    printf("Welcome to rock, paper, scissors\n");

    char player1_move;
    char player2_move;

    char player1_name[100];
    char player2_name[100];

    printf("Player 1, enter your name\n");
    printf(">");
    fgets(player1_name, 100, stdin);

    printf("Player 2, enter your name\n");
    printf(">");
    fgets(player2_name, 100, stdin);

    player1_move = prompt_for_move(player1_name);
    player2_move = prompt_for_move(player2_name);

    printf("\nPlayer 1 move: %c\n", player1_move);
    printf("Player 2 move: %c\n", player2_move);

    int result = determine_winner(player1_move, player2_move);

    if (result == TIE) {
        printf("Tie!\n");
    } else if (result == PLAYER1_WINS) {
        printf("Player 1 wins!\n");
    } else if (result == PLAYER2_WINS) {
        printf("Player 2 wins!\n");
    } else {
        printf("determine_winner returned %d\n", result);
    }

    return 0;
}

