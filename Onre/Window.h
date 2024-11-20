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

class Window{

	private:
		ALLEGRO_DISPLAY* window;
		ALLEGRO_BITMAP* ic;
		ALLEGRO_PATH* custpath;
		int screenwidth, screenhight;


		char name[20] = {"Onre"};
		ALLEGRO_EVENT eve;
		ALLEGRO_EVENT_QUEUE* que;
		ALLEGRO_TIMER* clock;
		ALLEGRO_TIMER* ani_frame;
	public:
		bool render;
		float fps;
		float ani_count;

	public:

		void SetPath();
		ALLEGRO_TIMER* GetDelta();
		ALLEGRO_TIMER* GetDeltaFrame();
		ALLEGRO_EVENT_QUEUE* GetEventQue();

		ALLEGRO_EVENT& GetEvent();


		Window();

		~Window();
};
