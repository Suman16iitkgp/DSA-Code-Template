#include <bits/stdc++.h>
using namespace std;

/*
Given a string of length n , your task is to determine the longest palindromic substring of the string. 
For example, the longest palindrome in "algoazzaa" is "azza". If there are multiple longest palindromic substrings, 
Output the one which comes first in the string.
*/

string longestPalindrome(string s) {
    string sManacher = "&";
    for( char ch:s ){
        sManacher += ch;
        sManacher += '&';
    }
    int n = int(sManacher.length());
    vector<int> palindromeRadius(n, 0);

    int center = 0, radius = 0;

    for( int i=0; i<n; i++ ){
        int mirror = 2*center - i;

        if( i < radius ){
            palindromeRadius[i] = min(radius-i, palindromeRadius[mirror]);
        }

        while( i-palindromeRadius[i]-1 >= 0 && i+palindromeRadius[i]+1 < n && 
        sManacher[i-palindromeRadius[i]-1] == sManacher[i+palindromeRadius[i]+1] ){
            palindromeRadius[i]++;
        }

        if( i+ palindromeRadius[i] > radius ){
            center = i;
            radius = i+ palindromeRadius[i];
        }
    }

    int maxLength = 0;
    int centerIndex = 0;
    for( int i=0; i<palindromeRadius.size(); i++ ){
        if( palindromeRadius[i] > maxLength ){
            maxLength = palindromeRadius[i];
            centerIndex = i;
        }
    }

    int startIndex = (centerIndex-maxLength)/2;
    string res = s.substr(startIndex, maxLength);

    return res;
}
