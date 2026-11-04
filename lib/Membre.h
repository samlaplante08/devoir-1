#pragma once

#include <Arduino.h>

class Membre {
private:
    int id_membre;
    String nom;

public:
    Membre();
    Membre(int id);

    int getIdMembre() const;
    String getNom() const;
    void setNom(String nomMembre);
};