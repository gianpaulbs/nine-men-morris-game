#pragma once

using namespace System;
using namespace System::Drawing;

ref class Entity {
	protected: Bitmap^ bmpBase;
	public:
		~Entity() {}
		Entity(String^ fullpath) {
			this->bmpBase = gcnew Bitmap(fullpath);
		}

		Bitmap^ GetBitmap_Base() {
			return this->bmpBase;
		}
};