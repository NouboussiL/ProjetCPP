//
// Created by lionel on 08/01/19.
//

#include "graphe.hpp"


template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe() : orientation() {
    this->orientation=false;
}


template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe(bool b) : orientation() {
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


template <class Sommet,class Poids> void Graphe<Sommet,Poids>::ajouter_Sommet(Sommet s){
    typename map<Sommet,vector<pair<Sommet,Poids> > >::iterator it;
    it = this->graphe.find(s);
    if(it != this->graphe.end())
        this->graphe[s]=vector<pair<Sommet,Poids> >(0);
}


template <class Sommet,class Poids> void Graphe<Sommet,Poids>::ajouter_Arete(Sommet deb, Sommet fin, Poids poids){
    ajouter_Sommet(deb);
    ajouter_Sommet(fin);

    typename vector<pair<Sommet,Poids> >::iterator it_vector;
    bool existe = false;

    if(this->orientation){
        for (it_vector = graphe[deb].begin() ; it_vector != graphe[deb].end() || existe; ++it_vector){
            if(it_vector == (pair<Sommet,Poids>(fin, poids)))
                existe=true;
        }
        if(!existe)
            graphe[deb].push_back(pair<Sommet,Poids>(fin, poids));

    }else{
        for (it_vector = graphe[deb].begin() ; it_vector != graphe[deb].end() || existe; ++it_vector){
            if(it_vector == (pair<Sommet,Poids>(fin, poids)))
                existe=true;
        }
        if(!existe) {
            graphe[deb].push_back(pair<Sommet, Poids>(fin, poids));
            graphe[fin].push_back(pair<Sommet, Poids>(deb, poids));
        }
    }
}


template <class Sommet,class Poids> void Graphe<Sommet,Poids>::supprimer_Sommet(Sommet s){
    typename map<Sommet,vector<pair<Sommet,Poids> > >::iterator it;
    it = this->graphe.find(s);
    if(it != this->graphe.end())
        graphe.erase (it);
}

template <class Sommet, class Poids> vector<Sommet> Graphe<Sommet,Poids> ::get_Sommets() const {
    return vector<Sommet>(0);
}


template <class Sommet,class Poids> void Graphe<Sommet,Poids>::supprimer_Arete(Sommet deb, Sommet fin, Poids poids){

    typename vector<pair<Sommet,Poids> >::iterator it_vector;
    bool existe = false;

    if(this->orientation){

        for (it_vector = graphe[deb].begin() ; it_vector != graphe[deb].end() || !existe; ++it_vector){
            if(it_vector == (pair<Sommet,Poids>(fin, poids)))
                existe=true;
        }

        if(existe)
            graphe[deb].erase(pair<Sommet,Poids>(fin, poids));

    }else{
        for (it_vector = graphe[deb].begin() ; it_vector != graphe[deb].end() || !existe; ++it_vector){
            if(it_vector == (pair<Sommet,Poids>(fin, poids)))
                existe=true;
        }
        if(existe){
            graphe[deb].erase(pair<Sommet,Poids>(fin, poids));
            graphe[deb].erase(pair<Sommet,Poids>(deb, poids));
        }
    }

}
