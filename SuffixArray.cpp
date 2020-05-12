#include <string>
#include <vector>
#include "SuffixArray.h"
#include <algorithm>
#include <sstream>
using namespace std;
struct suffix{
    int index;
    string letter;
};
int cmp(struct suffix a, struct suffix b) 
{ 
    return a.letter.compare(b.letter) < 0? 1 : 0; 
} 
/**
 * Implement suffix_array() correctly
 */
vector<unsigned int> suffix_array(const string & s) {
    /* YOUR CODE HERE */
    int minind = 0;
    struct suffix suff[s.length()];
    for(int i = 0; i < s.length(); i++){
        suff[i].index = i; 
        suff[i].letter = s.substr(i,s.length()); 
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
    vector<unsigned int> final;
    for (int i = 0; i < s.length(); i++) 
        final.push_back(suff[i].index);
  
    // Return the suffix array 
    return  final;
    /*string arr[2][s.length()];
    for(int i = 0; i < s.length(); i++){
        arr[0][i] = s.substr(i,s.length() - i);
        stringstream ss;  
        ss<<i;  
        string ss1;  
        ss>>ss1;  
        arr[1][i] = ss1;
    }
    for(int i = 0; i < s.length();i++){
        string s = arr[0][i];
        int minind = i;
        for(int j = i; j < s.length();j++){
            int comp = s.compare(arr[0][j]);
            if( comp > 0){
                s = arr[0][j];
                int minind = j;
            }
        }
        swap(arr[0][i],arr[0][minind]);
        swap(arr[1][i],arr[1][minind]);
    }
    vector<unsigned int> final;
    for(int i = 0; i < s.length(); i++){
        stringstream num(arr[1][i]);
        int convert = 0;
        num >> convert; 
        final.push_back(convert);
    }
    return final;*/
}
