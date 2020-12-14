#include <bits/stdc++.h>
#include "functions.h"

using namespace std;

void generatePublicKey(mpz_class e_mpz, mpz_class n_mpz){
    string e = e_mpz.get_str();
    string n = n_mpz.get_str();

    write_file("publicKey.txt", n, e);
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
        mpz_class m;
        m = find(msg[i], alphabet);
        if(m == -1) continue;
        mpz_class c, base;

        mpz_powm(c.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
        encryptMsg.push_back(c);
    }

    write_msg("encryptedMsg.txt", encryptMsg);
}

void decrypt(string p_str, string q_str, string e_str){

    mpz_class p, q, e;
    p = p_str;
    q = q_str;
    e = e_str;

    char alphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 
    'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 
    'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

    mpz_class totiente, d;
    totiente = (p - 1) * (q - 1);
    d = getReverse(e, totiente);

    vector <mpz_class> numbers = read_file("encryptedMsg.txt");
    vector <mpz_class> m;

    for(int i = 0; i < numbers.size(); i++){
        mpz_class ch, base, n;
        n = p * q;
        mpz_powm(ch.get_mpz_t(), numbers[i].get_mpz_t(), d.get_mpz_t(), n.get_mpz_t() );
        m.push_back(ch);
    } 

    string message;

    for(int i = 0; i < m.size(); i++){
        
        int index = mpz_to_int(m[i]);
        //printf("%c", alphabet[index - 2]);
        message.push_back(alphabet[index - 2]);
    }

    write_file("decryptedMsg.txt", message, "");
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

        printf("p: \n");
        cin >> p;
        mpz_class p_mpz;
        p_mpz = p;
        while (!primo(p_mpz))
        {
            printf("Digite um valor válido\n");
            cin >> p;
            p_mpz = p;
        }

        printf("q: \n");
        cin >> q;
        mpz_class q_mpz;
        q_mpz = q;
        while (!primo(q_mpz))
        {
            printf("Digite um valor válido\n");
            cin >> q;
            q_mpz = q;
        }

        printf("valor e: \n");
        cin >> e;

        mpz_class totiente_mpz, e_mpz ;
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
        scanf("\n");
        getline(cin, msg); 
        printf("Insira a chave pública: \n");
        cin >> n >> e;
        encrypt(msg, n, e);
    }

    else if( option == 3){
        string e, p, q;

        printf("p: \n");
        cin >> p;
        mpz_class p_mpz;
        p_mpz = p;
        while (!primo(p_mpz))
        {
            printf("Digite um valor válido\n");
            cin >> p;
            p_mpz = p;
        }

        printf("q: \n");
        cin >> q;
        mpz_class q_mpz;
        q_mpz = q;
        while (!primo(q_mpz))
        {
            printf("Digite um valor válido\n");
            cin >> q;
            q_mpz = q;
        }

        printf("valor e: \n");
        cin >> e;

        mpz_class totiente_mpz, e_mpz ;
        e_mpz = e;

        totiente_mpz = (p_mpz - 1) * (q_mpz - 1);
        while(coprimos(e_mpz, totiente_mpz) != 1 || e_mpz < 1 || e_mpz > totiente_mpz){
            printf("Digite um valor e válido\n");
            cin >> e;
            e_mpz = e;
        }

        decrypt(p, q, e);
    }
    return 0;
}