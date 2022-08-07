//Advent of code https://adventofcode.com/2021/day/2

#include<iostream>
#include<fstream>
#include<string>
 
using namespace std;
 
int main(){
    string filename; // Name of the file
    cout<<"Enter filename:"; // Prompts for the file to be used as argument
    cin>>filename; // Receives the filename as argument
    
    string word; // To read each line from code
    int horiz = 0, depth = 0, aim = 0, aux = 0, answer = 0; // Auxiliary variable, Horizontal position variable, depth position variable and aim variable declaration
    ifstream mFile (filename); // Opens the file named with the string stored in filename
    if(mFile.is_open()){ // Verifies if file is successfully opened
        while(mFile >> word) // Each iteration of while verification "consumes" a word and stores it's value into the word string
            {
                mFile >> aux; // The following character will be the number associated with the command, which is stored into the aux variable
                // cout << "Word: " << word << " number: " << aux << endl; //prints each reading, used for debugging
                if(word == "forward"){ // Verifies if the word read was "forward"
                    horiz = horiz + aux; // Adds the number associated with the forward command read to the horizontal position total
                    depth = depth + (aim * aux); // Increases depth by a multiplication of Aim + the number listed in the forward command
                }
                else if (word == "down") // Verifies if the word read was "down"
                    aim = aim + aux; // Adds the number associated with the down command read to the aim total
                else if (word == "up") // Verifies if the word read was "up"
                    aim = aim - aux; // Subtracts the number associated with the up command to the aim total
                else //Prints out a reading error if the word read was not a forward, down or up command
                    cout << "Reading error" << endl;
            } 
        cout << "Horizontal pos: " << horiz << " Depth: " << depth << " Aim: " << aim << endl; // Prints out the final horizontal position, depth and aim
        mFile.close(); // Closes the file
        answer = horiz * depth; // Multiplies one position by the other to provide the answer asked by the problem
        cout << "Answer: " << answer << endl; // Prints out the answer to the problem
    }
    else // Prints out a warning that the file was not successfully opened 
        cout<<"Couldn't open the file" << endl;
    return 0;
}