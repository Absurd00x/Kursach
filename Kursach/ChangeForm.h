#pragma once
#include "MyClass.h"

namespace Kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ChangeForm
	/// </summary>
	public ref class ChangeForm : public System::Windows::Forms::Form
	{
	public:
		ChangeForm(String^ type_needed)
		{
			InitializeComponent();
			this->type_needed = type_needed;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChangeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  data_textBox;
	protected:
	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::Button^  finish_button;
	private: String^ type_needed;
	public: static String^ package;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->data_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->finish_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// data_textBox
			// 
			this->data_textBox->Location = System::Drawing::Point(19, 39);
			this->data_textBox->Margin = System::Windows::Forms::Padding(10);
			this->data_textBox->Name = L"data_textBox";
			this->data_textBox->Size = System::Drawing::Size(146, 20);
			this->data_textBox->TabIndex = 0;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(29, 16);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(132, 13);
			this->label->TabIndex = 1;
			this->label->Text = L"Введите новое значение";
			// 
			// finish_button
			// 
			this->finish_button->Location = System::Drawing::Point(56, 72);
			this->finish_button->Name = L"finish_button";
			this->finish_button->Size = System::Drawing::Size(75, 23);
			this->finish_button->TabIndex = 2;
			this->finish_button->Text = L"OK";
			this->finish_button->UseVisualStyleBackColor = true;
			this->finish_button->Click += gcnew System::EventHandler(this, &ChangeForm::finish_button_Click);
			// 
			// ChangeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(184, 112);
			this->Controls->Add(this->finish_button);
			this->Controls->Add(this->label);
			this->Controls->Add(this->data_textBox);
			this->MaximumSize = System::Drawing::Size(200, 150);
			this->MinimumSize = System::Drawing::Size(200, 150);
			this->Name = L"ChangeForm";
			this->Text = L"Изменить";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: int string_to_integer(String^ number) {
		// Вернет число, если number состоит только из цифр
		// Вернет -1 в противном случае
		bool isNumber = true;
		int result = 0;
		string numbers = "0123456789";
		for (int i = 0; i < number->Length; i++)
			if (numbers.find(number[i]) == std::string::npos) {
				isNumber = false;
				break;
			}
			else {
				result *= 10;
				result += number[i] - '0';
			}
		if (!isNumber)
			return -1;
		return result;
	}

	private: System::Void finish_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (System::String::IsNullOrEmpty(data_textBox->Text)) {
			package = "Null";
			this->Close();
		}
		int integer_check = string_to_integer(data_textBox->Text);
		if (integer_check != -1) {
			if (type_needed == "string") {
				MessageBox::Show("Требуется ввести строку, а не число", "Ошибка!", MessageBoxButtons::OK);
				return;
			}
			package = Convert::ToString(integer_check);
			this->Close();
			return;
		}
		if (type_needed == "integer") {
			MessageBox::Show("Требуется ввести число, а не строку", "Ошибка!", MessageBoxButtons::OK);
			return;
		}
		package = data_textBox->Text;
		this->Close();
	}
	};
}
