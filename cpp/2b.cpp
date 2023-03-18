#include<iostream>
#include<fstream> 
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<int> roundScore;

    ifstream myfile("../input/Day2.txt");
  if(myfile.fail())
  {
    cout<<"Unable to open file"<<endl;
    return 0;
  }
	string line;
  int sum;
  int move;
  int result;
  while(getline(myfile,line)){
  if(line.substr(2,1) == "X"){
    result = 0;
    if(line.substr(0,1) == "A")
      move = 3;
    if(line.substr(0,1) == "B")
      move = 1;
    if(line.substr(0,1) == "C")
      move = 2;
  }
  if(line.substr(2,1) == "Y"){
    result = 3;
    if(line.substr(0,1) == "A")
      move = 1;
    if(line.substr(0,1) == "B")
      move = 2;
    if(line.substr(0,1) == "C")
      move = 3;
  }
  if(line.substr(2,1) == "Z"){
    result = 6;
    if(line.substr(0,1) == "A")
      move = 2;
    if(line.substr(0,1) == "B")
      move = 3;
    if(line.substr(0,1) == "C")
      move = 1;
  }
  sum = move + result;
  roundScore.push_back(sum);
  sum = 0;
  }
  myfile.close();
  int total = 0;
  for (int i = 0; i<roundScore.size(); i++)
  {
    total+=roundScore[i];
  }
  cout<<"Total score of all round: "<<total<<endl;
return 0;
}
