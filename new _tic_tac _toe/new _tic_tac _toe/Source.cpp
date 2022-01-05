#include <iostream>
using namespace std;
int n_players = 2;
const int N = 3;
const char marks[2] = { 'X', 'O' };
char grid[N][N];

//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid() {
    cout << "Player 1: " << marks[0] << "  vs  Player 2: " << marks[1] << "\n";
    cout << "--";
    for (int i = 0; i < N; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < N; cout << "---", i++);
        cout << "--\n";
    }
}
//This function checks if the game has a win state or not
bool check_win() {
    // check for rows :

    for (int row = 0; row <= 2; row++) {
        if (grid[row][0] == 'X' && grid[row][1] == 'X' && grid[row][2] == 'X')
            return true;
    }
    for (int row = 0; row <= 2; row++) {
        if (grid[row][0] == 'O' && grid[row][1] == 'O' && grid[row][2] == 'O')
            return true;
    }

    // check for colum : 
    for (int colum = 0; colum <= 3; colum++) {
        if (grid[0][colum] == 'X' && grid[1][colum] == 'X' && grid[2][colum] == 'X')
            return true;
    }
    for (int colum = 0; colum <= 3; colum++) {
        if (grid[0][colum] == 'O' && grid[1][colum] == 'O' && grid[2][colum] == 'O') {
            return true;
        }

    }
    //check for diagonal:
    if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X')
        return true;
    else if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O')
        return true;
    else if (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')
        return true;
    else if (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O')
        return true;
    else
        return false;

}
//This function checks if the game has a tie state or not for the given mark
bool check_tie_player(char mark) {
    int counter = 0;
    int bigcounter = 0;
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == mark || grid[i][1] == mark || grid[i][2] == mark) {
            counter++;
        }

    }
    if (counter == 2) {
        bigcounter++;

    }
    else
        return false;
    for (int j = 0; j < 3; j++) {
        if (grid[j][0] == mark || grid[j][1] == mark || grid[j][2] == mark) {
            counter++;
        }

    }
    if (counter == 2) {
        bigcounter++;

    }
    else
        return false;
    {
        if (grid[0][0] == mark || grid[1][1] == mark || grid[2][2] == mark) {
            counter++;
        }
        if (grid[2][0] == mark || grid[2][1] == mark || grid[0][2] == mark) {
            counter++;
        }

    }
    if (counter == 2) {
        bigcounter++;

    }
    else
        return false;
    if (bigcounter == 6) {

        return true;
    }
    else
        return false;

}
//This function checks if the game has a tie state or not
bool check_tie() {
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
}
//This function checks if given cell is empty or not 
bool check_empty(int i, int j) {
    if (grid[i][j] == ' ')
        return true;
    else
        return false;

}
//This function checks if given position is valid or not 
bool check_valid_position(int i, int j) {
    if (i >= 0 && i <= 3 && j >= 0 && j <= 3) {
        return true;
    }
    else
        return false;
}
//This function sets the given mark to the given cell
void set_cell(int i, int j, char mark) {
    grid[i][j] = mark;
}

//This function clears the game structures
void grid_clear() {
    for (int row = 0; row <= 3; row++) {
        for (int colum = 0; colum <= 3; colum++) {
            grid[row][colum] = ' ';
        }
    }
}
//This function reads a valid position input
void read_input(int& i, int& j) {
    cout << "Enter the row index and column index: ";
    cin >> i >> j;
    while (!check_valid_position(i, j) || !check_empty(i, j)) {
        cout << "Enter a valid row index and a valid column index: ";
        cin >> i >> j;
    }
}
//MAIN FUNCTION
void play_game() {
    cout << "Tic-Tac-Toe Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    bool player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input position from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i, j;
        read_input(i, j);
        //Set the player mark in the input position
        set_cell(i, j, marks[player]);
        //Check if the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }
        //Check if the grid has a tie state
        if (check_tie()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }
        //Player number changes after each turn
        player = 1 - player;
    }
}

int main() {
    while (true) {
        grid_clear();
        play_game();
        char c;
        cout << "Play Again [Y/N] ";
        cin >> c;
        if (c != 'y' && c != 'Y')
            break;
    }
}