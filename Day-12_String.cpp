/*
1704. Determine if String Halves Are Alike
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

SUBMISSION IN C++
*/
class Solution {
public:
    bool halvesAreAlike(string s) {
        string vwl="aeiouAEIOU";
        int cnt=0;
        int i=0;
        int n=s.size();
        while(i<n/2)
        {
            if(vwl.find(s[i]) != string::npos)
            {
                cnt++;
            }
            i++;
        }
        while(i<n)
        {
            if(vwl.find(s[i]) != string::npos)
            {
                cnt--;
            }
            i++;
        }

        return (cnt==0);
        
    }
};
