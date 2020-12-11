#ifndef FUNCTIONS_H
 #define FUNCTIONS_H

#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

void write_file(string filename, string n1, string n2)
{
    ofstream file;
    file.open(filename);

    if (!file.good())
        return;
    else
        printf("Arquivo criado com sucesso.\n");

    file << n1;
    file << ',';
    file << n2;
    file.close();
    return;
}

pair<string, string> read_file(string filename)
{
    ifstream file;
    string n;
    string e;

    file.open(filename);

    if (!file)
    {
        printf("File not found!\n");
    }
    else
    {
        char ch;

        int numberIndex = 0;

        while (1)
        {
            file >> ch;
            if (file.eof())
                break;
            if (ch == ',')
            {
                numberIndex++;
            }
            else if (!numberIndex)
            {
                n.push_back(ch);
            }
            else
            {
                e.push_back(ch);
            }
        }
    }
    return make_pair(n, e);
}

int mpz_to_int(mpz_class n)
{

    string number = n.get_str();
    int j = number.size() - 1;
    int result = 0;
    for (int i = 0; i < number.size(); i++)
    {
        int base = number[i] - '0';
        result += base * pow(10, j);
        j--;
    }
    return result;
}

int coprimos(mpz_class a, mpz_class b)
{
    if(a%b == 0) return mpz_to_int(b);
    return coprimos(b, a%b);
}

int mdc(mpz_class a, mpz_class b, vector<mpz_class> &quo)
{
    if (a == 0)
    {
        return -1; // (Não existe)
    }
    if (b == 0)
    {
        return mpz_to_int(a);
    }
    if (a % b != 0)
    {
        quo.push_back(a / b);
    }

    return mdc(b, a % b, quo);
}

void invert(vector<mpz_class> &quocientes)
{
    vector<mpz_class> vetorAux;
    for (int i = quocientes.size() - 1; i >= 0; i--)
    {
        vetorAux.push_back(quocientes[i]);
    }

    for (int i = 0; i < vetorAux.size(); i++)
    {
        quocientes[i] = vetorAux[i];
    }
}

pair<mpz_class, mpz_class> linearCombination(vector<mpz_class> quo)
{
    vector<mpz_class> resultados;
    mpz_class s, t;
    resultados.push_back(1);
    resultados.push_back(quo[0]);
    for (int i = 1; i < quo.size(); i++)
    {
        resultados.push_back(quo[i] * resultados[i] + resultados[i - 1]);
    }

    s = resultados[resultados.size() - 2];
    t = resultados[resultados.size() - 1];

    if (quo.size() % 2 == 0)
        return make_pair(-s, t);
    else
        return make_pair(s, -t);
}

mpz_class getReverse(mpz_class a, mpz_class m)
{
    vector<mpz_class> quo;
    mpz_class s, t;
    if (mdc(a, m, quo) == 1 && m > 1)
    {
        invert(quo);
        pair<mpz_class, mpz_class> linear = linearCombination(quo);
        s = linear.first;
        t = linear.second;
        return s;
    }
    return -1;
}

#endif
