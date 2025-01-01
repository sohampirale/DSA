#include<iostream>
#include <filesystem>
#include<fstream>
#include<queue>
#include<unordered_map>
#include <future>
using namespace std;
namespace fs = std::filesystem;
class User{
    public:
        string username;
        User(string username):username(username){}
};

class node{
    public:
        char data;
        int cnt;
        string mark;
        node* left,*right;
        node(char data,int cnt){
            this->cnt=cnt;
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
        }
};

class NodeComp {
    public:
        bool operator()(node* t1, node* t2) {
            return t1->cnt > t2->cnt;
        }
};

namespace EncoderDecoder {
    node* root = nullptr;
    unordered_map<char, string> encodingMap;
    unordered_map<string, char> decodingMap;
    unordered_map<char, int> frequenceCounts;
    priority_queue<node*, vector<node*>,NodeComp> pq;

    void createInititalNodes(string msg) {
        for (char ch : msg) {
            frequenceCounts[ch]++;
        }
        for (auto it : frequenceCounts) {
            pq.push(new node(it.first, it.second));
        }
    }

    void preOrder(node*& one_node) {
        if (!one_node) {
            return;
        }
        preOrder(one_node->left);
        preOrder(one_node->right);
    }

    void createDecodingMap() {
        decodingMap.clear();
        for (auto it : encodingMap) {
            decodingMap[it.second] = it.first;
        }
    }

    void createEncodingMap(node*& one_node, string path = "") {
        if (!one_node) return;
        string currPath = path + one_node->mark;
        encodingMap[one_node->data] = currPath;
        createEncodingMap(one_node->left, currPath);
        createEncodingMap(one_node->right, currPath);
    }

    void work(node*& root) {
        while (pq.size() != 1) {
            node* first = pq.top();
            pq.pop();
            node* second = pq.top();
            pq.pop();
            node* one_node = new node('#', first->cnt + second->cnt);
            one_node->left = first;
            one_node->right = second;
            first->mark = "0";
            second->mark = "1";
            pq.push(one_node);
        }
        root = pq.top();
        pq.pop();
        preOrder(root);
    }

    void deleteAllNodes(node*& one_node) {
        if (!one_node) return;
        deleteAllNodes(one_node->left);
        deleteAllNodes(one_node->right);
        delete one_node;
    }

    void displayDecodingMap() {
        for (auto it : decodingMap) {
            cout << it.first << " : " << it.second << endl;
        }
    }

    void displayEncodingMap() {
        for (auto it : encodingMap) {
            cout << it.first << " : " << it.second << endl;
        }
    }

    string convertEncodedMsgToMsg(string encodedMsg) {
        string comp = "", decodedMsg = "";
        int i = 0;
        while (i < encodedMsg.size()) {
            while (decodingMap.find(comp) == decodingMap.end() && i < encodedMsg.size()) {
                comp += encodedMsg[i];
                i++;
            }
            decodedMsg += decodingMap[comp];
            comp = "";
        }
        return decodedMsg;
    }

    string convertMsgToEncodedMsg(string msg) {
        string encodedMsg = "";
        for (char ch : msg) {
            encodedMsg += encodingMap[ch];
        }
        return encodedMsg;
    }

    void clearEverything(node*& root) {
        encodingMap.clear();
        decodingMap.clear();
        frequenceCounts.clear();
        while (!pq.empty()) pq.pop();
        deleteAllNodes(root);
        root = nullptr;
    }

    string encodeIt(string msg) {
        if (root) {
            clearEverything(root);
        }
        createInititalNodes(msg);
        work(root);
        createEncodingMap(root);
        encodingMap.erase('#');
        string encodedMsg = convertMsgToEncodedMsg(msg);
        return encodedMsg;
    }

    string decodeIt(string encodedMsg) {
        createDecodingMap();
        string decodedMsg = convertEncodedMsgToMsg(encodedMsg);
        return decodedMsg;
    }
}

unordered_map<string,node*>dataset;

void loadGraph() {
    // ...existing code...
}

void loginUser() {
    string userPath = "Users/";
    string username, enteredPassword, passwordPath, databasePassword;
    cout << "Enter your username : ";
    cin >> username;
    if (fs::exists(userPath)) {
        userPath += username;
        if (fs::is_directory(userPath)) {
            passwordPath = userPath + "/password.txt";
            if (fs::exists(passwordPath)) {
                cout << "Enter your password : ";
                cin >> enteredPassword;
                enteredPassword = EncoderDecoder::encodeIt(enteredPassword);
                ifstream password(passwordPath, ios::in);
                if (!password.is_open()) {
                    cout << "Error opening the password file of " << username << " from database" << endl;
                    return;
                }
                password >> databasePassword;
                if (enteredPassword == databasePassword) {
                    cout << "Login successful" << endl;
                } else {
                    cout << "Incorrect password" << endl;
                }
            } else {
                cout << username << " exists in database but password is not set" << endl;
                return;
            }
        } else {
            cout << "User does not exist in the database" << endl;
            return;
        }
    } else {
        cout << "Incorrect Path" << endl;
    }
}

void signupUser() {
    string userPath = "Users/";
    string username, enteredPassword, passwordPath, databasePassword, confirm;
    cout << "Enter your username : ";
    cin >> username;
    if (fs::exists(userPath)) {
        userPath += username;
        if (!fs::is_directory(userPath)) {
            fs::create_directory(userPath);
            cout << "Set password : ";
            cin >> enteredPassword;
            cout << "Confirm password : ";
            cin >> confirm;
            if (confirm != enteredPassword) {
                cout << "Both passwords do not match" << endl;
                return;
            }
            passwordPath = userPath + "/password.txt";
            string encodedPassword = EncoderDecoder::encodeIt(enteredPassword);
            ofstream passwordFile(passwordPath, ios::out);
            passwordFile << encodedPassword << endl;
            passwordFile.close();
            cout << "User created successfully!" << endl;
            return;
        } else {
            cout << "User already exists in the database with username : " << username << endl;
            return;
        }
    } else {
        cout << "Incorrect Path" << endl;
    }
}

int getChoice() {
    int choice;
    cout << "1 : Log In as User" << endl;
    cout << "2 : Login as Employer" << endl;
    cout << "3 : Sign up as User" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

int main() {
    int choice = 1;
    while (choice) {
        choice = getChoice();
        if (choice == 1) {
            loginUser();
        } else if (choice == 2) {
            // ...existing code...
        } else if (choice == 3) {
            signupUser();
        }
    }
}