//
// Created by uzay on 09/01/19.
//

#include "Tas.hpp"


template <class T> Tas<T>::Tas() {
    this->tableau=vector<T> (0);
}

template <class T> Tas<T>::Tas(T e){
    this->tableau=vector<T> (e);
}


template <class T> T Tas<T>::get_Minimum() const {
    if(tableau.size()!=0)
        return tableau[0];
    return NULL;
}

template <class T> void Tas<T>::ajout_Element(T e){
    this->tableau.push_back(e);
    int taille=this->tableau.size();
    T echange;
    if(taille!=1){
        int indice_fils=taille-1;
        int indice_pere=(indice_fils-1)/2;
        while(indice_fils!=0 && tableau[indice_pere]<tableau[indice_fils]){
            echange=tableau[indice_fils];
            tableau[indice_fils]=tableau[indice_pere];
            tableau[indice_pere]=echange;
            indice_fils=indice_pere;
            indice_pere=(indice_fils-1)/2;
        }
    }
}

template <class T> T Tas<T>::recherche_Element(T e){
    typename vector<T>::iterator it;
    it = this->tableau.find(e);
    if(it != this->tableau.end())
        return it;
    return NULL;
}
