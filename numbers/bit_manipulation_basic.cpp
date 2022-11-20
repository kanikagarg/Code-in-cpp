/**
 * @file bit_manipulation_basic.cpp
 * @author Kanika Garg
 * @brief 
 * @version 0.1
 * @date 2022-11-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Bit{
    public:
    /**
     * @brief Set the Ith Bit object
     * 
     * @param num 
     * @param i 
     * @return int 
     */
    int setIthBit(int num, int i){
        num |= (1<<i);
        return num;
    }

    /**
     * @brief Get the Ith Bit object
     * 
     * @param num 
     * @param i 
     * @return true 
     * @return false 
     */
    bool getIthBit(int num, int i){
        return ((num &(1<<i))!=0);
    }

    /**
     * @brief clear the ith bit, make it zero
     * 
     * @param num 
     * @param i 
     * @return int 
     */
    int clearIthBit(int num, int i){
        return num & ~(1<<i);
    }

    /**
     * @brief Return the string representing the number in 16 bit binary number
     * 
     * @param num 
     * @return string 
     */
    string binaryRepresentaton(int num){
        string binaryRepr;
        for(int i=15; i>=0;i--){
            binaryRepr.append(to_string(getIthBit(num,i)));
        }
        return binaryRepr;
    }


    /**
     * @brief Write a method to insert M into N such that M starts at bit j and ends at bit i.
     * @details you can assume that the bits j through i have enough space to fit all of M.
     *  That is, if M = 10011, you can assume that there are at least 5 bits between j and i.
     * You would not, for example, have j = 3 and i = 2, because M could not fully fit between 
     * bit 3 and bit 2.
     * EXAMPLE Input: N = 10000000000j M = 1 0 0 1 1 , i = 2, j = 6  Output: N = 10001001100
     * 
     * @param N  32-bit number
     * @param M 32-bit number
     * @param i bit position
     * @param j bit position (assuming  j >i)
     * @return int 
     */
    int insertion(int N, int M, int i, int j){
        int bitstartatm = 0;
        for(int b=31; b>=1; b--){
            if(getIthBit(M,b)==true){bitstartatm =b; break; }
        }
        if(bitstartatm > abs(j-i)){
            return 0;
        }else{
            // seting the jth bit in n to bth bit in m
            while(j>=i or bitstartatm>=0){
                // clear jth bit in n
                N=clearIthBit(N,j);
                //find bth bit from m
                if(getIthBit(M, bitstartatm)){
                    // set jth bit in n
                    N=setIthBit(N,j);
                }
                j--;
                bitstartatm--;
            };
        }
        return N;
    }


};

int main()
{
    Bit b;
    int num =5;
    cout<<"\n5 in binary:"<<b.binaryRepresentaton(num);

    int numneg =-5;
    cout<<"\n-5 in binary:"<<b.binaryRepresentaton(numneg);

    // updating the first bit
    int num4 = b.clearIthBit(num, 0);
    cout<<"\n num 4 is:"<<num4<<" binary:"<<b.binaryRepresentaton(num4);
    

     // updating the first bit
    int num5 = b.setIthBit(num4, 0);
    cout<<"\n num 5 is:"<<num5<<" binary:"<<b.binaryRepresentaton(num5);

    cout<<"\nExpected Insertion N = 10000000000  M = 10011 , i=2, j=6  Output: N = 10001001100 ";
    cout<<"\nExpected in decimal N =1024 M=19 ans= 1100";
    cout<<"\n input N "<<b.binaryRepresentaton(1024);
    cout<<"\n input M "<<b.binaryRepresentaton(19);
    cout<<"\nActual insertion n=1024, m=19, i=2, j=6 is : "<<b.insertion(1024, 19, 2, 6)<<" Binary: "<<b.binaryRepresentaton(b.insertion(1024, 19, 2, 6))<<endl;   
    return 0;
}