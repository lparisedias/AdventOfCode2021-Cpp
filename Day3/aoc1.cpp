//Advent of code https://adventofcode.com/2021/day/3
//Compiled with -lstdc++ -lm as arguments for gcc, to access the necessary libs

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<math.h>
 
using namespace std;
 
int main(){
    int i = 0, k = 11, count0[12] = {0}, count1[12]= {0}, gamma = 0, epsilon = 0, answer; // K is initialized as 11 so that it will work for binary conversion later
    string filename; // Name of the file
    cout<<"Enter filename:"; // Prompts for the file to be used as argument
    cin>>filename; // Receives the filename as argument
    
    char number; // To read each line from code
    ifstream mFile (filename); // Opens the file named with the string stored in filename
    if(mFile.is_open()){ // Verifies if file is successfully opened
        while(mFile >> number) // Each iteration of while verification "consumes" a word and stores it's value into the word string
            {
                // cout << "number read: " << number << " i: " << i << endl; // Prints out the readings and the i counter, used for debugging
                if(number == '1') // Identifies the number read and adds to the respective counter array in the i position
                    count1[i]++;
                else
                    count0[i]++;
                i++; // Increments the i counter for the correct array position tracking
                if(i == 12) // Resets the counter when the i counter goes beyond the position 11, which is the last position of the vector
                    i = 0;
            }
        /*for(i=0; i <12; i++){ // Prints out the 1 counter array, used for debugging
            cout << count1[i] << " ";
        }
        cout << endl;
        for(i=0; i <12; i++){ // Prints out the 0 counter array, used for debugging
            cout << count0[i] << " ";
        }
        cout << endl;*/
           for(i=0; i <12; i++){ // Loops through the positions of both counter arrays
            if(count1[i] > count0[i]) // Compares between the "0" counter and the "1" counter. The higher one is the more frequent bit. 
                gamma = gamma + pow(2.0, k); // For each i position where "1" appeared the most in the input, 2 to the power of k is added. This is done in order to 
                                            // convert the binary into an integer in a single loop
            else //For epsilon, since these are binary numbers, wherever gamma has a 1 bit, epsilon will have a 0 bit, so the sum is added in this else condition
                epsilon = epsilon + pow(2.0, k);
            k--; // Decreases the k counter in the same rate as the i counter increases, so that each respective calculations of binary conversion are made successfully
            }
        cout << "gamma: " << gamma << endl; // Prints out the final gamma value as an integer
        cout << "epsilon: " << epsilon << endl; // Prints out the final epsilon value as an integer
        answer = gamma * epsilon; // Calculates the answer to the problem, which is a multiplication og gamma by epsilon
        cout << "answer: " << answer << endl; // Prints out the final answer to the problem
        mFile.close(); // Closes the file
    }
    else // Prints out a warning that the file was not successfully opened 
        cout<<"Couldn't open the file" << endl;
    return 0;
}