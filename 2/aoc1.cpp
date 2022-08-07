//Advent of code https://adventofcode.com/2021/day/2

#include<iostream>
#include<fstream>
#include<string>
 
using namespace std;
 
int main(){
    string filename;   // Name of the file
    cout<<"Enter filename:"; // Prompts for the file to be used as argument
    cin>>filename; // Receives the filename as argument
    
    string word;   // To read each line from code
    int horiz = 0, depth = 0, aux = 0, answer = 0;    // Auxiliary variable, Horizontal position variable and depth position variable declaration
    ifstream mFile (filename); // Opens the file named with the string stored in filename
    if(mFile.is_open()){ // Verifies if file is successfully opened
        while(mFile >> word) // Each iteration of while verification "consumes" a word and stores it's value into the word string
            {
                mFile >> aux; // The following character will be the number associated with the command, which is stored into the aux variable
                // cout << "Word: " << word << " number: " << aux << endl; //prints each reading, used for debugging
                if(word == "forward") // Verifies if the word read was "forward"
                    horiz = horiz + aux; // Adds the number associated with the forward command read to the horizontal position total
                else if (word == "down") // Verifies if the word read was "down"
                    depth = depth + aux; // Adds the number associated with the down command read to the depth total
                else if (word == "up") // Verifies if the word read was "up"
                    depth = depth - aux; // Subtracts the number associated with the up command to the depth total
                else //Prints out a reading error if the word read was not a forward, down or up command
                    cout << "Reading error" << endl;
            } 
        cout << "Horizontal pos: " << horiz << " Depth: " << depth << endl; // Prints out the final horizontal position and depth
        mFile.close(); // Closes the file
        answer = horiz * depth; // Multiplies one position by the other to provide the answer asked by the problem
        cout << "Answer: " << answer << endl; // Prints out the answer to the problem
    }
    else // Prints out a warning that the file was not successfully opened 
        cout<<"Couldn't open the file" << endl;
    return 0;
}