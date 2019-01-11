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
    Graphe(Sommet s, bool b);
    Graphe(Sommet deb, Sommet fin, Poids poids);
    Graphe(Sommet deb, Sommet fin, Poids poids,bool b);
    Graphe(const Graphe &g);
    ~Graphe(){};

    //vector<Sommet> get_Sommets() const;

    bool get_Orientation() const {return orientation;};

    void ajouter_Sommet(Sommet s);
    void ajouter_Arete(Sommet deb, Sommet fin, Poids poids);
    void supprimer_Sommet(Sommet s);
    void supprimer_Arete(Sommet deb, Sommet fin, Poids poids);


};

template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe(){
    this=Graphe(false);
}


template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe(bool b):orientation(){
    this->orientation=b;
}


template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe(Sommet s){
    this=Graphe(s,false);
}

template <class Sommet,class Poids>Graphe<Sommet,Poids>::Graphe(Sommet s,bool b):orientation(){
    this->graphe[s]=vector<pair<Sommet,Poids> >(0);
    this->orientation=b;
}


template <class Sommet,class Poids> Graphe<Sommet,Poids>::Graphe(Sommet deb, Sommet fin, Poids poids){
    this=Graphe(deb,fin,poids,false);
}

template <class Sommet,class Poids> Graphe<Sommet,Poids>::Graphe(Sommet deb, Sommet fin, Poids poids,bool b):orientation(){
    this->orientation=b;
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
        for (it_vector = graphe[deb].begin() ; it_vector != graphe[deb].end() && !existe; ++it_vector){
            if(it_vector == (pair<Sommet,Poids>(fin, poids)))
                existe=true;
        }
        if(!existe)
            graphe[deb].push_back(pair<Sommet,Poids>(fin, poids));

    }else{
        for (it_vector = graphe[deb].begin() ; it_vector != graphe[deb].end() && !existe; ++it_vector){
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

/*
    template <class Sommet, class Poids> vector<Sommet> Graphe<Sommet,Poids> ::get_Sommets() const {
        return this->graphe.key_comp();
    }
 */


template <class Sommet,class Poids> void Graphe<Sommet,Poids>::supprimer_Arete(Sommet deb, Sommet fin, Poids poids){

    typename vector<pair<Sommet,Poids> >::iterator it_vector;
    bool existe = false;

    if(this->orientation){

        for (it_vector = graphe[deb].begin() ; it_vector != graphe[deb].end() && !existe; ++it_vector){
            if(it_vector == (pair<Sommet,Poids>(fin, poids)))
                existe=true;
        }

        if(existe)
            graphe[deb].erase(pair<Sommet,Poids>(fin, poids));

    }else{
        for (it_vector = graphe[deb].begin() ; it_vector != graphe[deb].end() && !existe; ++it_vector){
            if(it_vector == (pair<Sommet,Poids>(fin, poids)))
                existe=true;
        }
        if(existe){
            graphe[deb].erase(pair<Sommet,Poids>(fin, poids));
            graphe[deb].erase(pair<Sommet,Poids>(deb, poids));
        }
    }

}


template <class Sommet,class Poids> std :: ostream & operator << ( std:: ostream& ost, Graphe<Sommet,Poids> const &g);


#endif //PROJET_GRAPHE_HPP

