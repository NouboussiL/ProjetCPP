//
// Created by lionel on 08/01/19.
//


#ifndef PROJET_GRAPHE_HPP
#define PROJET_GRAPHE_HPP
#include <map>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <string>
#include <stdbool.h>
#include "Tas_ID.hpp"


using namespace std;

template <class Sommet, class Poids> class Graphe {


private:
    bool orientation;
    map<Sommet,vector<pair<Sommet,Poids> > > graphe;
public:

    Graphe():orientation(){
        //this=Graphe(false);
        this->orientation=false;
    }

    Graphe(bool b):orientation(){
        this->orientation=b;
    }

    Graphe(Sommet s){
        this=Graphe(s,false);
    }

    Graphe(Sommet s,bool b):orientation(){
        this->graphe[s]=vector<pair<Sommet,Poids> >(0);
        this->orientation=b;
    }

    Graphe(Sommet deb, Sommet fin, Poids poids){
        this=Graphe(deb,fin,poids,false);
    }

    Graphe(Sommet deb, Sommet fin, Poids poids,bool b):orientation(){
        this->orientation=b;
        if(orientation){
            this->graphe[deb]=vector<pair<Sommet,Poids> > (pair<Sommet,Poids>(fin, poids));
        }else{
            this->graphe[deb]=vector<pair<Sommet,Poids> > (pair<Sommet,Poids>(fin, poids));
            if(deb!=fin)
                this->graphe[fin]=vector<pair<Sommet,Poids> > (pair<Sommet,Poids>(deb, poids));
        }
    }

    Graphe(const Graphe &g){
        this->orientation=g.orientation;
        this->graphe(g.graphe);
    }

    ~Graphe(){};

    //vector<Sommet> get_Sommets() const;

    bool get_Orientation() const {return orientation;};

    void ajouter_Sommet(Sommet s){
        typename map<Sommet,vector<pair<Sommet,Poids> > >::iterator it;
        it = this->graphe.find(s);
        if(it != this->graphe.end())
            this->graphe[s]=vector<pair<Sommet,Poids> >(0);
    }

    void ajouter_Arete(Sommet deb, Sommet fin, Poids poids){
        if(this->orientation) {
            if (graphe.find(deb) == graphe.end()) {
                ajouter_Sommet(deb);
            }
            bool areteExiste = false;
            vector<pair<Sommet, Poids> > &v = graphe[deb];
            for (int i = 0; i < v.size(); ++i) {
                if (v[i].first == fin && v[i].second== poids) {
                    areteExiste = true;
                }
            }
            if (!areteExiste) {
                v.push_back(pair<Sommet, Poids>(fin, poids));
            } else {
                cout << "Impossible d'ajouter, l'arete existe déjà." << endl;
            }

            bool exist = false;
            for (typename map<Sommet, vector<pair<Sommet, Poids> > >::iterator it = graphe.begin();
                 it != graphe.end(); it++) {
                if (it->first == fin) {
                    exist = true;
                }
            }
            if (!exist) {
                ajouter_Sommet(fin);
            }
        }else{
            if (graphe.find(deb) == graphe.end()) {
                ajouter_Sommet(deb);
            }
            bool areteExiste = false;
            vector<pair<Sommet, Poids> > &v = graphe[deb];
            for (int i = 0; i < v.size(); ++i) {
                if (v[i].first == fin && v[i].second== poids) {
                    areteExiste = true;
                }
            }
            if (!areteExiste) {
                v.push_back(pair<Sommet, Poids>(fin, poids));
            } else {
                cout << "Impossible d'ajouter, l'arete existe déjà." << endl;
            }

            bool exist = false;
            for (typename map<Sommet, vector<pair<Sommet, Poids> > >::iterator it = graphe.begin();
                 it != graphe.end(); it++) {
                if (it->first == fin) {
                    exist = true;
                    graphe[fin].push_back(pair<Sommet, Poids>(deb, poids));
                }
            }
            if (!exist) {
                ajouter_Sommet(fin);
                graphe[fin].push_back(pair<Sommet, Poids>(deb, poids));
            }
        }
    }

    void supprimer_Sommet(Sommet s){
        typename map<Sommet,vector<pair<Sommet,Poids> > >::iterator it;
        it = this->graphe.find(s);
        if(it != this->graphe.end())
            graphe.erase (it);
    }

    void supprimer_Arete(Sommet deb, Sommet fin, Poids poids){

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

    void afficher (){
        for (typename map< Sommet , vector < pair<Sommet,Poids> > >::const_iterator it = (graphe).begin() ; it != (graphe).end() ; it++){
            cout<< "[";
            cout<< (it -> first) << "]->[";
            for (typename vector <pair<Sommet,Poids> >::const_iterator itv = (it->second).begin() ; itv != (it->second).end() ; itv++){
                pair<Sommet, Poids> myPair= *itv;
                cout<< "[" << (myPair.first) << "," <<  myPair.second << "]";
                if (itv != (it->second).end()-1) {
                    cout<< ",";
                }
            }
            cout<< "]\n";
        }
        cout<<endl;
    }

    void dijkstra(Sommet s,Poids p){//il faut mettre 0 par defaut car je sais pas faire sans
        pair<Sommet,Poids> myPair (s,p);
        typename map<Sommet,vector<pair<Sommet,Poids> > >::iterator it = graphe.find(myPair.first);
        if( it != graphe.end() ){
            vector<Sommet> *vect = new vector<Sommet>();
            if(graphe.size()>0){
                pair<Sommet,Poids> pere = myPair;
                Tas_ID<Sommet,Poids> *tas = new Tas_ID<Sommet,Poids>();
                tas->ajout_Element(myPair);
                while(tas->taille()!=0){
                    vector<pair<Sommet,Poids> > voisins = graphe[pere.first];
                    for (typename vector <pair<Sommet,Poids> >::iterator it = voisins.begin() ; it != voisins.end() ; it++){
                        pair<Sommet,Poids> voisin = pair<Sommet,Poids>(it->first,(it->second)+(pere.second));
                        if (find(vect->begin(),vect->end(),voisin.first) == vect->end()){
                            tas->ajout_Element(voisin);
                        }
                    }
                    pere=tas->extraire_Min();
                    vect->push_back(pere.first);
                }
            }
            for (int i = 0; i < vect->size(); ++i){
                cout << (*vect)[i] << endl;
            }
        }else{
            cout<<"Le sommet donné en argument n'existe pas dans le graphe."<<endl;
        }


    }


};

#endif //PROJET_GRAPHE_HPP

