#include <Windows.h>
#include "auth.hpp"
#include <string>
#include <iostream>
#include <string>
#include <tchar.h>
#include <string.h>
#include <direct.h>
#include <ios>
#include <limits>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <sstream>
#include <string>
#include <urlmon.h>
#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <winuser.h>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <Wininet.h>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <windows.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <lmcons.h>
#include <random>
#include <iostream>
#include <process.h>
#include <fstream>
#include <iostream>
#include <string>
#include <tchar.h>
#include <string.h>
#include "driver.h"
#include "mapper.h"
#include "winuser.h"
#include "skStr.h"

/*Made by : ac#1337 */

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

using namespace KeyAuth;

std::string name = ""; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = ""; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = ""; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.1/";
std::string sslPin = "ssl pin key (optional)"; 

api KeyAuthApp(name, ownerid, secret, version, url, sslPin);

namespace Utilities
{
	bool ReadFileToMemory(const std::string& file_path, std::vector<uint8_t>* out_buffer);
	bool CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size);
}

bool Utilities::ReadFileToMemory(const std::string& file_path, std::vector<uint8_t>* out_buffer)
{
	std::ifstream file_ifstream(file_path, std::ios::binary);

	if (!file_ifstream)
		return false;

	out_buffer->assign((std::istreambuf_iterator<char>(file_ifstream)), std::istreambuf_iterator<char>());
	file_ifstream.close();

	return true;
}

bool Utilities::CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size)
{
	std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}

	file_ofstream.close();
	return true;
}

void HideConsole() // Hiding Console
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ShowConsole() // Showing Console
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

void driver()
{
	SetConsoleTitleA("Your Cheeto Name");

	system("taskkill /f /im explorer.exe");
	BlockInput(TRUE);
	auto mapper_path = ("C:\\Windows\\System32\\msfthost.exe"); // here its downloading the mapper

	std::vector<std::uint8_t> bytes = KeyAuthApp.download(""); // here you put the downlaod id from KeyAuth Panel
	std::ofstream file("C:\\Windows\\nvidia.sys", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
	Utilities::CreateFileFromMemory(mapper_path, reinterpret_cast<const char*>(mapper), sizeof(mapper)); // Mapper downlaoding.


	system("C:\\Windows\\System32\\msfthost.exe C:\\Windows\\nvidia.sys"); // Mapping Driver

	remove("C:\\Windows\\System32\\nvidia.sys");
	remove("C:\\Windows\\System32\\msfthost.exe");
	system("cls");
	BlockInput(FALSE);
	system("start C:/Windows/explorer.exe");
}

void uwu()
{
	SetConsoleTitleA("Your Cheeto Name");

	std::vector<std::uint8_t> bytes = KeyAuthApp.download(""); // here you put the downlaod id from KeyAuth Panel
	std::ofstream file("C:\\Windows\\calc1.exe", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();


	system("C:\\Windows\\calc1.exe");

	remove("C:\\Windows\\System32\\calc1.exe");
	system("cls");
}

void balls()
{
	system("cls");
	system("color 0");
	std::cout << skCrypt("\n\n Subscription expiry:") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry)));
	std::cout << skCrypt("\n -------------------------------------------------------------------------------");
	Sleep(5000);
	std::cout << skCrypt("\n");
	std::cout << skCrypt("\n Loading Da Cheat....");
	Sleep(5000);
	MessageBox(NULL, "Click OK to Start The Cheat. [ Make sure you are in Fortnite Alr]", "Question", MB_ICONINFORMATION | MB_OK);
	uwu();
}

void driber()
{
	SetConsoleTitleA("Your Cheeto Name");

	BlockInput(TRUE);
	auto mapper_path = ("C:\\Windows\\System32\\msfthost.exe");

	std::vector<std::uint8_t> bytes = KeyAuthApp.download("065911");
	std::ofstream file("C:\\Windows\\System32\\nvidia1.sys", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
	Utilities::CreateFileFromMemory(mapper_path, reinterpret_cast<const char*>(mapper), sizeof(mapper));


	system("C:\\Windows\\System32\\msfthost.exe C:\\Windows\\System32\\nvidia1.sys");

	remove("C:\\Windows\\System32\\ratio2.sys");
	remove("C:\\Windows\\System32\\msfthost.exe");
	system("cls");
	BlockInput(FALSE);
	balls();
}


void Fortnite()
{
	system("cls");
	system("color 0");
	std::cout << skCrypt("\n\n Subscription expiry:") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry)));
	std::cout << skCrypt("\n -------------------------------------------------------------------------------");
	Sleep(5000);
	std::cout << skCrypt("\n");
	std::cout << skCrypt("\n Loading Cheeto....");
	Sleep(5000);
	const int result = MessageBox(NULL, "Wanna Map the Driver? [Need to map only once]", "test title", MB_YESNO);

	switch (result)
	{
	case IDYES:
		driber(); // Going to map the driver
		break;
	case IDNO:
		balls(); // Going to download Cheeto
		break;
	}
}

void starting()
{
	system("cls");
	system("color 0");
	std::cout << skCrypt("\n\n Subscription expiry:") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry))); // When the Subscription gonna expire
	std::cout << skCrypt("\n -------------------------------------------------------------------------------");
	Sleep(5000);
	std::cout << skCrypt("\n");
	std::cout << skCrypt("\n Loading Swoofer....");
	Sleep(5000);
	MessageBox(NULL, "Click OK to Swoof.", "Question", MB_ICONINFORMATION | MB_OK);
	HideConsole();
	driver();
	MessageBox(NULL, "Everything was Succesfull , you are completly Swoofed", "Yay you`re are swoofed", MB_ICONEXCLAMATION | MB_OK);
	ShowConsole();
	system("cls");
	std::cout << skCrypt("\n");
	system("wmic diskdrive get serialnumber");
	Sleep(5000);

}


int main()
{
	SetConsoleTitleA(skCrypt("Your Cheeto Name"));
	KeyAuthApp.init();
	if (!KeyAuthApp.data.success)
	{
		Sleep(1500);
		exit(0);
	}

	system("cls");
	KeyAuthApp.check();

	int option;
	std::string key;

	system("color 9");
	std::cout << skCrypt("\n Enter license: "); // Enter Licente :bruh:
	std::cin >> key;
	KeyAuthApp.license(key);
	
	for (std::string subs : KeyAuthApp.data.subscriptions)
	{
		if (subs == "default") // Subscription Names
		{
			std::cout << skCrypt("\n You`re subscription its : Spoofer");
			starting();
		}
		if (subs == "Fortnite") // Subscription Names
		{
			std::cout << skCrypt("\n You`re subscription its : Fortnite");
			Fortnite();
		}
	}

	std::cin >> option;
	switch (option)
	{
	default:
		std::cout << skCrypt("\n\n Invalid Key , have a nice day.");
		Sleep(3000);
		exit(0);
	}

	std::cout << skCrypt("\n\n Closing in ten seconds...");
	Sleep(10000);
	exit(0);
}

std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
