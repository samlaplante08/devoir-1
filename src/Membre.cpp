#include <Arduino.h>
#include <Membre.h>

Membre::Membre() {
    id_membre = -1;
    nom = "";
}

Membre::Membre(int id) {
    id_membre = id;
    nom = "";
}

int Membre::getIdMembre() const {
    return id_membre;
}

String Membre::getNom() const {
    return nom;
}

void Membre::setNom(String nomMembre) {
    nom = nomMembre;
}