/*Max Points on a Line Total Accepted: 26268 Total Submissions: 230552 My Submissions Question Solution 
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Author: Wencan Luo
Language: C++
Date: 12/07/2014
*/

#include<iostream>
using namespace std;

#include<vector>
#include<stack>
#include<string>
#include<map>
/**
 * Definition for a point.
**/

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPointsOne(vector<Point> &points, int k){
        map<double, int> M;
        
        int self = 0;
        int nonk = 0;
        for(int i=0;i<points.size();i++){
            if((points[i].x == points[k].x) && (points[i].y == points[k].y) ){
                self++;
            }
            else if(points[i].y == points[k].y){
                nonk++;
            }else{
                double s = (points[i].x - points[k].x)/double(points[i].y - points[k].y);
                if(M.find(s) != M.end()){
                    M[s]++;
                }else{
                    M[s] = 1;
                }
            }
        }
        
        //cout<<"s:";
        int maxP = 0;
        for (std::map<double,int>::iterator it=M.begin(); it!=M.end(); ++it){
            //cout<<it->second<<",";
            
            if(it->second > maxP){
                maxP = it->second;
            }
        }
        
        return max(maxP, nonk)+self;
    }
    
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if(n <= 2) return n;
        
        int maxN = 2;
        for(int i=0;i<n;i++){
            maxN = max(maxN, maxPointsOne(points, i));
        }        
        return maxN;
    }
};

int main(){
    Solution s;
    
    vector<Point> points;
    points.push_back(Point(-4,1));
    points.push_back(Point(-7,7));
    points.push_back(Point(-1,5));
    //points.push_back(Point(-4,1));
    
    cout << s.maxPoints(points)<<endl;
    //cout << s.maxPointsOne(points,0)<<endl;
    //cout << s.maxPointsOne(points,1)<<endl;
    //cout << s.maxPointsOne(points,2)<<endl;
    cout << "done";
}