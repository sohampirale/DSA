#include <iostream>
#include<vector>
#include <future>
#include <chrono>
#include <thread>
using namespace std;

void func1() {
    this_thread::sleep_for(chrono::seconds(8));
    return;
}
void func2() {
    this_thread::sleep_for(chrono::seconds(6));
    return;
}
void func3() {
    this_thread::sleep_for(chrono::seconds(4));
    return;
}
void func4() {
    this_thread::sleep_for(chrono::seconds(2));
    return;
}
int main() {
    future<void>r1=async(launch::async, func1);
    future<void>r2=async(launch::async, func2);
    future<void>r3=async(launch::async, func3);
    future<void>r4=async(launch::async, func4);
    auto timeout = chrono::steady_clock::now() + chrono::seconds(5);
    bool f1=false,f2=false,f3=false,f4=false;
    while(!f1||!f2||!f3||!f4){
        // cout<<"Not all processes are ready"<<endl;
        if(!f1){
            f1=r1.wait_until(timeout) == future_status::ready;
            if(f1)cout<<"Process1 is completed"<<endl;
        }
        if(!f2){
            f2= r2.wait_until(timeout) == future_status::ready;
            if(f2)cout<<"Process2 is completed"<<endl;
        }
        if(!f3){
            f3= r3.wait_until(timeout) == future_status::ready;
            if(f3)cout<<"Process3 is completed"<<endl;
        }
        if(!f4){
            f4= r4.wait_until(timeout) == future_status::ready;
            if(f4)cout<<"Process4 is completed"<<endl;
        }
    }
    cout<<"came out"<<endl;
    return 0;
}
