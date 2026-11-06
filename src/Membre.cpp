#include <Arduino.h>
#include "Membre.h"

// Constructeur par défaut : crée un membre "vide" (emplacement libre)
Membre::Membre() {
// -1 signifie qu'aucun membre n'est associé à cet objet
id_membre = -1;
// Nom vide par défaut
nom = "";
}

// Constructeur avec ID : crée un membre avec l'identifiant donné
Membre::Membre(int id) {
// Enregistre l'identifiant du membre
id_membre = id;
// Nom vide par défaut (peut être défini plus tard avec setNom)
nom = "";
}

// Retourne l'identifiant du membre (const : ne modifie pas l'objet)
int Membre::getIdMembre() const {
return id_membre;
 }
// Retourne le nom du membre
String Membre::getNom() const{ 
return nom; 
}
// Modifie le nom du membre
void Membre::setNom(String nomMembre) {
nom = nomMembre; 
}