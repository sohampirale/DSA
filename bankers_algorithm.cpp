#include <iostream>
#include <queue>
using namespace std;
class process
{
public:
    string name;
    vector<int> resources;
    vector<int>required;
    process(string name)
    {
        this->name = name;
    }
};
int main()
{
    int no_of_processes, n, alloc;
    string name;
    cout << "Enter how many processes you ahve : ";
    cin >> no_of_processes;
    queue<process> processes;
    for (int i = 0; i < no_of_processes; i++)
    {
        cout << "Enter name of the process : ";
        cin >> name;
        process temp(name);
        cout << "How many resources does " << name << " has : ";
        cin >> n;
        vector<int> allocated;
        for (int j = 0; j < n; j++)
        {
            int no_of_resources;
            cout << "Enter number of resources - are alllcoate to " << name << " & resource " << j + 1 << " : ";
            cin >> no_of_resources;
            temp.resources.push_back(no_of_resources);
        }
        int required_resources_temp;
        for(int j=0;j<n;j++){
            cout<<"Enter number of resources reuired of type - "<<j+1<<" : ";
            cin>>required_resources_temp;
            temp.required.push_back(required_resources_temp);
        }
        cout << "No of resources allocated for " << name << " are : ";
        for (int i = 0; i < temp.resources.size(); i++)
        {
            cout << temp.resources[i] << " ";
        }
        cout<<"No of resources reuired for "<<temp.name<<endl;
        for (int i = 0; i < temp.required.size(); i++)
        {
            cout << temp.required[i] << " ";
        }
        cout << endl;
        processes.push(temp);
    }
    int no_of_resources, number_of_recources;
    cout << "Enter how many resources are there : ";
    cin >> no_of_resources;
    vector<int> free_resources(no_of_resources);
    cout << "Processes and their resource allocated are : " << endl;
    for (int i = 0; i < processes.size(); i++)
    {
        process &temp = processes.front();
        cout << "Process : " << temp.name << " ";
        for (int j = 0; j < temp.resources.size(); j++)
        {
            cout << temp.resources[j] << " ";
        }
        cout << endl;
        processes.push(processes.front());
        processes.pop();
    }
    for (int i = 0; i < no_of_resources; i++)
    {
        cout << "Enter number of resources available for resource no-" << i + 1 << " : ";
        cin >> free_resources[i];
    }
    for (int i = 0; i < processes.size(); i++)
    {
        int size = processes.front().resources.size();
        vector<int> &temp = processes.front().resources;
        for (int j = 0; j < size; j++)
        {
            free_resources[j] -= temp[j];
        }
        processes.push(processes.front());
        processes.pop();
    }
    cout << "Free resources availaible are : ";
    for (int i = 0; i < free_resources.size(); i++)
    {
        cout << i + 1 << " : " << free_resources[i] << endl;
    }

    while(!processes.empty()){
        cout<<"hi"<<endl;
        bool possible=true;
        process& temp=processes.front();
        for(int i=0;i<processes.size();i++){
            for(int j=0;j<free_resources.size();j++){
                if(free_resources[j]<temp.required[j]){
                    possible=false;
                    break;
                }
            }
            if(!possible)break;
        }
        if(possible){
            cout<<"Possible for "<<temp.name<<endl;
          for(int i=0;i<temp.resources.size();i++){
            free_resources[i]+=temp.resources[i];
          }  
          cout<<"Process : "<<temp.name<<" is executed"<<endl;
          cout<<"Free recources modified to :"<<endl;
          for(int i=0;i<free_resources.size();i++){
                cout<<i+1<<" :" <<free_resources[i]<<endl;
          }
        } else {
            processes.push(temp);
        }
        processes.pop();
    }
}