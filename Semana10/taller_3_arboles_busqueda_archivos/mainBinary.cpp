//mainBinary.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "ArbolBinarioOrd.h" // Include header file for binary tree

using namespace std;

void processFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    // Create a new binary tree
    ArbolBinarioOrdenado<int> binaryTree;

    string line;
    while (getline(file, line)) {
        char op = line[0];
        int val = stoi(line.substr(2)); // Extract value from the line

        if (op == 'A') {
            binaryTree.insertarNodo(val); // Add value to the binary tree
            cout << "Added value to Binary Tree: " << val << endl;
        } else if (op == 'E') {
            bool removed = binaryTree.eliminarNodo(val); // Remove value from the binary tree
            if (removed) {
                cout << "Removed value from Binary Tree: " << val << endl;
            } else {
                cout << "Value " << val << " not found, cannot remove." << endl;
            }
        } else {
            cerr << "Error: Invalid operation type: " << op << endl;
        }
    }

    // Check if the binary tree is not empty before printing its data
    if (!binaryTree.esVacio()) {
        // Print binary tree data using in-order traversal
        cout << "Printing the data of the binary tree:" << endl;
        binaryTree.inOrden();
    } else {
        cout << "Binary tree is empty." << endl;
    }

    file.close();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    processFile(filename);

    return 0;
}
