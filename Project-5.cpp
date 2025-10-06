#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = nullptr;
    }
};
// This structure helps the priority queue compare nodes and also makes sure the node with the smallest frequency is always on top
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};
// This function prints all Huffman codes using preorder traversal and also it prints the binary code when a leaf node is reached.
void printCodes(Node* root, string code) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right)
        cout << code << " ";
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}
void HuffmanCodes(string S, int f[], int N) {  //Here this function builds the Huffman Tree and prints all codes.
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < N; i++) {
        pq.push(new Node(S[i], f[i]));
    }
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        //here it will create a new node with the sum of the two smallest frequencies.
        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged); // here we are add the new node back into the queue
    }
    Node* root = pq.top();
    printCodes(root, ""); //Finally we are printing all Huffman codes in preorder order
}
int main() {  // This is the main function to test the Huffman Coding program.
    string S = "abcdef";
    int f[] = {5, 9, 12, 13, 16, 45};
    int N = S.size();
    cout << "Hey buddy here the huffman Codes (Preorder): ";
    HuffmanCodes(S, f, N);
    cout << endl;
    return 0;
}
