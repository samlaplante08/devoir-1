#include <Arduino.h>
#include "Livre.h"
#include "Membre.h"
#include "bibli.h"

// Instanciation de la bibliothèque
bibli maBibliotheque;

void setup() {
    Serial.begin(9600);
    while (!Serial); // Attendre l'ouverture du moniteur série
    
    Serial.println("=== Systeme de gestion de bibliotheque initialise ===");
    Serial.println("Commandes disponibles via le moniteur serie :");
    Serial.println("- L <id_livre> : Ajouter un livre");
    Serial.println("- M <id_membre> : Ajouter un membre");
    Serial.println("- E <id_livre> <id_membre> : Emprunter un livre");
    Serial.println("- R <id_livre> : Retourner un livre");
    Serial.println("- A : Afficher l'etat de la bibliotheque");
    Serial.println("--------------------------------------------------");
}

void loop() {
    if (Serial.available() > 0) {
        char commande = Serial.read();
        
        // Ignorer les retours à la ligne ou espaces superflus
        if (commande == '\n' || commande == '\r' || commande == ' ') {
            return;
        }

        switch (commande) {
            case 'L': {
                int idLivre = Serial.parseInt();
                maBibliotheque.ajouterLivre(idLivre);
                break;
            }
            case 'M': {
                int idMembre = Serial.parseInt();
                maBibliotheque.ajouterMembre(idMembre);
                break;
            }
            case 'E': {
                int idLivre = Serial.parseInt();
                int idMembre = Serial.parseInt();
                maBibliotheque.emprunterLivre(idLivre, idMembre);
                break;
            }
            case 'R': {
                int idLivre = Serial.parseInt();
                maBibliotheque.retournerLivre(idLivre);
                break;
            }
            case 'A': {
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