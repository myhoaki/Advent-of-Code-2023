#include<iostream>
#include<fstream> 
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<string> badgeitems;
    vector<string> elf;
    string itemtypes[52] = {"a","b","c","d","e","f","g","h","i","j","k",
    "l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
    "A","B","C","D","E","F","G","H","I","J",
    "K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    ifstream myfile("../input/Day3.txt");
  if(myfile.fail())
  {
    cout<<"Unable to open file"<<endl;
    return 0;
  }
  string line;
  int counter =0;
  while(getline(myfile,line)){
      elf.push_back(line);
      counter++;
    }
   myfile.close();
   int groups = counter/3;
   cout<<"Number of groups: "<<groups<<endl;
    for(int i=0;i<counter;i=i+3){
      int j =0;
      while (elf[i+1].find(elf[i].at(j))== string::npos || elf[i+2].find(elf[i].at(j))== string::npos){
        j++;
      }
      badgeitems.push_back(elf[i].substr(j,1));
    }
    cout<<"Badge item of group "<<0<<" is: "<<badgeitems[0]<<endl;
    cout<<"Badge item of group "<<99<<" is: "<<badgeitems[99]<<endl;
    cout<<"Size no of badge items: "<<badgeitems.size()<<endl;
  int sum = 0;
    for (int i=0;i<groups;i++)
    {
        int j = 0;
        while(badgeitems[i]!=itemtypes[j]){
            j++;
        }
        sum+=j+1;
    }
    cout<<"Sum of all badge items: "<<sum<<endl;
    return 0;
}

