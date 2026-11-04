#pragma once

#include <Arduino.h>
#include "Livre.h"
#include "Membre.h"

class bibli {
private:
    Livre* livres[20];
    Membre membres[20];
    int tableau_livres[20];
    int tableau_membres[20];
    int nombre_livres_actuel;
    int nombre_membres_actuel;

public:
    bibli();

    void ajouterLivre(int id);
    void ajouterMembre(int id);
    void emprunterLivre(int id_livre, int id_membre);
    void retournerLivre(int id_livre);
    void afficherEtat();
};