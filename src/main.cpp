#include <Arduino.h>
#include "Livre.h"
#include "Membre.h"
#include "bibli.h"

// Objet global : la bibliothèque unique utilisée par tout le programme
bibli maBibliotheque;

// Affiche une question, attend la saisie de l'utilisateur et retourne l'entier lu
int lireEntier(const char* message) {
// Affiche la question à l'écran (ex. "ID du livre :")
Serial.println(message);
// Attend (bloque) tant que l'utilisateur n'a rien envoyé
while (Serial.available() <= 0);
// Lit l'entier tapé dans le moniteur série
int valeur = Serial.parseInt();
// Petite pause pour laisser arriver le retour à la ligne (Entrée)
delay(50);
// Vide le buffer pour ne pas laisser de caractères résiduels
while (Serial.available() > 0) Serial.read();
// Retourne la valeur saisie
return valeur;
}

// Exécutée une seule fois au démarrage de la carte
void setup() {
// Démarre la communication série à 9600 bauds
Serial.begin(9600);
// Attend que le port série soit prêt (utile sur certaines cartes)
while (!Serial); 
// Affiche le menu des options
Serial.println("1 Ajouter un livre");
Serial.println("2 Ajouter un membre");
Serial.println("3 Emprunter un livre");
Serial.println("4 Retourner un livre");
Serial.println("5 Afficher l'etat de la bibliotheque");
}

// Exécutée en boucle : lit le choix du menu et appelle la bonne fonction
void loop() {
// Si rien n'a été reçu, on sort et loop() recommence
if (Serial.available() <= 0) return;

// Lit le premier caractère reçu : c'est le choix du menu
char c = Serial.read();
// Laisse le temps au retour à la ligne d'arriver
delay(50);
// Vide le buffer pour ne garder que le choix
while (Serial.available() > 0) Serial.read();

// Exécute l'action correspondant au choix
switch (c) {
// Option 1 : demande l'ID puis ajoute un livre
case '1':
maBibliotheque.ajouterLivre(lireEntier("ID du livre :"));
break;
// Option 2 : demande l'ID puis ajoute un membre
case '2':
maBibliotheque.ajouterMembre(lireEntier("ID du membre :"));
break;
// Option 3 : emprunt (accolades pour déclarer des variables locales dans le case)
case '3': {
// Lit d'abord l'ID du livre, puis celui du membre (ordre garanti)
int idLivre = lireEntier("ID du livre :");
int idMembre = lireEntier("ID du membre :");
maBibliotheque.emprunterLivre(idLivre, idMembre);
break;
}
// Option 4 : demande l'ID du livre puis le retourne
case '4':
maBibliotheque.retournerLivre(lireEntier("ID du livre :"));
break;
// Option 5 : affiche l'état de la bibliothèque
case '5':
maBibliotheque.afficherEtat();
break;
// Tout autre caractère est ignoré
default:
break;
}
}