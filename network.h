#include <string>
#include <iostream>
#include <vector>

struct Post {
  std::string username;
  std::string message;
};

class Network {
private:
  static const int MAX_USERS = 20;
  int numUsers;
  int findID(std::string usern);
  Profile profiles[MAX_USERS];
  bool following[MAX_USERS][MAX_USERS]; // friendship matrix:
 // following[id1][id2] == true when id1 is following id2
  static const int MAX_POSTS = 100;
  int numPosts; // number of posts
  Post posts[MAX_POSTS]; // array of all posts

public:
  Network();
  bool addUser(std::string usern, std::string dspn);
  bool follow(std::string usrn1, std::string usrn2);
  void printDot();
  bool writePost(std::string usrn, std::string msg);   // Add a new post
  bool printTimeline(std::string usrn); // Print user's "timeline"
  std::vector<std::string> getFollowing(Profile prof); // get users that this person follows given a network

};
