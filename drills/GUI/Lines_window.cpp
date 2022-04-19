#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",cb_next},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit", cb_quit},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
    menu_button{Point{x_max()-80,40},80,20,"color menu",cb_menu},
    style_menu{Point{x_max()-160,40},70,20,Menu::vertical,"style"},
    s_menu_button{Point{x_max()-180,40},80,20,"style menu",cb_s_menu}
{
    attach(next_button);
    attach(quit_button);
    attach(style_menu);
    attach(s_menu_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");

    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);

    style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    style_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
    attach(style_menu);
    style_menu.hide();
    attach(s_menu_button);

    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}
void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}
void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}
void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}
void Lines_window::cb_s_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).s_menu_pressed();
}