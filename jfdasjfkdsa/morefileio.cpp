#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    ifstream fin;
    fin.open("input.txt");
    string tmpLine;

    while(getline(fin,tmpLine)){
        int currentChar;
        //cout << "tmpline.length(): " 
            //<< tmpLine.length()<< endl;
        for(int i = 0; i < tmpLine.length(); i++){
            currentChar = tmpLine.at(i);
            cout << currentChar <<" ";
            //cout<<tmpLine.at(i) - '0' << " ";
        }
        cout << endl;
    }
    fin.close();
    return 0;
}