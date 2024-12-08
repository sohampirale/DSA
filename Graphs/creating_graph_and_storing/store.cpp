#include<iostream>
#include<unordered_map>
#include<list>
#include<fstream>
#include<filesystem>
using namespace std;

class node{
    public:
        int data;
    node(int data):data(data){}

    ~node(){
        cout<<"Deleting "<<this->data<<endl;
    }
};

int totalGraphsPresent(){
    ifstream total("graphs_data/total_graphs.txt",ios::in);
    int total_graphs;
    if(!total.is_open()){
        cout<<"Error opening the file total_graphs.txt"<<endl;
        return -1;
    }
    total>>total_graphs;
    total.close();
    cout<<"Total grpahs present in the directory currently are : "<<total_graphs<<endl;
    return total_graphs;
}

void saveGraph(unordered_map<int,node*>&dataset,unordered_map<node*,list<node*>>&map,string newGraph){
    ofstream save(newGraph,ios::out);
    int n=dataset.size();
    save<<n<<endl;
    for(auto it=dataset.begin();it!=dataset.end();it++){
        save<<it->first<<" ";
    }
    save<<endl;
    n=map.size();
    save<<n<<endl;
    for(auto it=map.begin();it!=map.end();it++){
        save<<(it->first->data)<<" "<<it->second.size()<<" ";
        for(auto neighbour=it->second.begin();neighbour!=it->second.end();neighbour++){
            save<<(*neighbour)->data<<" ";
        }
        save<<endl;
    }
    cout<<"All nodes and their neighbours stored successfully in the file : "<<newGraph<<endl;
}

void updateTotalGraphs(int total_grpahs){
    ofstream update("graphs_data/total_graphs.txt",ios::out);
    update<<total_grpahs<<endl;
    update.close();
    cout<<"Total no fo graphs are updated to "<<total_grpahs<<endl;
}

void storeGraph(unordered_map<int,node*>&dataset,unordered_map<node*,list<node*>>&map){
    int total_graphs=totalGraphsPresent();
    if(total_graphs==-1)return;
    bool customGraph;
    string newGraph="graphs_data/";

    cout<<"Is this a custom graph?(1 : Yes 0 : No)\nYour choice : ";
    cin>>customGraph;
    if(customGraph){
        string customName;
        cout<<"Enter the custom name you want to give : ";
        cin>>customName;
        newGraph+=("custom_graphs/"+customName+".txt");
    } else {
        total_graphs++;
        newGraph+=("all_graphs/graph"+to_string(total_graphs)+".txt");
    }
    cout<<"Directory of new graph to be stored is : "<<newGraph<<endl;
    saveGraph(dataset,map,newGraph);
    if(!customGraph)updateTotalGraphs(total_graphs);
}

void displayAdjacancyList(unordered_map<node*,list<node*>>&map){
    cout<<"lets display adjacancy list"<<endl;
    for(auto it=map.begin();it!=map.end();it++){
        cout<<it->first->data<<" is connected with "<<it->second.size()<<" neighbours -> ";
        for(auto neighbour=it->second.begin();neighbour!=it->second.end();neighbour++){
            cout<<(*neighbour)->data<<" ";
        }
        cout<<endl;
    }
}

void delete_all_nodes(unordered_map<int,node*>&dataset){
    for(auto it=dataset.begin();it!=dataset.end();it++){
        delete(it->second);
    }
}

void createAdjacancyList(unordered_map<int,node*>&dataset,unordered_map<node*,list<node*>>&map){
    int k,data;
    for(auto it=map.begin();it!=map.end();it++){
        cout<<"How many neighbours does "<<it->first->data<<" has : ";
        cin>>k;
        for(int j=0;j<k;j++){
            cout<<"Enter data of neighbour no - "<<j+1<<" : ";
            cin>>data;
            auto neighbour=dataset.find(data);
            if(neighbour!=dataset.end()){
                it->second.push_front(dataset[data]);
            } else {
                cout<<"No node found with data : "<<data<<endl;
            }
        }
        cout<<it->first->data<<" has now linked list of "<<it->second.size()<<endl;
    }
}

