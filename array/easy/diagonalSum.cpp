#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    int primaryDiagonal(vector<vector<int>>& mat, int n ){
        int sum = 0;
        int row = 0 ;
        int col =0;


        while(row<n&& col <n){

            sum += mat[row][col];
            row ++;
            col++;
        }
        return sum;
    }


    int secondaryDiagonal(vector<vector<int>>& mat, int n ){
        int sum = 0;
        int row = 0 ;
        int col =n-1;

        if(n%2!=0){

        while(row<n&& col >=0){
            if(row == (n-1)/2 && col == (n-1)/2){
                row ++;
                col--;
            }
            else{
            
            sum += mat[row][col];
            row ++;
            col--;
            }
        }
        }


        else{

        while(row<n&& col <n){
            sum += mat[row][col];
            row ++;
            col--;

        }

      
    }
      return sum;
}
    int diagonalSum(vector<vector<int>>& mat) {
        
        int prisum =primaryDiagonal(mat ,  mat.size());

        int secsum = secondaryDiagonal(mat,mat.size());


        return prisum+secsum;
    }
};

int main(){
    return 0;
}