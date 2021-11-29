/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Daniel Thew
 */
#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;
//class holding the name and value (public variables)
class Name_value{
  public:string name;
  public:int value;
};
//function to check if Name_value variables are going to be duplicates
bool checkDupe(vector<Name_value> vec, string s, int v);

int main() {
  //vector of Name_value vars
  vector<Name_value> vec;
  //holder string and int that will hold a user string/value before being
  //put into a Name_value var
  string s_hold = "";
  int v_hold = 1;
  //placeholder Name_value var to hold each iteration of user vals
  Name_value cur_val;
  //while the exit flag hasn't been triggered
  while(s_hold!="NoName" && v_hold!=0){
    //scan in user input
    cin>>s_hold;
    cin>>v_hold;
    //if user input matches previous user input, exit message and end code
    if(!checkDupe(vec, s_hold, v_hold)){
      cout<<"Error: Duplicated values.\n";
      exit(0);
    }
    //otherwise, put placeholder string and int into the Name_value
    //var, then push that into the vector
    cur_val.name = s_hold;
    cur_val.value = v_hold;
    vec.push_back(cur_val);
  }
  //for one less than the vector's size (disincludes NoName 0)
  //print the name and value of each vector value
  for(int i = 0; i < vec.size()-1; i++){
    cout<<vec[i].name<<" "<<vec[i].value<<"\n";
  }
} 

bool checkDupe(vector<Name_value> vec, string s, int v){
  int size = vec.size();
  //for the size of the vector
  //check if the name is unique
  //if not, return false
  for(int i = 0; i < size; i++){
    if(s==vec[i].name){
      return false;
    }
  }
  //if every iteration of the for loop passed, return true
  return true;
}