#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono> 
#include <thread>
#include <ctime>
#include <algorithm>
#include <cctype>

// Defines variables userInput and victory
std::string userInput;
int victory = 0;

// Handles checking (and printing) the results of the user's guess.
int printResults(const std::string& input, const std::string& word){

    // If it detects if the user's answer is correct and if so, exits the function to stop it from continuing.
    if (input == word){
        std::cout << "You won!";
        return 0;
    }
    else{

        // This loop goes through every letter of the user's answer and checks every letter for if they're a match, is in the word or not at all in the word and prints accordingly.
        for (int i = 0; i < 4; i++){
            if (input[i] == word[i]){
                std::cout << "Match: " << input[i];
            }
            else if (word.find(input[i]) != std::string::npos){
                std::cout << "Contains: " << input[i];
            }
            else{
                std::cout << "Does not contain: " << input[i];
            }
            std::cout << "\n";
        }
        return 1;
    }
}

int main() {
    // Creates the vector containing all the possible words.
    std::vector<std::string> words = { "frog", "lamp", "door", "cake", "tree", "bark", "room", "boom", "four", "jazz", "rock", "ball", "jerk", "boat", "deck", "plus", "gulp", "sand", "claw", "wind", "hush", "milk", "dawn", "snip", "glow", "chip", "soak", "palm", "wolf", "kind", "mask", "yarn", "coil", "drip", "slam", "tuck", "moss", "vial", "pond"};

    // Handles getting a random word from the list of words.
    std::srand(std::time(nullptr));
    std::string randomWord = words[ std::rand() % words.size() ];

    // This is the main game loop that lasts 5 turns.
    for (int i = 0; i < 5; i++){
        std::cout << "Enter a 4-letter word: "; 
        std::cin >> userInput;

        // Checks if user input contains uppercase characters and if so, tells the user to not.
        if (!std::all_of(userInput.begin(), userInput.end(), ::islower)) {
            std::cout << "Please use lowercase letters only.\n";
            continue;
        }

        // Checks if user input is not four characters long and if so, tells the user to not.
        if (userInput.length() != 4) {
            std::cout << "Please make sure your word is 4 letters long.\n";
            continue;
        }

        // Runs printResults and checks if it has returned zero (meaning the user guessed), and if so, exits the loop and sets the variable victory to 1.
        if (printResults(userInput, randomWord) == 0){
            victory = 1;
            break;
        }
    }

    // If the variable victory is 0, it prints 'You Lost!' to inform the player of their tragic loss.
    if (victory == 0){
        std::cout << "You lost!";
    }

    // Pauses for 2 seconds to give the user time to read the results of this intense game.
    std::this_thread::sleep_for(std::chrono::seconds(2));

}
