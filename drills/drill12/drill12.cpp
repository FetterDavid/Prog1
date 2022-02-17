/*
    g++ drill12.cpp ../../source/week02-06/GUI/Graph.cpp ../../source/week02-06/GUI/Window.cpp ../../source/week02-06/GUI/GUI.cpp ../../source/week02-06/GUI/Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "../../source/week02-06/GUI/Simple_window.h"
#include "../../source/week02-06/GUI/Graph.h"

using namespace Graph_lib;

int main()
{
    Simple_window win {Point{100,100}, 800, 600, "Canvas"};

    win.wait_for_button();

    return 0;
}
