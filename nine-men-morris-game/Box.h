#pragma once
#include "Entity.h"

ref class Box : public Entity {
	public:
		~Box() {}
		Box(String^ BASE_IMAGE_PATH) : 
			Entity(BASE_IMAGE_PATH + "/chipbox.png") {}
};