/**
 * @file stacksOfStack.cpp
 * @author piles of stack
 * @brief 
 * @version 0.1
 * @date 2022-11-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

template <typename T>
    class StacksStack{
        private:

        public:

            vector<stack<T>> stacks;
            int threshhold;

            StacksStack(int d){
                stacks.clear();
                threshhold=d;
            }
            int get_threshold(){
                return threshhold;
            }

            int total_size(){
                int scount = stacks_count();
                if(scount>0)
                    return ((scount-1)*threshhold + stacks[scount-1].size());
                return 0;
            }

            int stacks_count(){
                return stacks.size();
            }

            void push(T data){
                int szStack = stacks.size();
                if(szStack==0){
                    cout<<"\n creating stackpile 1";
                    stack<T> ns;
                    ns.push(data);
                    // add stack to pile of stacks
                    stacks.push_back(ns);
                    std::cout<<"\nadded "<<data<<" to stack pile "<<stacks.size();
                }else{
                    std::cout<<"\n size of current stackpile is "<<stacks[szStack-1].size();
                    if(stacks[szStack-1].size()<threshhold){
                        stacks[szStack-1].push(data);
                        std::cout<<"\n added "<<data<<" to stack pile "<<szStack;
                    }else{

                        cout<<"\n creating stackpile "<<szStack+1;
                        stack<T> ns;
                        ns.push(data);
                        stacks.push_back(ns);
                        std::cout<<"\nadded "<<data<<" to stack pile "<<stacks.size();
                    }
                }
            }// end of push method
            
            bool pop(){
                int szStacks = stacks.size();
                if(szStacks==0){
                    std::cout<<"Stack empty";
                    return false;
                }

                else{
                    std::cout<<"\n pop from stack pile :"<< stacks.size()<<" element :" <<stacks[stacks.size()-1].top();
                    stacks[stacks.size()-1].pop();
                    if(stacks[stacks.size()-1].size()==0) 
                        stacks.resize(stacks.size()-1);
                }
                return true;
            }// end of pop method
            
            T top(){
                int szStack = stacks.size();
                if(szStack==0){
                    std::cout<<"Stack empty";
                }else{
                    stack<T> latestStack= stacks[szStack-1];

                    std::cout<<"\n top from stack pile "<<stacks.size()+1<<"is "<<latestStack.top();
                    return latestStack.top();
                }
            }// end of top method
    };

    int main(){
        StacksStack<int> ss(5);
        cout<<" threshold for stacks is "<<ss.get_threshold();
        ss.push(1);
        ss.push(2);
        ss.push(3);   
        ss.push(4);
        ss.push(5);
        ss.push(5);
        ss.push(6);
        ss.push(7);
        ss.push(8);
        ss.push(9);
        ss.push(10);
        ss.push(11);
        ss.push(12);
        ss.push(13);
        ss.push(14);
        ss.push(15);
        std::cout<<"\n Size of stack is "<<ss.total_size();
        std::cout<<"\n number of stacks "<<ss.stacks_count();
        std::cout<<"\n\n\n now removing all elements\n";
        int count =ss.total_size();
        while(count-->0){
            ss.pop();
        }
        std::cout<<"\n Size of stack is "<<ss.total_size();
        std::cout<<"\n number of stacks "<<ss.stacks_count()<<std::endl;
        return 0;
    }