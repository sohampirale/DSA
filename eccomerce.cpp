#include<iostream>
#include<unordered_map>
#include<utility>
using namespace std;
class Store{
    public:
        unordered_map<string,pair<int,int>>items;

        void add_item(){
            string item;
            cout<<"Enter the you want to add : ";
            cin>>item;
            auto it=items.find(item);
            if(it!=items.end()){
                cout<<it->second.first<<" "<<item<<"s already exists"<<endl;
                int add;
                cout<<"How many new you want to add : ";
                cin>>add;
                it->second.first+=add;
            } else {
                int quantity,price;
                cout<<"How many "<<item<<" is/are present initially : ";
                cin>>quantity;
                cout<<"What is price of "<<item<<" : ";
                cin>>price;
                items[item]={quantity,price};
                cout<<item<<" created successfully"<<endl;
            }
        
        }

        int buy(){

            try{
                string item;
                cout<<"Enter item name you want to buy : ";
                cin>>item;
                auto it=items.find(item);
                if(it!=items.end()){
                    int quantity;
                    cout<<"Enter quantity you need (in integer only): ";
                    cin>>quantity;
                    cout<<"Quantity availaible is : "<<it->second.first<<endl;
                    if(it->second.first<quantity){
                        throw "not enough stock available";
                    }
                    int ret=quantity*it->second.second;
                    it->second.first-=quantity;
                    return ret;
                } else {
                    cout<<"ENter you requested is not present in our store"<<endl;
                    return 0;
                }
            } catch(...){
                cout<<"Error occured"<<endl;
            }

            return 0;
        }

};

int main(){
    int choice=1;
    Store store;
    while(choice){
        cout<<"Enter your choice :\n1 : Owner\n2 : Customer\nYour choice : ";
        cin>>choice;
        if(choice==1){
            store.add_item();
        } else if(choice==2){
            int bill=0,buy_choice=1;
            while(buy_choice){
                try{
                    bill+=store.buy();
                } catch(...){
                    cout<<"Error occured"<<endl;
                }
                cout<<"Do you want to buy (1 : yes 0 : NO) : ";
                cin>>buy_choice;
            }
            cout<<"Your bill is : "<<bill<<endl;
        }
    }
}