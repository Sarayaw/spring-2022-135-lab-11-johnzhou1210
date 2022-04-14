#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "profile.h"
#include "network.h"
using std::cout;

TEST_CASE("TASK A") {
  Profile p1("marco123", "Marco");
  CHECK(p1.getUsername() == "marco123");
  CHECK(p1.getFullName() == "Marco (@marco123)");
  p1.setDisplayName("Marco Polo");
  CHECK(p1.getFullName() == "Marco Polo (@marco123)");

  Profile p2("johnzhou1210", "John Zhou");
  CHECK(p2.getUsername() == "johnzhou1210");
  CHECK(p2.getFullName() == "John Zhou (@johnzhou1210)");
  p2.setDisplayName("周广翔");
  CHECK(p2.getFullName() == "周广翔 (@johnzhou1210)");

  Profile p3("8081337", "Bob");
  CHECK(p3.getUsername() == "8081337");
  CHECK(p3.getFullName() == "Bob (@8081337)");
  p3.setDisplayName("Bobby Bobster");
  CHECK(p3.getFullName() == "Bobby Bobster (@8081337)");
}

TEST_CASE("TASK B") {
  Network nw;
  CHECK(nw.addUser("mario", "Mario") == true);
  CHECK(nw.addUser("mario", "Mario2") == false);
  CHECK(nw.addUser("mario 2", "Mario2") == false);
  CHECK(nw.addUser("mario-2", "Mario2") == false);
  for (int i = 1; i < 20; i++) {
    CHECK(nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) == true);
  }
  CHECK(nw.addUser("Yoshi", "YoshiTurtle") == false);
}

TEST_CASE("TASK C") {
  Network nw2;
  nw2.addUser("mario", "Mario");
  nw2.addUser("luigi", "Luigi");
  nw2.addUser("yoshi", "Yoshi");
  CHECK(nw2.follow("mario", "luigi") == true);
  CHECK(nw2.follow("mario", "yoshi") == true);
  CHECK(nw2.follow("luigi", "mario") == true);
  CHECK(nw2.follow("luigi", "yoshi") == true);
  CHECK(nw2.follow("yoshi", "mario") == true);
  CHECK(nw2.follow("yoshi", "luigi") == true);
  nw2.addUser("wario", "Wario");
  for(int i = 2; i < 6; i++) {
      std::string usrn = "mario" + std::to_string(i);
      std::string dspn = "Mario " + std::to_string(i);
      nw2.addUser(usrn, dspn);
      CHECK(nw2.follow(usrn, "mario") == true);
  }
  CHECK(nw2.follow("mario2", "luigi") == true);
}

TEST_CASE("TASK D") {
  Network nw3;
  nw3.addUser("mario", "Mario");
  nw3.addUser("luigi", "Luigi");
  nw3.addUser("yoshi", "Yoshi");
  nw3.follow("mario", "luigi");
  nw3.follow("luigi", "mario");
  nw3.follow("luigi", "yoshi");
  nw3.follow("yoshi", "mario");
  // write some posts
  CHECK(nw3.writePost("mario", "It's a-me, Mario!") == true);
  CHECK(nw3.writePost("luigi", "Hey hey!") == true);
  CHECK(nw3.writePost("mario", "Hi Luigi!") == true);
  CHECK(nw3.writePost("yoshi", "Test 1") == true);
  CHECK(nw3.writePost("yoshi", "Test 2") == true);
  CHECK(nw3.writePost("luigi", "I just hope this crazy plan of yours works!") == true);
  CHECK(nw3.writePost("mario", "My crazy plans always work!") == true);
  CHECK(nw3.writePost("yoshi", "Test 3") == true);
  CHECK(nw3.writePost("yoshi", "Test 4") == true);
  CHECK(nw3.writePost("yoshi", "Test 5") == true);
  CHECK(nw3.printTimeline("mario") == true);
  CHECK(nw3.printTimeline("yoshi") == true);
}
