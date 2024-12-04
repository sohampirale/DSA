#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<filesystem>
#include<fstream>
using namespace std;
class user{
    public:
        string userName;
        static unordered_map<string,user*>allUsers;
        unordered_map<string,user*>family,friends,relatives,close_friends;
        unordered_set<user*>all_connections;
        // static user* instance;
        user(string userName):userName(userName){
            allUsers[userName]=this;
            // instance=this;
        }
        
        ~user(){
            cout<<"Deleting "<<userName<<endl;
        }

        void addFriends(){
            int n;
            cout<<"How many friends does "<<userName<<" has : ";
            cin>>n;
            cin.ignore();
            string friendUsername;
            for(int i=0;i<n;i++){
                cout<<"Enter username of friend no - "<<i+1<<" : ";
                getline(cin,friendUsername);
                if(allUsers.find(friendUsername)==allUsers.end()){
                    cout<<friendUsername<<" does not exists in the database"<<endl;
                    i--;
                    continue;
                }
                bool closeFriend;
                cout<<"is "<<friendUsername<<" close friend?1 : yes 0 : No\nYour choice : ";
                cin>>closeFriend;
                cin.ignore();
                if(closeFriend){
                    close_friends[friendUsername]=allUsers[friendUsername];
                } else {
                    friends[friendUsername]=allUsers[friendUsername];
                }
                all_connections.insert(allUsers[friendUsername]);
            }
        }

        void addConnections(){
            cout<<"Lets add connections of "<<userName<<endl;
            addFamilyMembers();
            addFriends();
        }

        void addFamilyMembers(){
            int n;
            cout<<"How many family members does "<<userName<<" has : ";
            cin>>n;
            string familyMemName;
            for(int i=0;i<n;i++){
                cout<<"Enter username of family member no - "<<i+1<<" : ";
                cin>>familyMemName;
                if(allUsers.find(familyMemName)==allUsers.end()){
                    cout<<"No user exists with username - "<<familyMemName<<" in the database"<<endl;
                    i--;
                    continue;
                } 
                family[familyMemName]=allUsers[familyMemName];
                all_connections.insert(allUsers[familyMemName]);
            }
        }

        void giveRecommendation(){
            cout<<"Showing recommendations for : "<<userName<<endl;
            cout<<"Family recommendations : "<<endl;
            for(auto it=family.begin();it!=family.end();it++){
                for(auto familyOF=it->second->family.begin();familyOF!=it->second->family.end();familyOF++){
                    if(all_connections.find(familyOF->second)==all_connections.end()&&familyOF->first!=userName){
                        cout<<familyOF->first<<endl;
                    }
                }
            }
            cout<<"Close Friends Recommendations from close friends : "<<endl;
            for(auto it=close_friends.begin();it!=close_friends.end();it++){
                for(auto friendOF=it->second->close_friends.begin();friendOF!=it->second->close_friends.end();friendOF++){
                    if(all_connections.find(friendOF->second)==all_connections.end()&&friendOF->first!=userName){
                        cout<<friendOF->first<<endl;
                    }
                }
            }
            cout<<"Friends recommendation from close friends : "<<endl;
            for(auto it=close_friends.begin();it!=close_friends.end();it++){
                for(auto friendOF=it->second->friends.begin();friendOF!=it->second->friends.end();friendOF++){
                    if(all_connections.find(friendOF->second)==all_connections.end()&&friendOF->first!=userName){
                        cout<<friendOF->first<<endl;
                    }
                }
            }
            cout<<"Displayed all recommendations"<<endl;
        }
};

unordered_map<string,user*> user :: allUsers;
int getChoice(){
    int choice;
    cout<<"Enter your choice :"<<endl;
    cout<<"1 : Create New User"<<endl;
    cout<<"2 : See friends of a user"<<endl;
    cout<<"3 : See suggestions for a user"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

void deleteAllUsers(){
    
    unordered_map<string,user*>&allUsers= user::allUsers;
    for(auto it=allUsers.begin();it!=allUsers.end();it++){
        delete it->second;
    }
}
// user* user :: instance = nullptr;
int main(){
    
    int n;
    string userName;
    cout<<"How many users we have : ";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Enter userName of user no - "<<i+1<<" : ";
        getline(cin,userName);
        user* one_user=new user(userName);
    }
    for(auto it=user::allUsers.begin();it!=user::allUsers.end();it++){
        it->second->addConnections();
    }
    bool choice=1;
    while(choice){
        cout<<"Do you want to see recommendatiosn for any user ?1 : yes 0 : No\nYour choice : " ;
        cin>>choice;
        cin.ignore();
        if(choice){
            cout<<"Enter username : ";
            getline(cin,userName);
            if(user::allUsers.find(userName)!=user::allUsers.end())
                user::allUsers[userName]->giveRecommendation();
            else 
                cout<<"User not found"<<endl;
        }
    }
    deleteAllUsers();
}









// void giveP1(vector<string>&p1,string path){
//     vector<string>familyMembers;
//     ifstream familyMem(path+"family",ios::in);
//     if(familyMem.is_open()){
//         string line;
//         while(getline(cin,line)){
//             familyMembers.push_back(line);
//         }
//     } else {
//         cout<<"Unable to see family members of "<<path<<endl;
//     }
// }
// void showSuggestions(){
//     string userName,path="all_users/";
//     cin.ignore();
//     cout<<"Enter username : ";
//     getline(cin,userName);
//     if(filesystem::exists(path+userName)){
//         path+=(userName+"/");
//         vector<string>priority[4];

//     }
// }