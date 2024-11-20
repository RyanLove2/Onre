#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_opengl.h>
#include<allegro5/allegro_physfs.h>
#include<allegro5/allegro_primitives.h>
#include"Window.h"


void Window::SetPath(){
				//char * mypath = al_get_current_directory();
				custpath = al_create_path("");
				al_append_path_component(custpath,"Graphics");
				al_change_directory(al_path_cstr(custpath,ALLEGRO_NATIVE_PATH_SEP));
				std::cout<<al_get_current_directory();
				std::cout<<"\n";
}

ALLEGRO_EVENT_QUEUE* Window::GetEventQue(){

	return que;
}

ALLEGRO_EVENT& Window::GetEvent(){
			return eve;
}


ALLEGRO_TIMER* Window::GetDelta(){

return clock;

}

ALLEGRO_TIMER* Window::GetDeltaFrame(){
	return ani_frame;
}


Window::Window(){
	SetPath();
	render = true;
	fps = 60.0;
	ani_count = 15.0;

	screenwidth = 800;
	screenhight = 500;

	que = al_create_event_queue();
	clock = al_create_timer(1.0/fps);
	ani_frame = al_create_timer(1.0/ani_count);

	window = al_create_display(screenwidth,screenhight);
	al_set_window_title(window,name);
	ic = al_load_bitmap("gameicon.png");
	al_set_display_icon(window,ic);

			//al_register_event_source(que,ALLEGRO_EVENT_SOURCE *source);


			// Start the event queue to handle keyboard input and our timer
	que = al_create_event_queue();
	al_register_event_source(que, al_get_keyboard_event_source());
	al_register_event_source(que, al_get_display_event_source(window));
	al_register_event_source(que, al_get_mouse_event_source());
	al_register_event_source(que,al_get_timer_event_source(clock));
	al_register_event_source(que,al_get_timer_event_source(ani_frame));

	al_start_timer(clock);
	al_start_timer(ani_frame);
}

Window::~Window(){

	al_destroy_display(window);
	al_destroy_event_queue(que);
	al_destroy_path(custpath);
	al_destroy_timer(clock);
	delete this;

};

