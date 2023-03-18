#include<iostream>
#include<fstream> 
#include<string>
#include<vector>

using namespace std;

int main()
{
  ifstream myfile1("../input/Day5.txt");
  if(myfile1.fail())
  {
    cout<<"Unable to open file"<<endl;
    return 0;
  }
  int numStack;
  string line1;
  while(getline(myfile1,line1)){
     if(line1.substr(0,1)==" "){
        numStack=stoi(line1.substr(line1.size()-2,1));
        myfile1.close();
      }
  }
  ifstream myfile2("../input/Day5.txt");
  if(myfile2.fail())
  {
    cout<<"Unable to open file"<<endl;
    return 0;
  }
   string line2;
  vector <string> action;
  string column[numStack];
  int pos[numStack];
  for(int i=0;i<numStack;i++){
    pos[i]=4*i+1;
  }
  while(getline(myfile2,line2)){
    if(line2.find("[")!=string::npos){
    for (int i=0;i<numStack;i++){
      if (line2.substr(pos[i],1)!=" "){
        column[i].append(line2.substr(pos[i],1));
        }
      }
    }
    if(line2.find("move")!=string::npos){
      action.push_back(line2);
  }
  }
  myfile2.close();
  for (int i=0;i<numStack;i++){
      cout<<"Column "<<i+1<<" is "<<column[i]<<endl;
  }
  int move;
  int start;
  int end;
  for (int i=0;i<action.size();i++){
    if(action[i].size()==19){
    move = stoi(action[i].substr(5,2));
    start = stoi(action[i].substr(13,1));
    end = stoi(action[i].substr(18,1));
    }
    else{
    move = stoi(action[i].substr(5,1));
    start = stoi(action[i].substr(12,1));
    end = stoi(action[i].substr(17,1));
    }
      for(int j=0;j<move;j++){
        column[end-1].insert(0,column[start-1].substr(0,1));
        column[start-1].erase(0,1);
        cout<<"Column "<<start<<" is "<<column[start-1]<<endl;
        cout<<"Column "<<end<<" is "<<column[end-1]<<endl;
    }
        cout<<"Above is result after move "<<move<<" from "<<start<<" to "<<end<<endl;
  }
  cout<<"AFTER MOVING"<<endl;
    for (int i=0;i<numStack;i++){
      cout<<"Column "<<i+1<<" is "<<column[i]<<endl;
  }
  cout<<"Answer is: "<<endl;
      for (int i=0;i<numStack;i++){
      cout<<column[i].substr(0,1);
  }
   return 0;
}



