//
// Created by saidchoquehuanca on 13/10/2019.
//

#ifndef SOLVER_SAIDCHOQUEHUANCA_NODE_H
#define SOLVER_SAIDCHOQUEHUANCA_NODE_H
#include <stack>
#include <string>
#include <cmath>
#include "solver.cpp"
#include <map>

using namespace std;

class Node {
    string input = "" ;
    Node *left = nullptr;
    Node *right = nullptr;
public:
    explicit Node(stack<string> &str);
    map<char,double>* mapeo{};
    double execute(map<char , double > *buscador_mapeo){
        char nod_right= right->input[0];
        char nod_left= left->input[0];
        double right_, left_;
        if (comprobar_car(nod_right) and comprobar_car(nod_left)!=NULL){
            right_ = right->execute(buscador_mapeo);
            left_ = left->execute(buscador_mapeo);
        }else if(comprobar_car(nod_right) != NULL){
            right_ = right->execute(buscador_mapeo);
            if (comprobar_var(nod_left) == NULL  ){
                left_ = atof((left->input).c_str());
            }else {
                if ((buscador_mapeo->find(nod_left) == buscador_mapeo->end())){
                    cout<<"Ingresar variable "<< left->input<<endl;
                    cin>>left_;
                    buscador_mapeo->insert(pair<char, double >(nod_left,left_));
                }else
                    left_ = buscador_mapeo->operator[](nod_left);
            }
        }else if (comprobar_car(nod_left)){
            left_ = left->execute(buscador_mapeo);
            if (comprobar_var(nod_right) == NULL){
                right_ = atof((right->input).c_str());
            }else {
                if ((buscador_mapeo->find(nod_right) == buscador_mapeo->end())){
                    cout<<"Ingresa Variable "<< nod_right<<endl;
                    cin>>right_;
                    buscador_mapeo->insert(pair<char, double >(nod_right,right_));
                }else
                    right_=buscador_mapeo->operator[](nod_right);
            }
        }else {
            if (comprobar_var(nod_right) == NULL){
                right_ = atof((right->input).c_str());
            }else {
                if ((buscador_mapeo->find(nod_right) == buscador_mapeo->end())){
                    cout<<"Ingresar variable "<< right->input<<endl;
                    cin>>right_;
                    buscador_mapeo->insert(pair<char, double >(nod_right,right_));
                }else
                    right_ = buscador_mapeo->operator[](nod_right);
            }
            if (comprobar_var(nod_left) == NULL ){
                left_ = atof((left->input).c_str());
            }else {
                if ((buscador_mapeo->find(nod_left) == buscador_mapeo->end())){
                    cout<<"Ingresar variable "<< left->input<<endl;
                    cin>>left_;
                    buscador_mapeo->insert(pair<char, double >(nod_left,left_));
                }else
                    left_=buscador_mapeo->operator[](nod_left);
            }

        }
        return  operacion(this->input[0],left_,right_);
    }

    int result(Node* Solver){
        return Solver->execute(Solver->mapeo);
    }

};

Node::Node(stack<string> &cadena_solv) {
    this->input =cadena_solv.top();
    cadena_solv.pop();
    if(comprobar_car(this->input.at(0)) and  !cadena_solv.empty()){
        left = new Node(cadena_solv);
        right = new Node(cadena_solv);
    }
    mapeo = new map<char , double >;
}
#endif //SOLVER_SAIDCHOQUEHUANCA_NODE_H
