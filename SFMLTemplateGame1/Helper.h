#ifndef HELPER_H
#define HELPER_H


#include <iostream>
#include <type_traits>
#include <Windows.h>
#include <fstream>
#include <string>

namespace Ref {
	template <typename T>
	using remove_cv_ref = typename std::remove_cv<typename std::remove_reference<T>::type>::type;

	template <typename T>
	using remove_ref = typename std::remove_reference<T>::type ;

};


namespace Utils
{
	static std::string getPathWorkingDirectory() {
		TCHAR paths[MAX_PATH];
		GetModuleFileName(NULL, paths, MAX_PATH);

		std::wstring temp(&paths[0]);

		std::string pathR(temp.begin(), temp.end());

		std::size_t found = pathR.find_last_of("/\\");
		return std::string(pathR.substr(0, found));
	}

	static std::string getWorkingDirectory() {
		TCHAR paths[MAX_PATH];
		GetModuleFileName(NULL, paths, MAX_PATH);

		std::wstring temp(&paths[0]);

		return std::string(temp.begin(), temp.end());

	}
}
#endif // !HELPER_H
