#include<iostream>
#include "Member.h"
#include<string>
#include<vector>
using namespace std;


int Member:: counter = 0;
Member::Member(){
    counter++;
    m_numFollowers=0;
    m_numFollowing=0;
}
Member::~Member(){
    if(counter>0)
    {counter--;
    for(int i=0;i<m_numFollowers;i++)
    {
        followers[i]->unfollow(*this);
    }
    for(int i=0;i<m_numFollowing;i++)
    {
        unfollow(*I_follow[i]);
    }
    }
}
void Member::follow(Member &i_want_follow_after){
    int i;
    bool flag=true;
    for(i=0;i<I_follow.size();i++){
        if(I_follow[i]==&i_want_follow_after){
        i=I_follow.size();
        flag=false;
      }
    }
    
    if(flag){
   i_want_follow_after.followers.push_back(this);
   i_want_follow_after.m_numFollowers++;
 

   I_follow.push_back(&i_want_follow_after);
  m_numFollowing++;
   
  
    }
}

void Member::unfollow(Member &i_want_unfollow){
    int i;
    for(i=0;i<I_follow.size();i++){
    if(I_follow[i]==&i_want_unfollow){
        I_follow.erase(I_follow.begin()+i);
        m_numFollowing--;
        
    }
    
    }
    
    for(i=0;i<i_want_unfollow.followers.size();i++){
    if(i_want_unfollow.followers[i]==this){
        i_want_unfollow.followers.erase(i_want_unfollow.followers.begin()+i);
        i_want_unfollow.m_numFollowers--;
    }
    
    }
}

int Member:: numFollowers(){//number of followers
 return m_numFollowers;   
}
int Member:: numFollowing(){//number of member
return m_numFollowing;
    
}
int Member:: count(){

    return counter;

}








