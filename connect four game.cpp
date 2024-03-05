
//  purpose : this game is connect_four, it played between 2 players the winner who
//            select 4 sequence box there could be horizontal or vertical or diagonal and if all box has been selected
//            the game will print draw
// Author: Amr Khaled Ahmed Abd Al Hamid Mohammed.
// version 2.0
// date of creating : 26/2

#include <iostream>
#include <thread>

using namespace std;

bool check_for_draw();
int check_for_string();
bool check_for_winner();
void game_frame();

// I defined the frame of the game as a global variable to edit and use it in any part of my code
int row, column;

string frame[7][7] = {
         {"#","#","#","#","#","#","#"}
        ,{"#","#","#","#","#","#","#"}
        ,{"#","#","#","#","#","#","#"}  //win conditions for 1=64
        ,{"#","#","#","#","#","#","#"}  //(3*6)+(4*7)+2(1+2+3+2+1)
        ,{"#","#","#","#","#","#","#"}
        ,{"#","#","#","#","#","#","#"}
        ,{"I","I","I","I","I","I","I"} };


int main() {
    //print welcome massage
    cout << "Hello, welcome to my PvP connect four game\nhave a nice game\n";
    // To remake the board for new game
    for (int i = 0; i < 7; i++) { for (int j = 0; j < 7; j++) { frame[i][j] = "#"; } }
    bool win, draw;
    string player_1, player_2, player, symbol_1, symbol_2, symbol;
    cout << "please p1,enter your name:\n";
    cin >> player_1;
    cout << "Please " << player_1 << " choose your symbol: 1-->O , 2-->X \n";
    cin >> symbol_1;

    while (!(symbol_1 == "1" || symbol_1 == "2")) {
        cout << "Invalid Choice, Please " << player_1 << " choose your symbol: 1-->O , 2-->X \n";
        cin >> symbol_1;
    }
    if (symbol_1 == "1") {
        symbol_1 = "O";
        symbol_2 = "X";
    }
    else {
        symbol_1 = "X";
        symbol_2 = "O";
    }

    cout << "please p2,enter your name:\n";
    cin >> player_2;
    while (player_1 == player_2) {
        cout << "please p2,choose a different name:\n";
        cin >> player_2;
    }

    cout << "Ok\n" << player_1 << " your symbol is " << symbol_1 << endl
         << player_2 << " your symbol is " << symbol_2 << endl << "let`s start " << endl;

    this_thread::sleep_for(chrono::seconds(1));

    player = player_1;
    symbol = symbol_1;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while (true) {
        game_frame();
        cout << player << ", turn \nyour symbol is " << symbol
             << "\nEnter the box you want by the following order: row : column \n";

        do {
            cout << "Enter the row:";
            row = check_for_string();
            // check if correct row
            while (row > 6) {
                cout << "Please enter the an exist row:";
                row = check_for_string();
            }
            cout << "Enter the column:";
            column = check_for_string();
            // check if correct column
            while (column > 7) {
                cout << "Please enter the an exist column:";
                column = check_for_string();
            }
            // check if the chosen box in correct place
            while (frame[row][column - 1] == "#") {
                if (row == 6) { break; }
                cout << "Please choose a correct box: \n";
                cout << "Enter the row:";
                row = check_for_string();
                // check if correct row
                while (row > 6) {
                    cout << "Please enter the an exist row:";
                    row = check_for_string();
                }
                cout << "Enter the column: ";
                column = check_for_string();
                // check if correct column
                while (column > 7) {
                    cout << "please enter an exist column: \n";
                    column = check_for_string();
                }
            }
            // to print the error message
            if (!(frame[row - 1][column - 1] == "#")) {
                cout << "Please select an empty box: ";
            }
            // if the box was not empty repeat the input
        } while (!(frame[row - 1][column - 1] == "#"));


        frame[row - 1][column - 1] = symbol;
        win = check_for_winner();
        if (win) {
            game_frame();
            // print the winner
            cout << "****** Player " << player << " Win ******\n" << "****** Nice trick " << player << " ******" << endl << endl
                 << "do you want to play again?\n";
            // this part to ask for play again.
            string choice;
            cout << "press Y if yes N if no";
            cin >> choice;
            // her i will validate to enter N or Y
            while (!(choice == "N" || choice == "Y")) {
                cout << "Invalid choice. please choose Y or N\n";
                cin >> choice;
            }
            if (choice == "Y") {
                main();
            }
            else
                cout << "\nThank you for playing\nHave a nice day\n ";
            this_thread::sleep_for(chrono::seconds(1));
            return 0;

        }
        draw = check_for_draw();
        if (draw) {
            // this part to check if there is draw or no
            cout << "****** Draw ******\n" << "it was a nice game\nDo you want to continue\n";

            cout << "press Y if yes N if no\n";
            string choice;
            cin >> choice;
            // her i will validate to enter N or Y
            while (!(choice == "N" || choice == "Y")) {
                cout << "Invalid choice. please choose Y or N\n";
                cin >> choice;
            }
            if (choice == "Y") {
                main();

            }
            else
                cout << "\nThank you for playing\nHave a nice day\n ";
            this_thread::sleep_for(chrono::seconds(1));
            return 0;

        }

        // to swap between players and them symbols
        if (player == player_1) {
            player = player_2;
            symbol = symbol_2;
        }
        else {
            player = player_1;
            symbol = symbol_1;
        }

    }
}


