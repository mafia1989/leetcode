// Valid Anagram

// Given two strings s and t, write a function to determine if t is an anagram of s.

// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.

// Note:
// You may assume the string contains only lowercase alphabets.


// My solution

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() == 0 && t.size() == 0)
            return true;
        if(s.size() != t.size())
            return false;
        
        for(char c:t)
        {
            int i = s.find(c);
            if(i != string::npos)
            {
                s.erase(i,1);
            }
            else
            {
                return false;
            }
        }
        
        return true;
        
    }
};

//a better solution

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};