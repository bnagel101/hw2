#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <ctype.h>

using namespace std;

std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> keywords;
    int start = 0;

    for(unsigned int i = 0; i < rawWords.size(); i++){
        if((isalpha(rawWords[i]) || isdigit(rawWords[i]))){
            start = i;
            int end = i;
            for(unsigned int j = i; j < rawWords.size(); j++){
                if((!isalpha(rawWords[j]) && !isdigit(rawWords[j]))){
                    end = j;
                    break;
                }else if(j == rawWords.size()-1){
                    end = j+1;
                    break;
                }
            }
            if(end - start >= 2){
                keywords.insert(rawWords.substr(start, end - start));
            }
            i = end;
            
        }
    }
    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
