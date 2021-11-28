# Le Mot Mystère en CPP
Ce projet est réalisé dans le cadre d'un cours OpenClassrooms.  
Le but étant de faire deviner à l'utilisateur un mot dont les lettres ont été mélangées aléatoirement _(pour le moment, un autre joueur doit entrer le mot mystère)_ en passant par le terminal.
## Déroulement du jeu
1. Un menu s'affiche et le __Joueur__ sélectionne un mode de jeu _(singleplayer en développement)_ ou quitte le programme  

  ![Le menu](./Ressources/Menu.png)  
- En mode multijoueur : le __Joueur1__ doit saisir un mot (cf carré bleu)
 - On affiche le mot mélangé au **Joueur2** afin qu'il devine le mot initial (cf carré rouge et violet)
 - Le jeu s'arrête quand le **Joueur2** à deviné le mot entré par le **Joueur1**. (cf carré violet)


![Le jeu](./Ressources/allTheGame.png)

 2. Enfin, vous pouvez relancer une partie (ou quitter le programme) !

 ![New game](./Ressources/newGame.png)



## TODO
### Jeu  
- Cacher le mot entré par le __Joueur1__
- Ajouter un mode un joueur

### Documentation
- Traduire le README en anglais
- Ajouter des captures des parties
- Ajouter un guide d'installation et de lancement

### Autres
- Ajouter un makefile

## Contributeurs
- [Agenor2512](https://github.com/Agenor2512/)
