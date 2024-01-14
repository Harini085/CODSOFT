#include <iostream>
using namespace std;

// Function
void display_board(char board[3][3]);

bool make_move(char board[3][3], char current_player, int row, int col);

bool check_win(char board[3][3], char current_player);

bool check_draw(char board[3][3]);


   bool is_valid_move(char board[3][3], int row, int col);
   
char switch_player(char current_player);

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char current_player = 'X';
    int row, col;

    do {
        // Display the current state of the board
        display_board(board);

        // Prompt the current player for their move
        cout << "Player " << current_player << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid and update the board
        if (is_valid_move(board, row, col) && make_move(board, current_player, row, col)) {
            // Check for a win
            if (check_win(board, current_player)) {
                display_board(board);
                cout << "Player " << current_player << " wins!" << endl;
                break;
            }

            // Check for a draw
            if (check_draw(board)) {
                display_board(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players
            current_player = switch_player(current_player);
        } else {
            cout << "Invalid move. Try again." << endl;
        }

    } while (true);

    // Ask if the players want to play again
    char play_again;
    cout << "Do you want to play again? (y/n): ";
    cin >> play_again;

    if (play_again == 'y' || play_again == 'Y') {
        // Reset 
        main();
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}

// Function 

void display_board(char board[3][3]) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
cout << board[i][j];
            if (j < 2) {
          cout << "|";
            }
        }
        cout << endl;
        if (i<2) {
            cout << "  -----" << endl;
        }
    }
    cout << endl;
}

bool make_move(char board[3][3], char current_player, int row, int col) {
	
    if (board[row][col] == ' ') {
    	
        board[row][col] = current_player;
        return true;
    } 
	else {
		
        return false; // invalid
    }
}

bool check_win(char board[3][3], char current_player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
    	
        if ((board[i][0] == current_player  && board[i][1] == current_player &&  board[i][2] == current_player) ||
            (board[0][i] == current_player &&  board[1][i] == current_player && board[2][i] == current_player)) 
			{
            return true;
        }
    }

    if ((board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) ||
        (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)) 
        
		{
        return true;
    }

    return false;
}

bool check_draw(char board[3][3]) {
	
    // ---- board is full (draw)
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (board[i][j] == ' ') {
           return false; //---the board is not full
            } } }

    return true; // ----the board is full (draw)
}

bool is_valid_move(char board[3][3], int row, int col) 
{
    // Check if the move is within the bounds of the board
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

char switch_player(char current_player) {
    // Switch X and O
    return (current_player == 'X') ? 'O' : 'X';
}

