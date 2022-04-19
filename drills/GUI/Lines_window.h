#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );

	bool wait_for_button();

private:
	Open_polyline lines;

	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	Menu color_menu;
	Button menu_button;

	Menu style_menu;
	Button s_menu_button;

	void change(Color c){lines.set_color(c);}
	void hide_menu(){color_menu.hide();menu_button.show();}

	void change_style(Line_style s){lines.set_style(s);}
	void hide_s_menu(){style_menu.hide();s_menu_button.show();}

	void red_pressed(){change(Color::red); hide_menu();}
	void blue_pressed(){change(Color::blue); hide_menu();}
	void black_pressed(){change(Color::black); hide_menu();}
	void menu_pressed(){menu_button.hide();color_menu.show();}

	void solid_pressed(){change_style(Line_style::solid); hide_s_menu();}
	void dash_pressed(){change_style(Line_style::dash); hide_s_menu();}
	void dot_pressed(){change_style(Line_style::dot); hide_s_menu();}
	void s_menu_pressed(){s_menu_button.hide();style_menu.show();}

	void next();
	void quit();

	static void cb_red(Address,Address);
	static void cb_blue(Address,Address);
	static void cb_black(Address,Address);
	static void cb_menu(Address,Address);

	static void cb_solid(Address,Address);
	static void cb_dash(Address,Address);
	static void cb_dot(Address,Address);
	static void cb_s_menu(Address,Address);

	static void cb_next(Address,Address);
	static void cb_quit(Address,Address);
};