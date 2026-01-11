➡️ problemLinks --> https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

✅ Brute Force -->  

✅ Optimized Approach --> #include <bits/stdc++.h>
int countStud(vector<int> &books, int pages){
    int students =1;
    long long pagesStudent = 0;
    for(int i=0;i<books.size();i++){
        if(pagesStudent + books[i] <= pages){
            pagesStudent += books[i];
        }
        else{
            students+=1;
            pagesStudent = books[i];
            
        }
    }
    return students;
    
}


class Solution {
  public:
    int findPages(vector<int> &books, int students) {
        int n = books.size();
        if (students > n) return -1;
        int low = *max_element(books.begin(),books.end());
        int high = accumulate(books.begin(),books.end(),0);
        while(low<=high){
            int mid =(low+high)/2;
            int stud = countStud(books,mid);
            if(stud>students) low= mid+1;
            else high = mid-1;
        }
        return low;
    }
};

// Time Complexity: O(log base 2 (sum - max)) + )O(n)) where n is the number of books, sum is the total number of pages in all books and max is the maximum number of pages in a single book.
// Space Complexity: O(1) as we are not using any extra space to solve this problem.

✅ Company Tags -->  Infosys Amazon Microsoft Google Codenation Uber