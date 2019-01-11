#include <iostream>
#include "Tas.hpp"
#include "graphe.hpp"

int main() {
    Tas<int> *test = new Tas<int>();
    cout << test ;
    test->ajout_Element(2);

    delete test;

    return 0;
}