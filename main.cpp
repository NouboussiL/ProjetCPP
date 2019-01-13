#include <iostream>
#include "Tas.hpp"
#include "graphe.hpp"

int main() {

    /*
     *
     * PARTIE TAS
     *
     */

    cout << endl << "TAS" << endl << endl;

    Tas<int> *test_tas = new Tas<int>();

    test_tas->afficher() ;

    test_tas->get_Minimum();
    int n = test_tas->get_Minimum();

    test_tas->ajout_Element(2);
    test_tas->afficher();
    test_tas->ajout_Element(19);
    test_tas->afficher();
    test_tas->ajout_Element(17);
    test_tas->afficher();
    test_tas->ajout_Element(100);
    test_tas->afficher();
    test_tas->ajout_Element(25);
    test_tas->afficher();
    test_tas->ajout_Element(15);
    test_tas->afficher();
    test_tas->ajout_Element(1);
    test_tas->afficher();
    test_tas->ajout_Element(4);
    test_tas->afficher();
    test_tas->ajout_Element(13);
    test_tas->afficher();
    test_tas->ajout_Element(36);
    test_tas->afficher();
    test_tas->ajout_Element(9);
    test_tas->afficher();
    test_tas->ajout_Element(11);
    test_tas->afficher();
    test_tas->ajout_Element(44);
    test_tas->afficher();
    test_tas->ajout_Element(33);
    test_tas->afficher();
    test_tas->ajout_Element(99);
    test_tas->afficher();
    test_tas->ajout_Element(77);
    test_tas->afficher();
    test_tas->ajout_Element(3);
    test_tas->afficher();

    cout << "le minimum du tas est :: ";
    n=test_tas->get_Minimum();
    cout << n << endl;

    bool a = test_tas->recherche_Element(3);
    cout << a << endl;

    a = test_tas->recherche_Element(1000);
    cout << a << endl;

    delete test_tas;

    /*
     *
     * PARTIE GRAPHE
     *
     */

    cout << endl << "GRAPHE" << endl << endl;

    Graphe<string,int> *myGraphe = new Graphe<string,int>();

    myGraphe->ajouter_Arete("A", "B", 5);
    myGraphe->ajouter_Arete("A", "G", 1);
    myGraphe->ajouter_Arete("B", "A", 5);
    myGraphe->ajouter_Arete("B", "G", 2);
    myGraphe->ajouter_Arete("G", "A", 1);
    myGraphe->ajouter_Arete("G", "B", 2);
    myGraphe->ajouter_Arete("G", "E", 3);
    myGraphe->ajouter_Arete("G", "D", 32);
    myGraphe->ajouter_Arete("E", "G", 3);
    myGraphe->ajouter_Arete("E", "C", 7);
    myGraphe->ajouter_Arete("D", "G", 32);
    myGraphe->ajouter_Arete("D", "F", 5);
    myGraphe->ajouter_Arete("C", "F", 8);
    myGraphe->ajouter_Arete("C", "E", 7);
    myGraphe->ajouter_Arete("F", "C", 8);
    myGraphe->ajouter_Arete("F", "D", 5);

    myGraphe->afficher();

    myGraphe->dijkstra("B",0);

    delete myGraphe;
    return 0;
}