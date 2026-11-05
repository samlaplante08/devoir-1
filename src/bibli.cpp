#include <Arduino.h>
#include "Livre.h"
#include "Membre.h"
#include "bibli.h"

bibli::bibli() {
    for (int i = 0; i < 20; ++i) {
        livres[i] = 0;
        membres[i] = Membre(-1);
        tableau_livres[i] = -1;
        tableau_membres[i] = -1;
    }
    nombre_livres_actuel = 0;
    nombre_membres_actuel = 0;
}

void bibli::ajouterMembre(int id) {
    for (int i = 0; i < 20; ++i) {
        if (tableau_membres[i] == -1) {
            tableau_membres[i] = id;
            membres[i] = Membre(id);
            nombre_membres_actuel++;
            Serial.print("Membre ajouté avec succès, ID : ");
            Serial.println(id);
            return;
        }
    }
    Serial.println("La bibliothèque est pleine (membres).");
}

void bibli::ajouterLivre(int id) {
    for (int j = 0; j < 20; ++j) {
        if (tableau_livres[j] == -1) {
            tableau_livres[j] = id;
            livres[j] = new Livre(id);
            nombre_livres_actuel++;
            Serial.print("Livre ajouté : ");
            Serial.println(id);
            return;
        }
    }
    Serial.println("La bibliothèque remplie");
}

void bibli::emprunterLivre(int id_livre, int id_membre) {
    int indexLivre = -1;
    int indexMembre = -1;

    for (int i = 0; i < 20; ++i) {
        if (tableau_livres[i] == id_livre) {
            indexLivre = i;
            break;
        }
    }

    for (int i = 0; i < 20; ++i) {
        if (tableau_membres[i] == id_membre) {
            indexMembre = i;
            break;
        }
    }

    if (indexLivre == -1) {
        Serial.println("Erreur : Livre introuvable.");
        return;
    }

    if (indexMembre == -1) {
        Serial.println("Erreur : Membre introuvable.");
        return;
    }

    if (livres[indexLivre] != 0) {
        if (livres[indexLivre]->getEstEmprunte()) {
            Serial.println("Erreur : Le livre est déjà emprunté.");
            return;
        }
        
        livres[indexLivre]->setEstEmprunte(true);
        Serial.print("Le livre ");
        Serial.print(id_livre);
        Serial.print(" a été emprunté par le membre ");
        Serial.println(id_membre);
    }
}

void bibli::retournerLivre(int id_livre) {
    int indexLivre = -1;

    for (int i = 0; i < 20; ++i) {
        if (tableau_livres[i] == id_livre) {
            indexLivre = i;
            break;
        }
    }

    if (indexLivre == -1) {
        Serial.println("Erreur : Livre introuvable.");
        return;
    }

    if (livres[indexLivre] != 0) {
        if (!livres[indexLivre]->getEstEmprunte()) {
            Serial.println("Erreur : Ce livre n'était pas emprunté.");
            return;
        }

        livres[indexLivre]->setEstEmprunte(false);
        Serial.print("Le livre ");
        Serial.print(id_livre);
        Serial.println(" a été retourné avec succès.");
    }
}

void bibli::afficherEtat() {
    Serial.println("état bibli");
    if (nombre_livres_actuel == 0) {
        Serial.println("Aucun livre ");
    } else {
        for (int i = 0; i < 20; ++i) {
            if (tableau_livres[i] != -1 && livres[i] != 0) {
                Serial.print("Livre ID : ");
                Serial.print(tableau_livres[i]);
                Serial.print(" | Statut : ");
                if (livres[i]->getEstEmprunte()) {
                    Serial.println("Emprunté");
                } else {
                    Serial.println("Disponible");
                }
            }
        }
    }
}
