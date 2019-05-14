#pragma once
#include "MyClass.h"
#include "PopupForm.h"
#include "ChangeForm.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <string>

namespace Kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  add_button;
	private: System::Windows::Forms::Button^  delete_button;
	private: System::Windows::Forms::Button^  change_button;
	private: System::Windows::Forms::GroupBox^  button_group;
	private: System::Windows::Forms::DataGridView^  user_gridview;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  job;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  work_hours;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  salary;
	private: List<Worker^> data;
	private: int cur_id;
	private: System::Windows::Forms::Button^  exit_button;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->change_button = (gcnew System::Windows::Forms::Button());
			this->button_group = (gcnew System::Windows::Forms::GroupBox());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->user_gridview = (gcnew System::Windows::Forms::DataGridView());
			this->number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->job = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->work_hours = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->salary = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_group->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->user_gridview))->BeginInit();
			this->SuspendLayout();
			// 
			// add_button
			// 
			this->add_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->add_button->Location = System::Drawing::Point(605, 19);
			this->add_button->Margin = System::Windows::Forms::Padding(10);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(100, 64);
			this->add_button->TabIndex = 0;
			this->add_button->Text = L"Добавить";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &MyForm::addbutton_Click);
			// 
			// delete_button
			// 
			this->delete_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->delete_button->Location = System::Drawing::Point(605, 103);
			this->delete_button->Margin = System::Windows::Forms::Padding(10);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(100, 64);
			this->delete_button->TabIndex = 1;
			this->delete_button->Text = L"Удалить";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &MyForm::delete_button_Click);
			// 
			// change_button
			// 
			this->change_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->change_button->Location = System::Drawing::Point(605, 187);
			this->change_button->Margin = System::Windows::Forms::Padding(10);
			this->change_button->Name = L"change_button";
			this->change_button->Size = System::Drawing::Size(100, 64);
			this->change_button->TabIndex = 2;
			this->change_button->Text = L"Изменить";
			this->change_button->UseVisualStyleBackColor = true;
			this->change_button->Click += gcnew System::EventHandler(this, &MyForm::change_button_Click);
			// 
			// button_group
			// 
			this->button_group->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_group->Controls->Add(this->exit_button);
			this->button_group->Controls->Add(this->user_gridview);
			this->button_group->Controls->Add(this->add_button);
			this->button_group->Controls->Add(this->change_button);
			this->button_group->Controls->Add(this->delete_button);
			this->button_group->Location = System::Drawing::Point(12, 12);
			this->button_group->Name = L"button_group";
			this->button_group->Size = System::Drawing::Size(718, 338);
			this->button_group->TabIndex = 3;
			this->button_group->TabStop = false;
			// 
			// exit_button
			// 
			this->exit_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exit_button->Location = System::Drawing::Point(605, 271);
			this->exit_button->Margin = System::Windows::Forms::Padding(10);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(100, 64);
			this->exit_button->TabIndex = 4;
			this->exit_button->Text = L"Выйти";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &MyForm::exit_button_Click);
			// 
			// user_gridview
			// 
			this->user_gridview->AllowUserToAddRows = false;
			this->user_gridview->AllowUserToDeleteRows = false;
			this->user_gridview->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->user_gridview->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->user_gridview->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->number,
					this->name, this->job, this->work_hours, this->salary
			});
			this->user_gridview->Location = System::Drawing::Point(6, 19);
			this->user_gridview->Name = L"user_gridview";
			this->user_gridview->Size = System::Drawing::Size(586, 319);
			this->user_gridview->TabIndex = 3;
			this->user_gridview->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// number
			// 
			this->number->HeaderText = L"№";
			this->number->Name = L"number";
			this->number->ReadOnly = true;
			this->number->Width = 25;
			// 
			// name
			// 
			this->name->HeaderText = L"ФИО";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->Width = 200;
			// 
			// job
			// 
			this->job->HeaderText = L"Должность";
			this->job->Name = L"job";
			this->job->ReadOnly = true;
			// 
			// work_hours
			// 
			this->work_hours->HeaderText = L"Рабочих часов в неделю";
			this->work_hours->Name = L"work_hours";
			this->work_hours->ReadOnly = true;
			// 
			// salary
			// 
			this->salary->HeaderText = L"Заработная плата (руб.)";
			this->salary->Name = L"salary";
			this->salary->ReadOnly = true;
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 362);
			this->Controls->Add(this->button_group);
			this->MaximumSize = System::Drawing::Size(800, 500);
			this->MinimumSize = System::Drawing::Size(500, 400);
			this->Name = L"MyForm";
			this->Text = L"База данных";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->button_group->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->user_gridview))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		ifstream input("database.csv");
		int number = 1, work_hours, salary;
		string name, job;
		string integer_value;
		while (getline(input, name, ',')) {
			getline(input, integer_value, ',');
			work_hours = stoi(integer_value);
			getline(input, job, ',');
			getline(input, integer_value);
			salary = stoi(integer_value);
			String ^system_name = gcnew System::String(name.c_str());
			String ^system_job = gcnew System::String(job.c_str());
			data.Add(gcnew Worker(number, system_name, system_job, work_hours, salary));
			user_gridview->Rows->Add(number, system_name, system_job, work_hours, salary);
			++number;
		}
		cur_id = number;
		input.close();
	}

	private: System::Void addbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		List<Worker^> ^data_link = %data;
		DataGridView^ grid_link = user_gridview;
		PopupForm^ popup = gcnew PopupForm(data_link, grid_link, cur_id);
		cur_id++;
		popup->ShowDialog();
		if (popup->package->name != "None") {
			this->data.Add(popup->package);
			this->user_gridview->Rows->Add(popup->package->id, popup->package->name,
				popup->package->job, popup->package->hours_worked_per_week, popup->package->salary);
		}
	}

	private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		ofstream output("database.csv");
		for (int i = 0; i < data.Count; i++) {
			msclr::interop::marshal_context context;
			string cppstring_name = context.marshal_as<std::string>(data[i]->name);
			string cppstring_job = context.marshal_as<std::string>(data[i]->job);
			output << cppstring_name << ',' << data[i]->hours_worked_per_week
				<< ',' << cppstring_job << ',' << data[i]->salary << endl;
		}
		output.close();
	}
	private: System::Void exit_button_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void delete_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (user_gridview->SelectedRows->Count == 0) {
			MessageBox::Show("Не выделено ни одной строки", "Ошибка!", MessageBoxButtons::OK);
			return;
		}
		for (int i = 0; i < user_gridview->SelectedRows->Count; i++) {
			int id = Convert::ToInt32(user_gridview->SelectedRows[i]->Cells[0]->Value);
			user_gridview->SelectedRows[i]->Visible = false;
			for (int j = 0; j < data.Count; j++) {
				if (id == data[j]->id) {
					data.Remove(data[j]);
					break;
				}
			}
		}
	}
	private: System::Void change_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (user_gridview->SelectedCells->Count != 1) {
			MessageBox::Show("Выделите ровно одно поле", "Ошибка!", MessageBoxButtons::OK);
			return;
		}
		auto cell = user_gridview->SelectedCells[0];
		if (cell->ColumnIndex == 0) {
			MessageBox::Show("Нельзя изменить ключевое поле", "Ошибка!", MessageBoxButtons::OK);
			return;
		}
		String ^type_needed;
		if (cell->ColumnIndex == 1 || cell->ColumnIndex == 2)
			type_needed = "string";
		else
			type_needed = "integer";
		ChangeForm^ change = gcnew ChangeForm(type_needed);
		change->ShowDialog();
		cell->Value = change->package;
		int id = Convert::ToInt32(user_gridview->Rows[cell->RowIndex]->Cells[0]->Value);
		for (int j = 0; j < data.Count; j++) {
			if (id == data[j]->id) {
				switch (cell->ColumnIndex) {
					case 1:
						data[j]->name = Convert::ToString(cell->Value);
						break;
					case 2:
						data[j]->job = Convert::ToString(cell->Value);
						break;
					case 3:
						data[j]->hours_worked_per_week = Convert::ToInt32(cell->Value);
						break;
					case 4:
						data[j]->salary = Convert::ToInt32(cell->Value);
				}
				break;
			}
		}
	}
};
}
