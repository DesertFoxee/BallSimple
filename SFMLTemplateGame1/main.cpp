#include <iostream>

//
#include "Game.h"
//
//#include "Helper.h"
//#include <sstream> 


//void loadPath(const std::string & path_file) {
//	std::ifstream paths;
//	std::string pathDir = Utils::getPathWorkingDirectory();
//	paths.open(pathDir + path_file);
//
//	if(paths.is_open()) {
//		std::string line;
//		while(std::getline(paths , line)) {
//			 std::stringstream keystream(line);     
//			 std::string pathName;      
//			 std::string path;      
//			 keystream >> pathName;      
//			 keystream >> path;
//			 std::cout << pathName<< " ..... " << path << std::endl;
//		}
//		paths.close();
//	}
//	else {
//		std::cerr << "! [Failed] Loading file the path file : "
//			+ pathDir + path_file;
//	}
//}



int main()
{
	Game game(SCREEN_WIDTH, SCREEN_HEIGHT, "new Game");

	game.run();

	//loadPath("\\Assets\\image\\image1.jpg");

	
	//getchar();

}
