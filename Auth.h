#include <string>

using namespace std;

enum errors : int {
	expired = 1,
	no_exist = 2,
	hwid = 3,
	must_restart = 4,
	success = 5,
	internal_server = 6
};

class License {
public:
	string app_name;

	string license;
	string expiry;
	int duration;
	string creation_date;
};

class Response {
public:
	License* User;
	errors Error;

	Response(errors err) {
		this->Error = err;
	}
	Response(errors err, License* license) {
		this->Error = err;
		this->User = license;
	}
};
namespace myauth {
	bool verify_integrity();
	Response* authenticate(string token, string program_id);
}