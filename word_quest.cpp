#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;


struct Level {
    string category;
    vector<string> words;
};

void playGame() {
    srand(static_cast<unsigned int>(time(0)));

    vector<Level> levels = {
        {"Technology", {"coding", "algorithm", "database", "software"}},
        {"Business", {"startup", "founder", "marketing", "investment"}},
        {"Space", {"galaxy", "astronaut", "asteroid", "nebula"}}
    };

    cout << "--- 🚀 LILPAR'S C++ WORD CHALLENGE ---" << endl;
    cout << "Select Category: 0: Tech, 1: Business, 2: Space" << endl;
    int choice;
    cin >> choice;

    if (choice < 0 || choice > 2) choice = 0;

    Level selectedLevel = levels[choice];
    string secretWord = selectedLevel.words[rand() % selectedLevel.words.size()];
    string displayWord(secretWord.length(), '_');
    
    int lives = 5;
    int score = 0;

    cout << "\nCategory: " << selectedLevel.category << " | Good Luck!" << endl;

    while (lives > 0 && displayWord != secretWord) {
        cout << "\nWord: " << displayWord << endl;
        cout << "Lives ❤️: " << lives << " | Score 🏆: " << score << endl;
        cout << "Guess a letter: ";
        
        char guess;
        cin >> guess;

        bool found = false;
        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                if (displayWord[i] == '_') {
                    displayWord[i] = guess;
                    score += 15;
                    found = true;
                } else {
                    cout << "You already guessed this!" << endl;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "❌ Wrong guess!" << endl;
            lives--;
            score -= 5;
        } else {
            cout << "✅ Correct!" << endl;
        }
    }

    if (displayWord == secretWord) {
        cout << "\nCONGRATULATIONS! 🎉 The word was: " << secretWord << endl;
        cout << "Final Score: " << score + (lives * 10) << endl;
    } else {
        cout << "\nGAME OVER! 💀 The word was: " << secretWord << endl;
    }
}

int main() {
    playGame();
    return 0;
}
