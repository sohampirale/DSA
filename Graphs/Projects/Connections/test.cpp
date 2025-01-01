#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void appendNameToFile() {
    string filename="names.txt";
    string newName="soham3";
    // Read the count from the file
    ifstream inputFile(filename);
    int count = 0;

    if (inputFile.is_open()) {
        inputFile >> count; // Read the count
        inputFile.close();
    }

    // Increment the count and append the new name
    ofstream outputFile(filename, ios::app); // Open in append mode
    if (outputFile.is_open()) {
        count++;
        outputFile<< newName << endl; // Append the name
        outputFile.close();
    }

    // Update the count in the file (rewrite the first line)
    fstream file(filename, ios::in | ios::out);
    if (file.is_open()) {
        file.seekp(0); // Move the file pointer to the start
        file << count; // Overwrite the count
        file.close();
    } else {
        cout << "Error: Unable to open file." << endl;
    }
}

int main() {
    appendNameToFile();

    cout << "File updated successfully." << endl;

    return 0;
}
