//Advent of code https://adventofcode.com/2021/day/1

#include<iostream>
#include<fstream>
#include<string>
 
using namespace std;
 
int main()
{
    int i = 0, increased = 0; // Variable declaration
    string filename;   // Name of the file
    cout<<"Enter filename:"; // Prompts for the file to be used as argument
    cin>>filename; // Receives the filename as argument
    
    string line;   // To read each line from code
    int count=0;    // Variable to keep count of each line
    ifstream mFile (filename); // Opens the file named with the string stored in filename
    if(mFile.is_open()){ // Verifies if file is successfully opened
        while(mFile.peek()!=EOF) // Loop runs through the whole file using peek so that characters are not "consumed" in the verification,this way no extra line is read
        {
            getline(mFile, line); // Reads whole line, "consuming" it and placing the read pointer in the subsequent line
            count++; // Increases the line counter
        }
        
        cout<<"Number of lines in the file are: "<<count<<endl;
        int  number [count]; // Declares the array allocating the necessary space for all of the lines counted previously
        mFile.clear(); // Since EoF was read, the pointer needs to be cleared
        mFile.seekg(0, ios::beg); // Returns to the beginning of the file
        while (mFile >> number[i] && i <= count) { // Loops reads each integer and stores them on the array 
            if(i > 0 && number[i-1] < number[i]){ // Adds to the counter of increases when the previous number is lower than the current one, starts at i = 1
                increased++;
                //cout << number[i-1] << "<" << number[i] << endl; // Prints the comparison, used for testing
            }
            //cout << "i: " << i << ", number: " << number[i] << endl; // Prints the i counter and the current int stored in the array, used for testing
            i++; // Increases the i iteration counter
        }
        cout << "Number of increases:" << increased << endl; // Prints the number of increases counted
        mFile.close(); // Closes the file in the memory

    }
    else // Prints out a warning that the file was not successfully opened 
        cout<<"Couldn't open the file" << endl;
    
    return 0;
}