// 273. Integer to English Words
/*
273. Integer to English Words
Solved
Hard
Topics
Companies
Hint
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        int i = 0;
        string words = "";
        
        while (num > 0) {
            if (num % 1000 != 0) {
                words = helper(num % 1000) + thousands[i] + " " + words;
            }
            num /= 1000;
            i++;
        }
        
        return trim(words);
    }

private:
    vector<string> lessThan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                                 "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return lessThan20[num] + " ";
        else if (num < 100)
            return tens[num / 10] + " " + helper(num % 10);
        else
            return lessThan20[num / 100] + " Hundred " + helper(num % 100);
    }
    
    string trim(const string &str) {
        const string whitespace = " \t";
        const size_t strBegin = str.find_first_not_of(whitespace);
        if (strBegin == string::npos)
            return ""; // no content
        
        const size_t strEnd = str.find_last_not_of(whitespace);
        const size_t strRange = strEnd - strBegin + 1;
        
        return str.substr(strBegin, strRange);
    }
};
