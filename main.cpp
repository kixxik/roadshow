#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>
#include <windows.h>
#include <vector> //leaderboards
#include <fstream> // for file input/output
#include <sstream> // for string stream

using namespace std;

// Start art screen
void start()
{
    cout << " _______  _______  ______   _______    ______   _     _   ______  _______  _______  ______    ______ " << endl
         << "(_______)(_______)(______) (_______)  (____  \\ (_)   (_) / _____)(_______)(_______)(_____ \\  / _____)" << endl
         << " _        _     _  _     _  _____      ____)  ) _     _ ( (____      _     _____    _____) )( (____  " << endl
         << "| |      | |   | || |   | ||  ___)    |  __  ( | |   | | \\____ \\    | |   |  ___)  |  __  /  \\____ \\ " << endl
         << "| |_____ | |___| || |__/ / | |_____   | |__)  )| |___| | _____) )   | |   | |_____ | |  \\ \\  _____) )" << endl
         << " \\______) \\_____/ |_____/  |_______)  |______/  \\_____/ (______/    |_|   |_______)|_|   |_|(______/" << endl
         << "                                         PRESS ENTER                                                  " << endl;
}

void menu()
{
    cout << "1. The Code Busters is open for all participants of the 13th ICT Roadshow\n";
    cout << "2. You are challenged to answer questions about GENERAL PROGRAMMING.\n";
    cout << "3. You are given 2 mins to answer questions as many as you can.\n";
    cout << "4. Each right response awards points, and each wrong response subtracts points.\n";
    cout << "5. Players highest scores will be tracked and exhibited. Motivates players to increase their performance by encouraging friendly\ncompetition.\n";
    cout << "6. A tip/recommendation box  is displayed, everyone is encouraged to give us any amount that comes from your heart.\n";
}

// Loading animation
void LoadingAnimation()
{
    char bar1 = 177, bar2 = 219; // defining variable bar1 and bar2
    // print a loading message
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t Loading...";
    cout << "\n\n\n\t\t\t\t"; // empty line
    // print 25 bar1
    for (int bar = 0; bar < 25; bar++)
        cout << bar1;

    cout << "\r"; // to move the cursor to the beginning of the line
    cout << "\t\t\t\t"; // empty line

    // print 25 bar2
    for (int bar = 0; bar < 25; bar++)
    {
        cout << bar2;
        Sleep(80); // pause for 80 milliseconds
    }
}
//basta doon sa start screen
void pressAnyKey()
{
    cin.ignore();
    cin.get();
    //getchar();
}

//  questions
void getQuestions(string questions[], char choice)
{
    if (choice == 'a' || choice == 'A')
    {
    questions[0] = "1. User Input?\n(a) CIN\n(b) COUT\n";
    questions[1] = "2. What is the command to print 'Hello, World!' in C++?\n(a) cout << 'Hello, World!';\n(b) printf('Hello, World!')\n";
    questions[2] = "3. Use to display something on the screen?\n(a) CIN\n(b) COUT\n";
    questions[3] = "4. Who Invented C++?\n(a) Bjarne Stroustrup \n(b)Thomas C++  \n";
    questions[4] = "5. Which of the following is used for comments in C++?\n(a) /*  */\n(b) $$\n";
    questions[5] = "6. Which of the following user-defined header file extesion used in C++?\n(a) ccp\n(b) cpp\n";
    questions[6] = "7. Where does the execution of the program stars?\n(a) main function\n(b) void function\n";
    questions[7] = "8. What is used to terminate the function declaration?\n(a) :\n(b) ;\n";
    questions[8] = "9. What is the scope of the variable declared in the user definied function?\n(a) Whole Program\n(b) only inside the {} block\n";
    questions[9] = "10.What will you use if you are not intended to get a return value?\n(a) static\n(b) void\n";
    }
    else if (choice == 'b' || choice == 'B')
    {
    questions[0] = "1. What is Programming?\n(a) Coding\n(b) Depression\n";
    questions[1] = "2. A variable in programming?\n(a) Store\n(b) Carry\n";
    questions[2] = "3. What is loop in programming?\n(a) Exit\n(b) Repeat\n";
    questions[3] = "4. What is Debugging?\n(a) Fixing \n(b) Eliminating\n";
    questions[4] = "5. What is a compiler?\n(a) translate\n(b) coordinate";
    questions[5] = "6. Is a theory that places one element inside of another?\n(a) If Statement\n(b) Nested If Statement\n";
    questions[6] = "7. Is used if the value of a variable does not match any of the cases ?\n(a) Default \n(b) main function\n";
    questions[7] = "8. Terminates the switch case statement?\n(a) end\n(b) break\n";
    questions[8] = "9. Used for large floating-point numbers?\n(a) Large Double\n(b) Long Double\n";
    questions[9] = "10.Stores sequence of characters (text)?\n(a) strung\n(b) string\n";
    }
    else if (choice == 'c' || choice == 'C')
    {
    questions[0] = "1. The first C++ compiler known as?\n(a) Cfront\n(b) C++xxx\n";
    questions[1] = "2. The first true compiler written by?\n(a) Michael Tiemann G++\n(b) Cyrus Mae H++\n";
    questions[2] = "3. Template that describes the behaviors that object of its type support?\n(a) Mass\n(b) Class\n";
    questions[3] = "4. Sequence of instructions that the computer executes?\n(a) Program \n(b) Disc\n";
    questions[4] = "5. Locate or detect and correct error?\n(a) debugging\n(b) coordinating";
    questions[5] = "6. Can't directly access computer memory and work with the data?\n(a) low level programing language\n(b) high level programming language\n";
    questions[6] = "7. 0's and 1's ?\n(a) Binary \n(b) Cannary\n";
    questions[7] = "8. Terminates main function?\n(a) stop\n(b) return 0;\n";
    questions[8] = "9. Is a function in C++ where program execution begins?\n(a) lint main{}\n(b) int main()\n";
    questions[9] = "10.Collection of functions?\n(a) binary\n(b) library\n";
    }
    
    }
