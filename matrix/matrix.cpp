#include<vector>
#include<iostream>

template <typename T>
class Matrix{
    public:
        void print(std::vector<std::vector<int>> m){
            std::cout << std::endl;
            for(int r=0; r<m.size(); r++){
                for( int c=0; c<m[0].size(); c++){
                    std::cout << m[r][c] << "\t";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        void spiralordermatrix(std::vector<std::vector<int>> m){
            std::vector<int> spr;
            int arrsize = m.size()*m[0].size();
            int row=0, col=0, colstart=0, rowstart=0, colend=m[0].size(), rowend=m.size();
            bool right= true;
            bool down = false;
            while(spr.size()<arrsize){
                col = colstart;
                row = rowstart;

                while (right and col<colend and col>=colstart and spr.size()<arrsize){
                    spr.push_back(m[row][col++]);
                };
                if(spr.size()==arrsize){
                    break;
                }
                down = true;
                right = false;
                rowstart++;  
                
                while(down and ++row<rowend and row>=rowstart and spr.size()<arrsize){
                    spr.push_back(m[row][colend-1]); 
                };

                if(spr.size()==arrsize){
                    break;
                }
                right =  false;
                down = false;
                colend--;
                col = colend;
                while( (!right) and --col>=colstart and spr.size()<arrsize ){
                    spr.push_back(m[rowend-1][col]);
                };

                if(spr.size()==arrsize){
                    break;
                }
                rowend--;
                row--;
                while((!down) and --row>=rowstart and spr.size()<arrsize){
                    spr.push_back(m[row][colstart]);
                };

                if(spr.size()==arrsize){
                    break;
                }
                colstart++;
                right = true;
                rowstart = row+1;

            }
            std::cout <<std::endl <<  "Spiral order is ";
            for(int r=0; r<spr.size(); r++){
                std::cout  << " -> " << spr[r];
            }
            std::cout << std::endl;
        }
};

int main(){
    Matrix<int> *mtr= new Matrix<int>() ;
    std::vector<std::vector<int>> m;
    
    
    for(int j=0,k=0; j<4;j++){ 
        std::vector<int> row;
        for(int i=0; i<4;i++){ 
            row.push_back(++k);
        }
        m.push_back(row);
    }
    mtr->print(m);
    mtr->spiralordermatrix(m);
    delete mtr;
    return 0;
}