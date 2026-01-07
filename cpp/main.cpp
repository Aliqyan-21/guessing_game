#include "incanti.hpp"
#include <algorithm>
#include <iostream>
#include <random>

auto easy = []() {
  std::random_device rd;
  std::uniform_int_distribution<int> gen(1, 100);

  int randNum = gen(rd);
  int userGuess;
  int count = 1;

  std::cout << "Guess the number I am thinking of between 1 and 100..."
            << std::endl;
  std::cout << "Guess: ";
  std::cin >> userGuess;

  while (true) {
    if (userGuess > randNum) {
      count++;

      std::cout << "I am thinking of a smaller number than that..."
                << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else if (userGuess < randNum) {
      count++;

      std::cout << "I am thinking of a larger number than that..." << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else {
      std::cout << "Yes, you guessd it right " << userGuess
                << " is the number I was thinking of!" << std::endl;
      std::cout << "Total number of tries you took: " << count << std::endl;
      break;
    }
  }
};

auto medium = []() {
  std::random_device rd;
  std::uniform_int_distribution<int> gen(1, 200);

  int randNum = gen(rd);
  int userGuess;
  int count = 0;

  std::cout << "Guess the number I am thinking of between 1 and 200..."
            << std::endl;
  std::cout << "Guess: ";
  std::cin >> userGuess;

  while (true) {
    if (userGuess > randNum) {
      count++;

      std::cout << "I am thinking of a smaller number than that..."
                << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else if (userGuess < randNum) {
      count++;

      std::cout << "I am thinking of a larger number than that..." << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else {
      std::cout << "Yes, you guessd it right " << userGuess
                << " is the number I was thinking of!" << std::endl;
      std::cout << "Total number of tries you took: " << count << std::endl;
      break;
    }
  }
};

auto hard = []() {
  std::random_device rd;
  std::uniform_int_distribution<int> gen(1, 300);

  int randNum = gen(rd);
  int userGuess;
  int count = 0;

  std::cout << "Guess the number I am thinking of between 1 and 300..."
            << std::endl;
  std::cout << "Guess: ";
  std::cin >> userGuess;

  while (true) {
    if (userGuess > randNum) {
      count++;

      std::cout << "I am thinking of a smaller number than that..."
                << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else if (userGuess < randNum) {
      count++;

      std::cout << "I am thinking of a larger number than that..." << std::endl;
      std::cout << "Try again: ";
      std::cin >> userGuess;
    } else {
      std::cout << "Yes, you guessd it right " << userGuess
                << " is the number I was thinking of!" << std::endl;
      std::cout << "Total number of tries you took: " << count << std::endl;
      break;
    }
  }
};

void GameLoop(std::string &mode) {
  char playagain;
  while (true) {
    if (mode == "easy") {
      easy();
    } else if (mode == "medium") {
      medium();
    } else if (mode == "hard") {
      hard();
    }

    while (true) {
      std::cout << "Do you want to play again[y/n]: ";
      std::cin >> playagain;
      if (playagain == 'y' || playagain == 'n')
        break;
    }
    if (playagain == 'n')
      break;
    else {
      while (true) {
        std::cout << "Which difficulty[easy, medium, hard]: ";
        std::cin >> mode;
        if (mode == "easy" || mode == "medium" || mode == "hard") {
          break;
        }
      }
      continue;
    }
  }
}

int main(int argc, char *argv[]) {
  std::string mode;

  Incanti::Parser p;

  p >> arg("mode", "m", &mode) | required | "mode: easy, medium, hard" |
      [](const std::string &s) {
        std::string lower = s;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        if (lower != "easy" && lower != "medium" && lower != "hard") {
          std::cout << "Not a valid mode!" << std::endl;
          while (lower != "easy" && lower != "medium" && lower != "hard") {
            std::cout << "Enter mode here now[easy, medium, hard]: ";
            std::cin >> lower;
          }
        }
        GameLoop(lower);
        return lower;
      };

  try {
    p.parse(argc, argv);
  } catch (const Incanti::ParseError &pe) {
    std::cerr << "Error: " << pe.what() << std::endl;
    p.print_help();
  }

  return 0;
}
