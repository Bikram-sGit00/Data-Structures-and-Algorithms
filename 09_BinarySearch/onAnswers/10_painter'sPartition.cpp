➡️ problemLinks --> https://leetcode.com/problems/split-array-largest-sum/  &&  https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

✅ Optimized Approach --> int countStud(vector<int>& books, int pages) {
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < books.size(); i++) {
        if (pagesStudent + books[i] <= pages) {
            pagesStudent += books[i];
        } else {
            students += 1;
            pagesStudent = books[i];
        }
    }
    return students;
}

int findPages(vector<int>& books, int students) {
    int n = books.size();
    if (students > n)
        return -1;
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int stud = countStud(books, mid);
        if (stud > students)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

class Solution {
public:
    int splitArray(vector<int>& nums, int k) { return findPages(nums, k); }
};

✅ Company Tags -->  Microsoft Google Codenation