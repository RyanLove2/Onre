#include"GameObject.h"


GameObject::GameObject(std::string id){

	al_init_primitives_addon();


	// create a method that create objects based on strings values

}


GameObject::~GameObject(){



};


bool GameObject::DrawHitBox(){


	return true;
}

void GameObject::SetMass(float val){
    mg = val;
}

float GameObject::Mass(){

    return mg;
}
