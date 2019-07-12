//////////////////////
// Sort using x-end //
//////////////////////

class Solution {
public:
    // time O(nlogn)
    // space O(n) 
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows = 0;             // keeps track of number of arrows
        int i = 0;                  // ref curr point
        int numPts = points.size();      
        
        // need to sort in increasing order of x-end
        sort(points.begin(), points.end(), sortSecond);
        
        while (i < numPts) {
            arrows++;
            
            // consider this to be where we shoot ballons from
            int arrowPos = points[i][1];
            
            // start comparing arrowPos point with rest of points 
            // find all overlapping x-start with arrowPos
            i++; 
            while (i < numPts && points[i][0] <= arrowPos)
                i++;
        }
        
        return arrows;
    }
    
    // pass a and b as ref for cmp 
    static bool sortSecond(vector<int> &a, vector<int> &b) {
        return a[1] < b[1]; 
    }
    
};

////////////////////////
// Sort using x-start //
////////////////////////

// key difference between this and above solution is that you need 
// to traverse in reverse (back to front) and use the x-start as 
// your arrow position
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int numPts = points.size();
        int arrows = 0; 
        // start i at end 
        int i = numPts - 1; 
        
        sort(points.begin(), points.end(), sortSecond);
        
        // traverse from end to beginning of vector
        while (i >= 0) {
            arrows++; 
            // look at x-start [0] instead of x-end [1]
            int arrowPos = points[i][0]; 
            
            // careful with i ptr here bc it can go below 0
            // and you jump out of loop without considering
            // the remaining first element 
            while (i >= 1 && points[i-1][1] >= arrowPos)
                i--; 
            i--; 
        }
        
        return arrows; 
    }
    
    static bool sortSecond(vector<int> &a, vector<int> &b) {
        // use x-start [0] instead of x-end [1]
        return a[0] < b[0];
    }
    
};