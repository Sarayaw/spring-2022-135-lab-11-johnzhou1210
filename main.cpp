#include <iostream>
#include "profile.h"
#include "network.h"
using std::cout;

int main() {
  cout << "========= TASK A ==========\n";
  Profile p1("marco123", "Marco");
  cout << "p1 Profile object created with usrn \"marco123\" and dspn \"Marco\".\n";
  cout << "p1.getUsername() returns: " << p1.getUsername() << "\n";
  cout << "p1.getFullName() returns: " << p1.getFullName() << "\n";
  p1.setDisplayName("Marco Polo");
  cout << "p1 full name after calling setDisplayName(\"Marco Polo\") is " << p1.getFullName() << "\n\n";

  Profile p2("johnzhou1210", "John Zhou");
  cout << "p2 Profile object created with usrn \"johnzhou1210\" and dspn \"John Zhou\".\n";
  cout << "p2.getUsername() returns: " << p2.getUsername() << "\n";
  cout << "p2.getFullName() returns: " << p2.getFullName() << "\n";
  p2.setDisplayName("周广翔");
  cout << "p2 full name after calling setDisplayName(\"周广翔\") is " << p2.getFullName() << "\n\n";

  Profile p3("8081337", "Bob");
  cout << "p3 Profile object created with usrn \"8081337\" and dspn \"Bob\".\n";
  cout << "p3.getUsername() returns: " << p3.getUsername() << "\n";
  cout << "p3.getFullName() returns: " << p3.getFullName() << "\n";
  p3.setDisplayName("Bobby Bobster");
  cout << "p3 full name after calling setDisplayName(\"Bobby Bobster\") is " << p3.getFullName() << "\n\n";

  cout << "========= TASK B ==========\n" << std::boolalpha;
  Network nw;
  cout << "nw.addUser(\"mario\", \"Mario\") returns: " << nw.addUser("mario", "Mario") << "\n";
  cout << "nw.addUser(\"mario\", \"Mario2\") returns: " << nw.addUser("mario", "Mario2") << "\n";
  cout << "nw.addUser(\"mario 2\", \"Mario2\") returns: " << nw.addUser("mario 2", "Mario2") << "\n";
  cout << "nw.addUser(\"mario-2\", \"Mario2\") returns: " << nw.addUser("mario-2", "Mario2") << "\n";

  cout << "Adding users until profile array is full.\n";
  for (int i = 1; i < 20; i++) {
    nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i));
  }

  cout << "nw profiles array is now full.\n";
  cout << "nw.addUser(\"Yoshi\", \"YoshiTurtle\") returns: " << nw.addUser("Yoshi", "YoshiTurtle") << "\n";

  cout << "========= TASK C ==========\n";
  cout << "This network is the provided Lab 11 example.\n";
  cout << "Calling printDot() this example network prints out:\n\n";
  Network nw2;
  // add three users
  nw2.addUser("mario", "Mario");
  nw2.addUser("luigi", "Luigi");
  nw2.addUser("yoshi", "Yoshi");

  // make them follow each other
  nw2.follow("mario", "luigi");
  nw2.follow("mario", "yoshi");
  nw2.follow("luigi", "mario");
  nw2.follow("luigi", "yoshi");
  nw2.follow("yoshi", "mario");
  nw2.follow("yoshi", "luigi");

  // add a user who does not follow others
  nw2.addUser("wario", "Wario");

  // add clone users who follow @mario
  for(int i = 2; i < 6; i++) {
      std::string usrn = "mario" + std::to_string(i);
      std::string dspn = "Mario " + std::to_string(i);
      nw2.addUser(usrn, dspn);
      nw2.follow(usrn, "mario");
  }
  // additionally, make @mario2 follow @luigi
  nw2.follow("mario2", "luigi");

  nw2.printDot();
  cout << "\n";
  cout << "========= TASK D ==========\n";
  cout << "This network is the provided Lab 11 example.\n";
  cout << "Below are the results after calling printTimeline as shown in the example: \n";
  Network nw3;
  // add three users
  nw3.addUser("mario", "Mario");
  nw3.addUser("luigi", "Luigi");
  nw3.addUser("yoshi", "Yoshi");

  nw3.follow("mario", "luigi");
  nw3.follow("luigi", "mario");
  nw3.follow("luigi", "yoshi");
  nw3.follow("yoshi", "mario");

  // write some posts
  nw3.writePost("mario", "It's a-me, Mario!");
  nw3.writePost("luigi", "Hey hey!");
  nw3.writePost("mario", "Hi Luigi!");
  nw3.writePost("yoshi", "Test 1");
  nw3.writePost("yoshi", "Test 2");
  nw3.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw3.writePost("mario", "My crazy plans always work!");
  nw3.writePost("yoshi", "Test 3");
  nw3.writePost("yoshi", "Test 4");
  nw3.writePost("yoshi", "Test 5");

  cout << "\n";
  cout << "======= Mario's timeline =======" << "\n";
  nw3.printTimeline("mario");
  cout << "\n";

  cout << "======= Yoshi's timeline =======" << "\n";
  nw3.printTimeline("yoshi");
  cout << "\n";
  cout << "========= END TESTS ==========\n";
  return 0;
}