void game_frame() {
    //print the play frame.
    for (int i = 0; i <= 5; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j <= 6; j++) {
            cout << frame[i][j] << " ";
        }
        cout << endl;
    }
    cout << "  1 2 3 4 5 6 7 " << endl << endl;
}


int check_for_string() {
    //to validate for the row and column is string or no
    string x;
    cin >> x;
    while (true) {
        bool is_digit = true;
        for (char i : x) {
            if (isdigit(i) == 0) {
                is_digit = false;
                break;
            }
        }
        if (is_digit) {
            int y = stoi(x);

            return y;
        }
        else {
            cout << "Please enter an integer: " << endl;
            cin >> x;
        }
    }
}


bool check_for_winner() {
    int nRows = 6;
    int nCols = 7;
    // Check horizontal lines
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols - 3; ++j) {
            if (frame[i][j] != "#" && frame[i][j] == frame[i][j + 1] && frame[i][j] == frame[i][j + 2] && frame[i][j] == frame[i][j + 3]) {
                return true;
            }
        }
    }

    // Check vertical lines
    for (int i = 0; i < nRows - 3; ++i) {
        for (int j = 0; j < nCols; ++j) {
            if (frame[i][j] != "#" && frame[i][j] == frame[i + 1][j] && frame[i][j] == frame[i + 2][j] && frame[i][j] == frame[i + 3][j]) {
                return true;
            }
        }
    }

    // Check diagonal lines (top-right to bottom-left)
    for (int i = 0; i < nRows - 3; ++i) {
        for (int j = 3; j < nCols; ++j) {
            if (frame[i][j] != "#" && frame[i][j] == frame[i + 1][j - 1] && frame[i][j] == frame[i + 2][j - 2] && frame[i][j] == frame[i + 3][j - 3]) {
                return true;
            }
        }
    }
    // Check diagonal lines (top-left to bottom-right)
    for (int i = 0; i < nRows - 3; ++i) {
        for (int j = 0; j < nCols - 3; ++j) {
            if (frame[i][j] != "#" && frame[i][j] == frame[i + 1][j + 1] && frame[i][j] == frame[i + 2][j + 2] && frame[i][j] == frame[i + 3][j + 3]) {
                return true;
            }
        }
    }
    return false;
}


bool check_for_draw() {
    // check for draw by (if the frame box doesn`t contain any "#" symbol return true for draw).
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (frame[i][j] == "#")return false;
        }
    }
    return true;
}


