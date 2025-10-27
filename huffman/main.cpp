#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Node
{
    private:
    char _ch;
    int _freq;
    Node* _left;
    Node* _right;

    public:
    Node(char ch = '\0', int freq = 0, Node* left = nullptr, Node* right = nullptr) : 
    _ch(ch), _freq(freq), _left(left), _right(right)
    {
    }

    char getCh() { return _ch; }
    int getFreq() { return _freq; }
    Node* getLeft() { return _left; }
    Node* getRight() { return _right; }
};

class Compare
{
    public:
    bool operator() (Node* left, Node* right)
    {
        return left->getFreq() > right->getFreq();
    }
};

Node* buildHuffmanTree(string text);
void printHuffman(Node* root, string str, unordered_map<char, string>& huffmanCode);
string encodeStr(string str, unordered_map<char, string>& huffmanCode);
void decode(string bits, Node* root);

int main(int argc, char* argv[])
{
    string text = "abbcccddddeeeeeffffff";
    unordered_map<char, string> huffmanCode;
    Node* root;

    cout << "Enter a string to encode: ";
    getline(cin, text);

    root = buildHuffmanTree(text);

    printHuffman(root, "", huffmanCode);

    string encoded = encodeStr(text, huffmanCode);
    cout << "Encoded string: " << encoded << endl;

    cout << "Decoded string: ";
    decode(encoded, root);
    cout << endl;

    return 0;
}

void decode(string bits, Node* root)
{
    // bits = "100110110100110010"

    Node* curNode = root;
    for(auto ch : bits)
    {
        if(ch == '0')
        {
            curNode = curNode->getLeft();
        }
        else
        {
            curNode = curNode->getRight();
        }

        if(curNode->getLeft() == curNode->getRight())
        {
            //at leaf node
            cout << curNode->getCh();
            curNode = root;
        }
    }
}

string encodeStr(string str, unordered_map<char, string>& huffmanCode)
{
    /*
    'a': "000"
    'i': "0010"
    'y': "00110"
    */
    string toReturn = "";
    for(auto ch : str)
    {
        toReturn += huffmanCode[ch];
    }
    return toReturn;
}

Node* buildHuffmanTree(string text)
{
    unordered_map<char, int> charFreq;
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for(char ch : text)
    {
        charFreq[ch]++;
    }

    for(auto it = charFreq.begin(); it != charFreq.end(); it++)
    {
        // cout << it->first << ": " << it->second << endl;
        pq.push(new Node(it->first, it->second));
    }

    while(pq.size() > 1)
    {
        // cout << pq.top()->getCh() << ": " << pq.top()->getFreq() << endl;
        // pq.pop();
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('\0', left->getFreq() + right->getFreq(), left, right);
        pq.push(newNode);
    }

    Node* root = pq.top();
    pq.pop();
    return root;
}

void printHuffman(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if(root == nullptr) return;

    // print
    if(!root->getLeft() && !root->getRight())
    {
        cout << root->getCh() << ": " << str << endl;
        huffmanCode[root->getCh()] = str;
    }

    printHuffman(root->getLeft(), str + "0", huffmanCode);
    printHuffman(root->getRight(), str + "1", huffmanCode);
}