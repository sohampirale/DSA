// #include<iostream>
// #include<stack>
// #include<cstdint>
// #include<fstream>
// using namespace std;
// class node{
//     public:
//         int data;
//         node(int data){
//             this->data=data;
//         }
// };
// int main(){
//     ifstream inputFile("addr.txt", ios::in);
//     uintptr_t addr_from_file;
//     inputFile >> addr_from_file;
//     inputFile.close();

//     node* one_node = reinterpret_cast<node*>(addr_from_file);

//     if (one_node != nullptr) {
//         cout << "Data in node: " << one_node->data << endl;
//     } else {
//         cout << "Invalid pointer!" << endl;
//     }

// }

#include<iostream>
#include<fstream>
#include<cstdint> // for uintptr_t

using namespace std;

class node {
public:
    int data;
    node(int data) {
        this->data = data;
    }
};

int main() {
    node* original_node = new node(10);

    ofstream outputFile("addr.txt", ios::out);
    uintptr_t addr = reinterpret_cast<uintptr_t>(original_node);
    outputFile << addr;
    outputFile.close();

    ifstream inputFile("addr.txt", ios::in);
    uintptr_t addr_from_file;
    inputFile >> addr_from_file;
    inputFile.close();

    node* one_node = reinterpret_cast<node*>(addr_from_file);

    if (one_node != nullptr) {
        cout << "Data in node: " << one_node->data << endl;
    } else {
        cout << "Invalid pointer!" << endl;
    }

    // Clean up the allocated memory
    delete original_node;

    return 0;
}
