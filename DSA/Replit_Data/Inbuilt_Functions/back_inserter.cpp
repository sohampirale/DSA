// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int main(){
//   vector<int>no={1,2,3,4,5};
//   // back_inserter(no);
//   // cout<<"hey"<<endl;
//   // cout<<no[0]<<endl;
//   // cout<<"hey"<<endl;
//   vector<int>num;
//   copy(no.begin(),no.end(),num.end());
//   for(int i=0;i<num.size();i++)cout<<num[i]<<" ";
// }
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//   vector<int>no={1,2,3,4,5};
//   vector<int>ex1,ex2;
//   copy(no.begin(),no.end(),back_inserter(ex1));
//   for(int i=0;i<ex1.size();i++)cout<<ex1[i]<<" ";
//   copy(no.begin(),no.end(),front_inserter(ex2));
//   for(int i=0;i<ex2.size();i++)cout<<ex2[i]<<" ";
// }

//front inserter works better with list

// #include <iostream>
// #include <vector>
// #include <list> // For std::list
// #include <algorithm>
// #include <iterator> // For std::back_inserter and std::front_inserter

// int main() {
//     std::vector<int> no = {1, 2, 3, 4, 5};
//     std::vector<int> ex1;
//     std::list<int> ex2; // Use std::list for efficient front insertion

//     // Copy elements from 'no' to 'ex1' using back_inserter
//     std::copy(no.begin(), no.end(), std::back_inserter(ex1));
//     for (int i = 0; i < ex1.size(); i++) {
//         std::cout << ex1[i] << " "; // Output: 1 2 3 4 5
//     }
//     std::cout << std::endl;

//     // Copy elements from 'no' to 'ex2' using front_inserter
//     std::copy(no.begin(), no.end(), std::front_inserter(ex2));
//     for (int value : ex2) {
//         std::cout << value << " "; // Output: 5 4 3 2 1
//     }
//     std::cout << std::endl;

//     return 0;
// }
