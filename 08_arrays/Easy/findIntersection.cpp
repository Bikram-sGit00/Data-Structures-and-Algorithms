// GFG: https://www.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1
// brute force approach;
// Time complexity: O(n*m);

class Solution
{
public:
    int numberofElementsInIntersection(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        int count = 0;
        vector<int> ans;
        vector<int> visited(max(m, n), 0); // checking if the element is already been used;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j] && visited[j] == 0)
                {
                    // ans.push_back(a[i]);
                    //  && visited.back()!=
                    count++;
                    visited[j] = 1;
                    break;
                }
            }
        }

        return count;
    }
};

// LeetCode: https://leetcode.com/problems/intersection-of-two-arrays/
//  Optimized approach:
//  Time complexity: O(M+N);
//  Space complexity: O(Min(M,N));
class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        unordered_set<int> setA(a.begin(), a.end()); // Insert all elements of 'a' into a set
        unordered_set<int> intersection;             // Store unique intersection elements
        // int count = 0;
        for (auto num : b) // geting the elements of 'b' one by one into 'num';
        {
            if (setA.find(num) != setA.end()) // checking if the nums are in setA or not;
            {
                if (intersection.find(num) == intersection.end()) // checking if the num is already in the intersection set or not;
                {
                    // count++;
                    intersection.insert(num); // if not, insert it into the intersection set;
                }
            }
        }
        // return intersection; //cannot return an unordered_set<int> directly as the function signature expects a vector<int>.
        return vector<int>(intersection.begin(), intersection.end()); // returning an unordered_set<int>
        return intersection.size();                                   // for GFG;
    }
};

// Asked In:Accolite Amazon Microsoft PayPal Rockstand