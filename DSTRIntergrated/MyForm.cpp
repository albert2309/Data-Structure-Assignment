#include "Login.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::Login form;
	Application::Run(%form);
	return 0;
}