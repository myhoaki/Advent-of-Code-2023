#include<iostream>
#include<fstream> 
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<string> items;
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
  string compartment1;
  string compartment2;
  int counter = 0;
  while(getline(myfile,line)){
    compartment1 = line.substr(0,line.length()/2);
    compartment2 = line.substr(line.length()/2,compartment1.length());
    cout<<"Compartment 1 is: "<<compartment1<<". Compartment 2 is: "<<compartment2<<endl;
    int i =0;
    while(compartment2.find(compartment1.at(i)) == string::npos){
        i++;
    }
    cout<<"The index which similarities occur is: "<<i<<endl;
    cout<<"The value of that index is: "<<compartment1.substr(i,1)<<endl;
    string similar = compartment1.substr(i,1);
     items.push_back(similar);   
    counter++;
  }
    myfile.close();
    cout<<"Number of counter: "<<counter<<endl;
    int sum = 0;
    for (int i=0;i<counter;i++)
    {
        int j = 0;
        while(items[i]!=itemtypes[j]){
            j++;
        }
        sum+=j+1;
    }
    cout<<"Sum of all items: "<<sum<<endl;
    return 0;
}

