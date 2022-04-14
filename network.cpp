#include <string>
#include <iostream>
#include "profile.h"
#include "network.h"
#include <vector>
using std::cout;

bool isAlphanumeric(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    char currChar = str[i];
    // integer values from ASCII table
    bool isAlpha = (currChar >= 65 && currChar <= 90) || (currChar >= 97 && currChar <= 122);
    bool isNumeric = currChar >= 48 && currChar <= 57;
    if (isAlpha || isNumeric) {
      // do nothing
    } else {
      return false;
    }
  }
  return true;
}

int Network::findID(std::string usern) {
  for (int i = 0; i < MAX_USERS; i++) {
    Profile currProf = profiles[i];
    if (currProf.getUsername() == usern) {
      return i;
    }
  }
  return -1;
}

Network::Network() {
  numUsers = 0;
  numPosts = 0;
  for (int i = 0; i < MAX_USERS; i++) {
    for (int j = 0; j < MAX_USERS; j++) {
      following[i][j] = false;
    }
  }
}

bool Network::addUser(std::string usern, std::string dspn) {
  if (usern == "" || numUsers >= MAX_USERS || findID(usern) != -1 || !isAlphanumeric(usern)) {
    return false; // cannot add any more users!
  }
  numUsers = numUsers + 1; // update number of users counter
  // Now we know that accessing the index shouldn't error
  profiles[numUsers - 1] = Profile(usern, dspn);
  // findID should with usern here should be equal to numUsers now
  // std::cout << std::boolalpha << (findID(usern) == numUsers) << "\n";
  // std::cout << "numUsers now " << std::to_string(numUsers) << '\n';

  return true;
}

// Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
// return true if success (if both usernames exist), otherwise return false
bool Network::follow(std::string usrn1, std::string usrn2) {
  if (findID(usrn1) == -1 || findID(usrn2) == -1) {
    return false;
  }
  following[findID(usrn1)][findID(usrn2)] = true;
  return true;
}

int indexOf(std::vector<std::string> arr, std::string elem) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == elem) {
      return i;
    }
  }
  return -1;
}

// Print Dot file (graphical representation of the network)
void Network::printDot() {
  std::vector<std::string> usernames = {};
  cout << "digraph {\n";
  for (int i = 0; i < MAX_USERS; i++) {
    for (int j = 0; j < MAX_USERS; j++) {
      if (following[i][j]) {
        std::string usrnI = profiles[i].getUsername(), usrnJ = profiles[j].getUsername();
        if (indexOf(usernames, usrnI) == -1) {
          usernames.push_back(usrnI);
        }
        if (indexOf(usernames, usrnJ) == -1) {
          usernames.push_back(usrnJ);
        }
      }
    }
  }

  for (auto elem : usernames) {
    cout << "\t\"@" << elem << "\"\n";
  }
  cout << "\n";
  for (int i = 0; i < MAX_USERS; i++) {
    for (int j = 0; j < MAX_USERS; j++) {
      bool currElem = following[i][j];
      if (currElem) {
        Profile profI = profiles[i], profJ = profiles[j];
        std::string identifierI = "\t\"@" + profI.getUsername(), identifierJ = "@" + profJ.getUsername();
        cout <<  identifierI << "\" -> \"" << identifierJ << "\"\n";
      }
    }
  }
  cout << "}\n";
}

std::vector<std::string> Network::getFollowing(Profile prof) {
  std::vector<std::string> result;
  for (int i = 0; i < numUsers; i++) {
    for (int j = 0; j < numUsers; j++) {
      Profile follower = profiles[i];
      Profile followed = profiles[j];
      if (follower.getUsername() == prof.getUsername() && following[i][j]) {
        // cout << "follower username is " << follower.getUsername() << " and followed username is " << followed.getUsername() << "\n";
        result.push_back(followed.getUsername());
      }
    }
  }
  return result;
}

bool Network::writePost(std::string usrn, std::string msg) {
  if (findID(usrn) == -1 || numPosts >= MAX_POSTS) {
    return false;
  }
  numPosts = numPosts + 1;
  posts[numPosts - 1] = {usrn, msg};
  return true;
}

void printV(std::vector<std::string> v) {
  for (auto x : v) {
    cout << x << "\n";
  }
}

bool Network::printTimeline(std::string usrn) {
  if (findID(usrn) == -1) {
    return false;
  }
  for (int i = numPosts; i >= 0; i--) {
    Post currPost = posts[i];
    int posterID = findID(currPost.username);
    int usrID = findID(usrn);
    Profile usrProf = profiles[usrID];
    Profile posterProf = profiles[posterID];
    std::vector<std::string> posterFollowing = getFollowing(usrProf);
    // cout << "size of posterFollowing vector is " << posterFollowing.size() << "\n";
    // printV(posterFollowing);
    if (currPost.username == usrn || indexOf(posterFollowing, currPost.username) != -1) {
      cout << posterProf.getFullName() << ": " << currPost.message << "\n";
    } else {
      // do nothing
    }
  }
  return true;
}
