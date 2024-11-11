// // An educational institution wishes to maintain a database of its employees. The database is divided
// // into a number of classes whose hierarchical relationship are shown in figure. The figure also shows
// // the minimum information required for each class. Specify all the classes and define functions to
// // create the database and retrieve individual information as and when required.


// //Name - Soham Sachin Pirale
// //Roll no - 2022
// //Batch - S2

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// class officer;
// class typist;
// class regular;
// class casual;
// class institute{
// public:

//     string institute_name;
//     institute(){
//       cout<<"Default constructor of institue"<<endl;
//     }
//     institute(string institute_name){
//       this->institute_name=institute_name;
//     }
//     string get_name(){
//       return institute_name;
//     }
//   bool operator==(const institute &other) const {
//       return this->institute_name == other.institute_name;
//   }
// };

// class officer:public institute{
// public:

//     string officer_name;
//     char grade;
//     officer(string officer_name,char grade,string institute_name){
//       this->officer_name=officer_name;
//       this->grade=grade;
//       this->institute_name=institute_name;
//     }
// };

// class typist:public institute{
// public:

//     string typist_name;
//     int speed;
//     typist(){
//       cout<<"Default constructor of typist"<<endl;
//     }
//     typist(string typist_name,int speed, string institute_name){
//       this->typist_name=typist_name;
//       this->speed=speed;
//       this->institute_name=institute_name;
//     }
// };

// class regular: public typist{
// public:
//     string regular_typist_name;
//     regular(string regular_typist_name,int speed, string institute_name){
//       this->regular_typist_name=regular_typist_name;
//       this->speed=speed;
//       this->institute_name=institute_name;
//     }
// };

// class casual: public typist{
// public:  
//     string casual_typist_name;
//     casual(string casual_typist_name,int speed,string institute_name){
//       this->casual_typist_name=casual_typist_name;
//       this->speed=speed;
//       this->institute_name=institute_name;
//     }
// };


// class teacher:public institute{
// public:
//     string teacher_name,subject;
//     teacher(string teacher_name,string subject,string institute_name){
//       this->teacher_name=teacher_name;
//       this->institute_name=institute_name;
//       this->subject=subject;
//     }
// };

// vector<institute>institutes;
// vector<officer>officers;
// vector<casual>casual_typists;
// vector<regular>regular_typists;
// vector<teacher>teachers;

// bool check(string institute_name){
//   if(find(institutes.begin(),institutes.end(),institute(institute_name))==institutes.end()){
//     cout<<"New institute added"<<endl;
//     return false;
//     institutes.push_back(institute(institute_name));
//   }
//   return true;
// }

// int main(){
//   int choice=1;
//   while(choice!=0){
//     cout<<"Enter your choice \n1 : Create Institute\n2 : Create Teacher\n3 : Create Officer\n4 : Create regular typist\n5 : Create Casual Typist\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       string temp;
//       cout<<"ENter name of the institute : ";
//       cin>>temp;
//       if(check(temp)){
//         cout<<"INstitution with name : "<<temp<<" is already created"<<endl;
//         continue;
//       }
//       institutes.push_back(temp);
//       cout<<"Institue created with name : "<<temp<<endl;
//     } else if(choice==2){
//       string institutes_name,teachers_name,subject;
//       cout<<"Enter the name of the teacher : ";
//       cin>>teachers_name;
//       cout<<"Enter the name of the institue : ";
//       cin>>institutes_name;
//       check(institutes_name);
//       cout<<"Enter subject of the teacher : ";
//       cin>>subject;
//       teachers.push_back(teacher(teachers_name,subject,institutes_name));
//     } else if(choice==3){
//       string officer_name,institute_name;
//       char grade;
//       cout<<"Enter name of the officer: ";
//       cin>>officer_name;
//       cout<<"ENter name of the institute "<<officer_name<<" is working in : ";
//       cin>>institute_name;
//       check(institute_name);
//       cout<<"Enter grade of the officer : ";
//       cin>>grade;
//       officers.push_back(officer(officer_name,grade,institute_name));
//       cout<<"Officer : "<<officer_name<<" added successfully"<<endl;
//     } else if(choice==4||choice==5){
//       string typist_name,institute_name;
//       int speed;
//       cout<<"Enter name of the typist : ";
//       cin>>typist_name;
//       cout<<"Enter name of the institue "<<typist_name<<" is working in : ";
//       cin>>institute_name;
//       check(institute_name);
//       cout<<"Enter speed of the typist : ";
//       cin>>speed;
//       if(choice==4)regular_typists.push_back(regular(typist_name,speed,institute_name));
//       else if(choice==5)casual_typists.push_back(casual(typist_name,speed,institute_name));
//       cout<<"Typist : "<<typist_name<<" created successfully"<<endl;
//     }
//   }
//   cout<<endl<<endl<<endl<<endl;

//   choice=1;
//   while(choice!=0){
//     cout<<"Enter your choice\n1 : Show all institues\n2 : Show all officers\n3 : SHow all teacher\n4 : Show all regular typ[ist\n5 : Show all Speciall typists\nYour choice : " ;
//     cin>>choice;
//     if(choice==1){
//       if(institutes.empty()){
//         cout<<"No institues were created"<<endl;
//         continue;
//       }
//       cout<<"All th einstitues are : "<<endl;
//       for(int i=0;i<institutes.size();i++){
//         cout<<i+1<<". "<<institutes[i].institute_name<<endl;
//       }
//     } else if(choice ==2){
//       if(officers.empty()){
//         cout<<"No Officers were created"<<endl;
//         continue;
//       }
//       cout<<"Officers their institues and their grades are : ";
//       for(int i=0;i<officers.size();i++){
//         cout<<i+1<<". "<<officers[i].officer_name<<" Institue : "<<officers[i].institute_name<<" & Grade is : "<<officers[i].grade<<endl;
//       }
//     } else if(choice==3){
//       if(teachers.empty()){
//         cout<<"No teachers were created"<<endl;
//         continue;
//       }
//       cout<<"All the teachers their subjects and institues are :"
// <<endl;    
//       for(int i=0;i<teachers.size();i++){
//         cout<<i+1<<". "<<teachers[i].teacher_name<<" Subject = "<<teachers[i].subject<<" & Institue : " <<teachers[i].institute_name<<endl;
//       }
//     } else if(choice==4){
//       if(regular_typists.empty()){
//         cout<<"No regular typists were created"<<endl;
//         continue;
//       }
//       cout<<"All the regular typists their names , speed and isntitute is : "<<endl;
//       for(int i=0;i<regular_typists.size();i++){
//         cout<<i+1<<". "<<regular_typists[i].typist_name<<" speed : "<<regular_typists[i].speed<<" & institue : "<<regular_typists[i].institute_name<<endl;
//       }
//     } else if(choice==5){
//       if(casual_typists.empty()){
//         cout<<"No casual typists were created"<<endl;
//         continue;
//       }
//       cout<<"All the casual typists their speed and their institue is : "<<endl;
//       for(int i=0;i<casual_typists.size();i++){
//         cout<<i+1<<". "<<casual_typists[i].typist_name<<" Speed : "<<casual_typists[i].speed<<" Institue : "<<casual_typists[i].institute_name<<endl;
//       }
//     }
//   }
// }