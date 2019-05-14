#pragma once
#include "MyClass.h"
#include <msclr\marshal_cppstd.h>

namespace Kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для PopupForm
	/// </summary>
	public ref class PopupForm : public System::Windows::Forms::Form
	{
	public:
		PopupForm(List<Worker^> ^data, DataGridView ^grid, int next_user_number)
		{
			InitializeComponent();
			this->next_user_number = next_user_number;
			this->package = gcnew Worker();
			this->data = data;
			this->grid = grid;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PopupForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: static Worker^ package;
	private: System::Windows::Forms::Label^  name_label;
	protected:
	private: System::Windows::Forms::Label^  job_label;
	private: System::Windows::Forms::Label^  hwpw_label;
	private: System::Windows::Forms::Label^  salary_label;
	private: System::Windows::Forms::TextBox^  name_textBox;
	private: System::Windows::Forms::TextBox^  job_textBox;
	private: System::Windows::Forms::TextBox^  hwpw_textBox;
	private: System::Windows::Forms::TextBox^  salary_textBox;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::ListBox^  user_listBox;
	private: System::Windows::Forms::Button^  add_button;
	private: List<Worker^> ^data;
	private: DataGridView ^grid;

	private: int next_user_number;
	private: System::Windows::Forms::Button^  cancel_button;
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
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->job_label = (gcnew System::Windows::Forms::Label());
			this->hwpw_label = (gcnew System::Windows::Forms::Label());
			this->salary_label = (gcnew System::Windows::Forms::Label());
			this->name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->job_textBox = (gcnew System::Windows::Forms::TextBox());
			this->hwpw_textBox = (gcnew System::Windows::Forms::TextBox());
			this->salary_textBox = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->user_listBox = (gcnew System::Windows::Forms::ListBox());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->Location = System::Drawing::Point(32, 33);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(34, 13);
			this->name_label->TabIndex = 0;
			this->name_label->Text = L"ФИО";
			// 
			// job_label
			// 
			this->job_label->AutoSize = true;
			this->job_label->Location = System::Drawing::Point(18, 73);
			this->job_label->Name = L"job_label";
			this->job_label->Size = System::Drawing::Size(65, 13);
			this->job_label->TabIndex = 1;
			this->job_label->Text = L"Должность";
			// 
			// hwpw_label
			// 
			this->hwpw_label->AutoSize = true;
			this->hwpw_label->Location = System::Drawing::Point(10, 113);
			this->hwpw_label->Name = L"hwpw_label";
			this->hwpw_label->Size = System::Drawing::Size(80, 26);
			this->hwpw_label->TabIndex = 2;
			this->hwpw_label->Text = L"Рабочих часов\r\n     в неделю";
			// 
			// salary_label
			// 
			this->salary_label->AutoSize = true;
			this->salary_label->Location = System::Drawing::Point(16, 153);
			this->salary_label->Name = L"salary_label";
			this->salary_label->Size = System::Drawing::Size(67, 26);
			this->salary_label->TabIndex = 3;
			this->salary_label->Text = L"Заработная\r\n     плата";
			// 
			// name_textBox
			// 
			this->name_textBox->Location = System::Drawing::Point(96, 33);
			this->name_textBox->Margin = System::Windows::Forms::Padding(10);
			this->name_textBox->Name = L"name_textBox";
			this->name_textBox->Size = System::Drawing::Size(151, 20);
			this->name_textBox->TabIndex = 4;
			// 
			// job_textBox
			// 
			this->job_textBox->Location = System::Drawing::Point(96, 73);
			this->job_textBox->Margin = System::Windows::Forms::Padding(10);
			this->job_textBox->Name = L"job_textBox";
			this->job_textBox->Size = System::Drawing::Size(151, 20);
			this->job_textBox->TabIndex = 5;
			// 
			// hwpw_textBox
			// 
			this->hwpw_textBox->Location = System::Drawing::Point(96, 113);
			this->hwpw_textBox->Margin = System::Windows::Forms::Padding(10);
			this->hwpw_textBox->Name = L"hwpw_textBox";
			this->hwpw_textBox->Size = System::Drawing::Size(151, 20);
			this->hwpw_textBox->TabIndex = 6;
			// 
			// salary_textBox
			// 
			this->salary_textBox->Location = System::Drawing::Point(96, 153);
			this->salary_textBox->Margin = System::Windows::Forms::Padding(10);
			this->salary_textBox->Name = L"salary_textBox";
			this->salary_textBox->Size = System::Drawing::Size(151, 20);
			this->salary_textBox->TabIndex = 7;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(311, 35);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(165, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Поделить рабочее место с:";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// user_listBox
			// 
			this->user_listBox->FormattingEnabled = true;
			this->user_listBox->Location = System::Drawing::Point(272, 58);
			this->user_listBox->Name = L"user_listBox";
			this->user_listBox->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
			this->user_listBox->Size = System::Drawing::Size(232, 173);
			this->user_listBox->TabIndex = 9;
			// 
			// add_button
			// 
			this->add_button->Location = System::Drawing::Point(12, 196);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(109, 35);
			this->add_button->TabIndex = 10;
			this->add_button->Text = L"Добавить";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &PopupForm::ready_button_Click);
			// 
			// cancel_button
			// 
			this->cancel_button->Location = System::Drawing::Point(138, 196);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(109, 35);
			this->cancel_button->TabIndex = 11;
			this->cancel_button->Text = L"Отменить";
			this->cancel_button->UseVisualStyleBackColor = true;
			this->cancel_button->Click += gcnew System::EventHandler(this, &PopupForm::cancel_button_Click);
			// 
			// PopupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 247);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->user_listBox);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->salary_textBox);
			this->Controls->Add(this->hwpw_textBox);
			this->Controls->Add(this->job_textBox);
			this->Controls->Add(this->name_textBox);
			this->Controls->Add(this->salary_label);
			this->Controls->Add(this->hwpw_label);
			this->Controls->Add(this->job_label);
			this->Controls->Add(this->name_label);
			this->Name = L"PopupForm";
			this->Text = L"Добавить";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PopupForm::PopupForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &PopupForm::PopupForm_Load);
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
	private: string integer_to_string(int a) {
		string res = "";
		while (a > 0) {
			res.push_back((a % 10) + '0');
			a /= 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}

	private: System::Void ready_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (System::String::IsNullOrEmpty(name_textBox->Text)) {
			MessageBox::Show("Вы не ввели имя работника", "Ошибка!", MessageBoxButtons::OK);
			return;
		}
		if (System::String::IsNullOrEmpty(job_textBox->Text)) {
			MessageBox::Show("Вы не ввели должность работника", "Ошибка!", MessageBoxButtons::OK);
			return;
		}
		if (checkBox1->Checked == true) {
			if (user_listBox->SelectedItems->Count == 0) {
				MessageBox::Show("Вы не выбрали с кем поделить рабочее место", "Ошибка!", MessageBoxButtons::OK);
				return;
			}
			String ^profession = job_textBox->Text;
			bool same = true;
			for (int i = 0; i < user_listBox->SelectedItems->Count; i++)
				if (profession != data[user_listBox->SelectedIndices[i]]->job) {
					same = false;
					break;
				}
			if (!same) {
				MessageBox::Show("У всех выбранных сотрудников должна быть одинаковая должность", "Ошибка!", MessageBoxButtons::OK);
				return;
			}
			int salary_sum = 0, work_hours_sum = 0;
			for (int i = 0; i < user_listBox->SelectedItems->Count; i++) {
				salary_sum += data[user_listBox->SelectedIndices[i]]->salary;
				work_hours_sum += data[user_listBox->SelectedIndices[i]]->hours_worked_per_week;
			}
			int new_salary = salary_sum / (user_listBox->SelectedItems->Count + 1);
			int new_work_hours = work_hours_sum / (user_listBox->SelectedItems->Count + 1);
			for (int i = 0; i < user_listBox->SelectedItems->Count; i++) {
				int data_index = user_listBox->SelectedIndices[i];
				data[data_index]->salary = new_salary;
				data[data_index]->hours_worked_per_week = new_work_hours;
				grid->Rows[data_index]->SetValues(data[data_index]->id, data[data_index]->name,
					data[data_index]->job, data[data_index]->hours_worked_per_week, data[data_index]->salary);
			}
			this->package = gcnew Worker(next_user_number, name_textBox->Text, job_textBox->Text, new_work_hours, new_salary);
			this->Close();
			return;
		}
		int hwpw = string_to_integer(hwpw_textBox->Text);
		if (hwpw < 0 || hwpw > 168) {
			MessageBox::Show("Неверно введено количество рабочих часов в неделю", "Ошибка!", MessageBoxButtons::OK);
			return;
		}
		int salary = string_to_integer(salary_textBox->Text);
		if (salary < 0) {
			MessageBox::Show("Неверно введена заработная плата", "Ошибка!", MessageBoxButtons::OK);
			return;
		}
		this->package = gcnew Worker(next_user_number, name_textBox->Text, job_textBox->Text, hwpw, salary);
		this->Close();
	}
	private: System::Void PopupForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {}
	private: System::Void cancel_button_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void PopupForm_Load(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < data->Count; i++){
			msclr::interop::marshal_context context;
			String^ row = gcnew String((integer_to_string(data[i]->id) + ' '+ context.marshal_as<std::string>(data[i]->name)).c_str());
			user_listBox->Items->Add(row);
		}
	}
};
}
