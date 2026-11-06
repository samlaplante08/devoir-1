#include <Arduino.h>
#include "Livre.h"
#include "Membre.h"
#include "bibli.h"

bibli maBibliotheque;

int lireEntier(const char* message) {
Serial.println(message);
while (Serial.available() <= 0);
int valeur = Serial.parseInt();
delay(50);
while (Serial.available() > 0) Serial.read();
return valeur;
}

void setup() {
Serial.begin(9600);
while (!Serial); 
Serial.println("1 Ajouter un livre");
Serial.println("2 Ajouter un membre");
Serial.println("3 Emprunter un livre");
Serial.println("4 Retourner un livre");
Serial.println("5 Afficher l'etat de la bibliotheque");
}

void loop() {
if (Serial.available() <= 0) return;

char c = Serial.read();
delay(50);
while (Serial.available() > 0) Serial.read();

switch (c) {
case '1':
maBibliotheque.ajouterLivre(lireEntier("ID du livre :"));
break;
case '2':
maBibliotheque.ajouterMembre(lireEntier("ID du membre :"));
break;
case '3': {
int idLivre = lireEntier("ID du livre :");
int idMembre = lireEntier("ID du membre :");
maBibliotheque.emprunterLivre(idLivre, idMembre);
break;
}
case '4':
maBibliotheque.retournerLivre(lireEntier("ID du livre :"));
break;
case '5':
maBibliotheque.afficherEtat();
break;
default:
break;
}
}