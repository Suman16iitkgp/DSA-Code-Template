/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return 
the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return qSelect(points, k);
    }
private:
    vector<vector<int>> qSelect(vector<vector<int>>& points, int k) {
        int left = 0, right = int(points.size())-1;
        int pivotIndex = int(points.size());

        while( pivotIndex != k ){
            pivotIndex = partition(points, left, right);
            if( pivotIndex < k ){
                left = pivotIndex;
            }else{
                right = pivotIndex-1;
            }
        }

        return vector<vector<int>>(points.begin(), points.begin()+k);
    }

    int partition(vector<vector<int>>& points, int left, int right){
        int pivotIndex = findPivotIndex(left, right);
        int pivotDis = calculateDistance(points[pivotIndex]);

        while( left < right ){
            if( calculateDistance(points[left]) < pivotDis ){
                left++;
            }else{
                swap(points[left], points[right]);
                right--;
            }
        }

        if( calculateDistance(points[left]) < pivotDis ){
            left++;
        }

        return left;
    }

    int findPivotIndex(int l, int r){
        return l+(r-l)/2;
    }
    
    int calculateDistance(vector<int> cur){
        int dis = 0;
        dis += cur[0]*cur[0];
        dis += cur[1]*cur[1];

        return dis;
    }

};