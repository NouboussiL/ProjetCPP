//
// Created by uzay on 11/01/19.
//

#ifndef PROJET_TAS_ID_HPP
#define PROJET_TAS_ID_HPP


#include <iostream>
#include <map>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

template<class Sommet, class Poids> class Tas_ID {

    private:
        map<int,pair <Sommet,Poids> > tableau;

    public:
        Tas_ID(){}

        ~Tas_ID(){}

        int taille(){ return tableau.size(); }

        void ajout_Element(pair <Sommet,Poids> e){
            bool exist = false;
            int i = 0;
            for (typename map<int,pair<Sommet,Poids> >::iterator it = (tableau).begin() ; it != (tableau).end() ; it++){
                if(((*it).second).first == e.first){
                    if (((*it).second).second > e.second){
                        ((*it).second).second = e.second;
                        for (int j = i; j < tableau.size(); j++){
                            if ((j != tableau.size()-1) && ( e.second < tableau[j+1].second)){
                                tableau[j] = tableau[j+1];
                            } else {
                                tableau[j] = e;
                                break;
                            }
                        }
                    }
                    exist = true;
                    break;
                }
                i++;
            }
            if (!exist){
                tableau[tableau.size()] = e;
                for (int j = tableau.size()-1; j >= 0; j--){
                    if ((j != 0) && ( e.second > tableau[j-1].second)){
                        tableau[j] = tableau[j-1];
                    } else {
                        tableau[j] = e;
                        break;
                    }
                }
            }
        }

        pair<Sommet,Poids> extraire_Min(){
            if(tableau.size()>0){
                pair<Sommet,Poids> myPair = tableau[tableau.size()-1];
                tableau.erase(tableau.size()-1);
                return myPair;
            }else{
                throw length_error("Aucun élément à extraire");
            }
        }

        void afficher(){
            if (tableau.size() > 0){
                for (typename map<int,pair<Sommet,Poids> >::iterator it = (tableau).begin() ; it != (tableau).end() ; it++){
                    cout << "[";
                    cout << (*it).first;
                    cout <<  ",(";
                    pair<Sommet,Poids> myPair = it->second;
                    cout << myPair.first;
                    cout << ",";
                    cout << myPair.second;
                    cout << ")]" << endl;
                }
            }
        }
};

#endif //PROJET_TAS_ID_HPP
