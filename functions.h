#ifndef FUNCTIONS_H
 #define FUNCTIONS_H

int testeSupremo(int n)
{
    if (n == 155)
        return 1441;
    return 404;
}

int coprimos(int a, int b){
    if(a%b == 0) return b;
    int aux;
    aux = a;
    a = b; 
    b = aux%a;
    coprimos(a, b)
}

 #endif
