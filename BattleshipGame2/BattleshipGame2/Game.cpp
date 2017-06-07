#include <filesystem>
#include "Logger.h"
#include "GameManager.h"
#include "GameUtils.h"

using namespace std;

int main(int argc, char* argv[])
{
	int threads;
	string searchDir;
	GameUtils::getArgs(argc, argv, threads, searchDir);
	///check logger//
	Logger* logger = Logger::getInstance();
	//logger_ptr->init(path, "DEBUG");
	//logger_ptr->log("Test message", "ERROR");
	//logger_ptr->log("Test message2", "ERROR");
	//logger_ptr->destroy();
	string path = "";
	GameManager gameManager(path, 2);
	gameManager.init();

}
