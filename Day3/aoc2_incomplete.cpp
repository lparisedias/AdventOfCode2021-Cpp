//Advent of code https://adventofcode.com/2021/day/3
//Compiled with -lstdc++ -lm as arguments for gcc, to access the necessary libs
//Incomplete code

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
 
using namespace std;
void commoncounter(ifstream&, int*, int*);
void printarray (int*);
void printarrayc(char*);
void commonarray (int*, int*, char*, char*);
string verifyCO2 (ifstream&, string, string, int);
string convertToString(char*, int);
 
int main(){
    int i=0;
    string filename, temp, CO2, O2; // Name of the file
    cout<<"Enter filename:"; // Prompts for the file to be used as argument
    cin>>filename; // Receives the filename as argument
    ifstream mFile (filename); // Opens the file named with the string stored in filename
    if(mFile.is_open()){ // Verifies if file is successfully opened
        char number, mcommon[12], lcommon[12]; // To read each line from code
        int count0[12] = {0}, count1[12]= {0}, answer; // K is initialized as 11 so that it will work for binary conversion later
        commoncounter(mFile, count1, count0);
        printarray(count1);
        printarray(count0);
        commonarray(count1, count0, mcommon, lcommon);
        printarrayc(mcommon);
        string s_mcommon, s_lcommon;
        s_lcommon = convertToString(lcommon, 12);
        s_mcommon = convertToString(mcommon, 12);
        cout << "least common: " << s_lcommon << " most common: " << s_mcommon << endl;
        CO2 = verifyCO2(mFile, s_lcommon, temp, i);
        cout << "CO2: " << CO2 << endl;
        mFile.clear(); // Since EoF was read, the pointer needs to be cleared
        mFile.seekg(0, ios::beg); // Returns to the beginning of the file
        mFile.close(); // Closes the file
    }
    else // Prints out a warning that the file was not successfully opened 
        cout<<"Couldn't open the file" << endl;
    return 0;
}

void commoncounter(ifstream& mFile, int counter1[], int counter0[]){
    int i = 0;
    char number;
    while(mFile >> number) // Each iteration of while verification "consumes" a word and stores it's value into the word string
            {
                // cout << "number read: " << number << " i: " << i << endl; // Prints out the readings and the i counter, used for debugging
                if(number == '1') // Identifies the number read and adds to the respective counter array in the i position
                    counter1[i]++;
                else
                    counter0[i]++;
                i++; // Increments the i counter for the correct array position tracking
                if(i == 12) // Resets the counter when the i counter goes beyond the position 11, which is the last position of the vector
                    i = 0;
            }
}
void printarray(int* arr){
    int i;
    for(i=0; i <12; i++){ 
            cout << arr[i] << " ";
        }
        cout << endl;
}
void printarrayc(char* arr){
    int i;
    for(i=0; i <12; i++){ 
            cout << arr[i] << " ";
        }
        cout << endl;
}
void commonarray (int* counter1, int* counter0, char* mcommon, char* lcommon){
    int i;
    for(i=0; i <12; i++){ // Loops through the positions of both counter arrays
        if(counter1[i] > counter0[i]){ // Compares between the "0" counter and the "1" counter. The higher one is the more frequent bit. 
            cout << "1 ";
            mcommon[i] = '1';
            lcommon[i] = '0';
        } 
        else{  //For epsilon, since these are binary numbers, wherever gamma has a 1 bit, epsilon will have a 0 bit, so the sum is added in this else condition
            cout << "0 ";
            mcommon[i] = '0';
            lcommon[i] = '1';
        }    
    }
    cout << endl;
}
std::string verifyCO2 (ifstream& mFile, string s_lcommon, string temp, int i){
    int counterl = 0;
    string aux, store, final = "None";
    mFile.clear(); // Since EoF was read, the pointer needs to be cleared
    mFile.seekg(0, ios::beg); // Returns to the beginning of the file
    cout << s_lcommon << endl;
    while(mFile.peek()!=EOF) // Loop runs through the whole file using peek so that characters are not "consumed" in the verification,this way no extra line is read
        {
            getline(mFile, temp); // Reads whole line, "consuming" it and placing the read pointer in the subsequent line
            aux = temp;
            aux.erase(aux.size()-1, i);
            //cout << "aux: " << aux << endl;

            if(aux == temp)
                counterl++;
                //cout << "counterl = " << counterl << endl;
                store = temp;
                //cout << "temp: " << temp << " store: " << store << endl;
        }
        if (counterl == 1){
            //cout << "counterl = 1" << endl;
            final = store;
        }
        else if(counterl == 0){
            i++;
            //cout << "batata" << endl;
            store = verifyCO2(mFile, s_lcommon.erase(s_lcommon.size()-1, i), temp, i);
        }
        else{
            return "There were no unique combinations";
        }
    return final;
}
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
