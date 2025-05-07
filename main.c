#include <stdio.h>
// criei o tabuleiro do jogo
char board[3][3];

// jogador atual
char currentPlayer = 'X';

//    0 | 0 | 0
//    0 | 0 | 0
//    0 | 0 | 0


void initializeBoard() {
  for (int i = 0; i < 3 ;  i++)
    for (int j =0; j < 3; j++)
      board[i][j] = ' ';
}

// tabuleiro depois da funcao
//     |  | 
//     |  | 
//     |  | 

void printBoardWithOptions() {
  printf("\nTabuleiro:\n");
  for (int i=0; i<3; i++) {
    for (int j=0; j< 3; j++) {
      int pos = i * 3 + j + 1;

      if (board[i][j] == ' ')
        printf(" %d ", pos);
      
      else 
        printf(" %c ", board[i][j]);
      
      if ( j < 2 )
        printf("|");

      }
    if ( i < 2 )
      printf("\n-----------\n");
  }
  printf("\n");
}

// tabuleiro mostrado na tela
//    1 | 2 | 3
//    4 | 5 | 6
//    7 | 8 | 9

int isWinner() {
  for (int i =0; i < 3 ; i++) {
    //verifica se o jogador completou uma linha
    if (board[i][0] == currentPlayer  && board[i][1] == currentPlayer && board[i][2] == currentPlayer )
      return 1;
      // exemplo
      //    X | X | X
      //    4 | 5 | 6
      //    7 | 8 | 9

    //verifica se o jogador completou uma coluna

    if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
      return 1;
    // exemplo
    //    1 | 2 | X
    //    4 | 5 | X
    //    7 | 8 | X
  }

  if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    return 1;
    // exemplo
    //    X | 2 | 3
    //    4 | X | 6
    //    7 | 8 | X

  if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    return 1;
    // exemplo
    //    1 | 2 | X
    //    4 | X | 6
    //    X | 8 | 9

  return 0;
}

 // retornar 0 se for tiver um espaço vazio e 1, se não.
int isDraw() {
  for(int i =0; i<3; i++ ) 
    for(int j =0 ; j<3 ; j++)
      if (board[i][j] == ' ')
        return 0;
  return 1;
}


// funcao para alternar os jogadores
void switchPlayer() {
  if (currentPlayer == 'X')
    currentPlayer = 'O';
  else 
    currentPlayer = 'X';
}

void makeMove() {
  int pos; 
  while (1) {
    printf("Jogador %c, escolha uma posição entre 1-9: ", currentPlayer);
    scanf("%d", &pos);

    // [1, 9]
    if (pos >= 1 && pos <=9) {
      int row = (pos - 1)/3;
      int col = (pos - 1) % 3;

      if (board[row][col] == ' '){
        board[row][col] = currentPlayer;
        break;
      } else 
        printf("Essa posição já está ocupada.\n");
    } else
      printf("A posição %d é inválida. Tente de novo.\n", pos);
  }
}



int main() {

  initializeBoard();
  while(1) {
    printBoardWithOptions();
    makeMove();
    if(isWinner()){
      printBoardWithOptions();
      printf("Jogardor %c venceu!\n", currentPlayer);
      break;
    } if (isDraw())  {
      printBoardWithOptions();
      printf("Deu velha!\n");
      break;
    }
    switchPlayer();
  }
  return 0;
}