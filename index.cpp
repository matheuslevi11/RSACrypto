#include <bits/stdc++.h>

using namespace std;

int coprimos(int e, int totiente){
    return 0;
}

int main(){
    int option, p, q, e;
    printf("O que vc quer fazer?\n");
    printf("Gerar chave pública [1]\n");
    printf("Encriptar [2]\n");
    printf("Desencriptar [3]\n");
    scanf("%d", &option);

    if(option == 1){
        long long int totiente, e, p, q;
        printf("p e q: \n");
        cin >> p >> q;

        printf("valor e: \n");
        cin >> e;

        totiente = (p - 1) * (q - 1);
        while(coprimos(e, totiente) == 1 || e < 1 || e > totiente){
            printf("Digite um valor e válido\n");
            cin >> e;
        }
    }
   /*else if(option == 2){
        string msg, publicKey;
        printf("Mensagem: \n");
        cin >> msg;
        printf("Insira a chave pública: \n");
        cin >> publicKey;
    }*/
    else if( option == 3){
        long long int totiente, e, p, q;
        printf("p e q: \n");
        cin >> p >> q;

        printf("valor e: \n");
        cin >> e;

        totiente = (p - 1) * (q - 1);
        while(coprimos(e, totiente) == 1 || e < 1 || e > totiente){
            printf("Digite um valor e válido\n");
            cin >> e;
        }
        printf("Desencriptografando mensagem...");
    }
    return 0;
}