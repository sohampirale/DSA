#include <iostream>
#include <fstream>
#include <cstdint>  // For uintptr_t (to store pointer as integer)

using namespace std;

class node {
public:
    int data;
    node(int data) {
        this->data = data;
    }
};

int main() {
    // Dynamically allocate the node
    node* original_node = new node(10);

    // Store the address of the dynamically allocated node in a file
    ofstream outputFile("addr.txt", ios::out);
    uintptr_t addr = reinterpret_cast<uintptr_t>(original_node); // Convert pointer to integer
    outputFile << addr;
    outputFile.close();

    // Output to show the address
    cout << "Stored address: " << addr << endl;

    // NOTE: We intentionally do NOT delete the node here (memory leak occurs)
    
    return 0;  // The memory is still allocated but not freed
}
