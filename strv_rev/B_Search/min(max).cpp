// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution {
  public:
  
  int check(vector<int>&arr, int mid, int k) {
     int student = 1, presum = 0 ;
     for(int i=0 ; i< arr.size(); i++) {
      if(presum+arr[i]<=mid) {
        presum+=arr[i];
      }
      else {
     student+=1;
      presum=arr[i];
      }
     }
    return student;
  }
  
    int minTime(vector<int>& arr, int k) {
     int n = arr.size();
     
     if(k>n) return -1;
     
     int l = *max_element(arr.begin(),arr.end());
     int r = accumulate(arr.begin(), arr.end(),0);
     
     
     while(l<=r) {
     int mid = l +(r-l)/2;
     int std = check(arr, mid, k);
     if(std>k){
     l=mid+1;
     }
     else r = mid-1 ;
     }
    
    return l;
    }
};
