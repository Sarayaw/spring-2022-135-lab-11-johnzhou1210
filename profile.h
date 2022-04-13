#include <string>

class Profile {
private:
  std::string username;
  std::string displayname;
public:
  Profile(std::string usrn, std::string dspn); // Profile constructor for a user (initializing private variables: username = usern, displayname = dspn)
  Profile();   // Default Profile constructor (username="", displayname="")
  // accessor methods
  std::string getUsername();
  std::string getFullName(); // Return name in the format: "displayname (@username)"
  // mutator methods
  void setDisplayName(std::string dspn);
};
