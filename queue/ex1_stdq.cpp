#include<iostream>
#include<queue>

int main(){
    std::queue<std::string> q;
    std::cout<<"Pushing element 'apple',\"banana\",\"chikoo\",\"dates\",\"figs\" to the queue";
    q.push("apple");
    q.push("banana");
    q.push("chikoo");
    q.push("dates");
    q.push("figs");
    std::cout<<"\nQueue front is "<<q.front();
    std::cout<<"\npop "<<q.front()<<" from the queue ";
    q.pop();
    std::cout<<"\nQueue front is now "<<q.front();
    std::cout<<"\ncheck if queue is empty <-- "<< (q.empty()==false?"False":"True");
    std::cout<<"\nsize of queue is "<<q.size();
    std::cout<<"\nlast elememnt added to queue is "<<q.back();

    
    return 0;
}