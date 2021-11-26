#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

/*** DECLARATION DES PROTOTYPES DES FONCTIONS ***/
string askWord();
string mixUpWord(string word);
void gameLoop(string word, string mixedUpWord);
string displayAndGuess(string mixedUpWord);

int main() {
/*** APPEL DES FONCTIONS : askWord(), mixUpWord() et gameLoop() ***/
  string word = askWord();

  string mixedUpWord = mixUpWord(word);

  gameLoop(word, mixedUpWord);

  return 0;
}

/*** DECLARATION DES FONCTIONS ***/
// askWord() permet de demander le mot proposé par le __Joueur1__
// On crée une variable word qui stockera le mot au moment du cin et on return le mot choisit
string askWord(){

  string word;
  std::cout << "Enter a word : " << '\n';
  std::cin >> word;

  return word;

}

/*************************************************************************************************************************/

// mixUpWord() est la fonction qui permet de mélanger le mot proposé par le __Joueur1__, on lui envoie donc la variable word
// On définit une variable qui stockera le mot mélangé puis on crée un int qui stockera la taille du mot
// Dans le for : on fait appel à rand pour tirer une position aléatoire, puis la lettre est ajoutée dans mixedUpWord (var)
// au premier espace vide et enfin erase efface la position de la lettre tirée aléatoirement pour éviter la repioche
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

/*************************************************************************************************************************/

// On déclare la fonction "princiale" gameLoop() permettant de comparer la réponse du **Joueur2** et le mot initial (word et mixUpWord) en arguments
// Dans guessedWord on stocke la proposition du **Joueur2** en passant par la fonction displayAndGuess()
// Grâce au if, les mots sont comparé en argument (==) et on affiche un message selon la réussite ou non du **Joueur2**
void gameLoop(string word, string mixedUpWord) {

  string guessedWord;

  do { // Boucle principale : si le joueur se trompe, la boucle recommence, s'il gagne on sort de la boucle (argumants après while)


    guessedWord = displayAndGuess(mixedUpWord);

    if (word == guessedWord) {
      std::cout << "You've WON !" << '\n';
    }
    else {
      std::cout << "Die and RETRY." << '\n';

    }
  } while(word != guessedWord);
}

/***********************************************************************************************************************/

// displayAndGuess() fait en sorte que l'on puisse récupérer la proposition du **Joueur2**, on lui envoie mixedUpWord en argument
// La proposition sera stockée dans la variable guess déclarée au préalable
string displayAndGuess(string mixedUpWord){
  string guess;

  std::cout << "Here's the mixed up word : " << mixedUpWord << '\n';
  std::cout << "Enter your guess : " << '\n';
  std::cin >> guess;

  return guess;

}
