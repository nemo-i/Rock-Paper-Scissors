// Rock-Paper-Scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <math.h>
#include <cstdio>
using namespace std;

int ReadNumber(bool OnlyPostive = true) {
    int number;
    cin >> number;
    if (OnlyPostive) {
        return abs(number);
    }
    else
    {
        return number;
    }
}

int GameRound() {
    int number;
    do
    {
       cout << "How Many Rounds 1 to 10" << endl;
       number =  ReadNumber();
    } while (number<1&&number>10);
    return number;
}
enum GameChoices {
    Paper = 1,
    Rock = 2,
    Scissor = 3,
};

GameChoices ReadUserChoice() {
   cout << "Your choice: [1]:Rock, [2]:Paper, [3]:Scissors ?";
   return (GameChoices)ReadNumber();
}
int RandomNumber(int from, int to) {
    // to make this function work probably put this code in main file 
    //srand((unsigned)time(NULL));
    return rand() % (to - from + 1) + from;
}

GameChoices ComputerCohice() {
    return (GameChoices)RandomNumber(1,3);
}
struct GameData {
    GameChoices PlayerChoice;
    GameChoices ComputerChoice;
    int playerWins = 0;
    int computerWins = 0;
    int draws = 0;
    int rounds = 0;

};

enum Winner
{
    Player,
    Computer,
    Draw,
};

string  WinnerName(Winner winner) {
    switch (winner)
    {
    case Player:
        return "Player";
        break;
    case Computer:
        return "Computer";
        break;
    case Draw:
        return "No One";
        break;

    };
}

    Winner GameLogic(GameData gameData) {
        if (gameData.PlayerChoice == GameChoices::Paper && gameData.ComputerChoice == GameChoices::Rock) {
            return   Winner::Player;
        }
        else if (gameData.PlayerChoice == GameChoices::Rock && gameData.ComputerChoice == GameChoices::Scissor)
        {
            return  Winner::Player;
        }
        else if (gameData.PlayerChoice == GameChoices::Scissor && gameData.ComputerChoice == GameChoices::Paper)
        {
            return Winner::Player;
        }
        else if (gameData.PlayerChoice == gameData.ComputerChoice) {
            return Winner::Draw;
        }
        else
        {
            return Winner::Computer;
        };
    };

enum enColor {
    Red,
    Blue,
    Green,
    Black,
};
void ConsoleBackgroudColor(enColor color) {
    switch (color)
    {
    case Red:
        system("color 4");
        break;
    case Blue:
       system("color 1");
        break ;
    case Green:
       system("color 2");
        break;
    default:
        system("color 0");
        break;
    }
}
void ComputerWinSound() {
    cout << "\a";
}

void GameEffects(Winner winner) {
    switch (winner)
    {
    case Player:
        ConsoleBackgroudColor(enColor::Green);
        break;
    case Computer:
        ComputerWinSound();
        ConsoleBackgroudColor(enColor::Red);
        break;
    case Draw:
        ConsoleBackgroudColor(enColor::Blue);
        break;
    default:
        ConsoleBackgroudColor(enColor::Black);
        break;
    }
}

Winner FillGameData(GameData& gameData) {
    Winner winner = GameLogic(gameData);
    if (winner == Winner::Player) {
        GameEffects(winner);
        gameData.playerWins++;
    }
    else if (winner == Winner::Computer) {
        GameEffects(winner);
        gameData.computerWins++;
    }
    else
    {
        GameEffects(winner);
        gameData.draws++;
    }

    return winner;
}

string GameChoiceName(GameChoices gameChoice) {
    switch (gameChoice)
    {
    case Rock:
        return "Rock";
        break;
    case Paper:
        return "Paper";
        break;
    case Scissor:
        return "Scissor";
        break;
    default:
        return "Not Found";
        break;
    }
}


void PrintRoundResults(GameData gameData,int roundNumber,Winner winner) {
    cout << "-------------- Round [" << roundNumber + 1 << "] -------------------" << endl;
    cout << "Player Choice : " << GameChoiceName(gameData.PlayerChoice) << endl;
    cout << "Computer Choice : " << GameChoiceName(gameData.ComputerChoice) << endl;
    cout << "Round Winner : " << WinnerName(winner) << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

void PrintGameOverHeader() {
    cout << "                               --------------------------------------------------------------------" << endl;
    cout << "                               ---------------------------+++ Game Over +++------------------------" << endl;
    cout << "                                                          +++ Game Over +++                        " << endl;
    cout << "                               --------------------------------------------------------------------" << endl;
}
void PrintGameResultHeader() {
    cout << "                                                            [ Game Results ]                          " << endl;
}

string FinalWinner(GameData gameData) {
    if (gameData.playerWins > gameData.computerWins) {
        return WinnerName(Winner::Player);
    }
    else if (gameData.playerWins == gameData.computerWins)
    {
        return WinnerName(Winner::Draw);
    }
    else
    {
        return WinnerName(Winner::Computer);
    }
}

void PrintGameResults(GameData gameData) {
    cout << "                               Game Rounds           : " << gameData.rounds<<endl;
    cout << "                               Player Win Times      : " << gameData.playerWins << endl;
    cout << "                               Computer Win Times    : " << gameData.computerWins << endl;
    cout << "                               Draw Times            : " << gameData.draws << endl;
    cout << "                               Final Winner          : " << FinalWinner(gameData) << endl;
    cout << "                               --------------------------------------------------------------------" << endl;
}

void FillGameRound(GameData &gameData) {
   
    
    Winner winner;
    for (short i = 0; i < gameData.rounds; i++)
    {
       cout << "Round [" << i + 1 << "] " << "begins:" << endl;
       gameData.PlayerChoice = ReadUserChoice();
       gameData.ComputerChoice = ComputerCohice();
       winner=FillGameData(gameData);
       PrintRoundResults(gameData,i,winner);
    }
    PrintGameResults(gameData);

}

void StartGame(GameData &gameData) {

    ConsoleBackgroudColor(enColor::Black);
    gameData.rounds = GameRound();
    FillGameRound(gameData);
}

enum GameLoop 
void GameLoop()

int main()
{
    GameData gameData;
    srand((unsigned)time(NULL));
    StartGame(gameData);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
