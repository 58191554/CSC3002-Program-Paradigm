/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */

#include "RemoveComments.h"
/* Function prototypes */

/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */


void removeComments(istream & is, ostream & os){
    char ifName[50];

    cout << "Input file: ";
    cin >> ifName;
    ifstream infile(ifName);

    string words;
    string s;

    while(getline(infile,s)){
        words+=s;
        words+="\n";
    }

    int longCommentLocs[100][2];
    int longIndex = 0;                  //This variable is used to go through the longCommentLocs array index
    //cout<<"Read from file:"<<words<<endl;


    for(int i = 0;i<words.size();i++){

        int leftComment = words.find("/*",i);
        int rightComment = words.find("*/",leftComment);

        if(leftComment == -1)
            break;
        //cout<<" leftComment "<<leftComment<<" rightComment "<<rightComment<<endl;
        longCommentLocs[longIndex][0] = leftComment;
        longCommentLocs[longIndex][1] = rightComment;
        longIndex++;
        i = rightComment;
    }

    for(int i = longIndex-1;i>=0;i--){
        int pos = longCommentLocs[i][0]; int length = longCommentLocs[i][1]-longCommentLocs[i][0]+2;
        //cout << (pos)<< ", " <<(pos + length)<<endl;
        //cout << words.at(pos)<< ", " << words.at(pos + length)<<endl;
        words.erase(pos,length);
    }

    //cout<<words<<endl;

    int shortCommentLocs[100][2];
    int shortIndex = 0;                     //This variable is used to go through the shortCommentLocs array index
    for(int i = 0;i<words.size();i++){

        int doubleSlash = words.find("//",i);
        int lineEndIdx = words.find("\n",doubleSlash);

        if(doubleSlash == -1)
            break;
        //cout<<" doubleSlash "<<doubleSlash<<" lineEndIdx "<<lineEndIdx<<endl;
        shortCommentLocs[shortIndex][0] = doubleSlash;
        shortCommentLocs[shortIndex][1] = lineEndIdx;
        shortIndex++;
        i = doubleSlash;
    }

    for(int i = shortIndex-1;i>=0;i--){
        int pos = shortCommentLocs[i][0]; int length = shortCommentLocs[i][1]-shortCommentLocs[i][0];
        //cout << (pos)<< ", " <<(pos + length)<<endl;
        //cout << words.at(pos)<< ", " << words.at(pos + length)<<endl;
        words.erase(pos,length);
    }
    cout << words<<endl;

    infile.close();
};
