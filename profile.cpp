#include "profile.h"
#include <string>

Profile::Profile() {
  username = "";
  displayname = "";
}

Profile::Profile(std::string usrn, std::string dspn) {
  username = usrn;
  displayname = dspn;
}

std::string Profile::getUsername() {
  return username;
}

std::string Profile::getFullName() {
  return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(std::string dspn) {
  displayname = dspn;
}
