#include <iostream>
#include <conio.h>
#include <windows.h>

#define NB_CASES 10
#define GRIDSIZE 20

using namespace std;

#define RESET   "\x1b[0m"
#define BLACK   "\x1b[30m"      /* Black */
#define RED     "\x1b[31m"      /* Red */
#define GREEN   "\x1b[32m"      /* Green */
#define YELLOW  "\x1b[33m"      /* Yellow */
#define BLUE    "\x1b[34m"      /* Blue */
#define MAGENTA "\x1b[35m"      /* Magenta */
#define CYAN    "\x1b[36m"      /* Cyan */
#define WHITE   "\x1b[37m"      /* White */

int posX = 2;
int posY = 8;
int playerX = 4;
int playerY = 16;

// Utiliser les constantes pour définir le tableau de couleurs
string colors[NB_CASES][NB_CASES] = {
    {GREEN, RED, RED, RED, RED, RED, RED, RED, RED, BLACK},                 //LIGNE 0
    {RED, BLACK, BLACK, RED, BLACK, BLACK, RED, BLACK, RED, BLACK},         //LIGNE 1
    {RED, BLACK, BLUE, RED, BLACK, BLACK, RED, BLACK, RED, BLACK},          //LIGNE 2
    {RED, BLACK, BLACK, RED, BLACK, BLACK, RED, BLACK, RED, YELLOW},        //LIGNE 3
    {RED, BLACK, BLACK, RED, BLUE, BLACK, RED, BLUE, RED, BLACK},           //LIGNE 4
    {RED, BLACK, BLACK, RED, BLACK, BLACK, RED, BLACK, RED, BLACK},         //LIGNE 5
    {RED, BLACK, BLUE, RED, BLACK, BLACK, RED, BLACK, RED, BLACK},          //LIGNE 6
    {RED, BLACK, BLACK, RED, BLACK, BLACK, RED, BLUE, RED, BLACK},          //LIGNE 7
    {RED, RED, RED, RED, RED, RED, RED, RED, RED, BLACK},                   //LIGNE 8
    {BLACK, BLACK, BLUE, BLACK, BLACK, BLACK, BLUE, BLACK, BLUE, BLACK}     //LIGNE 9
};

// Fonction pour afficher la grille
void displayMap() {
    system("cls");

    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            if ((i == playerY || i == playerY + 1) && (j == playerX || j == playerX + 1)) {
                cout << RESET << "00"; // Case vide au milieu
            } else {
                cout << colors[i/2][j/2] << "[]" << RESET; // Case
            }
        }
        cout << endl;
    }
}

void movePlayer(char c)
{
    switch (c) {
        case 'w':
            if (posY > 0) {
                if(colors[posY-1][posX] != BLACK){
                    playerY -= 2; // Déplacement de deux cases vers le haut
                    posY--;
                }
            }
            break;
        case 'a':
            if (posX > 0) {
                if(colors[posY][posX-1] != BLACK){
                    playerX -= 2; // Déplacement de deux cases vers la gauche
                    posX--;
                }
            }
            break;
        case 's':
            if (posY < NB_CASES - 1) {
                if(colors[posY+1][posX] != BLACK){
                    playerY += 2; // Déplacement de deux cases vers le bas
                    posY++;
                }
            }
            break;
        case 'd':
            if (posX < NB_CASES - 1) {
                if(colors[posY][posX+1] != BLACK){
                    playerX += 2; // Déplacement de deux cases vers la droite
                    posX++;
                }
            }
            break;
        default:
            break;
    }
}

void entrerSalle()
{
    system("cls");
    cout << CYAN << "Vous etes dans la salle " << posX << "-" << posY << endl << RESET;
    Sleep(1000);
}

void entrerTech()
{
    system("cls");
    cout << YELLOW << "Vous etes dans le bureau des techniciens.\n" << endl << RESET;
    Sleep(1000);
}

void gererSalle()
{
    
}

void findEvent()
{
    if(colors[posY][posX] == BLUE)
        entrerSalle();
    else if(colors[posY][posX] == YELLOW)
        entrerTech();
}

void startGame()
{
    cout << GREEN;
    cout << "                     /$$       /$$                    \n";
    cout << "                    | $$      |__/                    \n";
    cout << "  /$$$$$$   /$$$$$$ | $$   /$$ /$$ /$$$$$$$  /$$$$$$$$\n";
    cout << " /$$__  $$ /$$__  $$| $$  /$$/| $$| $$__  $$|____ /$$/\n";
    cout << "| $$  \\ $$| $$$$$$$$| $$$$$$/ | $$| $$  \\ $$   /$$$$/ \n";
    cout << "| $$  | $$| $$_____/| $$_  $$ | $$| $$  | $$  /$$__/  \n";
    cout << "| $$$$$$$/|  $$$$$$$| $$ \\  $$| $$| $$  | $$ /$$$$$$$$\n";
    cout << "| $$____/  \\_______/|__/  \\__/|__/|__/  |__/|________/\n";
    cout << "| $$                                                  \n";
    cout << "| $$                                                  \n";
    cout << "|__/                                                  \n";

    cout << "                                                            \n";
    cout << "                                                            \n";
    cout << " /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$$\n";
    cout << "|  $$ /$$/ /$$__  $$ /$$__  $$ /$$__  $$ /$$_____/ /$$_____/\n";
    cout << " \\  $$$$/ | $$  \\ $$| $$  \\__/| $$$$$$$$|  $$$$$$ |  $$$$$$ \n";
    cout << "  >$$  $$ | $$  | $$| $$      | $$_____/ \\____  $$ \\____  $$\n";
    cout << " /$$/\\  $$| $$$$$$$/| $$      |  $$$$$$$ /$$$$$$$/ /$$$$$$$/\n";
    cout << "|__/  \\__/| $$____/ |__/       \\_______/|_______/ |_______/ \n";
    cout << "          | $$                                               \n";
    cout << "          | $$                                               \n";
    cout << "          |__/                                               \n" << RESET;
    Sleep(2500);
}

void indiquerMission()
{
    system("cls");
    cout << RED << "Bienvenue dans le jeu 'Pekinz xpress' !\n";
    cout << "L'equipe P-15 a perdu son robot, et c'est a vous de le retrouver.\n";
    cout << "Votre mission : explorer l'etage 3 de la faculte de genie pour localiser le robot\n";
    cout << "et le ramener a Serge, le technicien, avant qu'il ne soit trop tard.\n";
    cout << "Si le robot n'est pas retrouve, une facture de 650$ sera emise!\n";
    cout << "Bonne chance et que la mission commence !\n" << RESET;
    Sleep(7500);
}

int main() {
    Sleep(10000);
    startGame();
    indiquerMission();

    char move;

    do {
        displayMap();

        cout << "Utilisez les touches WASD pour vous deplacer (Q pour quitter): ";
        move = _getch();

        movePlayer(move);
        findEvent();


    } while (move != 'q' && move != 'Q');

    system("cls");
    cout << "Merci d'avoir joue !" << endl;
    Sleep(1000);

    return 0;
}
