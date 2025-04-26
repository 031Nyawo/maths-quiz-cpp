#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>

using namespace std;

int getRangeFromDifficulty(string level) {
    if (level == "easy") return 10;
    if (level == "medium") return 50;
    if (level == "hard") return 100;
    return 10;
}

void saveHighScore(int score) {
    ofstream file("highscore.txt");
    if (file.is_open()) {
        file << score;
        file.close();
    }
}

int loadHighScore() {
    ifstream file("highscore.txt");
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

int main() {
    srand(time(0)); // Seed for random numbers
    int score = 0;
    int totalQuestions = 5;

    string level;
    cout << "🎮 Welcome to the Advanced Math Flash Game!" << endl;
    cout << "Select difficulty (easy, medium, hard): ";
    cin >> level;

    int maxRange = getRangeFromDifficulty(level);

    for (int i = 1; i <= totalQuestions; i++) {
        int num1 = rand() % maxRange + 1;
        int num2 = rand() % maxRange + 1;
        int operation = rand() % 3; // 0 = +, 1 = -, 2 = *

        int correctAnswer;
        string symbol;

        switch (operation) {
            case 0:
                correctAnswer = num1 + num2;
                symbol = "+";
                break;
            case 1:
                correctAnswer = num1 - num2;
                symbol = "-";
                break;
            case 2:
                correctAnswer = num1 * num2;
                symbol = "*";
                break;
        }

        int userAnswer;
        cout << "Q" << i << ": What is " << num1 << " " << symbol << " " << num2 << "? ";
        while (!(cin >> userAnswer)) {
            cout << "⚠️ Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (userAnswer == correctAnswer) {
            cout << "✅ Correct!" << endl;
            score++;
        } else {
            cout << "❌ Wrong! The correct answer was " << correctAnswer << "." << endl;
        }
        cout << "-----------------------------" << endl;
    }

    cout << "🎯 You scored " << score << " out of " << totalQuestions << "." << endl;

    int previousHighScore = loadHighScore();
    if (score > previousHighScore) {
        cout << "🏆 New high score! Saving..." << endl;
        saveHighScore(score);
    } else {
        cout << "📈 Your high score remains: " << previousHighScore << endl;
    }

    return 0;
}