//scoring and timer
bool askQuestion(const string& question, char correctAnswer, int& score, bool& timeExpired)
{
    cout << question << " (Choose 'a' or 'b'): ";
    auto startTime = chrono::steady_clock::now();

    char playerAnswer;
    cin >> playerAnswer;

    auto endTime = chrono::steady_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();

    if (elapsedTime >= 10)
    {
        cout << "Time's up!" << endl;
        timeExpired = true; // set timeExpired to true
        return false;
    }
    else
    {
        if (playerAnswer == correctAnswer)
        {
            if (elapsedTime <= 3)
                score += 3;
            else if (elapsedTime <= 6)
                score += 2;
            else
                score += 1;
        }
        //------------------------------------------------
        return playerAnswer == correctAnswer;
    }
}
struct PlayerScore
{
    string playerName;
    int score;

    PlayerScore(const string& name, int score) : playerName(name), score(score) {}
};

bool comparePlayerScores(const PlayerScore& a, const PlayerScore& b)
{
    return a.score > b.score;
}

void displayLeaderboard(const vector<PlayerScore>& scores)
{
    cout << "\nLEADERBOARD\n";
    cout << "-------------------------\n";
    cout << "Player\t\tScore\n";
    cout << "-------------------------\n";

    for (const PlayerScore& score : scores)
    {
        cout << score.playerName << "\t\t" << score.score << "\n";
    }

    cout << "-------------------------\n";
}

void saveLeaderboard(const vector<PlayerScore>& scores)
{
    ofstream outputFile("leaderboard.txt");

    if (outputFile.is_open())
    {
        for (const PlayerScore& score : scores)
        {
            outputFile << score.playerName << " " << score.score << "\n";
        }

        outputFile.close();
    }
    else
    {
        cout << "Unable to save leaderboard." << endl;
    }
}

vector<PlayerScore> loadLeaderboard()
{
    vector<PlayerScore> scores;

    ifstream inputFile("leaderboard.txt");

    if (inputFile.is_open())
    {
        string line;

        while (getline(inputFile, line))
        {
            istringstream iss(line);
            string playerName;
            int score;

            if (iss >> playerName >> score)
            {
                scores.push_back(PlayerScore(playerName, score));
            }
        }

        inputFile.close();
    }
    else
    {
        cout << "Unable to load leaderboard." << endl;
    }

    return scores;
}

int main()
{
    // Declarations
    string playerName;
    char playAgain,choice;

    // Start screen
    start();
    pressAnyKey();
    system("cls");

    LoadingAnimation();

    // After loading animation
    system("cls");
    cout << "   a) mikaela\n";
    cout << "   b) mae\n";
    cout << "   c) de guzman\n";
    cout << "Choose from the three (a/b/c) for your questions to be ready: ";
    cin  >> choice;
    system("cls");
    menu();


    do {
        cout << "Enter your Name to play the Game: ";
        cin >> playerName;
        system("cls");



        // Declaration again
        int score = 0;
        string questions[10];
        getQuestions(questions,choice);
        
        // Answer key answer[10]
        char answers[10] = { 'a', 'a', 'b','a', 'a', 'b', 'a', 'b' ,'b', 'b' };
        //para di ko madelete askQuestion(questions[i], answers[i], score, timeExpired)
        bool timeExpired = false; // Initialize timeExpired to false
        
        for (int i = 0; i < 10; i++) { // Use the correct number of questions
            cout << "\nQuestion " << (i + 1) << endl;
            bool isAnswerCorrect = askQuestion(questions[i], answers[i], score, timeExpired);
            
            if (isAnswerCorrect) {
                cout << "Correct! ";
            }else {
                cout << "Incorrect! ";
            }
            cout << "Current Score: " << score << endl;

            // 1 second before moving to the next question
            Sleep(800);
            //this_thread::sleep_for(chrono::seconds(1));

            if (timeExpired) {
                break; // Move to the next question
            }
        }

        cout << "\nQuiz finished!" << endl;
        cout << "Final Score: " << score << " points out of 30" << endl;

        system("cls");

        vector<PlayerScore> leaderboard = loadLeaderboard();

        leaderboard.push_back(PlayerScore(playerName, score));

        sort(leaderboard.begin(), leaderboard.end(), comparePlayerScores);

        displayLeaderboard(leaderboard);

        saveLeaderboard(leaderboard);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
