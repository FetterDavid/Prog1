/*
    g++ drill15.cpp ../GUI/Graph.cpp ..//GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

int main()
{
    Simple_window win {Point{100,100}, 600, 600, "Function graphs"};

    Axis y(Axis::y,Point{300,500},400,20,"1 = = 20 pixels");
    y.set_color(Color::red);
    Axis x(Axis::x,Point{100,300},400,20,"1 = = 20 pixels");
    x.set_color(Color::red);

    Point origo{300,300};

    Function o (one,-10,11,origo,400,20,20);

    Function s (slope,-10,11,origo,400,20,20);
    Text t (Point{100,400},"x/2");
    t.set_color(Color::blue);

    Function sq (square,-10,11,origo,400,20,20);
    Function co (cos,-10,11,origo,400,20,20);
    co.set_color(Color::blue);

    Function sco (sloping_cos,-10,11,origo,400,20,20);

    win.attach(y);
    win.attach(x);
    win.attach(o);
    win.attach(s);
    win.attach(t);
    win.attach(sq);
    win.attach(co);
    win.attach(sco);

    win.wait_for_button();
}