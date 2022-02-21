/*
    g++ drill12.cpp ../../source/week02-06/GUI/Graph.cpp ../../source/week02-06/GUI/Window.cpp ../../source/week02-06/GUI/GUI.cpp ../../source/week02-06/GUI/Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "../../source/week02-06/GUI/Simple_window.h"
#include "../../source/week02-06/GUI/Graph.h"

using namespace Graph_lib;

int main()
{
    Simple_window win {Point{100,100}, 800, 600, "Canvas"};

    //Polligon rectangle
    Polygon poly_rect;
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{200,200});
    poly_rect.add(Point{100,200});
    poly_rect.set_color(Color::red);
    win.attach(poly_rect);

    //Rectangle rectangle
    Rectangle rect{Point{300,300},100,100};
    rect.set_color(Color::blue);
    win.attach(rect);

    //Rectangle with text
    Rectangle rect2(Point{300,200},100,30);
    win.attach(rect2);

    Text t(Point{320,220},"Howdy!");
    win.attach(t);

    //Initials
    Text initial1(Point(400,150),"F");
    Text initial2(Point(440,150),"D");
    initial1.set_font(Font::times_bold);
    initial2.set_font(Font::times_bold);
    initial1.set_font_size(50);
    initial2.set_font_size(50);
    initial1.set_color(Color::blue);
    initial2.set_color(Color::yellow);


    win.attach(initial1);
    win.attach(initial2);


    win.wait_for_button();

    return 0;
}
