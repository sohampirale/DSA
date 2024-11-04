#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    int choice;
    cout<<"Enter your choice \n1 : Copy from one file \n2 : Append in one file\n3 : Append data at a specific line\nYour choice  : ";
    cin>>choice;
    cin.ignore();
    if(choice==1){
        fstream file1;
        file1.open("file1.txt",ios::in);
        if(file1.is_open()){
            fstream file2;
            string line;
            file2.open("file2.txt",ios::out);
            while(getline(file1,line)){
                file2<<line;
            }
            cout<<"Data from file1.txt is copy pasted in file2.txt"<<endl;
            file2.close();
        }
        file1.close();
    } else if(choice==2){
        string filename;
        cout<<"Enter name of th efile : ";
        cin>>filename;
        fstream file;
        file.open(filename,ios::out);
        if(file.is_open()){
             string data;
            cout<<"Enter th edata you want to append : ";
            cin>>data;
            file<<data;
        } else cout<<"Error opening the file"<<endl;
    } else if(choice==3){
       int p;
       cout<<"After which line you want to append : ";
       cin>>p;
       cin.ignore();
       string data,filename;
       cout<<"At which line you  want to append : ";
       getline(cin,data);
       cout<<"Enter name of the file : ";
       getline(cin,filename);
       cout<<"Filename : "<<filename<<" & data : "<<data<<endl;
       fstream file;
       file.open(filename,ios::in);
       vector<string>all_data;
       if(file.is_open()){
            string line;
            int i=1;
            while(getline(file,line)){
                if(i==p)all_data.push_back(data);
                all_data.push_back(line);
                i++;
            }
            fstream writefile;
            writefile.open(filename,ios::out);
            i=0;
            while(i<all_data.size()){
                writefile<<all_data[i++]<<endl;
            }
            cout<<"data written into the "<<filename<<endl;
            writefile.close();
            file.close();
       } else cout<<"Error opening the file"<<endl;
    }
}


// Enter your choice 
// 1 : COpy from one file 
// 2 : Append in one filenYour choice  : 1
// Data from file1.txt is copy pasted in file2.txt
// @sohampirale ➜ /workspaces/DSA/file_handling (main) $ 



// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// using namespace std;

// int main() {
//     int choice;
//     cout << "Enter your choice \n1 : Copy from one file \n2 : Append in one file\n3 : Append data at a specific line\nYour choice  : ";
//     cin >> choice;
//     cin.ignore(); // Clear newline from the input buffer

//     if (choice == 1) {
//         fstream file1;
//         file1.open("file1.txt", ios::in);
//         if (file1.is_open()) {
//             fstream file2("file2.txt", ios::out);
//             string line;
//             while (getline(file1, line)) {
//                 file2 << line << endl; // Add newline after each line
//             }
//             cout << "Data from file1.txt is copied to file2.txt" << endl;
//             file2.close();
//         } else {
//             cout << "Error opening file1.txt" << endl;
//         }
//         file1.close();
//     } else if (choice == 2) {
//         string filename;
//         cout << "Enter name of the file: ";
//         cin >> filename;
//         fstream file(filename, ios::app); // Open in append mode
//         if (file.is_open()) {
//             string data;
//             cout << "Enter the data you want to append: ";
//             cin.ignore(); // Clear buffer
//             getline(cin, data); // Use getline to allow spaces
//             file << data << endl; // Add newline for separation
//             file.close();
//         } else {
//             cout << "Error opening the file" << endl;
//         }
//     } else if (choice == 3) {
//         string line, filename;
//         int p;
//         cout << "Enter data you want to insert: ";
//         cin.ignore(); // Clear buffer
//         getline(cin, line); // Use getline to allow spaces
//         cout << "At which line you want to insert (0-based index): ";
//         cin >> p;
//         cin.ignore(); 
//         cout << "Enter name of the file: ";
//         cin >> filename;

//         // Read the current contents of the file
//         fstream file(filename, ios::in);
//         vector<string> extracted_data;

//         if (file.is_open()) {
//             while (getline(file, line)) {
//                 extracted_data.push_back(line);
//             }
//             file.close();

//             // Insert the new line at the specified position
//             if (p >= 0 && p <= extracted_data.size()) {
//                 extracted_data.insert(extracted_data.begin() + p, line);
//             } else {
//                 cout << "Invalid line number. Appending at the end." << endl;
//                 extracted_data.push_back(line);
//             }

//             // Write the modified data back to the file
//             fstream file2(firoject: Open Visual Studio and create a new project or open an existing one.lename, ios::out | ios::trunc); // Use trunc to overwrite the file
//             for (const auto& l : extracted_data) {
//                 file2 << l << endl; // Add newline for each line
//             }
//             file2.close();
//             cout << "Data has been successfully inserted!" << endl;
//         } else {
//             cout << "Error opening the file." << endl;
//         }
//     } else {
//         cout << "Invalid choice." << endl;
//     }

//     return 0;
// }
