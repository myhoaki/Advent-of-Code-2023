#include<iostream>
#include<fstream> 
#include<string>

using namespace std;

int main()
{
    ifstream myfile("../input/Day4.txt");
  if(myfile.fail())
  {
    cout<<"Unable to open file"<<endl;
    return 0;
  }
  string line;
  int counter =0;
  int overlap =0;
  int x1;
  int y1;
  int x2;
  int y2;
  int pos_slash1;
  int pos_slash2;
  int pos_comma;

  while(getline(myfile,line)){
      pos_slash1 = line.find("-");
      cout<<"Position of slash 1th: "<<pos_slash1<<endl;
      pos_slash2 = line.find_last_of("-");
      cout<<"Position of slash 2nd: "<<pos_slash2<<endl;
      pos_comma = line.find(",");
      x1 = stoi(line.substr(0,pos_slash1));
      y1 = stoi(line.substr(pos_slash1+1,pos_comma-pos_slash1));
      x2 = stoi(line.substr(pos_comma+1,pos_slash2-pos_comma));
      y2 = stoi(line.substr(pos_slash2+1,line.length()-pos_slash2));
      cout<<"The pairs are: "<<x1<<"-"<<y1<<" and "<<x2<<"-"<<y2<<endl;
        if((x1 <= y2) && (x2 <= y1)){
        overlap++;
        cout<<"This pair is overlap!"<<endl;
      }
    }
   myfile.close();
    cout<<"Number of pairs that overlap: "<<overlap<<endl;
    return 0;
}

