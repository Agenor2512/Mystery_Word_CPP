#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

string askWord();
string mixUpWord(string word);
void gameLoop(string word, string mixedUpWord);
string displayAndGuess(string mixedUpWord);

int main() {

// TODO : - Demander un mot à l'utilisateur
//        - Mélanger les lettres sa mère
//        - Afficher le mot mélangé et demander de guess
//        - Comparer les deux mots
//        - SI les mots sont pareils ALORS t'as gagné poto --> le jeu s'arrête
//        - SINON le jeu continue jusqu'à ce que "t'as gagné poto"

  string word = askWord();
  // std::cout << "Le mot est : " << word << '\n'; // Test unitaire de askWord()

  string mixedUpWord = mixUpWord(word);
  // std::cout << "Le mot mélangé est : " << mixedUpWord << '\n'; // Test unitaire de mixUpWord()

  // string guessedWord = displayAndGuess(mixedUpWord);
  // std::cout << "Votre proposition était : " << guessedWord << '\n';

  gameLoop(word, mixedUpWord);

  return 0;
}

string askWord(){

  string word;
  std::cout << "Enter a word : " << '\n';
  std::cin >> word;

  return word;

}

string mixUpWord(string word){

  string mixedUpWord;
  int initialWordSize = word.size();

  // TODO : - Tirer une position aléatoire
  //        - On ajoute la lettre choisie aléatoirement au premier espace vide (+=)
  //        - On efface la lettre choisie aléatoirement pour éviter de la re piocher

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
      std::cout << "You've WON !" << '\n';
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
