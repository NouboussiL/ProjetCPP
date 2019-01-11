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
            return NULL;
        }

        void ajout_Element(T e){
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

        T recherche_Element(T e){
            typename vector<T>::iterator it;
            it = this->tableau.find(e);
            if(it != this->tableau.end())
                return it;
            return NULL;
        }

        friend std::ostream & operator << ( std:: ostream& ost, const Tas & tab){
            typename vector<T>::iterator it;
            if(tab.tableau.size()!=0){
                for(it = tab.tableau.begin() ; it < tab.tableau.end() ; it ++){
                    if(it != tab.tableau.end()-1) {
                        ost << it << " ; ";
                    }else
                        ost << it <<endl;
                }
            }else{
                ost << "Arbre Vide";
            }
            return ost;
        }

};

#endif //PROJET_TAS_HPP
