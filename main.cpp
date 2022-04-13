#include <iostream>
#include "profile.h"
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

  Profile p3("8081337", "Bob Bobster");
  cout << "p3 Profile object created with usrn \"8081337\" and dspn \"Bob\".\n";
  cout << "p3.getUsername() returns: " << p3.getUsername() << "\n";
  cout << "p3.getFullName() returns: " << p3.getFullName() << "\n";
  p3.setDisplayName("Bobby Bobster");
  cout << "p3 full name after calling setDisplayName(\"Bobby Bobster\") is " << p3.getFullName() << "\n";

  cout << "========= TASK B ==========\n";
  return 0;
}
