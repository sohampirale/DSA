#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    char name[50];
    float grade;
};

int main() {
    Student s1 = {1, "Soham", 92.5};

    // Open a binary file for writing
    ofstream outFile("student.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    // Write object to the file
    outFile.write(reinterpret_cast<char*>(&s1), sizeof(s1));

    outFile.close();
    cout << "Data written to file successfully." << endl;
    return 0;
}
