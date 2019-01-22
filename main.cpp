//----------------------------------------------------------
//  Name: Waylon Wu
//  E-mail Address: wiw5145@psu.edu
//  Class: CMPSC 122
//  Assignment #1
//  Due Date: 2/2/17
//  Brief Project Description: Encrypting Text Files
//----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string line;
string fileName;

void readFile();
void encryptFile(string);
int encrypt(int);
void saveFile();

int main() {
    
    cout << "Please enter file name: ";
    cin >> fileName;
    
    ifstream inFile;
    inFile.open(fileName);
    
//    while(getline(inFile, line)) {
//        inFile >> line;
//    }
    
    int *message = nullptr;
    int *output = nullptr;
    char *chara = nullptr;
    
    output = new int[line.length()];
    message = new int[line.length()];
    chara = new char[line.length()];
    
    if(inFile.is_open())
    {
        
        for(int i = 0; i < line.length(); ++i)
        {
            inFile >> message[i];
        }
    }
    
    //if the letters are lowercase, then it converts them to uppercase.
    for(int x = 0; x < line.length(); x++)
    {
        if(line.at(x) >= (int)97 && line.at(x) <= (int)122)
        {
            putchar(toupper(line.length()));
        }
        
        //changes the letters to ascii int, and reduces them to 0-25
        message[x] = (int)line.at(x) - 65;
    }
    
    for(int x = 0; x < line.length(); x++)
    {   //if the character is a certain ascii value, then print its corresponding character
        if(line.at(x) == (int)46)
        {
            cout << ".";
        }
        else if(line.at(x) == (int)32)
        {
            cout << " ";
        }
        //if they arent those chars, then call first method
        else
        {
            output[x] = encrypt(message[x]);
            output[x] = output[x] + 65;
            chara[x] = (char)output[x];
            cout << chara[x];
        }
    }
    
    cout << endl;
    
    inFile.close();
    
    ofstream outFile;
    outFile.open("Encrypted.rtf");
    outFile << output[line.length()];
    outFile.close();
    
//    readFile();
//    saveFile();
    
    return 0;
}

void readFile() {
    
    ifstream inFile;
    inFile.open(fileName);
    
    while(getline(inFile, line)) {
        
    }
    
    inFile.close();
}

void encryptFile(string line) {
    
    int *message = nullptr;
    int *output = nullptr;
    char *chara = nullptr;
    
    output = new int[line.length()];
    message = new int[line.length()];
    chara = new char[line.length()];
    
    //if the letters are lowercase, then it converts them to uppercase.
    for(int x = 0; x < line.length(); x++)
    {
        if(line.at(x) >= (int)97 && line.at(x) <= (int)122)
        {
            putchar(toupper(line.length()));
        }
        
        //changes the letters to ascii int, and reduces them to 0-25
        message[x] = (int)line.at(x) - 65;
    }
    
    for(int x = 0; x < line.length(); x++)
    {   //if the character is a certain ascii value, then print its corresponding character
        if(line.at(x) == (int)46)
        {
            cout << ".";
        }
        else if(line.at(x) == (int)32)
        {
            cout << " ";
        }
        //if they arent those chars, then call first method
        else
        {
            output[x] = encrypt(message[x]);
            output[x] = output[x] + 65;
            chara[x] = (char)output[x];
            cout << chara[x];
        }
    }
    
    cout << endl;
}

int encrypt(int a) {
    int code;
    
    code = (a + 7) % 26;
    
    return code;
}

void saveFile() {
    
    ofstream outFile;
    outFile.open("Encrypted.rtf");
    
    outFile.close();
}
