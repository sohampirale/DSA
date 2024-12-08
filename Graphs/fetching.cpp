#include <iostream>
#include <fstream>
#include <cstdint>  // For uintptr_t

using namespace std;

class node {
public:
    int data;
    node(int data) {
        this->data = data;
    }
};

int main() {
    ifstream inputFile("addr.txt", ios::in);
    uintptr_t addr_from_file;
    inputFile >> addr_from_file;
    inputFile.close();
    node* one_node = reinterpret_cast<node*>(addr_from_file);
    cout<<"one_node = "<<one_node<<endl;
    if (one_node != nullptr) {
        cout<<"addr of one_node  = "<<one_node<<endl;
        cout << "Pointer read from file: " << addr_from_file << endl;
        cout << "Data in node: " << one_node->data << endl;  // This could cause access issues if the address is invalid
    } else {
        cout << "Pointer is invalid!" << endl;
    }

    return 0;
}
