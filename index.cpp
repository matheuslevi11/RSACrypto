#include <bits/stdc++.h>
#include "functions.h"

using namespace std;

void generatePublicKey(mpz_class e_mpz, mpz_class n_mpz){
    string e = e_mpz.get_str();
    string n = n_mpz.get_str();

    write_file("publicKeys.txt", n, e);
}

void encrypt(string msg, string n_str, string e_str){
   char alphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 
    'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 
    'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    int size = msg.size();
    vector <mpz_class> encryptMsg; 
    mpz_class e, n;

    e = e_str;
    n = n_str;

    for(int i = 0; i < size; i++){
        unsigned long int m = find(msg[i], alphabet);
        if(m == -1) continue;
        mpz_class c, base;
        mpz_ui_pow_ui (base.get_mpz_t(), m, e.get_ui());
        c = base % n; 
        cout << m << ' '; 
        encryptMsg.push_back(c);
    }

    write_msg("encryptedMsg.txt", encryptMsg);


}
int main(){
    int option, p, q, e;
    printf("O que vc quer fazer?\n");
    printf("Gerar chave pública [1]\n");
    printf("Encriptar [2]\n");
    printf("Desencriptar [3]\n");
    cin >> option;  

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
        string msg, n, e;
        printf("Mensagem: \n");
        cin >> msg; 
        printf("Insira a chave pública: \n");
        cin >> n >> e;
        encrypt(msg, n, e);
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

    }
    return 0;
}