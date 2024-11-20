
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
#include<iostream>
#include<vector>
#include<string>


class GameObject{

	private:
		ALLEGRO_BITMAP* brush;
		float right, left,top, bottom;
		float mg;
		std::vector<std::string> id;


	public:

		bool DrawHitBox();
		float Mass();
		void SetMass(float value);
		GameObject(std::string id);
		~GameObject();





};
