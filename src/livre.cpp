#include <Arduino.h>
#include <Livre.h>

Livre::Livre(int id) {
    id_livre = id;
    est_emprunte = false;
    auteur = "";
    ISBN = 0;
    code_barre = 0;
}

int Livre::getIdLivre() const {
    return id_livre;
}

bool Livre::getEstEmprunte() const {
    return est_emprunte;
}

void Livre::setEstEmprunte(bool etat) {
    est_emprunte = etat;
}

String Livre::getAuteur() const {
    return auteur;
}

void Livre::setAuteur(String auteurLivre) {
    auteur = auteurLivre;
}

long Livre::getISBN() const {
    return ISBN;
}

void Livre::setISBN(long isbnLivre) {
    ISBN = isbnLivre;
}

long Livre::getCodeBarre() const {
    return code_barre;
}

void Livre::setCodeBarre(long codeBarreLivre) {
    code_barre = codeBarreLivre;
}