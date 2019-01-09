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

        Tas();
        Tas(T e);

        T get_Minimum() const;
        void ajout_Element(T e);
        T recherche_Element(T e);

};

template <class T> std :: ostream & operator << ( std:: ostream& ost, Tas<T> const &tab);


#endif //PROJET_TAS_HPP
