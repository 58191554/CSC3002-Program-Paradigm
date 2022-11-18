/*
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file solves the DNA matching exercise from the text.
 */

#include "FindDNAMatch.h"

/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */

int findDNAMatch(string s1, string s2, int start){
    string matchS1 = matchingStrand(s1);
    if(s2.size()>=s1.size() && start<=s2.size()-s1.size()){
        for(int i = start;i<=s2.size()-s1.size();i++){
            for(int j = 0;j<s1.size();j++){
                if(matchS1[j]!=s2[i+j]){
                    break;
                }
                if(j == s1.size()-1){
                    return i;
                }
            }
        }
    }
    return -1;
}

/*
 * Function: matchingStrand
 * Usage: string match = matchingStrand(strand);
 * ---------------------------------------------
 * Returns a string in which each base has been replaced by its
 * counterpart base (C <-> G and A <-> T).  Any other characters
 * are replaced by an X.
 */

string matchingStrand(string strand){
    string matchString = strand;
    for(int i =0;i<strand.size();i++){
        if(matchString.at(i) == 'A')
            matchString[i] = 'T';
        else if(matchString.at(i) == 'T')
            matchString[i] = 'A';
        else if (matchString.at(i) == 'C')
            matchString[i] = 'G';
        else
            matchString[i] = 'C';
    }
    return matchString;
};

/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

void findAllMatches(string s1, string s2){
    bool flage = 0;
    if(s2.size()<s1.size())
        cout<<-1<<endl;

    else{
        for(int i = 0;i<=s2.size()-s1.size();i++){
            int number = findDNAMatch(s1,s2,i);
            if(number != -1){
                cout<<number<<" ";
                i += s1.size();
                flage =1;
            }
            else if(flage == 0 && i == s2.size()-s1.size())
                cout<<-1<<endl;
        }
    cout << endl;
    }
}
