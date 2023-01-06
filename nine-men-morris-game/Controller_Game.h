#pragma once
#include "Board.h"
#include "Box.h"
#include "Piece.h"

#define RESOURCE_IMAGE "resources/images"
#define RESOURCE_MUSIC "resources/music"

ref class Controller_Game {
	private:
		Board^ board;
		Box^ box_j1;
		Box^ box_j2;

	public:
		~Controller_Game() {}
		Controller_Game() {
			board = gcnew Board(RESOURCE_IMAGE);
			box_j1 = gcnew Box(RESOURCE_IMAGE);
			box_j2 = gcnew Box(RESOURCE_IMAGE);
		}

		void Load_Resources(Graphics^ g) {
			g->DrawImage(board->GetBitmap_Background(), 0, 0, 768, 1000);
			g->DrawImage(board->GetBitmap_Base(), 25, 155, 710, 680);
			g->DrawImage(box_j1->GetBitmap_Base(), 400, 95, 275, 120);
			g->DrawImage(box_j2->GetBitmap_Base(), 95, 780, 275, 120);
		}
};