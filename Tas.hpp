//
// Created by uzay on 09/01/19.
//

#ifndef PROJET_TAS_HPP
#define PROJET_TAS_HPP

#include <vector>
#include <iostream>

using namespace std;

template <class T>class Tas {

    private:
        vector<T> tableau;
    public:

        Tas() {
            this->tableau=vector<T> (0);
        }

        Tas(T e){
            this->tableau=vector<T> (e);
        }

        Tas(Tas const &t){
            this->tableau=t.tableau;
        }

        T get_Minimum() const {
            if(tableau.size()!=0)
                return tableau[0];
            else
                cout << "Arbre Vide" << endl;
        }

        void ajout_Element(T e){
            this->tableau.push_back(e);
            int taille=this->tableau.size();
            T echange;
            if(taille!=1){
                int indice_fils=taille-1;
                int indice_pere=(indice_fils-1)/2;
                while(indice_fils!=0 && tableau[indice_pere]>tableau[indice_fils]){
                    echange=tableau[indice_fils];
                    tableau[indice_fils]=tableau[indice_pere];
                    tableau[indice_pere]=echange;
                    indice_fils=indice_pere;
                    indice_pere=(indice_fils-1)/2;
                }
            }
        }

        bool recherche_Element(T e){
            typename vector<T>::iterator it;
            for (it = this->tableau.begin() ; it < this->tableau.end() ; it ++){
                if(*it==e){
                    return true;
                }
            }
            return false;
        }

        void afficher (){
            typename vector<T>::iterator it;
            if(this->tableau.size()!=0){
                for(it = this->tableau.begin() ; it < this->tableau.end() ; it ++){
                    if(it != this->tableau.end()-1) {
                        cout << *it << " ; ";
                    }else
                        cout << *it <<endl;
                }
            }else{
                cout << "Arbre Vide" << endl;
            }
        }

};

#endif //PROJET_TAS_HPP
