/*
    g++ drill13.cpp ../../source/week02-06/GUI/Graph.cpp ../../source/week02-06/GUI/Window.cpp ../../source/week02-06/GUI/GUI.cpp ../../source/week02-06/GUI/Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "../../source/week02-06/GUI/Simple_window.h"
#include "../../source/week02-06/GUI/Graph.h"
#include <stdlib.h>

using namespace Graph_lib;

int main()
{
    Simple_window win {Point{100,100}, 800, 1000, "Canvas"};

    //grid
    Lines x;
    for (int i = 0; i < 8; ++i)
    {
        x.add(Point{i*100, 0}, Point{i*100, 800});
        x.add(Point{0, i*100}, Point{800, i*100});
    } 
    win.attach(x);

    Vector_ref<Rectangle> rects;

    //diagonal red rectangles
    for (int i = 0; i < 8; ++i)
    {
        rects.push_back(new Rectangle {Point{i*100, i*100},100,100});
        rects[i].set_fill_color(Color::red);
        win.attach(rects[i]);
    }

    //imiges
    Image im1{Point{0,200},"200*200.jpg"};
    win.attach(im1);
    Image im2{Point{200,400},"200*200.jpg"};
    win.attach(im2);
    Image im3{Point{400,600},"200*200.jpg"};
    win.attach(im3);

    //moving image
    int x_pos = 0;
    int y_pos = 0;
    Image im4{Point{0,0},"100*100.jpg"};
    while(true)
    {
        win.wait_for_button();
        im4.move((x_pos*-1),(y_pos*-1));
        x_pos = (rand() % 7) * 100;
        y_pos = (rand() % 7) * 100;
        im4.move(x_pos,y_pos);
        win.attach(im4);
    }


    win.wait_for_button();

    return 0;
}
