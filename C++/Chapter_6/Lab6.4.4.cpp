#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    string name;
    char mark;
    string choices;
public:
    Player(string name, char mark)
    {
        this->name = name;
        this->mark = mark;
    }
    string get_name();
    char get_mark();
};
string Player::get_name()
{
    return this->name;
}
char Player::get_mark()
{
    return this->mark;
}
class Game
{
public:
    static void board(string playerName1, string playerName2);
    static void playerChoice(int &playerNumb, Player &player1, Player &player2, char &mark, int &choice, string &playerName);
    static int checkWin();
};
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
void Game::board(string playerName1, string playerName2)
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player" << playerName1 << "(X)  -  Player" << playerName2 << "(O)" << endl << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}
void Game::playerChoice(int &playerNumb, Player &player1, Player &player2, char &mark, int &choice, string &playerName)
{
    playerNumb = (playerNumb % 2) ? 1:2;
    playerName = (playerNumb == 1) ? player1.get_name() : player2.get_name();

    cout << "Player " << playerName << ", enter a number:  ";
    cin >> choice;

    mark = (playerNumb == 1) ? player1.get_mark() : player2.get_mark();

    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        cout<<"Invalid move ";
        playerNumb--;
        cin.ignore();
        cin.get();
    }
}
int Game::checkWin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
             && square[4] != '4' && square[5] != '5' && square[6] != '6'
             && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}


int main()
{
    /*int player = 1,i,choice;
    char mark;*/
    Player player1("1", 'X');
    Player player2("2", 'O');
    int playerNumb = 1;
    string playerName;
    char mark;
    int choice;
    int i;
    do
    {
        Game::board(player1.get_name(), player2.get_name());
        Game::playerChoice(playerNumb, player1, player2, mark, choice, playerName);
        i = Game::checkWin();
        playerNumb++;
    }while(i==-1);
    Game::board(player1.get_name(), player2.get_name());
    if(i==1)
    {
        playerNumb--;
        playerName = (playerNumb == 1) ? player1.get_name() : player2.get_name();
        cout<<"==>\aPlayer "<<playerName<<" win ";
    }
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}


