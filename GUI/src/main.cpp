#include <iostream>
#include "gtkmm-3.0/gtkmm.h"

int main(int argc, char *argv[])
{
	std::cout << "GUI" << std::endl;
	
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

	Gtk::Window window;
	window.set_default_size(200, 200);

	return app->run(window);

	return 0;
}
