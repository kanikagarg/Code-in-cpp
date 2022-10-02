#include<iostream>
#include<stack>

int main(){
  std::stack<std::string> st;
  std::cout<<"\nchecking is stack is empty :"<<(st.empty()==true?"True":"False");
  std::cout<<"\nPushing \"apple\", \"banana\", \"chikoo\", \"dates\", \"figs\" in order to stack";
  st.push("apple");
  st.push("banana");
  st.push("chikoo");
  st.push("dates");
  st.push("figs");
  std::cout<<"\n push successful";
  std::cout<<"\nchecking is stack is empty :"<<(st.empty()==true?"True":"False");
  std::cout<<"\n Stack has "<<st.size()<<" elements and "<<st.top()<<" is the element at top";
  
  while(st.empty()==false){
    std::cout<<"\nRemoving element from top : "<<st.top();
    st.pop();
    std::cout<<"\nRemoved successfully";
    if(st.empty()==true){
      std::cout<<"\nstack is now empty";
    }else{
      std::cout<<"\nTop element is now : "<<st.top()<<" Stack has now "<<st.size()<<" elements left in it.";
    }
  }
return 0;
}
