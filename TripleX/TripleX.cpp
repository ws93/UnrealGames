#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    // Print welcome message to the terminal
    std::cout << "You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

int GetRandonNumberInRange(int MaxValue) {
    return rand() % MaxValue;
}

bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty);
    // Declare numbers
    int CodeA = GetRandonNumberInRange(Difficulty) + Difficulty;
    int CodeB = GetRandonNumberInRange(Difficulty) + Difficulty;
    int CodeC = GetRandonNumberInRange(Difficulty) + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give " << CodeProduct << std::endl;

    // Store player's guess
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;
    // std::cout << "You have entered: " << GuessA << GuessB << GuessC << std::endl;

    // Check if player's guess is correct
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\nWell done agent! Keep going!\n\n";
        
        return true;
    } else {
        std::cout << "\nYou entered the wrong code! Try again!\n\n";

        return false;
    }
}

int main() {
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 5;
    while (LevelDifficulty <= MaxLevel) { // Loop the game until all completed
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            // increase the level difficulty
            ++LevelDifficulty;
        }
    }

    std::cout << "Congrats! You have now hacked all server rooms!\n";

    return 0;
}