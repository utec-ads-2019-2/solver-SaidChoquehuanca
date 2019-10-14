//
// Created by saidchoquehuanca on 13/10/2019.
//

#include <stack>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool comprobar_car(char character) {
    if( character == '+' or character == '-'
        or character == '*' or character == '/'
        or character == '^'){
        return  true;
    }
    else return false;
}
bool comprobar_var(char variable){
    if((variable>='A' and variable<='Z') or (variable>='a' and variable<='z')){
        return true;
    }else return false;
}

bool restricts(char character) {
    if((comprobar_car(character) == false) and character != '(' and character != ')')
        return true;
    else return false;
}

int compareOperators(char op_r, char op_l) {
    if ((op_r == '+' or op_r == '-') and (op_l == '*' or op_l == '/' or op_l == '^')){
        return 1;
    }else if ((op_r == '*' or op_r == '/' or op_r == '^') and (op_l == '+' or op_l == '-')){
        return -1;
    }
    else return 0;
}
double operacion(char operador, double left ,double right){
    if(operador == '+' ){
        return left + right;
    }
    else if(operador =='-'){
        return right-left;
    }
    else if (operador == '*'){
        return  right*left;
    }
    else if (operador == '/'){
        return right/left;
    }
    else if (operador == '^'){
        return pow(right,left);
    }
    else
        throw out_of_range("Sin reconocer");
}
void do_vector( stack<string> &string_vector,string cadena , string add){
    for (int i = 0; i < cadena.size(); i++) {
        if (restricts(cadena[i]) and cadena[i] != ' ') {
            add += cadena[i];
        }else if ((cadena[i] == ' ' or comprobar_car(cadena[i])) and !add.empty()){
            string_vector.push(add);
            add ="";
        }if (comprobar_car(cadena[i])){
            add += cadena[i];
            string_vector.push(add);
            add = "";
        }
    }
}
string postfijo(){
    string post_string = "";
    stack<char> stack_ops;
    char solver[1000];
    cout << "Escriba Operacion : ";
    cin >> solver;
    char *solve_work = solver;
    while (*solve_work != '\0') {
        if (restricts(*solve_work)){
            post_string += *solve_work;
        }else if (*solve_work == '('){
            stack_ops.push(*solve_work);
        }else if (*solve_work == ')'){
            while (!stack_ops.empty()){
                if (stack_ops.top() == '('){
                    stack_ops.pop();
                    break;}
                post_string += stack_ops.top();
                stack_ops.pop();
            }
        }else if (comprobar_car(*solve_work)){
            while (!stack_ops.empty() and (stack_ops.top() != '(') and (compareOperators(stack_ops.top(),*solve_work) <= 0)) {
                post_string += stack_ops.top();
                stack_ops.pop();
            }
            post_string += ' ';
            stack_ops.push(*solve_work);
        }
        solve_work++;
    }
    while (!stack_ops.empty()) {
        post_string += stack_ops.top();
        post_string += ' ';
        stack_ops.pop();
    }
    return post_string;
}



