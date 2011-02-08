//============================================================================
// Name        : iPhoneBackupRestore.cpp
// Author      : martijn jonkers
// Version     :
// Copyright   : copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <gtkmm.h>
#include <iostream>

#include "interface.h"

using namespace std;

int main(int argc, char *argv[]) {
	cout << "iphone backup restore is starting" << endl; // prints iphone backup restore

	Gtk::Main kit(argc, argv);
	MainWindow window;
	Gtk::Main::run(window);

	cout << "iphone backup restore is closing" << endl;
	return 0;
}
