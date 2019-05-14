#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;
using namespace System;

ref class Worker {
public:
	int id, salary, hours_worked_per_week;
	String^ name;
	String^ job;
	Worker(int id, String^ name, String^ job, int hwpw, int salary) {
		this->id = id;
		this->name = name;
		this->job = job;
		this->hours_worked_per_week = hwpw;
		this->salary = salary;
	}
	Worker() {
		this->name = "None";
		this->hours_worked_per_week = -1;
		this->job = "None";
		this->salary = 0;
	}
};
