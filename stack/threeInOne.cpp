/**
 * @file threeInOne.cpp
 * @author Kanika Garg
 * @brief use single array to implement three stacks
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

class MyStacks{
    private:
        vector<int> st;
        int zTop, oTop, tTop;
    public:
        MyStacks(){
            st.clear();
            zTop = -3;
            oTop=-2;
            tTop=-1;
        }
        
        /**
         * @brief Print the stack from top to bottom
         * 
         * @param stackKey 
         */
        void printStack(int stackKey){
            int top=0;
            if(stackKey==1){
                top = zTop;
                cout<<"\nStack 1";
            }else if (stackKey==2){
                top = oTop;
                cout<<"\nStack 2";
            }else if (stackKey==3){
                top = tTop;
                cout<<"\nStack 3";
            }else top =-1;
            cout<<" Top-> ";
            while(top>=0){
                cout<<st[top]<<" ->";
                top-=3;
            }
            cout<<" bottom of stack\n";
        }//end of printStack method

        /**
         * @brief push a value val into the stack with stackkey ranges from 1-3
         * 
         * @param stackKey 
         * @param val 
         * @return true 
         * @return false 
         */
        bool push(int stackKey, int val){
            if(stackKey==1){
                //stack 1 with zTop
                if (zTop <0 and st.size()==1){
                    while(st.size()!=3){
                        st.push_back(-1);
                    }
                    zTop =0;
                    st[zTop]=val;
                } else {
                    if(zTop+3+1>st.size()){
                        for(int i=0; i<3; i++){
                            st.push_back(-1);
                        }
                    }
                    zTop+=3;
                    st[zTop]=val;
                }
            }else if(stackKey==2){
                //stack 2 with oTop
                if (oTop<0 and st.size()==0){
                    while(st.size()!=3){
                        st.push_back(-1);
                    }
                    oTop =1;
                    st[oTop]=val;
                } else {
                    if(oTop+3+1>st.size()){
                        for(int i=0; i<3; i++){
                            st.push_back(-1);
                        }
                    }
                    oTop+=3;
                    st[oTop]=val;
                }
            }else if(stackKey==3){
                // stack 3 with tTop
                if (tTop<0 and st.size()==0){
                    while(st.size()!=3){
                        st.push_back(-1);
                    }
                    tTop =1;
                    st[tTop]=val;
                } else {
                    if(tTop+3+1>st.size()){
                        for(int i=0; i<3; i++){
                            st.push_back(-1);
                        }
                    }
                    tTop+=3;
                    st[tTop]=val;
                }
            }else{
                cout<<"please choose the correct stack number from 1-3";
                return false;
            }
            return true;
        }

        bool pop(int stackKey){
            if(stackKey==1){
                if(zTop<0){
                    cout<<"Stack 1 underflow";
                    return false;
                }else{
                    zTop-=3;
                }
            }else if (stackKey==2){
                if(oTop<0){
                    cout<<"Stack 2 underflow";
                    return false;
                }else{
                    oTop-=3;
                }
            }else if (stackKey==3){
                if(tTop<0){
                    cout<<"Stack 3 underflow";
                    return false;
                }else{
                    tTop-=3;
                }
            }else return false;
            return true;
        }// end of pop method

        int peekTop(int stackKey){
            if(stackKey==1){
                if(zTop<0) return -1;
                else return st[zTop];

            }else if(stackKey==2){

                if(oTop<0) return -1;
                else return st[oTop];

            }else if(stackKey==3){

                if(tTop<0) return -1;
                else return st[tTop];

            }
        return -1;
        }// end of top method


        ~MyStacks(){
        }
};


int main()
{   
    MyStacks stack;
    stack.push(1,3);
    stack.push(1,4);
    stack.push(1,5);
    stack.push(2,3);
    stack.push(2,0);
    stack.printStack(1);
    stack.printStack(2);
    stack.printStack(3);
    stack.push(3,1);
    stack.push(3,2);
    stack.pop(1);
    cout<<"Top at s1 : "<<stack.peekTop(1);
    stack.printStack(1);
    stack.pop(1);
    stack.pop(2);
    stack.push(2,8);
    stack.printStack(1);
    stack.printStack(3);
    stack.printStack(2);
    stack.push(3,3);
    stack.push(2,3);
    stack.push(1,3);
    stack.printStack(3);
    stack.printStack(2);

    stack.printStack(1);
    
    return 0;
}