#pragma once
#include "AnnPoints.h"
#include "Matrix.h"

#include <iostream>
#include <math.h>
#include <time.h>

#define CLASS_ONE (1)
#define CLASS_TWO (-1)
#define PANEL_SIZE 520
#define PANEL_SIZE_DIV_TWO 260

#define LEARNING_RATE_PERCEPTRON 0.2
#define LEARNING_RATE_DELTA 0.8

#define PRINT_FREQ 500
#define LAMBDA 0.0001


namespace YSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			refPoints = gcnew AnnPoints();
			w = gcnew Matrix(3, 1);
			isRandomPressed = false;
			isDrawWeight = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  radioButtonClassOne;
	private: System::Windows::Forms::RadioButton^  radioButtonClassTwo;
	private: System::Windows::Forms::Button^  buttonReset;
	private: System::Windows::Forms::Button^  buttonProcess;
	private: System::Windows::Forms::RadioButton^  radioButtonBinary;
	private: System::Windows::Forms::RadioButton^  radioButtonContinuous;
	private: System::Windows::Forms::GroupBox^  groupBoxClass;
	private: System::Windows::Forms::Label^  labelDebug;
	private: System::Windows::Forms::Button^  buttonNormalize;
	private: System::Windows::Forms::Button^  buttonRandom;
	private: System::Windows::Forms::TrackBar^  trackBarZoom;
	private: System::Windows::Forms::Label^  labelZoom;
	protected:

	private:
		AnnPoints^ refPoints;
		Matrix^ w;
		bool isDrawWeight;
		bool isRandomPressed;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButtonClassOne = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonClassTwo = (gcnew System::Windows::Forms::RadioButton());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->buttonProcess = (gcnew System::Windows::Forms::Button());
			this->radioButtonBinary = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonContinuous = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxClass = (gcnew System::Windows::Forms::GroupBox());
			this->labelDebug = (gcnew System::Windows::Forms::Label());
			this->buttonNormalize = (gcnew System::Windows::Forms::Button());
			this->buttonRandom = (gcnew System::Windows::Forms::Button());
			this->trackBarZoom = (gcnew System::Windows::Forms::TrackBar());
			this->labelZoom = (gcnew System::Windows::Forms::Label());
			this->groupBoxClass->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarZoom))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 8);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(780, 780);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseClick);
			// 
			// radioButtonClassOne
			// 
			this->radioButtonClassOne->AutoSize = true;
			this->radioButtonClassOne->Checked = true;
			this->radioButtonClassOne->Location = System::Drawing::Point(16, 35);
			this->radioButtonClassOne->Name = L"radioButtonClassOne";
			this->radioButtonClassOne->Size = System::Drawing::Size(79, 24);
			this->radioButtonClassOne->TabIndex = 1;
			this->radioButtonClassOne->TabStop = true;
			this->radioButtonClassOne->Text = L"class1";
			this->radioButtonClassOne->UseVisualStyleBackColor = true;
			// 
			// radioButtonClassTwo
			// 
			this->radioButtonClassTwo->AutoSize = true;
			this->radioButtonClassTwo->Location = System::Drawing::Point(130, 35);
			this->radioButtonClassTwo->Name = L"radioButtonClassTwo";
			this->radioButtonClassTwo->Size = System::Drawing::Size(79, 24);
			this->radioButtonClassTwo->TabIndex = 2;
			this->radioButtonClassTwo->TabStop = true;
			this->radioButtonClassTwo->Text = L"class2";
			this->radioButtonClassTwo->UseVisualStyleBackColor = true;
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(867, 248);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(95, 33);
			this->buttonReset->TabIndex = 3;
			this->buttonReset->Text = L"RESET";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &MyForm::buttonReset_Click);
			// 
			// buttonProcess
			// 
			this->buttonProcess->Location = System::Drawing::Point(997, 248);
			this->buttonProcess->Name = L"buttonProcess";
			this->buttonProcess->Size = System::Drawing::Size(104, 33);
			this->buttonProcess->TabIndex = 3;
			this->buttonProcess->Text = L"PROCESS";
			this->buttonProcess->UseVisualStyleBackColor = true;
			this->buttonProcess->Click += gcnew System::EventHandler(this, &MyForm::buttonProcess_Click);
			// 
			// radioButtonBinary
			// 
			this->radioButtonBinary->AutoSize = true;
			this->radioButtonBinary->Checked = true;
			this->radioButtonBinary->Location = System::Drawing::Point(881, 147);
			this->radioButtonBinary->Name = L"radioButtonBinary";
			this->radioButtonBinary->Size = System::Drawing::Size(78, 24);
			this->radioButtonBinary->TabIndex = 5;
			this->radioButtonBinary->TabStop = true;
			this->radioButtonBinary->Text = L"Binary";
			this->radioButtonBinary->UseVisualStyleBackColor = true;
			// 
			// radioButtonContinuous
			// 
			this->radioButtonContinuous->AutoSize = true;
			this->radioButtonContinuous->Location = System::Drawing::Point(986, 147);
			this->radioButtonContinuous->Name = L"radioButtonContinuous";
			this->radioButtonContinuous->Size = System::Drawing::Size(115, 24);
			this->radioButtonContinuous->TabIndex = 6;
			this->radioButtonContinuous->TabStop = true;
			this->radioButtonContinuous->Text = L"Continuous";
			this->radioButtonContinuous->UseVisualStyleBackColor = true;
			// 
			// groupBoxClass
			// 
			this->groupBoxClass->Controls->Add(this->radioButtonClassOne);
			this->groupBoxClass->Controls->Add(this->radioButtonClassTwo);
			this->groupBoxClass->Location = System::Drawing::Point(867, 39);
			this->groupBoxClass->Name = L"groupBoxClass";
			this->groupBoxClass->Size = System::Drawing::Size(234, 77);
			this->groupBoxClass->TabIndex = 7;
			this->groupBoxClass->TabStop = false;
			this->groupBoxClass->Text = L"groupBox1";
			// 
			// labelDebug
			// 
			this->labelDebug->AutoSize = true;
			this->labelDebug->Location = System::Drawing::Point(868, 480); // 958, 424
			this->labelDebug->Name = L"labelDebug";
			this->labelDebug->Size = System::Drawing::Size(0, 20);
			this->labelDebug->TabIndex = 9;
			// 
			// buttonNormalize
			// 
			this->buttonNormalize->Location = System::Drawing::Point(867, 197);
			this->buttonNormalize->Name = L"buttonNormalize";
			this->buttonNormalize->Size = System::Drawing::Size(233, 39);
			this->buttonNormalize->TabIndex = 10;
			this->buttonNormalize->Text = L"NORMALIZE";
			this->buttonNormalize->UseVisualStyleBackColor = true;
			this->buttonNormalize->Click += gcnew System::EventHandler(this, &MyForm::buttonNormalize_Click);
			// 
			// buttonRandom
			// 
			this->buttonRandom->Location = System::Drawing::Point(867, 297);
			this->buttonRandom->Name = L"buttonRandom";
			this->buttonRandom->Size = System::Drawing::Size(234, 38);
			this->buttonRandom->TabIndex = 11;
			this->buttonRandom->Text = L"RANDOM";
			this->buttonRandom->UseVisualStyleBackColor = true;
			this->buttonRandom->Click += gcnew System::EventHandler(this, &MyForm::buttonRandom_Click);
			// 
			// trackBarZoom
			// 
			this->trackBarZoom->Location = System::Drawing::Point(867, 375);
			this->trackBarZoom->Name = L"trackBarZoom";
			this->trackBarZoom->Size = System::Drawing::Size(233, 69);
			this->trackBarZoom->TabIndex = 12;
			this->trackBarZoom->Maximum = 100;
			this->trackBarZoom->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarZoom_Scroll);
			// 
			// labelZoom
			// 
			this->labelZoom->AutoSize = true;
			this->labelZoom->Location = System::Drawing::Point(958, 424);
			this->labelZoom->Name = L"labelZoom";
			this->labelZoom->Size = System::Drawing::Size(0, 20);
			this->labelZoom->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Bisque;
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->labelZoom);
			this->Controls->Add(this->trackBarZoom);
			this->Controls->Add(this->buttonRandom);
			this->Controls->Add(this->buttonNormalize);
			this->Controls->Add(this->labelDebug);
			this->Controls->Add(this->radioButtonBinary);
			this->Controls->Add(this->groupBoxClass);
			this->Controls->Add(this->radioButtonContinuous);
			this->Controls->Add(this->buttonProcess);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"Artificial Neural Networks";
			this->groupBoxClass->ResumeLayout(false);
			this->groupBoxClass->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarZoom))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonProcess_Click(System::Object^  sender, System::EventArgs^  e) {

		if (!isRandomPressed) {
			w->random();
		}

		bool isBinary = true;
		double c = LEARNING_RATE_PERCEPTRON;
		double epsilon = 0;

		if (radioButtonContinuous->Checked) {
			c = LEARNING_RATE_DELTA;
			isBinary = false;
			epsilon = 0.1;
		}

		AnnPoint* p;
		Matrix^ x = gcnew Matrix(3, 1);
		int cycle = 0;
		double error = 1;
		while ((isBinary ? (error != epsilon) : (error >= epsilon))) {
			int j = 0;
			error = 0;
			p = refPoints->getPoints()->getNext();

			while (p != nullptr) {
				x->set(p->getX(), 0, 0);
				x->set(p->getY(), 1, 0);
				x->set(1, 2, 0);

				Matrix^ wTranspose = w->transpose();
				Matrix^ wx = wTranspose * x;

				double net = wx->get(0, 0);
				double fTnet;
				double fnet = activationFunction(isBinary, net, &fTnet);
				
				if (fnet != p->getClassId()) {
					Matrix^ dw = x * (c * (p->getClassId() - fnet));// *fTnet);
					w += dw;
					dw->~Matrix();

					error += isBinary ? abs(p->getClassId() - fnet) / 2 : (pow(p->getClassId() - fnet, 2) / 2);
				}

				wTranspose->~Matrix();
				wx->~Matrix();
				p = p->getNext();
			}					

			cycle++;
			if (cycle % PRINT_FREQ == 0) {
				isDrawWeight = true;
				panel1->Refresh();
			}
		}

		labelDebug->Text = "";
		labelDebug->Text += "Cycle :" + cycle + "\n";
		labelDebug->Text += "Error :" + error + "\n";
		isDrawWeight = true;
		panel1->Refresh();
	}

	private: double activationFunction(bool isBinary, double net, double *fTNet) {
		if (isBinary) {
			// Derivative fNet = fTNet
			*fTNet = 1;
			return ((net >= 0 ? 1 : -1));
		}
		else {
			double temp = exp(-LAMBDA * net) + 1;
			if (temp == 0) {
				temp = 0.0000001;
			}
			double fNet = (2.0 / (temp) - 1.0);

			*fTNet = 0.5 * (1 - (fNet * fNet));
			if (*fTNet == 0) {
				temp = 0.0000001;
			}
			return fNet;
		}
	}

	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		labelDebug->Text = "";
		double real_x = e->X - PANEL_SIZE_DIV_TWO;
		double real_y = PANEL_SIZE_DIV_TWO - e->Y;


		if (radioButtonClassOne->Checked) {
			labelDebug->Text += "Class 1: ";
			refPoints->addPoint(real_x, real_y, CLASS_ONE);
		}
		else {
			labelDebug->Text += "Class 2: ";
			refPoints->addPoint(real_x, real_y, CLASS_TWO);
		}

		labelDebug->Text += "x: " + e->X + " y: " + e->Y + " \n";
		labelDebug->Text += "coordinate x: " + real_x + " coordinate y: " + real_y + " \n";
		panel1->Refresh();
	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		g->Clear(System::Drawing::SystemColors::Control);

		Pen^ pen = gcnew Pen(Color::Black, 2);

		// Coordinates (Axis, Ordinate)
		g->DrawLine(pen, PANEL_SIZE_DIV_TWO, 0, PANEL_SIZE_DIV_TWO, PANEL_SIZE);
		g->DrawLine(pen, 0, PANEL_SIZE_DIV_TWO, PANEL_SIZE, PANEL_SIZE_DIV_TWO);

		int plusSize = 5;
		int zoom = 1 + this->trackBarZoom->Value;

		// First point is invalid
		AnnPoint* p = refPoints->getPoints()->getNext();

		while (p != nullptr) {
			if (p->getClassId() == CLASS_ONE) {
				pen->Color = Color::Red;
			}
			else {
				pen->Color = Color::Blue;
			}

			int x, y;
			x = PANEL_SIZE_DIV_TWO + p->getX() * zoom;
			y = PANEL_SIZE_DIV_TWO - p->getY() * zoom;

			// Draws a small plus in clicked coordinates
			g->DrawLine(pen, x - plusSize, y, x + plusSize, y);
			g->DrawLine(pen, x, y - plusSize, x, y + plusSize);
			p = p->getNext();
		}

		// Draws line (iterations)
		if (isDrawWeight)
		{
			double w1, w2, w3;
			pen->Color = Color::Purple;

			// x*w1 + y*w2 + w3 = 0
			w1 = w->get(0, 0);
			w2 = w->get(1, 0);

			if (w2 == 0) {
				w2 = 0.00001;
			}

			//bias
			w3 = w->get(2, 0);

			int x1, y1, x2, y2;

			x1 = 0;
			y1 = (x1 - PANEL_SIZE_DIV_TWO) * w1 / w2 + (w3 / w2) + PANEL_SIZE_DIV_TWO;

			x2 = PANEL_SIZE;
			y2 = (x2 - PANEL_SIZE_DIV_TWO) * w1 / w2 + (w3 / w2) + PANEL_SIZE_DIV_TWO;

			g->DrawLine(pen, x1, y1, x2, y2);
			isDrawWeight = false;
		}
	}

	private: System::Void buttonNormalize_Click(System::Object^  sender, System::EventArgs^  e) {
		double meanX = 0;
		double meanY = 0;

		AnnPoint* p = refPoints->getPoints();

		int size = 0;
		while ((p = p->getNext()) != nullptr) {
			meanX += p->getX();
			meanY += p->getY();
			size++;
		}

		meanX /= size;
		meanY /= size;

		double sumx = 0;
		double sumy = 0;

		p = refPoints->getPoints();
		while ((p = p->getNext()) != nullptr) {
			sumx += pow((p->getX() - meanX), 2);
			sumy += pow((p->getY() - meanY), 2);
		}

		//standart derivation
		double sdx = sqrt(sumx / (size - 1));
		double sdy = sqrt(sumy / (size - 1));

		p = refPoints->getPoints();
		while ((p = p->getNext()) != nullptr) {
			p->setX((p->getX() - meanX) / sdx);
			p->setY((p->getY() - meanY) / sdy);
		}

		panel1->Refresh();
	}

	private: System::Void buttonReset_Click(System::Object^  sender, System::EventArgs^  e) {
		refPoints->~AnnPoints();
		refPoints = gcnew AnnPoints();

		w->~Matrix();
		w = gcnew Matrix(3, 1);

		isRandomPressed = false;
		isDrawWeight = false;

		labelDebug->Text = "";
		panel1->Refresh();
	}

	private: System::Void buttonRandom_Click(System::Object^  sender, System::EventArgs^  e) {
		isRandomPressed = true;
		w->random();

		isDrawWeight = true;
		panel1->Refresh();
	}

	private: System::Void trackBarZoom_Scroll(System::Object^  sender, System::EventArgs^  e) {
		labelZoom->Text = "Zoom: " + trackBarZoom->Value.ToString();
		panel1->Refresh();
	}
};
}
