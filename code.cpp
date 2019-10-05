#include<iostream>
#include<vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;
void sudoku_populate(vii& arr,vi& row,vi& col,vii& mat)
{
    //to check whether we can place that value inn that position
    
     for(int i=0;i<9;i++){
      for(int j=0;j<9;j++)
      {
          int mask=1<<arr[i][j];
         if(arr[i][j]!=0)
         {
             row[i]|=mask;
             col[j]|=mask;
             mat[i/3][j/3]|=mask;
         }
      }
     }
}
void display(vector<vector<int> >&arr)
{
    for( vector<int> ar:arr)
    {
        for(int i:ar)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int sudoku_02(vii &arr,int idx,vi& row,vi& col,vii & mat)
{
if(idx==81)
{
    display(arr);
    cout<<endl;
    return 1;
}
int r=idx/9;
//here col size=9
int c=idx%9;

int count=0;
if(arr[r][c]==0){
for(int val=1;val<=9;val++){
    int mask=1<<val;
 if(((row[r] & mask)==0) && ((col[c] & mask)==0) && ((mat[r/3][c/3] & mask)==0) )
 {
    arr[r][c]=val;
    row[r]|=mask;
    col[c]|=mask;
    mat[r/3][c/3]|=mask;
     count+=sudoku_02(arr,idx+1,row,col,mat);
    arr[r][c]=0;
    row[r]^=mask;
    col[c]^=mask;
    mat[r/3][c/3]^=mask;
 }
    }

}
else
{
     count+=sudoku_02(arr,idx+1,row,col,mat);
}
return count;
}
int main(int args,char** argv)
{
    vii mat(3,vi(3,0));
    vi row(9,0);
    vi col(9,0);
   vii arr={{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
    sudoku_populate(arr,row,col,mat);
    cout<<sudoku_02(arr,0,row,col,mat);
}
