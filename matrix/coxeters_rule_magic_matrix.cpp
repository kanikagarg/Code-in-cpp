/**
 * @file coxeters_rule_magic_matrix.cpp
 * @author Kanika Garg
 * @brief  Find the magic matrix of nxn. 
 * @details magic matrix is the matrix with sum of all diagnals, rows or columns all being same.
 * let sum be x of row 1 of nxn matrix
 * Sum of {r(i), c(j)} = x ( for j in range(0,n-1), i being constant) and (for each i in range(0, n-1), j constant)
 * and ( for i=j and i in range(0, n-1)) 
 * 
 * example
 * for n =3:
 * _______________
 * | 5 |  1 | 9  |
 * |___|____|____|
*  | 8 |  4 |  3 |
 * |___|____|____|
 * | 2 | 7  | 6  |
 * |___|____|____|
 * 
 * 5+1+9 = 15
 * 8+4+3 = 15
 * 2+7+6 = 15
 * 5+4+6 = 15
 * 2+4+9 = 15
 * 5+8+2 = 15
 * 1+4+6 = 15
 * 9+3+6 = 15
 * 
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include<math.h>

class Solution{
    public:
        /**
         * @brief magic matrix creates a magic matrix if n is odd and returns true. if n is even, it returns false as magic matrix cannot be created.
         * It prints all the steps if printSteps is set to True
         * @param n 
         * @param matrix 
         * @param  printSteps
                
         * @return bool
         */
        bool magic_matrix(int n, int ** matrix, bool printSteps=false){
            if(n%2 == 0){
                    return false;
            }
            // initialising matrix with 0
            for(int i=0; i<n;i++)
            for(int j=0; j<n; j++)
            matrix[i][j]=0;

            if(printSteps){
                cout<<"initial set to 0\n";
                print_matrix( n,matrix);
            }
            
            // setting first number in middle of top row
            int row=0, col =int(n/2), keyrow = row, keycol = col;
            matrix[row][col]=1;
            
            if(printSteps){
                cout<<"\n Step 1\n";
                print_matrix( n,matrix);
            }

            for(int i=2, n2 = n*n; i<=n2; i++){
                if(row>=1) row--;
                else row = n-1;

                if(col>=1) col--;
                else col=n-1;

                if(matrix[row][col]>0){
                    row =  ((row+2)%n);
                    col = ((col+1)%n);
                }

                matrix[row][col]=i;

                if(printSteps){
                    cout<<"\n Step "<<i<<"\n";
                    print_matrix( n,matrix);
                }

            }
            return true;
        }
        
        
        /**
         * @brief Check whether the given matrix is a magic matrix or not
         * 
         * @param n 
         * @param matrix 
         * @return true 
         * @return false 
         */
        bool is_magic_matrix(int n, int ** matrix){
            int sum=0, d1_sum=0, d2_sum=0;
            bool is_magic = true;
            // sum set to first row's elements sum
            for(int j=0;j<n;j++)
                sum+=matrix[0][j];

            // checking all other rows and column sum
            for(int i=0;i<n;i++)
            {   int row_sum=0, col_sum = 0;
                for(int j=0; j<n; j++){
                    row_sum+=matrix[i][j];
                    col_sum += matrix[j][i];
                }
                cout<<"\nRow sum for "<<i+1<<" row "<<row_sum;
                cout<<"\nCol sum for "<<i+1<<" col "<<col_sum;
                if(row_sum!=sum or row_sum!=col_sum or row_sum!=col_sum){
                    is_magic = false;
                }
                d1_sum += matrix[i][i];
                d2_sum += matrix[i][n-1-i];
            }
             cout<<"\nD1 sum: "<<d1_sum;
                cout<<"\nD2 sum : "<<d2_sum;
            if(d1_sum!=d2_sum or d1_sum!=sum or d2_sum!=sum){
                cout<<"D1 sum: "<<d1_sum<<" D2 sum:"<<d2_sum;
                is_magic= false;
            }

            return is_magic;
        }




        /**
         * @brief It prints the matrix on console
         * 
         * @param n 
         * @param matrix 
         */
        void print_matrix(int n, int ** matrix){
            for(int i=0; i<n; i++)
            {   for(int j=0; j<n; j++)
                {
                        int digits = floor(log10(n) + 1);
                        digits+=6;
                        while(digits-- >0){
                            cout<<"_";
                        }
                }
                cout<<"\n";
                for(int j=0; j<n; j++)
                    cout<<"|  "<<matrix[i][j]<<"  ";
                cout<<"|\n";
            }

            for(int j=0; j<n; j++)
            {
                        int digits = floor(log10(n) + 1);
                        digits+=6;
                        while(digits-- >0){
                            cout<<"_";
                        }
            }
            cout<<"\n";
        }
};

int main(){

    cout<<"\aPress 0 for printing the resultant magic matrix after creation \nor press 1 for printing all the steps to create the magic matrix: ";
    bool printsteps;
    cin>>printsteps;
    Solution sol;
    int n;

    cout<<"\nPlease enter value of n for creating nxn magic matrix: ";
    cin >> n;

    // to allocate the memory
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i)
     matrix[i] = new int[n];
    
    
    
    
    int res = sol.magic_matrix( n, matrix, printsteps);
    if(res == true)
    {
        if(printsteps==false)
            sol.print_matrix(n,matrix);

        cout<<"\nChecking whether the matrix is actually a magic matrix or not...\n\n";
        cout<<(sol.is_magic_matrix(n,matrix)==true?"\n\nYay! Yes it is a magic matrix": "\n\nOOPS! the resultant matrix is not actually a magic matrix. Something went wrong!");

    }else cout<<"\nCannot create a magic matrix with even n; "<<n<<" is even.";
    

    // to deallocate the memory
    for (int i = 0; i < n; ++i)
        delete [] matrix[i];
    delete [] matrix;

    cout<<"\nExit";
    
    return 0; 
    // end of main method  
}