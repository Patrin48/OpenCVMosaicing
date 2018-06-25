#include "MyForm.h"
#include <iostream>
#include <fstream>
#include <time.h>




using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	Project1::MyForm form;
	Application::Run(%form);
}
