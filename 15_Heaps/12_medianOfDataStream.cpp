➡️ problemLinks --> https://leetcode.com/problems/find-median-from-data-stream/  && https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

✅USE ::
i> Streaming medians help monitor latency, response times, and sensor readings online, where a few extreme values could distort the average.
ii> The median is central to real-time signal and image processing, including median filters that reduce isolated noise while preserving edges.


✅ Brute Force --> 
class MedianFinder {
public:
    vector<int> nums;

    MedianFinder() {}

    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        // Brute force: sort all numbers whenever we need the median
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Odd number of elements → middle element
        if(n % 2 != 0) {
            return nums[n / 2];
        }

        // Even number of elements → average of two middle elements
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};

Time Complexity : O(n log n) for findMedian() due to sorting the array every time we need to find the median.

Space Complexity : O(n) for storing the numbers in the vector.


✅ Optimized Approach --> class MedianFinder { 
public: 
    priority_queue<int> leftMaxHeap; 
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; 
 
    MedianFinder() {} 
 
    void addNum(int num) { 
       if(leftMaxHeap.empty() || num < leftMaxHeap.top()) leftMaxHeap.push(num); 
       else rightMinHeap.push(num); 
 
       // Balance rule:
       // Left heap can have at most 1 extra element.
       // Even size  → both heaps have equal elements
       // Odd size   → left heap has exactly 1 extra element, not more than that.

       if(leftMaxHeap.size() > rightMinHeap.size() + 1){ // Left has 2+ extra elements, Move its largest element to the right heap.
            rightMinHeap.push(leftMaxHeap.top()); 
            leftMaxHeap.pop(); 
       
       }else if(rightMinHeap.size() > leftMaxHeap.size()){ // Right has more elements Move its smallest element to the left heap.
            leftMaxHeap.push(rightMinHeap.top()); 
            rightMinHeap.pop(); 
       } 
    } 
     
    double findMedian() {
//Or -> if(leftMaxHeap.size() == rightMinHeap.size()) return (double)(leftMaxHeap.top() + rightMinHeap.top())/2;
        if(leftMaxHeap.size() == rightMinHeap.size()) return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0; 
        else return leftMaxHeap.top(); 
    } 
};

Time Complexity : O(log n) for addNum() and O(1) for findMedian(). Overall --> O(n log n) 

Space Complexity : O(n) for storing the numbers in the heaps.


✅GFG version -->
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;
        vector<double> ansArray;
        
        for(int i = 0; i < arr.size(); i++){
            if(leftMaxHeap.empty() || arr[i] < leftMaxHeap.top()) leftMaxHeap.push(arr[i]);
            else rightMinHeap.push(arr[i]);
            
            if(leftMaxHeap.size() > rightMinHeap.size() + 1){
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            }else if(rightMinHeap.size() > leftMaxHeap.size()){
                leftMaxHeap.push(rightMinHeap.top());
                rightMinHeap.pop();
            }
            
            if(leftMaxHeap.size() == rightMinHeap.size()){
                double mean = (leftMaxHeap.top() + rightMinHeap.top())/2.0;
                ansArray.push_back(mean);
            }else{
                ansArray.push_back(leftMaxHeap.top());
            } 
        }
        return ansArray;
    }
};

Time Complexity : O(log n) for each insertion and O(1) for finding the median, overall -> O(n log n) 
Space Complexity : O(n) for storing the numbers in the heaps.

✅ Company Tags -->  Amazon - asked 9 times in the last 6 months
Intuit - asked 4 times in the last 6 months
Google - asked 3 times in the last 6 months
Adobe - asked 3 times in the last 6 months
Bloomberg - asked 3 times in the last 6 months
Apple - asked 3 times in the last 6 months
TikTok - asked 2 times in the last 6 months
Spotify - asked 2 times in the last 6 months
IXL - asked 2 times in the last 6 months
DE Shaw - asked 2 times in the last 6 months
Uber - asked 2 times in the last 6 months