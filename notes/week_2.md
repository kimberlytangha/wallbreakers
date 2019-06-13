202. Happy Number
- WEEK 2
- Came up with sub optimal solution
- Divide by 10 removes the ones place of n (bc of flooring property of INT division) 
- % 10 returns the ones place digit 
- Find more optimal solution!


290. Word Pattern
- WEEK 2
- Came up with suboptimal solution 
- Pattern found: Using 2 hash map to check for unique pattern->str and str->pattern 
- Coding issues: meant to use pmap[c] != word, not pmap.find(c) != pmap.end() to check if the value of key (C) matches current word. Also missed edge case where pattern is the same as the str; in this case, check pIdx reaches the end of pattern. 
- Forgot 2 equal signs: 
int i, j;
i = j = 0;
j = 0;
i = j;
- Thoughts: how to restructure looking in two maps? How to do at same time? 


387. First Unique Character in a String
- WEEK 2
- Came up with suboptimal solution O(n)
- Pattern: Using letter - 'a' as an index into datastructure, using HM to store frequencies
- Coding mistaks: Forgot to use letter - 'a' when indexing into HM
- Not sure how to incorporate multisets? 


438. Find All Anagrams in a String
- WEEK 2
- Solution doesn't work...not sure why? 
- Had a lot of bugs + didn't catch edge case (always check bounds of sliding door implementation!!)
- Pattern: Sliding door problem 
- Keep getting type: length of strings => accidentally put s.length() twice instead of s.length() and p.length()


575. Distribute Candies
- WEEK 2
- Had no idea how to approach problem. Came up with part of solution (needed to split candies evenly between brother/ sister at minimum) 
- Pattern: Sister could not get more than half! Use set to determine how many unique candies there area and chose between that number of half of entire candies. 
- REDO
- What is time complexity of copying constructor of set? 


804. Unique Morse Code Words
- WEEK 2
- Came up with optimal time solution
- Utilized vector indicies to retrieve correct morse code for a given char 
- Used set to store unique morse codes (despite various readings of it) 
- Looking through HT to find duplicate (ex.) abcd. Is it O(n^2)


819. Most Common Word
- WEEK 2
- Logic was correct for solution; struggled ONLY with string cleaning! 
- for auto loop/ isalpha(char) used for lowercasing + clean string of punctuation
- Use istringstream iss(str) for accessing each word in string seperated by space. Use while (iss >> word) {} loop. 
- KEY FUNCTIONS TO REMEBER: 
- isalpha(c) - alphabetic character 
- isdigit(i) - digit
- isalnum - digit or alphabetic character 
- Time complexities of istringstream + set(bd.begin(), bd.end()) constructor ? 


893. Groups of Special-Equivalent Strings
- WEEK 2
- Phrasing of set problems is EXTREMELY confusing (many in week 2 I didn't understand); this problem made no sense to me.
- Wouldn't recommend redoing bc description still makes no sense. 
- Pattern: realize you need an unordered_set to keep track of the word signatures


