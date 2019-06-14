1. Two Sum
[LeetCode](https://leetcode.com/problems/two-sum/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/two_sum.cpp)
- Forgot to use find() instead of [] for searching through unordered_map
- If we need to figure out the time complexity of an algorithm (worst case), do we use the worst case in helper functions (insert/ find in unordered map) as well? 
***
14. Longest Common Prefix
[LeetCode](https://leetcode.com/problems/longest-common-prefix/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/longest_common_prefix.cpp)
- Came up with optimal solution O(mn)
- Accidentally flipped for loop (looped through words instead of char in first word first)
- Also mistook j for i in loop => led to compile errors 
***
66. Plus One
[LeetCode](https://leetcode.com/problems/plus-one/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/plus_one.cpp)
- Came up with carry idea, but couldn't implement correctly
- Couldn't implement correctly
- REDO 
***
125. Valid Palindrome
[LeetCode](https://leetcode.com/problems/valid-palindrome/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/valid_palindrome.cpp)
- Came up with O(n) sub optimal solution 
- Used two pointer approach to check ends of string for matching characters
- Had some trouble with buggy code (used j++ instead j--, didn't need to use - 'a' because everything already in lower case and will be validated for alphanumeric/ non spaces) 
- REDO to ensure optimal solution 
***
130. Surrounded Regions
[LeetCode](https://leetcode.com/problems/surrounded-regions/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/surrounded_regions.cpp)
- Found optimal dfs solution without looking at discussions!
- Remember to check if rows == 0 and return, THEN check cols == 0 bc it depends on row or array[0].size(). 
- Optimize space by storing indicies of 'O' in flip board and loop through that
***
136. Single Number
[LeetCode](https://leetcode.com/problems/single-number/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/single_number.cpp)
- Came up with solution immediately after realizing XOR operation was key 
***
171. Excel Sheet Column Number
[LeetCode](https://leetcode.com/problems/excel-sheet-column-number/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/excel_sheet_column_number.cpp)
- Came up with major parts of solution (multiply by 26 and add a product, noticed pattern of cols increased by 26 after each additional digit, noticed last number mean you were a-z(1-26) after last Z); couldn't translate thoughts into complete solution
- REDO
***
200. Number of Islands
[LeetCode](https://leetcode.com/problems/number-of-islands/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/number_of_islands.cpp)
- Wrongfully assumed numRows == numCols => resulted in compilation error/ out of range 
***
231. Power of Two
[LeetCode](https://leetcode.com/problems/power-of-two/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/power_of_two.cpp)
- Couldn't come up with working solution (2 bit manip algos where you would work with least sig bit and perform & 1, another algo involved division by 2 constantly and checking result's binary)
- REDO
***
242. Valid Anagram
[LeetCode](https://leetcode.com/problems/valid-anagram/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/valid_anagram.cpp)
- Came up with suboptimal solution O(n) time and space; couldn't think of better one
- Difference between using unordered_map vs array to store frequences? 
- Think of using arrays when dealing with characters in C++ (bc they char converts to int and vice versa) 
- Array has faster performance than hashmap (found optimal solution in discussions) 
***
344. Reverse String
[LeetCode](https://leetcode.com/problems/reverse-string/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/reverse_string.cpp)
- Came up with optimal solution
- Forgot that swap(x,y) function exists! Slightly more efficient
- REDO 
***
345. Reverse Vowels of a String
[LeetCode](https://leetcode.com/problems/reverse-vowels-of-a-string/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/reverse_vowels_of_a_string.cpp)
- Came up with O(n) suboptimal solution 
- Could be more elegant using arary [256] to hold vowels. Set vowels to 1 and constants to 0. Check if char has 1/0 in the array. 
***
461. Hamming Distance
[LeetCode](https://leetcode.com/problems/hamming-distance/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/hamming_distance.cpp)
- Came up and solved for solution quickly; but non-optimal (faster than 0%)
- Don't completely understand optimal solution. 
- What is time/ space complexity for bit operations? 
***
476. Number Complement
[LeetCode](https://leetcode.com/problems/number-complement/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/number_complement.cpp)
- Struggled with first algorithm (didn't work because forgot a step after XOR to single out ones digit) 
- Eventually came up with O(n) solution where n represents number of bits to represent highest binary that uses the same number of bits as num
***
520. Detect Capital
[LeetCode](https://leetcode.com/problems/detect-capital/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/detect_capital.cpp)
- Came up with O(n) solution; not very elegant
- Came up with correct logic (2 cases + 2 sub cases)  
***
547. Friend Circles
[LeetCode](https://leetcode.com/problems/friend-circles/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/friend_circles.cpp)
- Had trouble understanding how to determine the number of circles
- Tried to find patterns => noticed that if you listed the number and all of its friends and check their friends in a sort of DFS, you could rule out that friend group.
- Not sure how to code up the traversal through graph 
- Super helpful to draw out adj matrix to visualize graph!
- REDO
***
557. Reverse Words in a String III
[LeetCode](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/reverse_words_in_a_string_iii.cpp)
- Came up with O(n) suboptimal solution 
- More optimal + elegant solution possible?
***
728. Self Dividing Numbers
[LeetCode](https://leetcode.com/problems/self-dividing-numbers/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/self_dividing_numbers.cpp)
- Jumped to O(n times k) solution, maybe should have optimized before diving in
- Still had small bug issues that increase solving time (vector() vs {} for filling array of certain length/ with nums) 
- optimzied using solution in discussions 
***
867. Transpose Matrix
[LeetCode](https://leetcode.com/problems/transpose-matrix/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/transpose_matrix.cpp)
- Review how to initalize 2D vector literal; tricky syntax 
- Figured out O(n^2) solution immediately
***
868. Binary Gap
[LeetCode](https://leetcode.com/problems/binary-gap/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/binary_gap.cpp)
- Did come up with main logic (bitshifting right and checking 1's) 
- Need more practice with bit related problems 
- Why is dist set to -32? 
- REDO
***
905. Sort Array By Parity
[LeetCode](https://leetcode.com/problems/sort-array-by-parity/description/)    [Solution](https://github.com/kimberlytangha/wallbreakers/blob/master/week2/sort_array_by_parity.cpp)
- got O(n) algorithm idea in mind; issue coding up solution (always buggy—% error, nested while loop i < j doesn't apply to inner loop)
- catching edge case [0,1]
***
