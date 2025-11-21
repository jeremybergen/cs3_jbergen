#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <fstream>

using namespace std;

void cleanWord(string&);
bool isPrime(int);
int nextPrime(int);
int hashFunction(string, int);

int main(int argc, char* argv[])
{
    string inStr;

    // cout << "Enter a string to hash: ";
    // getline(cin, inStr);

    ifstream fin;
    fin.open("input.txt");

    vector<string> words;
    string word, line;
    while(getline(fin, line))
    {
        istringstream iss(line);
        while(iss >> word)
        {
            cleanWord(word);
            words.push_back(word);
        }
    }

    // istringstream iss;
    // iss.str(inStr);
    // while(iss >> word)
    // {
    //     cleanWord(word);
    //     words.push_back(word);
    // }

    int hashTableSize = words.size();
    hashTableSize = nextPrime(hashTableSize * 2);

    // cout << "Hash table size: " << hashTableSize << endl;

    vector<list<string>> hashTable(hashTableSize);

    for(auto word : words)
    {
        int idx = hashFunction(word, hashTableSize);
        // cout << "debug: " << idx << ", " << word << endl;
        hashTable.at(idx).push_back(word);
    }

    for(int i = 0; i < hashTableSize; i++)
    {
        if(hashTable[i].size() == 0) continue;
        cout << "hashTable[" << i << "]: ";
        for(auto it : hashTable[i])
        {
            cout << it << ", ";
        }
        cout << endl;
    }

    cout << "Table size: " << hashTableSize << endl;

    // for(auto it: words)
    // {
    //     cout << it << endl;
    // }

    return 0;
}

int hashFunction(string str, int tblSize)
{
    // SDBM Hash
    unsigned long hash = 0;

    for(auto ch : str)
    {
        hash = ch + (hash << 6) + (hash << 16) - hash;
    }
    return hash % tblSize;

    // Bitwise hash (DJB2)
    // unsigned long hash = 5381;
    // for(auto ch : str)
    // {
    //     hash = ch + (hash << 5) + hash;
    // }
    // return (hash % tblSize);

    // Modified Rabin-Karp
    // int p = 31;
    // int hashval = 0;
    // int p_pow = 1;

    // for(auto ch : str)
    // {
    //     hashval = (hashval + (ch - 'a' + 1) * p_pow);
    //     p_pow = (p_pow * p) % tblSize;
    // }

    // return (hashval % tblSize);


    // int strSum = 0;
    // for(auto ch : str)
    // {
    //     strSum += ch;
    // }
    // // strSum %= tblSize;
    // return strSum%tblSize;
}

int nextPrime(int n)
{
    while(!isPrime(n)) n++;
    return n;
}

bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6)
    {
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}

void cleanWord(string& str)
{
    string cleanStr = "";
    for(auto ch : str)
    {
        if(isalpha(ch)) cleanStr += tolower(ch);
    }
    str = cleanStr;
}