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

 #endif
