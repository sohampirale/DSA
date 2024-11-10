#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class box{
    public:
        int x,y;
        box(int x,int y):x(x),y(y){}
        box(const box& box2){
            this->x=box2.x;
            this->y=box2.y;
        }
};
bool found=false;
void findNear(vector<box>&maze,queue<box>&q,int ex,int ey){
    auto it=q.front();
    for(auto it2 = maze.begin();it2!=maze.end();){
        if((it2->x==it.x+1||it2->x==it.x-1)&&it2->y==it.y){
            cout<<"Can move from "<<it.x<<","<<it.y<<" to : "<<it2->x<<","<<it2->y<<endl;
            if(it2->x==ex&&it2->y==ey){
                cout<<"Found"<<endl;
                found=true;
                return;
            }
            q.push(box(it2->x,it2->y));
            maze.erase(it2);
            continue;
        }
        if((it2->y==it.y+1||it2->y==it.y-1)&&it2->x==it.x){
            cout<<"Can move from "<<it.x<<","<<it.y<<" to : "<<it2->x<<","<<it2->y<<endl;
            if(it2->x==ex&&it2->y==ey){
                cout<<"Found"<<endl;
                found=true;
                return;
            }
            q.push(box(it2->x,it2->y));
            maze.erase(it2);
            continue;
        }
        ++it2;
    }
}
int stepsReq(vector<box>&maze,queue<box>&q,int ex,int ey){
    int cnt=-1;
    while(!maze.empty()){
        cnt++;
        int size=q.size();
        for(int i=0;i<size;i++){
            findNear(maze,q,ex,ey);
            if(found)return cnt+1;
            q.pop();
        }
    }
    return -1;
}
auto find(vector<box>&maze,box& toComp){
    for(auto it=maze.begin();it!=maze.end();){
        if(it->x==toComp.x&&it->y==toComp.y){
            cout<<"it->x = "<<it->x<<" & toComp.x = "<<toComp.x<<endl;
            cout<<"it->y = "<<it->y<<" & toComp.y = "<<toComp.y<<endl;
            return it;
        }
        ++it;
    }
    return maze.end();
}
int main(){
    int n,choice=1;
    while(choice){
        cout<<"ENter n : ";
        cin>>n;
        vector<box>maze;
        cout<<maze.size()<<endl;
        int sx,sy,ex,ey;
        cout<<"Enter starting x & y co-ordinates : ";
        cin>>sx>>sy;
        cout<<"ENter destination x & y co-ordinates : ";
        cin>>ex>>ey;
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                if(x==sx&&y==sy)continue;
                maze.push_back(box(x,y));
            }
        }
        cout<<"Maze created"<<endl;
        cout<<maze.size()<<endl;
        int o;
        cout<<"How many obstacles you have : ";
        cin>>o;
        cout<<"Enter co-ordinates of "<<o<<" obstacles : "<<endl;
        int tx,ty;
        for(int i=0;i<o;i++){
            cout<<"Enter x & y co-ordinates of obstacle no-"<<i+1<<" : ";
            cin>>tx>>ty;
            box toComp(tx,ty);
            auto it=find(maze,toComp);
            if(it!=maze.end()){
                cout<<"Deleting "<<it->x<<","<<it->y<<" from maze"<<endl;
                maze.erase(it);
            } else {
                cout<<"Out of bounds obstacle or already deleted"<<endl;
            }
        }
        queue<box>q;
        q.push(box(sx,sy));
        // maze.erase(maze.begin());
        int steps=stepsReq(maze,q,ex,ey);
        cout<<"Steps required to reach["<<ex<<","<<ey<<"]  are : "<<steps<<endl;
        cout<<"Again ? : " ;
        cin>>choice;
    }
}