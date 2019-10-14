#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
int main(){
    string postfixed;
    postfixed = postfijo();
    //cout<<postfixed<<endl;
    string agregar = "";
    stack<string> solver;
    do_vector(solver,postfixed,agregar);
    Node* Solver = new Node(solver);
    cout<<Solver->result(Solver)<<endl;

}