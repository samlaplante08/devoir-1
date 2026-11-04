#pragma once
#include <Arduino.h>

class Livre {
private:
    int id_livre;
    bool est_emprunte;
    String auteur;
    long ISBN;
    long code_barre;

public:
    Livre(int id);

    int getIdLivre() const;
    bool getEstEmprunte() const;
    void setEstEmprunte(bool etat);
    
    String getAuteur() const;
    void setAuteur(String auteurLivre);

    long getISBN() const;
    void setISBN(long isbnLivre);

    long getCodeBarre() const;
    void setCodeBarre(long codeBarreLivre);
};