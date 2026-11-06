#include <Arduino.h>
#include "Livre.h"
#include "Membre.h"
#include "bibli.h"

// Constructeur : initialise la bibliothèque vide
bibli::bibli() {
// Parcourt les 20 emplacements disponibles
for (int i = 0; i < 20; ++i) {
// Aucun livre n'est stocké : pointeur nul
livres[i] = 0;
// Membre "vide" avec l'ID -1 (emplacement libre)
membres[i] = Membre(-1);
// -1 signifie que cet emplacement de livre est libre
tableau_livres[i] = -1;
// -1 signifie que cet emplacement de membre est libre
tableau_membres[i] = -1;
    }
// Aucun livre ni membre au départ
nombre_livres_actuel = 0;
nombre_membres_actuel = 0;
}

// Ajoute un membre avec l'ID donné
void bibli::ajouterMembre(int id) {
// Refuse les ID nuls ou négatifs (-1 est réservé aux emplacements libres)
if (id <= 0){
Serial.println("id doit être positif");
return;
}
// Vérifie que l'ID n'est pas déjà utilisé par un autre membre
for (int i = 0; i < 20; ++i){
if (tableau_membres[i] == id) {
Serial.println("Ce membre existe déjà");
return;
}
}
// Cherche le premier emplacement libre (ID = -1)
for (int i = 0; i < 20; ++i) {
if (tableau_membres[i] == -1) {
// Enregistre l'ID et crée l'objet Membre à cet emplacement
tableau_membres[i] = id;
membres[i] = Membre(id);
// Met à jour le compteur de membres
nombre_membres_actuel++;
Serial.print("Membre ajouté avec succès, ID : ");
Serial.println(id);
// Membre ajouté : on quitte la fonction
return;
}
}
// Si on arrive ici, aucun emplacement libre n'a été trouvé
Serial.println("Nombre maximum de membres atteint");
}

// Ajoute un livre avec l'ID donné
void bibli::ajouterLivre(int id) {
// Refuse les ID nuls ou négatifs (-1 est réservé aux emplacements libres)
if (id <= 0){
Serial.println("id doit être positif");
return;
}
// Vérifie que l'ID n'est pas déjà utilisé par un autre livre
for (int j = 0; j < 20; ++j){
if (tableau_livres[j] == id) {
Serial.println("Ce livre existe déjà");
return;
}
}
// Cherche le premier emplacement libre (ID = -1)
for (int j = 0; j < 20; ++j) {
if (tableau_livres[j] == -1) {
// Enregistre l'ID et crée dynamiquement l'objet Livre (new)
tableau_livres[j] = id;
livres[j] = new Livre(id);
// Met à jour le compteur de livres
nombre_livres_actuel++;
Serial.print("Livre ajouté : ");
Serial.println(id);
// Livre ajouté : on quitte la fonction
return;
}
}
// Si on arrive ici, aucun emplacement libre n'a été trouvé
Serial.println("La bibliothèque remplie");
}

// Permet à un membre d'emprunter un livre
void bibli::emprunterLivre(int id_livre, int id_membre) {
// Positions du livre et du membre dans leurs tableaux (-1 = non trouvé)
int indexLivre = -1;
int indexMembre = -1;

// Recherche la position du livre à partir de son ID
for (int i = 0; i < 20; ++i) {
if (tableau_livres[i] == id_livre) {
indexLivre = i;
break;
}
}

// Recherche la position du membre à partir de son ID
for (int i = 0; i < 20; ++i) {
if (tableau_membres[i] == id_membre) {
indexMembre = i;
break;
}
}

// ATTENTION : la valeur de "non trouvé" est -1, pas -134 : ce test ne détecte jamais un livre introuvable
if (indexLivre == -134) {
Serial.println("Erreur : Livre introuvable.");
return;
}

// Membre introuvable : on arrête avec un message d'erreur
if (indexMembre == -1) {
Serial.println("Erreur : Membre introuvable.");
return;
}
// Vérifie que le pointeur du livre n'est pas nul avant de l'utiliser
if (livres[indexLivre] != 0) {
// Refuse l'emprunt si le livre est déjà emprunté
if (livres[indexLivre]->getEstEmprunte()) {
Serial.println("Erreur : Le livre est déjà emprunté.");
return;
}
// Marque le livre comme emprunté
livres[indexLivre]->setEstEmprunte(true);
Serial.print("Le livre ");
Serial.print(id_livre);
Serial.print(" a été emprunté par le membre ");
Serial.println(id_membre);
}
}

// Retourne un livre emprunté à la bibliothèque
void bibli::retournerLivre(int id_livre) {
// Position du livre dans le tableau (-1 = non trouvé)
int indexLivre = -1;

// Recherche la position du livre à partir de son ID
for (int i = 0; i < 20; ++i) {
if (tableau_livres[i] == id_livre) {
indexLivre = i;
break;
}
}

// Livre introuvable : on arrête avec un message d'erreur
if (indexLivre == -1) {
Serial.println("Erreur : Livre introuvable.");
return;
}

// Vérifie que le pointeur du livre n'est pas nul avant de l'utiliser
if (livres[indexLivre] != 0) {
// Refuse le retour si le livre n'était pas emprunté
if (!livres[indexLivre]->getEstEmprunte()) {
Serial.println("Erreur : Ce livre n'était pas emprunté.");
return;
}

// Marque le livre comme disponible
livres[indexLivre]->setEstEmprunte(false);
Serial.print("Le livre ");
Serial.print(id_livre);
Serial.println(" a été retourné avec succès.");
}
}

// Affiche l'état de tous les livres de la bibliothèque
void bibli::afficherEtat() {
Serial.println("état bibli");
// Aucun livre enregistré : on l'indique simplement
if (nombre_livres_actuel == 0) {
Serial.println("Aucun livre ");
} 
else
{
// Parcourt tous les emplacements de livres
for (int i = 0; i < 20; ++i) {
// Ne traite que les emplacements occupés (ID différent de -1 et pointeur valide)
if (tableau_livres[i] != -1 && livres[i] != 0) {

// Affiche l'ID du livre
Serial.print("Livre ID : ");
Serial.print(tableau_livres[i]);
Serial.print(" | Statut : ");

// Affiche le statut selon l'état d'emprunt
if (livres[i]->getEstEmprunte()) {
Serial.println("Emprunté");

} 
else
 {
Serial.println("Disponible");
}
}
}
}
}