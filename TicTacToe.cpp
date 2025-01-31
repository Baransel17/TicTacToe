#include <iostream>
#include <ctime>
#include <array>
using namespace std;

void board(char *square){
    
    cout << endl;
    cout << "   TIC TAC TOE" << endl;
    cout << endl;
    cout << "     |"<<"     |" <<endl;
    cout << "  "<<square[0]<<"  "<<"|"<<"  "<<square[1]<<"  "<<"|"<<"  "<<square[2]<<endl;
    cout << "_____|"<< "_____|"<<"_____"<< endl;
    cout << "     |"<<"     |" <<endl;
    cout << "  "<<square[3]<<"  "<<"|"<<"  "<<square[4]<<"  "<<"|"<<"  "<<square[5]<<endl;
    cout << "_____|"<< "_____|"<<"_____"<< endl;
    cout << "     |"<<"     |" <<endl;
    cout << "  "<<square[6]<<"  "<<"|"<<"  "<<square[7]<<"  "<<"|"<<"  "<<square[8]<<endl;
    cout << "     |"<<"     |" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

void playerChoice(char playerMark,char *square){

    int choice;
    do
    {
        cout << "Where do you want to place your mark(1-9)?: ";
        cin >> choice;
        choice--;
        if(square[choice]== ' '){
            square[choice] = playerMark;
        }
        else{
            cout << endl;
            cout << "INVALID VALUE!" << endl;
            cout << endl;
        }
    } while (choice < 0 || choice > 10);
    
}

void computerChoice(char computerMark, char* square){
    int choice;
    srand(time(0));
    
    while(true){
        choice = rand() % 9;
        if(square[choice] == ' '){
            square[choice] = computerMark;
            break;
        }
    }
}

bool winner(char* square, char playerMark, char computerMark){

    if((square[0] != ' ' && square[0] == square[1] && square[0] == square[2]) || (square[3] != ' ' && square[3] == square[4] && square[3] == square[5]) || (square[6] != ' ' && square[6] == square[7] && square[6] == square[8])){
        square[0] == playerMark  || square[3] == playerMark || square[6] == playerMark ? cout << endl << "CONGRATS, YOU WON!" << endl : cout << endl <<"YOU LOSE!" << endl;
        return true;        
    }
    if((square[0] != ' ' && square[0] == square[3] && square[0] == square[6]) || (square[1] != ' ' && square[1] == square[4] && square[1] == square[7]) || (square[2] != ' ' && square[2] == square[5] && square[2] == square[8])){
        square[0] == playerMark || square[1] == playerMark || square[2] == playerMark ? cout << endl << "CONGRATS, YOU WON!" << endl : cout << endl <<"YOU LOSE!" << endl; 
        return true;        
    }
    if((square[0] != ' ' && square[0] == square[4] && square[0] == square[8]) || (square[2] != ' ' && square[2] == square[4] && square[2] == square[6])){
        square[0] == playerMark || square[2] == playerMark ? cout << endl << "CONGRATS, YOU WON!" << endl : cout << endl <<"YOU LOSE!" << endl; 
        return true;
    }

    return false;
}

bool draw(char* square){
    
    for(int i = 0; i < 9; i++){
        if(square[i] == ' '){
            return false;
        }
    }
    cout << "It's a draw!" << endl;
    return true;
}

int main(int argc, const char** argv) {

    char playerMark = 'O';
    char computerMark = 'X';
    bool gameRunning = true;

    array<char, 9> square = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; 
    board(square.data());

    while(gameRunning){

        playerChoice(playerMark, square.data());
        board(square.data());
        if(winner(square.data(), playerMark, computerMark)){
            gameRunning = false;
            break;
        }
        else if(draw(square.data())){
            gameRunning =false;
            break;
        }

        computerChoice(computerMark, square.data());
        board(square.data());
        if(winner(square.data(), playerMark, computerMark)){
            gameRunning = false;
            break;
        }
        else if(draw(square.data())){
            gameRunning = false;
            break;
        }
    }

    return 0;
}