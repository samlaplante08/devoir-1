#include <Arduino.h>
#include "Livre.h"
#include "Membre.h"
#include "bibli.h"


bibli maBibliotheque;

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
    if (Serial.available() > 0) {
        char commande = Serial.read();
        

        switch (commande) {
            case '1': {
                int idLivre = Serial.parseInt();
                maBibliotheque.ajouterLivre(idLivre);
                break;
            }
            case '2': {
                int idMembre = Serial.parseInt();
                maBibliotheque.ajouterMembre(idMembre);
                break;
            }
            case '3': {
                int idLivre = Serial.parseInt();
                int idMembre = Serial.parseInt();
                maBibliotheque.emprunterLivre(idLivre, idMembre);
                break;
            }
            case '4': {
                int idLivre = Serial.parseInt();
                maBibliotheque.retournerLivre(idLivre);
                break;
            }
            case '5': {
                maBibliotheque.afficherEtat();
                break;
            }
            default:
                Serial.println("Commande inconnue.");
                break;
        }
        
        // Vider le buffer série restant
        while (Serial.available() > 0) {
            Serial.read();
        }
    }
}