//
// Created by lionel on 08/01/19.
//


#ifndef PROJET_GRAPHE_HPP
#define PROJET_GRAPHE_HPP
#include <map>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <class Sommet, class Poids> class Graphe {


private:
    bool orientation;
    map<Sommet,vector<pair<Sommet,Poids> > > graphe;
public:
    Graphe();
    Graphe(bool b);
    Graphe(Sommet s);
    Graphe(Sommet deb, Sommet fin, Poids poids);
    Graphe(const Graphe &g);
    ~Graphe(){};

    const vector<Sommet> get_Sommets() {};

    bool get_Orientation() const {return orientation;};

    void ajouter_Sommet(Sommet s);
    void ajouter_Arete(Sommet deb, Sommet fin, Poids poids);
    void supprimer_Sommet(Sommet s);
    void supprimer_Arete(Sommet deb, Sommet fin, Poids poids);


};

//std :: ostream & operator << ( std:: ostream& ost, Graphe<Sommet,Poids> const &g);

#endif //PROJET_GRAPHE_HPP
