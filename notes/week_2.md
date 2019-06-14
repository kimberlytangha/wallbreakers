202. Happy Number
[LeetCode](https://leetcode.com/problems/happy-number/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/happy_number.cpp)
- Came up with sub optimal solution
- Divide by 10 removes the ones place of n (bc of flooring property of INT division) 
- % 10 returns the ones place digit 
- Find more optimal solution!
***
205. Isomorphic Strings
[LeetCode](https://leetcode.com/problems/isomorphic-strings/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/isomorphic_strings.cpp)
- Found suboptimal solution using two HM
- Pattern: using 2 HM to store the same kind of value (indicies of where a character appears) and check if the indicies are the same given a pair.
- ee/ pk => e and p have index 0 stored. Then e has index 0 while k has index -1 (return false)
***
290. Word Pattern
[LeetCode](https://leetcode.com/problems/word-pattern/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/word_pattern.cpp)
- Came up with suboptimal solution 
- Pattern found: Using 2 hash map to check for unique pattern->str and str->pattern 
- Coding issues: meant to use pmap[c] != word, not pmap.find(c) != pmap.end() to check if the value of key (C) matches current word. Also missed edge case where pattern is the same as the str; in this case, check pIdx reaches the end of pattern. 
- Forgot 2 equal signs: 
int i, j;
i = j = 0;
j = 0;
i = j;
- Thoughts: how to restructure looking in two maps? How to do at same time? 
***
349. Intersection of Two Arrays
[LeetCode](https://leetcode.com/problems/intersection-of-two-arrays/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/intersection_of_two_arrays.cpp)
- Found solution O(n^2); double for loop and find common elements to add to set
- Pattern: Use set to keep track of elements without duplicates. 
- Try to reduce to O(n) time if n^2.
- Optimized solution was to create set using one array. Cross check second array against set and erase if in set. Add unique element out vector. 
***
387. First Unique Character in a String
[LeetCode](https://leetcode.com/problems/first-unique-character-in-a-string/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/first_unique_character_in_a_string.cpp)
- Came up with suboptimal solution O(n)
- Pattern: Using letter - 'a' as an index into datastructure, using HM to store frequencies
- Coding mistaks: Forgot to use letter - 'a' when indexing into HM
- Not sure how to incorporate multisets? 
***
389. Find the Difference
[LeetCode](https://leetcode.com/problems/find-the-difference/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/find_the_difference.cpp)
- Came up with optimal solution by optimizing space complexity to O(1)
- Pattern: Using HM/ vector to store frequencies of characters + find different char, using ascii values of char 
- Coding: Ascii for a-z range from 0-25 not 0-26!
***
438. Find All Anagrams in a String
[LeetCode](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/find_all_anagrams_in_a_string.cpp)
- Solution doesn't work...not sure why? 
- Had a lot of bugs + didn't catch edge case (always check bounds of sliding door implementation!!)
- Pattern: Sliding door problem 
- Keep getting type: length of strings => accidentally put s.length() twice instead of s.length() and p.length()
***
451. Sort Characters By Frequency
[LeetCode](https://leetcode.com/problems/sort-characters-by-frequency/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/sort_characters_by_frequency.cpp)
- Came up with partial logic to solve, just couldn't figure out how to implement ordering frequencies
- REDO - come up with several ways to sort by frequency in HM or other ways to solve problem 
***
575. Distribute Candies
[LeetCode](https://leetcode.com/problems/distribute-candies/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/distribute_candies.cpp)
- Had no idea how to approach problem. Came up with part of solution (needed to split candies evenly between brother/ sister at minimum) 
- Pattern: Sister could not get more than half! Use set to determine how many unique candies there area and chose between that number of half of entire candies. 
- REDO
- What is time complexity of copying constructor of set? 
***
645. Set Mismatch
[LeetCode](https://leetcode.com/problems/set-mismatch/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/set_mismatch.cpp)
- Came up with SLOW O(nlogn) solution, but then optimized to O(n)
- Pattern: Using buckets to sort frequencies 
- Could optimize space more
***
726. Number of Atoms
[LeetCode](https://leetcode.com/problems/number-of-atoms/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/number_of_atoms.cpp)
- Came up with partial solution (only works when there is 1 char and 1 int possible; need better parser) that works! 
- Pattern: Using stacks to parse strings 
- Coding: stoi to convert string ints to integer
***
771. Jewels and Stones
[LeetCode](https://leetcode.com/problems/jewels-and-stones/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/jewels_and_stones.cpp)
- Carefully read problems (set problems are somewhat confusing to me)
***
804. Unique Morse Code Words
[LeetCode](https://leetcode.com/problems/unique-morse-code-words/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/unique_morse_code_words.cpp)
- Came up with optimal time solution
- Utilized vector indicies to retrieve correct morse code for a given char 
- Used set to store unique morse codes (despite various readings of it) 
- Looking through HT to find duplicate (ex.) abcd. Is it O(n^2)
***
819. Most Common Word
[LeetCode](https://leetcode.com/problems/most-common-word/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/most_common_word.cpp)
- Logic was correct for solution; struggled ONLY with string cleaning! 
- for auto loop/ isalpha(char) used for lowercasing + clean string of punctuation
- Use istringstream iss(str) for accessing each word in string seperated by space. Use while (iss >> word) {} loop. 
- KEY FUNCTIONS TO REMEBER: 
- isalpha(c) - alphabetic character 
- isdigit(i) - digit
- isalnum - digit or alphabetic character 
- Time complexities of istringstream + set(bd.begin(), bd.end()) constructor ? 
***
884. Uncommon Words from Two Sentences
[LeetCode](https://leetcode.com/problems/uncommon-words-from-two-sentences/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/uncommon_words_from_two_sentences.cpp)
- Careful deciding what to increment j-pointer using double pointers for identifying words seperated by spaces
- Came up with sub-optimal solution! Yay. 
- Try redoing with sets!
***
893. Groups of Special-Equivalent Strings
[LeetCode](https://leetcode.com/problems/groups-of-special-equivalent-strings/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/groups_of_special-equivalent_strings.cpp)
- Phrasing of set problems is EXTREMELY confusing (many in week 2 I didn't understand); this problem made no sense to me.
- Wouldn't recommend redoing bc description still makes no sense. 
- Pattern: realize you need an unordered_set to keep track of the word signatures
***
