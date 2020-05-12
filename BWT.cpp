#include <string>
#include "BWT.h"
using namespace std;

struct suffix{
    int index;
    string letter;
};
/**
 * Implement bwt() correctly
 */
string bwt(const string & s) {
    /* YOUR CODE HERE */
    string s1 = s;
    int minind;
    struct suffix suff[s.length()];
    for(int i = 0; i < s.length(); i++){
        suff[i].index = i;
        char a = s1[s1.length() - 1];
        for(int j = s1.length() -1; j >= 0;j--){
            s1[j] = s1[j-1];
        }
        s1[0] = a;
        suff[i].letter = s1.substr(0,s1.length()); 
    }
    for(int i = 0; i < s.length() -1;i++){
        string s1 = suff[i].letter;
        minind = i;
        for(int j = i + 1; j < s.length();j++){
            int comp = s1.compare(suff[j].letter);
            if( comp > 0){
                s1 = suff[j].letter;
                minind = j;
            }
        }
        string a = suff[i].letter;
        int b = suff[i].index;
        suff[i].letter = suff[minind].letter;
        suff[i].index =suff[minind].index;
        suff[minind].letter = a;
        suff[minind].index = b;
    }
    std::string arr;
    for(int i = 0; i< s.length();i++){
        arr.push_back(suff[i].letter[s.length()-1]);
    }
    return arr;
}
