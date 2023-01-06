#pragma once
#include "Entity.h"

ref class Board : public Entity {
	private: Bitmap^ bmpBackground;
	public:
		~Board() {}
		Board(String^ BASE_IMAGE_PATH) : Entity(BASE_IMAGE_PATH + "/board.png") {
			this->bmpBackground = gcnew Bitmap(BASE_IMAGE_PATH + "/bg_game.jpg");
		}

		Bitmap^ GetBitmap_Background() {
			return this->bmpBackground;
		}
};