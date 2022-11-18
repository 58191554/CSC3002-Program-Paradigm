/*
 * File: morsecode.cpp
 * -------------------
 * This file implements the morsecode.h interface.
 */

#include "morsecode.h"
using namespace std;
//TODO

/*
 * Function: createMorseCodeMap
 * Usage: Map<string> map = createMorseCodeMap();
 * ----------------------------------------------
 * Returns a map in which each uppercase letter is mapped into its
 * Morse code equivalent.
 */

Map<string,string> createMorseCodeMap() {
   Map<string,string> map;
   map["A"] = ".-";
   map["B"] = "-...";
   map["C"] = "-.-.";
   map["D"] = "-..";
   map["E"] = ".";
   map["F"] = "..-.";
   map["G"] = "--.";
   map["H"] = "....";
   map["I"] = "..";
   map["J"] = ".---";
   map["K"] = "-.-";
   map["L"] = ".-..";
   map["M"] = "--";
   map["N"] = "-.";
   map["O"] = "---";
   map["P"] = ".--.";
   map["Q"] = "--.-";
   map["R"] = ".-.";
   map["S"] = "...";
   map["T"] = "-";
   map["U"] = "..-";
   map["V"] = "...-";
   map["W"] = ".--";
   map["X"] = "-..-";
   map["Y"] = "-.--";
   map["Z"] = "--..";
   return map;
}
string translateLettersToMorse(string line){
    Map<string,string> map = createMorseCodeMap();
    string morse = "";
    for(int i = 0;i<line.size();i++){
        if(line.at(i)>=65&&line.at(i)<=90){
            morse += map.get(line.substr(i,1));
            morse += " ";
        }
    }
    return morse;
}

Map<std::string,std::string> invertMap(const Map<std::string,std::string> & map){
    Map<string,string> newMap;

    for(int i = 65;i<=90;i++){
        char c = i;
        string k = "";
        k+=i;
        string v = map.get(k);
        newMap.put(v,k);
    }
    return newMap;
}

std::string translateMorseToLetters(std::string line){
    Map<string,string> oldMap = createMorseCodeMap();
    Map<string, string> map = invertMap(oldMap);
    string temp = "";
    string outLetters = "";
    for(int i = 0;i<line.size();i++){
        if(line.at(i) == ' '){
            outLetters+=map.get(temp);
            temp = "";
        }
        else
            temp+=line.at(i);
    }
    if(temp != ""){
        outLetters+=map.get(temp);
    }
    return outLetters;
}


//TODO
