#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set> // Include set for red-black tree implementation

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

    // Red-black tree to store values
    set<int> rbTree;

    string line;
    while (getline(file, line)) {
        char op = line[0];
        int val = stoi(line.substr(2)); // Extract value from the line

        if (op == 'A') {
            rbTree.insert(val); // Add value to the red-black tree
            cout << "Added value: " << val << endl;
        } else if (op == 'E') {
            bool found = false;
            for (set<int>::iterator it = rbTree.begin(); it != rbTree.end(); ++it) {
                if (*it == val) {
                    rbTree.erase(it); // Remove value from the red-black tree
                    found = true;
                    cout << "Removed value: " << val << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Value " << val << " not found, cannot remove." << endl;
            }
        } else {
            cerr << "Error: Invalid operation type: " << op << endl;
        }
    }

    printInOrderRedBlackTree(rbTree); // Print tree data using in-order traversal

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
