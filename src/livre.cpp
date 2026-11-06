#include <Arduino.h>
#include <Livre.h>

// Constructeur : crée un livre avec l'ID donné, non emprunté et sans informations
Livre::Livre(int id) {
// Enregistre l'identifiant du livre
id_livre = id;
// Un nouveau livre est disponible (pas emprunté)
est_emprunte = false;
// Auteur vide par défaut
auteur = "";
// ISBN non défini (0 par défaut)
ISBN = 0;
// Code-barre non défini (0 par défaut)
code_barre = 0;
}

// Retourne l'identifiant du livre (const : ne modifie pas l'objet)
int Livre::getIdLivre() const {
return id_livre;
}

// Retourne true si le livre est actuellement emprunté, false sinon
bool Livre::getEstEmprunte() const {
return est_emprunte;
}

// Modifie l'état d'emprunt du livre (true = emprunté, false = disponible)
void Livre::setEstEmprunte(bool etat) {
est_emprunte = etat;
}

// Retourne le nom de l'auteur du livre
String Livre::getAuteur() const {
return auteur;
}

// Modifie le nom de l'auteur du livre
void Livre::setAuteur(String auteurLivre) {
auteur = auteurLivre;
}

// Retourne l'ISBN du livre
long Livre::getISBN() const {
return ISBN;
}

// Modifie l'ISBN du livre
void Livre::setISBN(long isbnLivre) {
ISBN = isbnLivre;
}

// Retourne le code-barre du livre
long Livre::getCodeBarre() const {
return code_barre;
}

// Modifie le code-barre du livre
void Livre::setCodeBarre(long codeBarreLivre) {
code_barre = codeBarreLivre;
}