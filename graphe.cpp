//
// Created by lionel on 08/01/19.
//

#include "graphe.hpp"

template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe(){
    this->orientation=false;
}

template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe(bool b){
    this->orientation=b;
}

template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe(Sommet s){
    this->graphe[s]=vector<pair<Sommet,Poids> >(0);
}

template <class Sommet,class Poids> Graphe<Sommet,Poids>::Graphe(Sommet deb, Sommet fin, Poids poids){
    if(orientation){
        this->graphe[deb]=vector<pair<Sommet,Poids> > (pair<Sommet,Poids>(fin, poids));
    }else{
        this->graphe[deb]=vector<pair<Sommet,Poids> > (pair<Sommet,Poids>(fin, poids));
        if(deb!=fin)
            this->graphe[fin]=vector<pair<Sommet,Poids> > (pair<Sommet,Poids>(deb, poids));
    }
}

template <class Sommet,class Poids> Graphe<Sommet,Poids>::Graphe(const Graphe &g){
    this->orientation=g.orientation;
    this->graphe(g.graphe);
}

template <class Sommet,class Poids> vector<Sommet> Graphe<Sommet,Poids>::get_Sommets(){

}

