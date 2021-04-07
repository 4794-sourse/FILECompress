#include "../_include/FileCompress.h"

void show_list() {
	std::cout << "Please select an action:" << std::endl;
	std::cout << std::endl;
	std::cout << "0.Exit" << std::endl;
	std::cout << "1.Compress" << std::endl;
	std::cout << "2.Decompress" << std::endl;
	std::cout << std::endl;
}

void run() {
	show_list();
	int ctl = 1;

	while (ctl) {
		std::cout << "Please Choice: " << std::endl;
		std::cin >> ctl;
		std::string file;
		switch (ctl) {
		case 1: {
			std::cout << "Please Enter File Path: " << std::endl;
			std::cin >> file;
			FileCompress cps;
			cps.Compress(file.c_str());
			std::cout << "Compress Success" << std::endl;
			ctl = 0;
		} break;
		case 2: {
			std::cout << "Please Enter File Path: " << std::endl;
			std::cin >> file;
			FileCompress cps;
			cps.UnCompress(file.c_str());
			std::cout << "UnCompress Success" << std::endl;
			ctl = 0;
		} break;
		default:
			break;
		}
	}

	return ;
}

int main() {
	run();
	return 0;	
}