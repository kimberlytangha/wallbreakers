1. Two Sum
- Forgot to use find() instead of [] for searching through unordered_map
- If we need to figure out the time complexity of an algorithm (worst case), do we use the worst case in helper functions (insert/ find in unordered map) as well? 


14. Longest Common Prefix
- Came up with optimal solution O(mn)
- Accidentally flipped for loop (looped through words instead of char in first word first)
- Also mistook j for i in loop => led to compile errors 


66. Plus One
- Came up with carry idea, but couldn't implement correctly
- Couldn't implement correctly
- REDO 


125. Valid Palindrome
- Came up with O(n) sub optimal solution 
- Used two pointer approach to check ends of string for matching characters
- Had some trouble with buggy code (used j++ instead j--, didn't need to use - 'a' because everything already in lower case and will be validated for alphanumeric/ non spaces) 
- REDO to ensure optimal solution 


130. Surrounded Regions
- Found optimal dfs solution without looking at discussions!
- Remember to check if rows == 0 and return, THEN check cols == 0 bc it depends on row or array[0].size(). 
- Optimize space by storing indicies of 'O' in flip board and loop through that


136. Single Number
- Came up with solution immediately after realizing XOR operation was key 


171. Excel Sheet Column Number
- Came up with major parts of solution (multiply by 26 and add a product, noticed pattern of cols increased by 26 after each additional digit, noticed last number mean you were a-z(1-26) after last Z); couldn't translate thoughts into complete solution
- REDO


200. Number of Islands
- Wrongfully assumed numRows == numCols => resulted in compilation error/ out of range 


231. Power of Two
- Couldn't come up with working solution (2 bit manip algos where you would work with least sig bit and perform & 1, another algo involved division by 2 constantly and checking result's binary)
- REDO


242. Valid Anagram
- Came up with suboptimal solution O(n) time and space; couldn't think of better one
- Difference between using unordered_map vs array to store frequences? 
- Think of using arrays when dealing with characters in C++ (bc they char converts to int and vice versa) 
- Array has faster performance than hashmap (found optimal solution in discussions) 


344. Reverse String
- Came up with optimal solution
- Forgot that swap(x,y) function exists! Slightly more efficient
- REDO 


345. Reverse Vowels of a String
- Came up with O(n) suboptimal solution 
- Could be more elegant using arary [256] to hold vowels. Set vowels to 1 and constants to 0. Check if char has 1/0 in the array. 


349. Intersection of Two Arrays
- Found solution O(n^2); double for loop and find common elements to add to set
- Pattern: Use set to keep track of elements without duplicates. 
- Try to reduce to O(n) time if n^2.
- Optimized solution was to create set using one array. Cross check second array against set and erase if in set. Add unique element out vector. 


461. Hamming Distance
- Came up and solved for solution quickly; but non-optimal (faster than 0%)
- Don't completely understand optimal solution. 
- What is time/ space complexity for bit operations? 


476. Number Complement
- Struggled with first algorithm (didn't work because forgot a step after XOR to single out ones digit) 
- Eventually came up with O(n) solution where n represents number of bits to represent highest binary that uses the same number of bits as num


520. Detect Capital
- Came up with O(n) solution; not very elegant
- Came up with correct logic (2 cases + 2 sub cases)  


547. Friend Circles
- Had trouble understanding how to determine the number of circles
- Tried to find patterns => noticed that if you listed the number and all of its friends and check their friends in a sort of DFS, you could rule out that friend group.
- Not sure how to code up the traversal through graph 
- Super helpful to draw out adj matrix to visualize graph!
- REDO


557. Reverse Words in a String III
- Came up with O(n) suboptimal solution 
- More optimal + elegant solution possible?


728. Self Dividing Numbers
- Jumped to O(n times k) solution, maybe should have optimized before diving in
- Still had small bug issues that increase solving time (vector() vs {} for filling array of certain length/ with nums) 
- optimzied using solution in discussions 


867. Transpose Matrix
- Review how to initalize 2D vector literal; tricky syntax 
- Figured out O(n^2) solution immediately


868. Binary Gap
- Did come up with main logic (bitshifting right and checking 1's) 
- Need more practice with bit related problems 
- Why is dist set to -32? 
- REDO


884. Uncommon Words from Two Sentences
- Careful deciding what to increment j-pointer using double pointers for identifying words seperated by spaces
- Came up with sub-optimal solution! Yay. 
- Try redoing with sets!


905. Sort Array By Parity
- got O(n) algorithm idea in mind; issue coding up solution (always buggy—% error, nested while loop i < j doesn't apply to inner loop)
- catching edge case [0,1]


