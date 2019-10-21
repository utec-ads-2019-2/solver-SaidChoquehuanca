#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
int main(){
    string postfixed;
    postfixed = postfijo();
    //cout<<postfixed<<endl;
    string agregar = "";
    // No funciona con decimales en las variables
    stack<string> solver;
    do_vector(solver,postfixed,agregar);
    Node* Solver = new Node(solver);
    // Falta liberar la memoria
    cout<<Solver->result(Solver)<<endl;

}