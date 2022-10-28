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
        std::vector<std::vector<int>> rotateMatrixClockwise( std::vector<std::vector<int>> Mat) {
            int sz= Mat.size()*Mat[0].size();
            int k=0;
            int rs=0,re=Mat.size()-1; //re = row end
            int cs=0,ce=Mat[0].size()-1; //cs = col start
            // flags to define the rotational direction for clockwise shifting
            bool colleft=false;
            bool colright=true;
            bool rowup=false;
            bool rowdown=true;
            
            // value to save when to update the matrix start and end indices
            int dir=0;
            // temprary storing the value for swapping
            int tempstore = Mat[rs][ce];
            
            // run atleast once
            do{
                // if single element in the matrix
                if(rs==re and cs==ce){
                    // single element matrix, returning
                    break;        
                }
                // else if( re==rs+1 and ce==cs+1){
                //     // matrix is of size 2x2 
                //     Mat[rs][ce] = Mat[rs][cs];
                    
                //     // swapping temp with end row's ending column's cell value
                //     Mat[re][ce] += tempstore;
                //     tempstore = Mat[re][ce] - tempstore;
                    
                //     // swapping temp with end row's starting column's cell value
                //     Mat[re][cs] += tempstore;
                //     tempstore = Mar[re][cs] - tempstore;
                    
                //     // saving last unchanged value
                //     Mat[rs][cs] = tempstore;
                    
                //     break;
                // }else {
                    // matrix is more than 2x2 matrix
                    
                    // shifting first row
                    if (colright){
                     // shifting values to the right
                         for(int j=ce; j>cs; j--){
                            Mat[rs][j]=Mat[rs][j-1];
                            ++k;
                         }    
                        colright=false;
                        rowdown=true;
                    }else  if(rowdown){
                        // shifting values downwards
                        int tempstore2 = Mat[re][ce];
                        for(int i=re; i>rs; i--){
                            Mat[i][ce]=Mat[i-1][ce];
                            ++k;
                        } 
                        Mat[rs+1][ce]=tempstore;   // saving tempstore to the next row's last column
                        tempstore=tempstore2; 
                        rowdown=false;
                        colleft=true;
                    }else if (colleft){
                        // shifting values to the left
                        int tempstore2 = Mat[re][cs];
                        for(int j=cs; j<ce; j++){ //moving one cell left till start
                            Mat[re][j]=Mat[re][j+1];
                            ++k;
                        }
                        Mat[re][ce-1]=tempstore;
                        tempstore = tempstore2;
                        colleft=false;
                        rowup=true;
                    }else if(rowup){
                        // shifting values up
                        for(int i=rs; i<re; i++){
                            Mat[i][cs]=Mat[i+1][cs];
                        ++k;
                        }
                        Mat[re-1][cs]=tempstore;
                        rowup=false;
                        colright=true;
                    }
                // } // end of if for greater than 2x2 matrix
                
                //one time direction traversed
                dir++;
                // moved all four directions when its 5 i.e when outer layer rotated
                // now setting params to rotate inner layer
                
                if(dir%5==0){
                    dir=0;
                    // moved outer layer time to rotate inner layers if any
                    cs++; rs++; ce--; re--;
                    // update tempstore when two rows and two columns at least
                    if(rs!=re and cs!=ce){
                        // initially have first end
                        tempstore = Mat[rs][ce];
                    }
                } //end of directional block
                
            }while (k<sz);

            return Mat;
    }

        std::vector<std::vector<int>> rotateMatrix(int M, int N, std::vector<std::vector<int>> Mat) {
        
            int sz= Mat.size()*Mat[0].size();
            int i=0,j=0,k=0;
            int rs=0,re=M-1;
            int cs=0,ce=N-1;
            bool colleft=false;
            bool colright=true;
            bool rowup=false;
            bool rowdown=true;
            int dir=0;
            int tempstore = Mat[rs][ce];
            // int tempstore = Mat[rs+1][cs];
            std::cout<<"\n Printing rotated matrix";
            // i,j stands for current element
            do{
                dir++;
                if(dir%5==0){
                    // moved outer layer
                    // time to move inner layers if any
                    cs++;
                    rs++;
                    ce--;
                    re--;
                    if(rs!=re){
                        tempstore = Mat[rs][ce];
                    }
                }
                
                if(rs==re and cs==ce){
                    break;        
                }
                
                
                if (colright){
                    if(cs+1==ce){
                        
                        Mat[rs][ce]=Mat[rs][cs];
                        Mat[rs][cs]=Mat[rs+1][cs];

                    }else {
                    
                        // moving cell from left to rignt
                        for(j=ce; j>cs; j--){
                            Mat[rs][j]=Mat[rs][j-1];
                            ++k;
                        }    
                        // // moving element just below the first col of the row
                        if(cs!=ce){
                        //    std::cout<<"\ntempstore for right "<<Mat[rs+1][cs];
                            Mat[rs][cs]=Mat[rs+1][cs];
                            ++k;
                        }
                    }
                    // now to traverse cell -- downwards in last column
                    colright=false;
                    rowdown=true;
                }else 
                if(rowdown){
                    // tempstore contains data to add to second cell in the column
                    int tempstore2 = Mat[re][ce];
                    if(rs+1==re){
                        // row start and column end is already set 
                        Mat[re][ce]=tempstore;

                    }else {
                    
                    
                        //moving one cell down till end
                        for(i=re; i>rs+1; i--){
                        Mat[i][ce]=Mat[i-1][ce];
                        ++k;
                        }
                        // moved the data in temp storage
                        if(rs!=re){

                        std::cout<<"\ntempstore for down "<<tempstore;
                        Mat[rs+1][ce]=tempstore;
                        ++k;
                        }
                    }

                    tempstore = tempstore2;
                    rowdown=false;
                    colleft=true;
                    
                }else
                if (colleft){
                    
                    // tempstore contains data of first cell in the row
                    int tempstore2 = Mat[re][cs];
                    if(rs+1==re){
                        // row end and col end already set
                        Mat[re][cs]=tempstore;

                    }else {
                        //moving one cell left till start
                        for(j=cs; j<ce-1; j++){
                        Mat[re][j]=Mat[re][j+1];
                        ++k;
                        }
                        // moved the data in temp storage
                        if(cs!=ce){

                        std::cout<<"\ntempstore for left "<<tempstore;
                        Mat[re][ce-1]=tempstore;
                        ++k;
                        }
                    }
                    tempstore = tempstore2;
                    
                    colleft=false;
                    rowup=true;
                }else if(rowup){
                    if(rs+1!=re)
                        
                    {
                         //moving one cell up till start
                        for(i=rs; i<re; i++){
                        Mat[i][cs]=Mat[i+1][cs];
                        ++k;
                        }

                        
                        // moved the data in temp storage
                        if( re!=rs){
                            std::cout<<"\ntempstore for up"<<tempstore; 
                            Mat[re-1][cs]=tempstore;
                        ++k;
                        }
                    }
                    
                    rowup=false;
                    colright=true;
                };
            }while (k<sz);

            std::cout<<"\n";
            for(int a=0;a<Mat.size();a++){
                for(int p=0;p<Mat[0].size();p++){
                    std::cout<<"\t"<<Mat[a][p];
                }
                std::cout<<std::endl;
            }
            return Mat;
    }
};

int main(){
    Matrix<int> *mtr= new Matrix<int>() ;
    std::vector<std::vector<int>> m;
    int n;
    std::cout<<" N for N*N matrix";
    std::cin>>n;
    for(int j=0,k=0; j<n;j++){ 
        std::vector<int> row;
        for(int i=0; i<n;i++){ 
            row.push_back(++k);
        }
        m.push_back(row);
    }
    mtr->print(m);
    mtr->spiralordermatrix(m);
    // mtr->rotateMatrix(n,n,m);
    m = mtr->rotateMatrixClockwise(m);

    mtr->print(m);

    // mtr->print(m);
    
    delete mtr;
    return 0;
}