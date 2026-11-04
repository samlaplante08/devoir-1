#include <Arduino.h>
#include <Livre.h>
#include <Membre.h>
#include <bibli.h>

bibli::bibli() {
    for (int i = 0; i < 20; ++i) {
        livres[i] = nullptr;
        membres[i] = Membre();
        tableau_livres[i] = -1;
        tableau_membres[i] = -1;
    }
    nombre_livres_actuel = 0;
    nombre_membres_actuel = 0;
}

void bibli::ajouterMembre(int id) {
    if (Serial.available() <= 0) {
        return;
    }

    String nom = Serial.readStringUntil('\n');
    nom.trim();

    for (int i = 0; i < 20; ++i) {
        if (tableau_membres[i] == -1) {
            tableau_membres[i] = id;
            membres[i] = Membre(id);
            membres[i].setNom(nom);
            nombre_membres_actuel++;
            Serial.print("Membre ajouté avec succès : ");
            Serial.println(nom);
            return;
        }
    }

    Serial.println("La bibliothèque est pleine.");
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

    Serial.println("La bibliothèque est pleine.");
}

void bibli::emprunterLivre(int id_livre, int id_membre) {
  
}

void bibli::retournerLivre(int id_livre) {
  
}

void bibli::afficherEtat() {
  
}