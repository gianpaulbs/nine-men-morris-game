#pragma once
#include "Controller_Game.h"


namespace ninemenmorrisgame {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Escena_Juego
	/// </summary>
	public ref class Scene_Game : public System::Windows::Forms::Form
	{
		public:
			Scene_Game(void)
			{
				InitializeComponent();

				/* Inicializamos las variables gráficas
				 * que nos permitirá crear gráficos donde
				 * le asignemos.
				*/
				graphics = PnlEscena_Juego->CreateGraphics();

				/* Creamos un espacio que nos proporciona métodos para poder-
				 * configurar nuestro bufer gráfico. Con el método allocate creo
				 * un contenedor bufer de gráficos con las dimensiones de nuestros paneles
				*/
				bfContext = BufferedGraphicsManager::Current;
				bfGraphics = bfContext->Allocate(graphics, PnlEscena_Juego->ClientRectangle);

				/* Inicializamos los mapas de bits con las rutas de la imagen */
				controller = gcnew Controller_Game();
			}

		protected:
			/// <summary>
			/// Limpiar los recursos que se estén usando.
			/// </summary>
			~Scene_Game()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Timer^ Loop;
		private: System::Windows::Forms::Panel^ PnlEscena_Juego;
		private: System::ComponentModel::IContainer^ components;
		private:
			Graphics^ graphics;
			Bitmap^ bmpBackground;
			BufferedGraphicsContext^ bfContext;
			BufferedGraphics^ bfGraphics;
			Controller_Game^ controller;

		private:
			/// <summary>
			/// Variable del diseñador necesaria.
			/// </summary>

			#pragma region Windows Form Designer generated code
			/// <summary>
			/// Método necesario para admitir el Diseñador. No se puede modificar
			/// el contenido de este método con el editor de código.
			/// </summary>
				void InitializeComponent(void)
				{
					this->components = (gcnew System::ComponentModel::Container());
					this->Loop = (gcnew System::Windows::Forms::Timer(this->components));
					this->PnlEscena_Juego = (gcnew System::Windows::Forms::Panel());
					this->SuspendLayout();
					// 
					// Loop
					// 
					this->Loop->Enabled = true;
					this->Loop->Tick += gcnew System::EventHandler(this, &Scene_Game::Loop_Tick);
					// 
					// PnlEscena_Juego
					// 
					this->PnlEscena_Juego->Location = System::Drawing::Point(0, 0);
					this->PnlEscena_Juego->Name = L"PnlEscena_Juego";
					this->PnlEscena_Juego->Size = System::Drawing::Size(768, 1000);
					this->PnlEscena_Juego->TabIndex = 0;
					// 
					// Escena_Juego
					// 
					this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
					this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					this->ClientSize = System::Drawing::Size(768, 1000);
					this->Controls->Add(this->PnlEscena_Juego);
					this->Name = L"Scene_Game";
					this->Text = L"Scene_Game";
					this->ResumeLayout(false);

				}
			#pragma endregion

			#pragma region Windows Events
			private: System::Void Loop_Tick(System::Object^ sender, System::EventArgs^ e) {
				controller->Load_Resources(bfGraphics->Graphics);
				bfGraphics->Render(graphics);
			}
			#pragma endregion
	};
}
