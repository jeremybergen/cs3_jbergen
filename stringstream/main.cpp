#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream fin;
    fin.open("input.csv");

    string inLine;
    while(getline(fin, inLine))
    {
        istringstream iss;
        iss.str(inLine);
        string token;
        int counter = 0;
        string tokens[3];

        while(getline(iss, token, ','))
        // while(iss >> token)
        {
            // cout << token << "|";
            tokens[counter] = token;
            counter++;
        }
        // cout << endl;

        // u = tokens[0];
        // v = tokens[1];
        // int weight = stoi(tokens[2]);
    }

    fin.close();
    return 0;
}