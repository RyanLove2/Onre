
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



#include"Onre.cpp"

class GameObject {

	private:
		ALLEGRO_BITMAP* platforms;
		float right, left,top, bottom;

		std::vector<std::string> id;



	public:

		bool DrawHitBox();
		void HitBox();
		void SetHitBox(float f_top, float f_bottom);
		void DrawObject(float x, float y,float f_top, int face);
		GameObject(int land);
		~GameObject();





};
