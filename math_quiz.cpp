#include <iostream>
using namespace std;

int main() {
    int score = 0, answer;

    cout << "Welcome to the Math Quiz!" << endl;

    cout << "1. What is 5 + 3? ";
    cin >> answer;
    if (answer == 8) score++;

    cout << "2. What is 9 - 4? ";
    cin >> answer;
    if (answer == 5) score++;

    cout << "3. What is 6 * 7? ";
    cin >> answer;
    if (answer == 42) score++;

    cout << "You scored " << score << " out of 3!" << endl;

    return 0;
}
