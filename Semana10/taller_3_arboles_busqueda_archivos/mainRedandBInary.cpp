#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set> // Include set for red-black tree implementation

#include "ArbolBinarioOrd.h" // Include header file for binary tree
#include "NodoBinario.h" 

using namespace std;

// Function to print the red-black tree data in-order
void printInOrderRedBlackTree(const set<int>& rbTree) {
    if (rbTree.empty()) {
        cout << "Tree is empty" << endl;
        return;
    }

    cout << "Tree data (in-order traversal): ";
    for (set<int>::iterator it = rbTree.begin(); it != rbTree.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void processFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    // Create a new Red-black tree to store values
    set<int> rbTree;
    // Create a new binary tree
    ArbolBinarioOrdenado<int> binaryTree;

    string line;
    while (getline(file, line)) {
        char op = line[0];
        int val = stoi(line.substr(2)); // Extract value from the line

        if (op == 'A') {
            rbTree.insert(val); // Add value to the red-black tree
            binaryTree.insertarNodo(val); // Add value to the binary tree
            cout << "Added value to RedBlackTree adn Binary Tree: " << val << endl;
        } else if (op == 'E') {
            // RED-BLACK TREE
            bool found = false;
            for (set<int>::iterator it = rbTree.begin(); it != rbTree.end(); ++it) {
                if (*it == val) {
                    rbTree.erase(it); // Remove value from the red-black tree
                    found = true;
                    cout << "Removed value from RedBlackTree: " << val << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Value " << val << " not found, cannot remove from RedBlack Tree." << endl;
            }
            // BINARY TREE
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

    
    cout << "IMPRIMIENDO LOS DATOS DEL ARBOL ROJO-NEGRO " << endl;
    printInOrderRedBlackTree(rbTree); // Print tree data using in-order traversal

     // Print binary tree data using in-order traversal
    cout << "IMPRIMIENDO LOS DATOS DEL ARBOL BINARIO :" << endl;
    binaryTree.inOrden();

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
