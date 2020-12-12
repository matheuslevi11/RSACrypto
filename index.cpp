#include <bits/stdc++.h>
#include "functions.h"

using namespace std;

void generatePublicKey(mpz_class e_mpz, mpz_class n_mpz){
    string e = e_mpz.get_str();
    string n = n_mpz.get_str();

    write_file("giulinhaGata.txt", n, e);
}

int main(){
    int option, p, q, e;
    printf("O que vc quer fazer?\n");
    printf("Gerar chave pública [1]\n");
    printf("Encriptar [2]\n");
    printf("Desencriptar [3]\n");
    scanf("%d", &option);

    if(option == 1){
        string e, p, q;
        printf("p e q: \n");
        cin >> p >> q;

        printf("valor e: \n");
        cin >> e;

        mpz_class totiente_mpz, p_mpz, q_mpz, e_mpz ;
        p_mpz = p;
        q_mpz = q;
        e_mpz = e;

        totiente_mpz = (p_mpz - 1) * (q_mpz - 1);
        while(coprimos(e_mpz, totiente_mpz) != 1 || e_mpz < 1 || e_mpz > totiente_mpz){
            printf("Digite um valor e válido\n");
            cin >> e;
            e_mpz = e;
        }

        generatePublicKey(e_mpz, p_mpz * q_mpz);
        
    }
   else if(option == 2){
        string msg, publicKey;
        printf("Mensagem: \n");
        cin >> msg;
        printf("Insira a chave pública: \n");
        cin >> n >> e;
    }
    else if( option == 3){
        string e, p, q;
        printf("p e q: \n");
        cin >> p >> q;

        printf("valor e: \n");
        cin >> e;

        mpz_class totiente_mpz, p_mpz, q_mpz, e_mpz ;
        p_mpz = p;
        q_mpz = q;
        e_mpz = e;

        totiente_mpz = (p_mpz - 1) * (q_mpz - 1);
        while(coprimos(e_mpz, totiente_mpz) != 1 || e_mpz < 1 || e_mpz > totiente_mpz){
            printf("Digite um valor e válido\n");
            cin >> e;
            e_mpz = e;
        }
        printf("Desencriptografando mensagem...");
    }
    return 0;
}