#include "Auth.h"
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <ctime>

#define PUBLIC_KEY "public_key"

int main() {
	string key;
	cout << "[+] Enter key: ";
	getline(cin, key);
	auto response = myauth::authenticate(key, PUBLIC_KEY);

	if (response->Error == success) 
	{
		if (myauth::verify_integrity()) 
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)AntiJMP, (LPVOID)response, 0, 0);
			cout << "App-name: " << response->User->app_name << endl;
			cout << "License key: " << response->User->license << endl;
			cout << "Expiry: " << response->User->expiry << endl;
			cout << "Duration: " << response->User->duration << " days" << endl;
			cout << "Created at: " << response->User->creation_date << endl;
			cin.get();
		}
		else 
			exit(5);
	}
	else 
	{
		switch (response->Error) 
		{
			case must_restart:
				cout << "[~] Please restart application!" << endl;
				break;
			case hwid:
				cout << "[-] Invalid HWID!" << endl;
				break;
			case internal_server:
				cout << "[-] Internal server error - Restart application!" << endl;
				break;
			case expired:
				cout << "[-] Your license has expired!" << endl;
				break;
			case no_exist:
				cout << "[-] We couldn't find that license!" << endl;
				break;
		}
	}
	cin.get();
}
