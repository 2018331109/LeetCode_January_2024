/*
1657. Determine if Two Strings Are Close
Two strings are considered close if you can attain one from the other using the following operations:

    Operation 1: Swap any two existing characters.
        For example, abcde -> aecdb
    Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
        For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

SUBMISSION IN C++
*
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int>a, b;
        map<int, int>mp;
        set<char>sa, sb;
        for(auto it:word1)
        {
            a[it]++;
            sa.insert(it);
        }
        for(auto it:word2)
        {
            b[it]++;
            sb.insert(it);
        }
        if(sa!=sb)
        {
            return false;
        }
        for(auto it:a)
        {
            mp[it.second]++;
        }
        for(auto it:b)
        {
            mp[it.second]--;
        }
 
        for(auto it:mp)
        {
            if(it.second!=0)
            {
                return false;
            }
        }
        return true;
        
    }
};