void createGraph(unordered_map<int,node*>&dataset,unordered_map<node*,list<node*>>&map){
    int n,data,k;
    cout<<"Enter number of nodes in the graph : ";
    cin>>n;
    //creating all nodes first
    for(int i=0;i<n;i++){
        cout<<"Enter data of node no - "<<i+1<<" : ";
        cin>>data;
        node* one_node=new node(data);
        list<node*>temp;
        map[one_node]=temp;
        dataset[data]=one_node;
    }

    //adding neighbours int he adjacancy list
   createAdjacancyList(dataset,map);
}

void loadFromFile(ifstream& input,unordered_map<int,node*>&dataset,unordered_map<node*,list<node*>>&map){
    int n,data;
    input>>n;
    for(int i=0;i<n;i++){
        input>>data;
        node* one_node=new node(data);
        dataset[data]=one_node;
        list<node*>temp;
        map[one_node]=temp;
    }
    // cout<<"All "<<dataset.size()<<" nodes loaded from file"<<endl;
    int mapSize,k,nodeData,neighbourData;
    input>>mapSize;
    for(int i=0;i<mapSize;i++){
        input>>nodeData;
        node* originateNode=dataset[nodeData];
        input>>k;
        for(int j=0;j<k;j++){
            input>>neighbourData;
            map[originateNode].push_back(dataset[neighbourData]);
        }
        // cout<<originateNode->data<<" now has "<<map[originateNode].size()<<" neighbours in the adjacancy list"<<endl;
    }
    cout<<"Whole graph loaded from file"<<endl;
}

void loadGraph(unordered_map<int,node*>&dataset,unordered_map<node*,list<node*>>&map){
    string path="graphs_data/";
    bool custom;
    cout<<"Is the graph you want to load is custom graph?\nYour choice(1 : Yes 0 : No) : ";
    cin>>custom;
    if(custom){
        path+="custom_graphs/";
        string graphName;
        cout<<"Enter the custom name of the graph you want to load : ";
        cin>>graphName;
        graphName+=".txt";
        if(filesystem::exists(path+graphName)){
            path+=graphName;
            ifstream input(path,ios::in);
            if(input.is_open()){
                cout<<"opened "<<path<<endl;
                loadFromFile(input,dataset,map);
            } else cout<<"couldn't oepn the file "<<graphName<<endl;
        } else {
            cout<<graphName<<" does not exist at "<<path<<endl;
        }
    } else{
        int total=totalGraphsPresent(),graphNo;
        cout<<"There are total "<<total<<" graphs present\nEnter the graph you want to load (1-"<<total<<") : ";
        cin>>graphNo;
        path+="all_graphs/";
        string graphName="graph"+to_string(graphNo)+".txt";
        if(filesystem::exists(path+graphName)){
            path+=graphName;
            ifstream input(path,ios::in);
            if(input.is_open()){
                cout<<"opened "<<path<<endl;
                loadFromFile(input,dataset,map);
            } else cout<<"couldn't oepn the file "<<graphName<<endl;
        } else {
            cout<<graphName<<" does not exist in the directory : "<<path<<endl;
        }
    }
}

int getChoice(){
    //getChoice
    int choice;
    cout<<"Enter your choice :"<<endl;
    cout<<"1 : Create a new graph"<<endl;
    cout<<"2 : Store this graph to a file"<<endl;
    cout<<"3 : Total no of graphs present(except custom graphs)"<<endl;
    cout<<"4 : Load a Graph"<<endl;
    cout<<"5 : Display adjacancy list"<<endl;
    cout<<"Your choice :";
    cin>>choice;
    return choice;
}

int main(){
    int choice=1;
    unordered_map<node*,list<node*>>map;
    unordered_map<int,node*>dataset;

    while(choice){
        choice=getChoice();
        if(choice==1){
            delete_all_nodes(dataset);
            map.clear();
            dataset.clear();
            createGraph(dataset,map);
        }else if(choice==2){
            storeGraph(dataset,map);
        } else if(choice==3){
            totalGraphsPresent();
        } else if(choice==4){
            delete_all_nodes(dataset);
            dataset.clear();
            map.clear();
            loadGraph(dataset,map);
        } else if(choice==5){
            displayAdjacancyList(map);
        }
    }
   
    delete_all_nodes(dataset);
}