#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class test{
    public:
        int var;
        test(int var){
            this->var=var;
        }
};
template <typename T>
struct greaterr {
    // Function call operator
    bool operator()(const T& a, const T& b) const {
        // Returns true if 'a' is greater than 'b'
        return a > b;
    }
};
int main(){
    priority_queue <int, vector<int>, greaterr<int>> pq;
    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.push(9);


}