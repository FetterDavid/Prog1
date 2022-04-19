/*
    g++ drill16.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Lines_window.cpp -o drill16 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "../GUI/Lines_window.h"
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Lines_window win{Point{100,100}, 1280, 720, "Canvas"};

    return gui_main();
}
