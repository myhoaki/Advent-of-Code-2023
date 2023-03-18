#include<iostream>
#include<fstream> 
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<int> elfCalories;

    ifstream myfile("../input/Day1.txt");
  if(myfile.fail())
  {
    cout<<"Unable to open file"<<endl;
    return 0;
  }
	string line;
  int sum;
  int counter;
  while(getline(myfile,line)){
  if(line!=""){
    sum+= stoi(line);
  }else{
   elfCalories.push_back(sum);
   sum =0;
  }
  }
  elfCalories.push_back(sum);
  myfile.close();
    for(int i=0; i<elfCalories.size()-1; i++){
      for(int j=i+1; j<elfCalories.size();j++)
            if (elfCalories[i]<elfCalories[j])
              swap(elfCalories[i],elfCalories[j]);
            }
cout<<"Number of Elves: "<<elfCalories.size()<<endl;
cout<<"Calories of top 1 elf is: "<<elfCalories[0]<<endl;
cout<<"Sum Calories of top 1, 2, 3 elve is: "<<elfCalories[0]+elfCalories[1]+elfCalories[2]<<endl;
return 0;
}
