

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
   
    Rock = 1,
    Paper = 2,
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
        system("color 4F");
        break;
    case Blue:
       system("color 1F");
        break ;
    case Green:
       system("color 2F");
        break;
    default:
        system("color 0F");
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
    cout << "Player Choice   : " << GameChoiceName(gameData.PlayerChoice) << endl;
    cout << "Computer Choice : " << GameChoiceName(gameData.ComputerChoice) << endl;
    cout << "Round Winner    : " << WinnerName(winner) << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

void PrintGameOverHeader() {
    cout << "                               --------------------------------------------------------------------" << endl;
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
    PrintGameOverHeader();
    PrintGameResultHeader();
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
     GameData emptyGameData;
    ConsoleBackgroudColor(enColor::Black);
    gameData.rounds = GameRound();
    FillGameRound(gameData);
    gameData = emptyGameData;
}




enum GameLoop {
    Yes = 1,
    No = 0,
};

bool WantToPlay(char charcters) {

    int number = int(charcters);

    if (number == 121 || number == 89) {
        return true;
    }
    else
    {
        return false;
    }
}
void GameLoop() {
    ConsoleBackgroudColor(enColor::Black);
    GameData gameData;
    bool wantToPlay;
    char again;
    do
    {
        StartGame(gameData);
        ConsoleBackgroudColor(enColor::Black);
        cout << "                               Do you want to play again? Y/N?";
        cin >> again;
        wantToPlay = (bool)WantToPlay(again);
       
    } while (wantToPlay);
    
}

int main()
{
   
    srand((unsigned)time(NULL));
    GameLoop();
}

