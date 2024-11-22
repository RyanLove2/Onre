#include"GameObject.h"


GameObject::GameObject(){
	this->face = 0;

}


GameObject::~GameObject(){



};

void GameObject::CreatePlatforms(int land){

	switch( land){
			case 0:
				platforms = al_load_bitmap("stone_platform.png");


			break;

			case 1:

			break;


			case 2:

			break;


		}


}

float GameObject::GetTop(){
	return top;
}

float GameObject::GetBottom(){
	return bottom;
}

float GameObject::GetRight(){
	return right;
}

float GameObject::GetLeft(){
	return left;
}

bool GameObject::DrawHitBox(){


	return true;
}

void GameObject::SetDrawObject(float x, float y,float f_top, int face ){
	left = x;
	this->x = x;
	this->y = y;
	right = x + 50;
	top = f_top;
	bottom = f_top +50;
	this->face = face;
/*
	if(platforms != 0){

		al_draw_filled_rectangle(left,top,right,bottom,al_map_rgb(250,0,0));
		al_draw_bitmap(platforms,x,y,face);
		//al_draw_filled_rectangle(150,451,200,500,al_map_rgb(250,0,0));
		//al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0,0,200));
	}
	else{
	//	std::cout<<"faild to load bmp :(";
	}*/
}

void GameObject::DrawObject(){

	if(platforms != 0){

		al_draw_filled_rectangle(left,top,right,y,al_map_rgb(250,0,0));
		al_draw_bitmap(platforms,left,top,face);
		//al_draw_filled_rectangle(150,451,200,500,al_map_rgb(250,0,0));
		//al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0,0,200));
	}
	else{
	//	std::cout<<"faild to load bmp :(";
	}

}

void GameObject::HitBox(){

	al_draw_filled_rectangle(50,100,100,50,al_map_rgb(250,0,0));


}
