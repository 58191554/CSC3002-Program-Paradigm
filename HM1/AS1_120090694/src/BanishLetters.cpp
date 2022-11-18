/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include "BanishLetters.h"
void banishLetters(){
    string ifName;
    string ofName;
    string banishLetterList;

    cout << "Input file: ";
    cin >> ifName;
    cout <<"Output file: ";
    cin >> ofName;

    cout<<"Letter to banish:";
    cin >> banishLetterList;
    // scanf("%s",banishLetterList);

    ifstream readfile(ifName.c_str());
    ofstream outfile(ofName.c_str());
    string orgTex;
    string s;

    readfile >> orgTex;
    while(getline(readfile,s)){
        orgTex+=s;
        orgTex+="\n";
    }
//    cout<<banishLetterList.size()<<endl;
    for(int i = 0; i< banishLetterList.size();i++){
        char c = banishLetterList.at(i);
//        cout<<c<<endl;
        char s;
        if ((c>=65)&&(c<=90))
            s =   c+32;
        else if ((c>=97)&&(c<=122))
            s = c-32;
        for(int j = 0;j<orgTex.size();j++){
            if(orgTex.at(j)==s||orgTex.at(j)==c){
                orgTex.erase(j,1);
                j--;
            }
        }
    }


    cout<<orgTex<<endl;
    outfile<<orgTex;
}
