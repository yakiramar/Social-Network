#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Member{
    private:
       static int counter;//count of members 
       vector<Member*> followers;//array of followers.
       vector<Member*> I_follow;//array of members that i follow.
       int m_numFollowing;//count of members that i followe
       int m_numFollowers;//count of number that followe after me
    public:
      
       Member();//
       ~Member();
       void follow(Member &i_want_follow_after);
       void unfollow(Member &i_want_unfollow);
       int numFollowers();
       int numFollowing();
       static int count();
       
};
