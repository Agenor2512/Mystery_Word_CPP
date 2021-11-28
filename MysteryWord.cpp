/*
* / Fichier : MysteryWord.cpp
* / Auteur : Agenor2512
* / Dernière modification : 29/11/2021
*/

/************************************************************************************/
/*                                 LIBRAIRIES                                       */
/************************************************************************************/

#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

/*** DECLARATION DES PROTOTYPES DES FONCTIONS ***/

// Permet de demander le mot à deviner au __Joueur1__
string askWord();
  // TODO : - Fonction pour cacher le mot initial (multi)

// Mélange le mot
string mixUpWord(string word);

// Définit si le jeu s'arrête ou non
void gameLoop(string word, string mixedUpWord);

// Affiche le mot mélangé et demande la proposition du __Joueur2__
string displayAndGuess(string mixedUpWord);

// Affiche le menu et demande au Joueur de choisir un mode de jeu
void displayMenu();

// Traite le choix entré par le Joueur
void processChoice(char* optionChoice);

// Traitement du mode multijoueur
void launchMultiplayerGame();

/* TODO : - Fonction singleplayer
          - Dictionnaire
          - Empêcher l'utilisateur d'entrer des int 
*/

int main() {

  displayMenu();

  return 0;
}

/*** DECLARATION DES FONCTIONS ***/

string askWord(){

  string word;
  int const minWordSize = 2;
  bool isInvalidWord;

  do {
    isInvalidWord = false;

    std::cout << "Enter a word : " << '\n';
    std::cin >> word;

// L'utilisateur ne peut pas entrer un mot trop petit
    if (word.size() < minWordSize) {
      isInvalidWord = true;

      std::cout << "You entered too small word. Please enter a " << minWordSize << " or more characters word." << '\n';
    }

  } while (isInvalidWord);



  return word;

}

string mixUpWord(string word){

  string mixedUpWord;
  int initialWordSize = word.size();

  for (int i(0); i < initialWordSize; i++) {

    int randomPos = rand() % word.size();
    mixedUpWord += word[randomPos];
    word.erase(randomPos, 1);

  }

  return mixedUpWord;

}

void gameLoop(string word, string mixedUpWord) {

  string guessedWord;

  do {

    guessedWord = displayAndGuess(mixedUpWord);

    if (word == guessedWord) {
      std::cout << "You've WON !" << "\n\n";
      std::cout << "You can start a new game !" << '\n';
    }
    else {
      std::cout << "Die and RETRY." << '\n';

    }
  } while(word != guessedWord);
}


string displayAndGuess(string mixedUpWord){
  string guess;

  std::cout << "Here's the mixed up word : " << mixedUpWord << '\n';
  std::cout << "Enter your guess : " << '\n';
  std::cin >> guess;

  return guess;

}

void displayMenu() {
  char optionChoice;

  do {
    std::cout << "==Menu==" << '\n';
  //std::cout << "1. Singleplayer" << '\n';
    std::cout << "2. Multiplayer" << '\n';
    std::cout << "0. Exit" << '\n';

    std::cin >> optionChoice;

    processChoice(&optionChoice);

  } while(optionChoice != '0');
}


void processChoice(char* optionChoice) {
  bool isInvalidChoice;

  do {
    isInvalidChoice = false;

    // Vide le buffer d'entrée
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (*optionChoice) {
    /*case '1' : // Singleplayer
          break;*/
      case '2' : // Multiplayer
          launchMultiplayerGame();
          break;
      case '0' : // Exit
          break;
      default :
          std::cout << "Please enter a valid choice." << '\n';
          std::cin >> *optionChoice;
          isInvalidChoice = true;
    }
  } while (isInvalidChoice);
}

void launchMultiplayerGame(){

  // Appel de askWord(), mixUpWord() et gameLoop()
    string word = askWord();

    string mixedUpWord = mixUpWord(word);

    gameLoop(word, mixedUpWord);
}
