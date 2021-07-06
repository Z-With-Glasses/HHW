#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "Addition.h"
#include "HHWDescriptions.h"
#include "HHWProjStrings.h"
#include "setup.h"
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>																
#include <limits>																
#include <stdlib.h>																
#include <string>
#include <string_view>
#include <utility>
#include <wx/colour.h>
#include <wx/font.h>
//#include <wx/gauge.h>
#include <wx/listbox.h>
#include <wx/msgdlg.h>
#include <wx/numdlg.h> 
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/textdlg.h>
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
	wxTextCtrl* gui_out;
	wxListBox* gui_choice;
	wxTextCtrl* gui_disp;
	wxTextCtrl* gui_info;
	wxSplitterWindow* gui_split;
	//wxMessageDialog* gui_about;
	//wxGauge* gui_gauge;
	
	void displayAndRun(wxCommandEvent& event);
	long getNumInput(wxString message, wxString prompt, wxString caption);
	wxString getTextInput(wxString message, wxString prompt, wxString caption);
	double getDblInput(wxString message, wxString prompt, wxString caption);
	int getIntInput(wxString message, wxString prompt, wxString caption);
	void proj1();
	void proj2();
	void proj3();
	void proj4();
	void proj5();
	void proj6();
	void proj7();
	void proj8();
	void proj9();
	void proj10();
	void proj11();
	void proj12();
	void proj13();
	void proj14();
	void proj15();
	void proj16();
	void proj17();
	void proj18();
	void proj19();
	void proj20();
	void proj21();
	void proj22();
	void proj23Auto();
	void proj23Manual();
	void proj23();
	void proj24();
	void proj25();
private:
	//DECLARE_EVENT_TABLE()
	enum
	{
		ID_out = 1,
		ID_choice = 2,
		ID_disp = 3,
		ID_info = 4,
		//ID_gauge = 5,
		ID_panel_out = 11,
		ID_panel_disp = 12,
		ID_panel_choice = 13,
		ID_panel_controls = 14,
		ID_splitter = 15,
		ID_button_display = 21,
		ID_button_run = 22,
		ID_button_about = 23,
	};
};
//BEGIN_EVENT_TABLE(MainFrame, wxFrame)
//EVT_BUTTON(ID_button_display, MainFrame::displayAndRun)
//EVT_BUTTON(ID_button_run, MainFrame::displayAndRun)
//EVT_BUTTON(ID_button_about, MainFrame::onAbout)
//EVT_LISTBOX_DCLICK(ID_dbl_click, MainFrame::displayAndRun)
//EVT_LISTBOX(ID_sgl_click, MainFrame::displayAndRun)
//END_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MainFrame* frame = new MainFrame("Hello, Hello World", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}
MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
	this->SetBackgroundColour(*wxBLACK);
	this->SetForegroundColour(*wxGREEN);
	wxFont myFont(10, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	this->SetFont(myFont);

    wxString choices[25] =
    {
     _T("Project 1: Integer Doubling"),
	 _T("Project 2: Int Doubling With Parameters"),
	 _T("Project 3: Forward Declaration"),
	 _T("Project 4: Data Types And Sizes"),
	 _T("Project 5: Prime Number Checker"),
	 _T("Project 6: Character Usage Demonstration"),
	 _T("Project 7: Radius To Circumfrence"),
	 _T("Project 8: Even Or Odd"),
	 _T("Project 9: Low And High Integer Swap"),
	 _T("Project 10: Positive Number Swap"),
	 _T("Project 11: Years Lived Per Character In Name"),
	 _T("Project 12: Character Replace In String"),
	 _T("Project 13: Enumerators And Enum Classes"),
	 _T("Project 14: Struct Demo. Ad Revenue"),
	 _T("Project 15: Struct Demo. Fraction Multiplication"),
	 _T("Project 16: Struct Demonstration-RPG"),
	 _T("Project 17: Forward Declaration"),
	 _T("Project 18: Floating Point Math"),
	 _T("Project 19: Ball Drop From Tower #1"),
	 _T("Project 20: Switch Statement"),
	 _T("Project 21: Loops And Nested Loops"),
	 _T("Project 22: For Loop Of Evens"),
	 _T("Project 23: The Monty Hall Problem"),
	 _T("Project 24: Ball Drop From Tower #2"),
	 _T("Project 25: Prime Check With Asserts")
    };

	//wxPanel* panel_out = new wxPanel(this, ID_panel_out, wxDefaultPosition, wxSize(200, 200));
	gui_split = new wxSplitterWindow(this, ID_splitter, wxDefaultPosition, wxSize(600,400), wxSP_3D);
	gui_out = new wxTextCtrl(gui_split, ID_out, wxString("The output of the selcted project will be displayed here as the project runs."), wxDefaultPosition, wxSize(600, 200), wxTE_READONLY | wxTE_MULTILINE | wxTE_DONTWRAP | wxTE_RICH | wxBORDER_THEME);
	//wxPanel* panel_disp = new wxPanel(this, ID_panel_disp, wxDefaultPosition, wxSize(600, 200), wxBORDER_THEME);
	gui_disp = new wxTextCtrl(gui_split, ID_out, wxString("The code for the selected project will be displayed here."), wxDefaultPosition, wxSize(600, 200), wxTE_READONLY | wxTE_MULTILINE | wxTE_DONTWRAP | wxTE_RICH | wxBORDER_THEME);
	wxPanel* panel_choice = new wxPanel(this, ID_panel_choice, wxDefaultPosition, wxSize(315, 600), wxBORDER_RAISED);
	gui_choice = new wxListBox(panel_choice, ID_choice, wxDefaultPosition, wxSize(315, 600), 25, choices, wxLB_SINGLE | wxVSCROLL);
	//wxPanel* panel_controls = new wxPanel(this, ID_panel_controls, wxDefaultPosition, wxSize(300, 300), wxBORDER_RAISED);
	gui_info = new wxTextCtrl(this, ID_info, wxString("Select a project to display the code or double click to run the project! \n\nThis program was created by Zack Green on 2021/07/05 using C++ and wxWidgets.\n\n           github.com/Z-With-Glasses"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_MULTILINE | wxTE_RICH | wxBORDER_THEME);
	//gui_gauge = new wxGauge(this, ID_gauge, INT_MAX, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);//disabled for performance
	//gui_about = new wxMessageDialog(this, wxString ("Select a project to display the code or double click to run the project! \nThis program was created by Zack Green on 2021/07/05 using C++ and wxWidgets.\n                            github.com/Z-With-Glasses"), wxString(""), wxOK | wxSTAY_ON_TOP, wxDefaultPosition);

	wxBoxSizer* sizer_main = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* sizer_left = new wxBoxSizer(wxVERTICAL);
	gui_split->SplitHorizontally(gui_disp, gui_out);
	gui_split->SetSashGravity(.5);
	//wxBoxSizer* sizer_right = new wxBoxSizer(wxVERTICAL);
	sizer_left->Add(panel_choice, 0);
	//sizer_left->Add(panel_controls, 0);
	sizer_left->Add(gui_info, 1, wxEXPAND, 1);
	//sizer_left->Add(gui_gauge);
	//sizer_right->Add(gui_disp, 1, wxEXPAND, 1);
	//sizer_right->Add(gui_out, 1, wxEXPAND, 1);
	//sizer_right->Add(gui_split, 1, wxEXPAND, 1);
	sizer_main->Add(sizer_left, 0, wxEXPAND);
	sizer_main->Add(gui_split, 1, wxEXPAND);
	this->SetSizerAndFit(sizer_main);

	//wxButton* button_display = new wxButton(panel_controls, ID_button_display, _T("Display"), wxPoint(50, 30), wxSize(100, 30));
	//wxButton* button_run = new wxButton(panel_controls, ID_button_run, _T("Run"), wxPoint(50, 80), wxSize(100, 30));
	//wxButton* button_about = new wxButton(panel_controls, ID_button_about, _T("Info"), wxPoint(85, 130), wxSize(30, 30));
	//button_display->Bind(wxEVT_BUTTON, &MainFrame::displayAndRun, this);
	//button_run->Bind(wxEVT_BUTTON, &MainFrame::displayAndRun, this);
	//button_about->Bind(wxEVT_BUTTON, &MainFrame::onAbout, this);
	gui_choice->Bind(wxEVT_LISTBOX, &MainFrame::displayAndRun, this);
	gui_choice->Bind(wxEVT_LISTBOX_DCLICK, &MainFrame::displayAndRun, this);

	gui_disp->SetBackgroundColour(*wxBLACK);
	gui_disp->SetForegroundColour(*wxGREEN);
	gui_out->SetBackgroundColour(*wxBLACK);
	gui_out->SetForegroundColour(*wxGREEN);
	gui_choice->SetBackgroundColour(*wxBLACK);
	gui_choice->SetForegroundColour(*wxGREEN);
	gui_info->SetBackgroundColour(*wxBLACK);
	gui_info->SetForegroundColour(*wxGREEN);
	
    CreateStatusBar();
    SetStatusText("Select a project to display the code or double click to run the project!");
	this->SetSize(wxSize(1200, 1000));
	this->CenterOnScreen();
}
long MainFrame::getNumInput(wxString message, wxString prompt, wxString caption)
{
	long input{ wxGetNumberFromUser(wxString(message), wxString(prompt), wxString(caption), long{}, long {LONG_MIN}, long {LONG_MAX}, gui_disp, wxDefaultPosition) };
	return input;
}
wxString MainFrame::getTextInput(wxString message, wxString prompt, wxString caption)
{
	wxString input{ wxGetTextFromUser(wxString(message), wxString(prompt), wxString(caption), gui_disp, wxCoord(850), wxCoord(350), false) };
	return input;
}
int MainFrame::getIntInput(wxString message, wxString prompt, wxString caption)
{
	wxString input{ wxGetTextFromUser(wxString(message), wxString(prompt), wxString(caption), gui_disp, wxCoord(850), wxCoord(350), false) };
	int value = wxAtoi(input);
	return value;
}
double MainFrame::getDblInput(wxString message, wxString prompt, wxString caption)
{
	wxString input{ wxGetTextFromUser(wxString(message), wxString(prompt), wxString(caption), gui_disp, wxCoord(850), wxCoord(350), false) };
	double value = wxAtof(input);
	return value;
}
void MainFrame::displayAndRun(wxCommandEvent& event)
{
	int andRun{ event.GetId() };
	int choice{ gui_choice->GetSelection() };
	int evntType = event.GetEventType();
		gui_out->Clear();
	switch (choice)
	{
	case 0:
		gui_disp->SetLabel(proj1String());
		SetStatusText("Project 1: Integer Doubling");
		gui_info->SetLabel(proj1Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj1();
			break;
		}
		break;
	case 1:
		gui_disp->SetLabel(proj2String());
		SetStatusText("Project 2: Integer Doubling w/ Parameter");
		gui_info->SetLabel(proj2Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj2();
			break;
		}
		break;
	case 2:
		gui_disp->SetLabel(proj3String());
		SetStatusText("Project 3: Forward Declaration Demonstration-Integer Addition");
		gui_info->SetLabel(proj3Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj3();
			break;
		}
		break;
	case 3:
		gui_disp->SetLabel(proj4String());
		SetStatusText("Project 4: Data Types And Sizes");
		gui_info->SetLabel(proj4Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj4();
			break;
		}
		break;
	case 4:
		gui_disp->SetLabel(proj5String());
		SetStatusText("Project 5: Prime Number Checker");
		gui_info->SetLabel(proj5Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj5();
			break;
		}
		break;
	case 5:
		gui_disp->SetLabel(proj6String());
		SetStatusText("Project 6: Character Usage Demonstration");
		gui_info->SetLabel(proj6Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj6();
			break;
		}
		break;
	case 6:
		gui_disp->SetLabel(proj7String());
		SetStatusText("Project 7: Constants Demonstration-Radius To Circumfrence");
		gui_info->SetLabel(proj7Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj7();
			break;
		}
		break;
	case 7:
		gui_disp->SetLabel(proj8String());
		SetStatusText("Project 8: Even Or Odd");
		gui_info->SetLabel(proj8Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj8();
			break;
		}
		break;
	case 8:
		gui_disp->SetLabel(proj9String());
		SetStatusText("Project 9: Low And High Integer Swap");
		gui_info->SetLabel(proj9Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj9();
			break;
		}
		break;
	case 9:
		gui_disp->SetLabel(proj10String());
		SetStatusText("Project 10: Positive Number Swap");
		gui_info->SetLabel(proj10Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj10();
			break;
		}
		break;
	case 10:
		gui_disp->SetLabel(proj11String());
		SetStatusText("Project 11: Years Lived Per Character In Name");
		gui_info->SetLabel(proj11Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj11();
			break;
		}
		break;
	case 11:
		gui_disp->SetLabel(proj12String());
		SetStatusText("Project 12: Character Replacement In Strings");
		gui_info->SetLabel(proj12Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj12();
			break;
		}
		break;
	case 12:
		gui_disp->SetLabel(proj13String());
		SetStatusText("Project 13: Enumerators And Enumerated Classes");
		gui_info->SetLabel(proj13Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj13();
			break;
		}
		break;
	case 13:
		gui_disp->SetLabel(proj14String());
		SetStatusText("Project 14: Struct Demonstration-Ad Revenue");
		gui_info->SetLabel(proj14Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj14();
			break;
		}
		break;
	case 14:
		gui_disp->SetLabel(proj15String());
		SetStatusText("Project 15: Struct Demonstration-Fractional Multiplication");
		gui_info->SetLabel(proj15Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj15();
			break;
		}
		break;
	case 15:
		gui_disp->SetLabel(proj16String());
		SetStatusText("Project 16: Struct Demonstration-RPG");
		gui_info->SetLabel(proj16Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj16();
			break;
		}
		break;
	case 16:
		gui_disp->SetLabel(proj17String());
		SetStatusText("Project 17: Integer Addition");
		gui_info->SetLabel(proj17Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj17();
			break;
		}
		break;
	case 17:
		gui_disp->SetLabel(proj18String());
		SetStatusText("Project 18: Floating Point Math With Error Catch");
		gui_info->SetLabel(proj18Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj18();
			break;
		}
		break;
	case 18:
		gui_disp->SetLabel(proj19String());
		SetStatusText("Project 19: Ball Drop From Tower #1");
		gui_info->SetLabel(proj19Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj19();
			break;
		}
		break;
	case 19:
		gui_disp->SetLabel(proj20String());
		SetStatusText("Project 20: Integer Addition With Switch Statement");
		gui_info->SetLabel(proj20Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj20();
			break;
		}
		break;
	case 20:
		gui_disp->SetLabel(proj21String());
		SetStatusText("Project 21: Loops And Nested Loops");
		gui_info->SetLabel(proj21Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj21();
			break;
		}
		break;
	case 21:
		gui_disp->SetLabel(proj22String());
		SetStatusText("Project 22: For Loop Of Evens");
		gui_info->SetLabel(proj22Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj22();
			break;
		}
		break;
	case 22:
		gui_disp->SetLabel(proj23String());
		SetStatusText("Project 23: The Monty Hall Problem");
		gui_info->SetLabel(proj23Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj23();
			break;
		}
		break;
	case 23:
		gui_disp->SetLabel(proj24String());
		SetStatusText("Project 24: Ball Drop From Tower #2: ");
		gui_info->SetLabel(proj24Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj24();
			break;
		}
		break;
	case 24:
		gui_disp->SetLabel(proj25String());
		SetStatusText("Project 25: Prime Number Check With Assert");
		gui_info->SetLabel(proj25Info());
		if (andRun == 22 || event.GetEventType() == wxEVT_LISTBOX_DCLICK)
		{
			proj25();
			break;
		}
		break;
	default:
		{
		wxStreamToTextRedirector redirect(gui_out);
		std::cout << "Select a project, then click Display or Run." << '\n';
		break;
		}
	}
}
void MainFrame::proj1()
{

	wxStreamToTextRedirector redirect(gui_out);
	int num{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	std::cout << "Double that integer is: " << num * 2 << '\n';
}
int proj2DoubleNumber(int x)			//takes one integer as a parameter
{
	return x * 2;						//returns double the value of the integer when called, the caller determines the value of the integer
}
void MainFrame::proj2()
{
	wxStreamToTextRedirector redirect(gui_out);
	int num{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };													//assigns the value of function 'getNumInput' to the integer variable 'num' by calling it
	std::cout << "Double that integer is: " << proj2DoubleNumber(num) << '\n';	//calls function 'doubleNumber' to double the value of the variable 'num' then prints to console the result
	num = proj2DoubleNumber(num);
}
void MainFrame::proj3()
{
	wxStreamToTextRedirector redirect(gui_out);
	int a{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	int b{ getIntInput(wxString { "Enter another integer." },wxString { "" }, wxString { "" }) };

	std::cout << a << " + " << b << " = " << a + b << '\n';
}
//begin project 4
void MainFrame::proj4()
{
	wxStreamToTextRedirector redirect(gui_out);
	std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
	std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
	std::cout << "wchar_t:\t\t" << sizeof(wchar_t) << " bytes\n";
	std::cout << "char16_t:\t\t" << sizeof(char16_t) << " bytes\n"; // C++11 only
	std::cout << "char32_t:\t\t" << sizeof(char32_t) << " bytes\n"; // C++11 only
	std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
	std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
	std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
	std::cout << "long long:\t" << sizeof(long long) << " bytes\n"; // C++11 only
	std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
	std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
	std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
}
//begin project 5
void MainFrame::proj5()
{
	wxStreamToTextRedirector redirect(gui_out);
	long n, i, m = 0, flag = 0;
	n = getIntInput(wxString{ "Enter a number." }, wxString{ "Number:" }, wxString{ "" });
	m = n / 2;
	for (i = 2; i <= m; i++)
	{
		if (n % i == 0)
		{
			std::cout << n << " is not Prime." << '\n';
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		std::cout << n << " is Prime." << '\n';
}
//begin project 6
void MainFrame::proj6()	//examples of the usages of chars (chapter 4.11)
{
	wxStreamToTextRedirector redirect(gui_out);
	std::cout << "6f in hex is char '\x6F'\n";
	std::cout << "\"this is quoted text\"\n";
	std::cout << "'this is quoted text'\n";
	std::cout << "\'this is quoted text\'\n";
	std::cout << "\'\'\n";
	std::cout << "''\n";
	std::cout << "\\\n";
	std::cout << "\\\\\n";
	std::cout << "'" << "\'" << "'''" << "'\''" << '\n';
	char cha{ '?' };
	std::cout << cha << '\n';
	char cha2{ '\'' };
	std::cout << cha2;
}
//begin project 7
void MainFrame::proj7()//Example of how to use the compile time constants(constexpr) in Addition.h
{
	wxStreamToTextRedirector redirect(gui_out);
	int radius{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString {""})};

	double circumference{ 2.0 * radius * constants::pi }; // using the namespace 'constants' and the scope resolution operator '::' to place the value of pi, defined in Addition.h
	std::cout << std::fixed << "The circumference is: " << circumference << '\n';
}
//begin project 8
//Write a program that asks the user to input an integer and tells the user whether the number is even or odd. Write a function called isEven() that returns true
//if an integer passsed to it is even and false otherwise. Use the modulus operator to test whether the integer paramater is even.

bool proj8IsEven(int x)	//This is my answer, it works but a function that only checks even/odd and returns a boolean would be reusable. Make this a habit.
{
	return (x % 2 == 0);
}

void MainFrame::proj8()
{
	wxStreamToTextRedirector redirect(gui_out);
	int x = getIntInput(wxString{ "Enter an integer." }, wxString{ "" }, wxString{ "" });
		if (bool y = proj8IsEven(x) == true)
			std::cout << x << " is even" << '\n';
		else
			std::cout << x << " is odd" << '\n';
}
void proj9Compare(int smaller, int larger)
{
	if (smaller > larger)// if the user did it wrong
	{	//swap the values of smaller and larger
		std::cout << "Swapping the values" << '\n';
		int temp{ smaller };
		smaller = larger;
		larger = temp;
	}//temp dies here
	std::cout << "The smaller value is " << smaller << '\n';
	std::cout << "The larger value is " << larger << '\n';
}// smaller and larger die here
void MainFrame::proj9()
{
	wxStreamToTextRedirector redirect(gui_out);
	int smaller{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	int larger{ getIntInput(wxString { "Enter a larger integer." },wxString { "" }, wxString {""})};
	proj9Compare(smaller, larger);
}
//begin project 10
void MainFrame::proj10()
{
	wxStreamToTextRedirector redirect(gui_out);
	int num{ getIntInput(wxString { "Enter a positive number." },wxString { "Positive Number:"}, wxString {""})};

	if
		(num < 0)
	{
		std::cout << "Negative number entered.  Making positive.\n";
		num = -num;
	}
	std::cout << "You entered: " << num << '\n';
}
//begin project 11
//Write a program that asks the user to enter their full name and their age. As output, tell the user how many years they’ve lived for each letter in their name(for simplicity, count spaces as a letter).
//Sample output :
//Enter your full name : John Doe
//Enter your age : 46
//You've lived 5.75 years for each letter in your name.
void MainFrame::proj11()
{
	wxStreamToTextRedirector redirect(gui_out);
	wxString name{ getTextInput(wxString { "Enter your full name." },wxString { "Name:" }, wxString { "" }) };

	int age{ getIntInput(wxString { "Enter your age." },wxString { "Age" }, wxString { "" })};

	double nameLength{ static_cast<double>(name.length()) };//name.length returns an unsigned integer, bad to use and we need a double for the division anyway
	double nameAgeDiv = { age / nameLength };
	std::cout << "You've lived " << nameAgeDiv << " years for each letter in your name.";
}
void MainFrame::proj12()
{
	wxStreamToTextRedirector redirect(gui_out);
	std::string str{ "I saw a red car yesterday."};

	str.replace(8, 3, "blue");

	std::cout << str << '\n'; // I saw a blue car yesterday.
}
//begin project 13
enum proj13ItemType
{
	ITEMTYPE_SWORD,
	ITEMTYPE_TORCH,
	ITEMTYPE_POTION
};

/*std::string getItemName(proj13ItemType itemType)
{
	if (itemType == ITEMTYPE_SWORD)
		return "Sword";
	if (itemType == ITEMTYPE_TORCH)
		return "Torch";
	if (itemType == ITEMTYPE_POTION)
		return "Potion";

	// Just in case we add a new item in the future and forget to update this function
	return "???";
}
*/
void MainFrame::proj13()
{
	wxStreamToTextRedirector redirect(gui_out);
	// ItemType is the enumerated type we've defined above.
	// itemType (lower case i) is the name of the variable we're defining (of type ItemType).
	// ITEMTYPE_TORCH is the enumerated value we're initializing variable itemType with.
	//proj13ItemType itemType{ ITEMTYPE_TORCH };
	//auto itemType{ ItemType::ITEMTYPE_TORCH };//Same as above but this is the fully scoped name. Used when enum class is used.

	//std::cout << "You are carrying a " << getItemName(itemType) << '\n';

	//The following is an example of using the enum class.
	enum class Colour
	{//scoped enumeration
		red,//red and blue are inside the scope of Colour
		blue
	};

	Colour colour{ Colour::red };

	if (colour == Colour::red) //red is not directly accessible, we have to use Colour::red
		std::cout << "The colour is red!\n";
	else if (colour == Colour::blue)
		std::cout << "The colour is blue!\n";
}
void MainFrame::proj14()
{
	wxStreamToTextRedirector redirect(gui_out);
	int amountViewed{ getIntInput(wxString { "Enter amount of ads viewed." },wxString { "" }, wxString { "" }) };
	double percentClicked{ getDblInput(wxString { "Enter percentage of ads clicked." },wxString { "" }, wxString { "" }) };
	double earnedPerClick{ getDblInput(wxString { "Enter amount earned per click." },wxString { "" }, wxString { "" }) };
	std::cout << "Amount of ads viewed by users: " << amountViewed << '\n';
	std::cout << "Percentage of ads clicked by users: " << percentClicked << '%' << '\n';
	std::cout << "Average amount earned per click: $" << earnedPerClick << '\n';
	std::cout << "Daily earnings: $" << ((percentClicked / 100) * amountViewed * earnedPerClick);
}
void MainFrame::proj15()
{
	wxStreamToTextRedirector redirect(gui_out);
	double numerator1{ getDblInput(wxString { "Enter a value for the numerator." },wxString { "" }, wxString { "" }) };
	double denominator1{ getDblInput(wxString { "Enter a value for the denominator." },wxString { ""}, wxString { "" }) };;
	double numerator2{ getDblInput(wxString { "Enter a value for the nuerator." },wxString { "" }, wxString { "" }) };;
	double denominator2{ getDblInput(wxString { "Enter a value for the denominator." },wxString { "" }, wxString { "" }) };;
	std::cout << numerator1 << '/' << denominator1 << " * " << numerator2 << '/' << denominator2 << " = " <<
		static_cast<double>(numerator1 * numerator2) / (denominator1 * denominator2) << '\n';
}

enum class proj16MonsterType
{
	dragon,
	ogre,
	giant_spider,
	orc,
	slime,
};
struct Monster
{
	proj16MonsterType type;
	std::string name;
	int health;
};
std::string monsterTypeString(proj16MonsterType type)
{
	if (type == proj16MonsterType::dragon)
		return "Dragon";
	else if (type == proj16MonsterType::ogre)
		return "Ogre";
	else if (type == proj16MonsterType::giant_spider)
		return "Giant Spider";
	else if (type == proj16MonsterType::orc)
		return "Orc";
	else if (type == proj16MonsterType::slime)
		return "Slime";

	return "Unknown Monster";
}
void printMonster(Monster monster)
{
	std::cout << "This " << monsterTypeString(monster.type) << " is named " << monster.name << " and has " << monster.health << " health." << '\n';
}
void MainFrame::proj16()
{
	wxStreamToTextRedirector redirect(gui_out);
	Monster ogre{ {proj16MonsterType::ogre}, "Torg", 145 };
	Monster slime{ {proj16MonsterType::slime}, "Blurp", 23 };
	printMonster(ogre);
	printMonster(slime);
}
//begin project 17
//proj17 readNumber() and writeAnswer() are in addition.cpp with forward declarations in Addition.h
void MainFrame::proj17()
{
	wxStreamToTextRedirector redirect(gui_out);
	int a{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	int b{ getIntInput(wxString { "Enter another integer." },wxString { "" }, wxString { "" }) };
	std::cout << "The sum is " << (a + b) << '\n';
}
void proj18CalculateAndPrint(double inputA, char charInput, double inputB)
{
	if (charInput == '+')
		std::cout << inputA << charInput << inputB << '=' << inputA + inputB << '\n';
	else if (charInput == '-')
		std::cout << inputA << charInput << inputB << '=' << inputA - inputB << '\n';
	else if (charInput == '*')
		std::cout << inputA << charInput << inputB << '=' << inputA * inputB << '\n';
	else if (charInput == '/')
		std::cout << inputA << charInput << inputB << '=' << inputA / inputB << '\n';
}
void MainFrame::proj18()
{
	wxStreamToTextRedirector redirect(gui_out);
	double a {getDblInput(wxString { "Enter a floating point number. E.g. 10.32" },wxString { "" }, wxString { "" }) };
	double b {getDblInput(wxString { "Enter another floating point number." },wxString { "" }, wxString { "" }) };
	wxString c{ getTextInput(wxString { "Enter one of the following: +, -, *, or /" },wxString { "Operator:" }, wxString { "" }) };
	if (c == '+')
		std::cout << a << c << b << '=' << a + b << '\n';
	else if (c == '-')
		std::cout << a << c << b << '=' << a - b << '\n';
	else if (c == '*')
		std::cout << a << c << b << '=' << a * b << '\n';
	else if (c == '/')
		std::cout << a << c << b << '=' << a / b << '\n';
}
double proj19CalculateBallHeight(double towerHeight, int secondsFallen)
{
	double distanceFallen{ (constants::gravity * (static_cast<double>(secondsFallen) * static_cast<double>(secondsFallen)) / 2.0) };
	double calculatedBallHeight{ towerHeight - distanceFallen };
	return calculatedBallHeight;
}
void proj19PrintHeight(double ballHeight, int seconds)
{
	if (ballHeight > 0.0) 
	{
		if (seconds == 1)
			std::cout << "At " << 1 << " second, the ball is at a height of " << ballHeight << " meters." << "\n";

		if (seconds > 1)
		std::cout << "At " << seconds << " seconds , the ball is at a height of " << ballHeight << " meters." << '\n';
	}
	else
		std::cout << "At " << seconds << " seconds , the ball is on the ground " << '\n';
}
void proj19CalculateAndPrintHeight(double towerHeight, int seconds)
{
	double ballHeight{ proj19CalculateBallHeight(towerHeight, seconds) };
	proj19PrintHeight(ballHeight, seconds);
}
void MainFrame::proj19()
{
	wxStreamToTextRedirector redirect(gui_out);
	const double towerHeight{ getDblInput(wxString { "Enter the height of the tower in meters." },wxString { "" }, wxString { "" }) };
	proj19CalculateAndPrintHeight(towerHeight, 0);
	proj19CalculateAndPrintHeight(towerHeight, 1);
	proj19CalculateAndPrintHeight(towerHeight, 2);
	proj19CalculateAndPrintHeight(towerHeight, 3);
	proj19CalculateAndPrintHeight(towerHeight, 4);
	proj19CalculateAndPrintHeight(towerHeight, 5);
}
void MainFrame::proj20()
{
	wxStreamToTextRedirector redirect(gui_out);
	int a{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	int b{ getIntInput(wxString { "Enter another integer." },wxString { "" }, wxString { "" }) };
	wxString str{ getTextInput(wxString { "Enter one of the following operators: +, -, *, / or %" },wxString { "" }, wxString { "" }) };
	wxChar c = str[0];
	{
		switch (c)
		{
		case ('+'):
			std::cout << a << " + " << b << " = " << (a + b) << '\n';
			break;
		case  ('-'):
			std::cout << a << " - " << b << " = " << (a - b) << '\n';
			break;
		case  ('*'):
			std::cout << a << " * " << b << " = " << (a * b) << '\n';
			break;
		case  ('/'):
			std::cout << a << " / " << b << " = " << (a / b) << '\n';
			break;
		case  ('%'):
			std::cout << a << " % " << b << " = " << (a % b) << '\n';
			break;
		default:
		{
			std::cout << "Please enter a valid operator." << '\n';
			proj20();
			break;
		}
		}
	}
}
void proj21Q1()
{
	char askey{ 'a' };
	while (askey <= 'z')
	{
		std::cout << askey << ' ' << static_cast<int>(askey) << '\n';
		++askey;
	}
	std::cout << '\n';
}
//Print 5 4 3 2 1
//		4 3 2 1 etcetera to 1
void proj21Q2()
{
	int outer{ 5 };
	while (outer >= 1)
	{
		int inner{ outer };
		while (inner >= 1)
		{
			std::cout << inner-- << ' ';
		}
		std::cout << '\n';
		--outer;
	}
}
void proj21Q3()
{
	int outer{ 1 };
	while (outer <= 5)
	{
		int inner{ outer };
		int inner2{ outer };
		while (inner >= 1)
		{
			while (inner2 <= 4)
			{
				std::cout << "  ";
				++inner2;
			}
			if (inner == outer)
				std::cout << inner;
			else
				std::cout << ' ' << inner;

			--inner;
		}
		++outer;
		std::cout << '\n';
	}
}
void MainFrame::proj21()
{
	wxStreamToTextRedirector redirect(gui_out);
	proj21Q1();
	proj21Q2();
	proj21Q3();
}
//begin project 22
//Write a for loop that prints every even number from 0 to 20.
void proj22Q1(int value)
{
	for (int y{ 0 }; y <= value; y += 2)
		std::cout << y << '\n';
}
//Write a function named sumTo() that takes an integer parameter named value, and returns the sum of all the numbers from 1 to value.
//For example, sumTo(5) should return 15, which is 1 + 2 + 3 + 4 + 5.
int sumTo(int value)
{
	int total{ 0 };
	for (int count{ 1 }; count <= value; ++count)
		total += count;
	return total;
}
void MainFrame::proj22()
{
	wxStreamToTextRedirector redirect(gui_out);
	int value{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	std::cout << "Printing every even number from 0 to " << value << '.' << '\n';
	proj22Q1(value);
	std::cout << '\n';
	std::cout << "Printing the sum of all the numbers from 1 to " << value << ". Example: entered number 5: (1 + 2 + 3 + 4 + 5) = 15" << '\n';
	std::cout << sumTo(value);
}
void MainFrame::proj23Auto()
{
	srand((unsigned)time(0));//sets the random seed to the current time
	int correctDoor{};
	int firstChoice{};
	int removedDoor{};
	int secondChoice{};
	double keepWinCounter{};
	double swapWinCounter{};
	std::cout << "Up to 100 iterations can be actively watched," << '\n'
				<< "or up to "  << std::setprecision(2) << std::fixed << std::numeric_limits<double>::max() << '\n' 
				<< "iterations can be done behind the scenes." << '\n' 
				<< "About 25s run time for 100,000,000 iterations on creator's machine." << '\n' 
				<< "About 238s run time for 1,000,000,000 iterations on creator's machine." << '\n' << '\n';

	double iterations { getDblInput(wxString { "Enter amount of iterations." },wxString { "" }, wxString { "" }) };
	wxBusyCursor wait;
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << std::setprecision(0) << "Running " << iterations << " times..." << '\n' << '\n';
	for (int count = 0; count < iterations; count++) //user chooses how many times to run this loop
	{
		correctDoor = (rand() % 3) + 1; //randomly picks the correct door
		firstChoice = (rand() % 3) + 1;//randomly makes the first door choice
		if (correctDoor != firstChoice)//removes one incorrect door if the first choice was incorrect (example: 6 - correctdoor(2) + firstchoice(1) = 3 or 6-2+1=3)
			removedDoor = (6 - (correctDoor + firstChoice));
		else if (correctDoor == 1 && firstChoice == 1)  //these next three ifs remove one incorrect door if the first choice was correct
			removedDoor = (rand() % 2) + 2;				//randomly picks 2 or 3
		else if (correctDoor == 2 && firstChoice == 2)
			removedDoor = (rand() % 4) + 1 <= 2 ? 1 : 3;//randomly picks 1-4, if less than or equal to 2 evaluates to 1 else evaluates to 3
		else if (correctDoor == 3 && firstChoice == 3)
			removedDoor = (rand() % 2) + 1;				//randomly picks 1 or 2

		if ((firstChoice == 1 && removedDoor == 2) || (firstChoice == 2 && removedDoor == 1))//swaps for door 3 if 1 or 2 were removed
			secondChoice = 3;
		else if ((firstChoice == 3 && removedDoor == 1) || (firstChoice == 1 && removedDoor == 3))//swaps for door 2 if 1 or 3 were removed
			secondChoice = 2;
		else if ((firstChoice == 2 && removedDoor == 3) || (firstChoice == 3 && removedDoor == 2))//swaps for door 1 if 2 or 3 were removed
			secondChoice = 1;

		if (firstChoice == correctDoor)//counts wins for not swapping
			++keepWinCounter;

		if (secondChoice == correctDoor)//counts wins for swapping
			++swapWinCounter;

		if (count % 100000 == 0)
		{
			gui_out->Clear();
			std::cout << count << " iterations ran.";
			gui_out->Clear();
		}


		if (iterations <= 100)
		{
			std::cout << "The first choice was: " << firstChoice << '\n'
				<< "The door removed was: " << removedDoor << '\n'
				<< "The door picked if you chose to swap was: " << secondChoice << '\n'
				<< "The correct door was: " << correctDoor << '\n' << '\n';
		}
	}
	std::cout << iterations << " iterations ran." << '\n' << "Wins for Keep: " << std::setprecision(0) << keepWinCounter << '/' << iterations << " = " << std::setprecision(2) << ((keepWinCounter / iterations) * 100) << '%' << '\n'
		<< "Wins for Swap: " << std::setprecision(0) << swapWinCounter << '/' << iterations << " = " << std::setprecision(2) << ((swapWinCounter / iterations) * 100) << '%' << '\n' << '\n';

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Run time: " << elapsed.count() << " s\n" << std::scientific;
	//wxString continueAuto{ getTextInput(wxString { "Run again?" },wxString { "" }, wxString { "" }) };
	int continueAuto = wxMessageBox("Run again?", " ", wxYES_NO, this);
	if (continueAuto == wxYES)
	{
		gui_out->Clear();
		proj23Auto();
	}
}
void MainFrame::proj23Manual()
{
	srand((unsigned)time(0));//sets the random seed to the current time
	int iterations{};
	int correctDoor{};
	int removedDoor{};
	int secondChoice{};
	int winsForPlayer{};
	int continueManual = wxYES;
	uint64_t keepWinCounter{};
	uint64_t swapWinCounter{};
	while (continueManual == wxYES)
	{
		start:
		int firstChoice{ getIntInput(wxString { "Pick door 1, 2 or 3?" },wxString { "" }, wxString { "" }) };
		if (firstChoice == 1 || firstChoice == 2 || firstChoice == 3)
		{
			correctDoor = (rand() % 3) + 1; //randomly picks the correct door
			if (correctDoor != firstChoice) //removes one incorrect door if the first choice was incorrect (example: 6 - correctdoor(2) + firstchoice(1) = 3 or 6-2+1=3)
				removedDoor = (6 - (correctDoor + firstChoice));
			else if (correctDoor == 1 && firstChoice == 1)  //these next three ifs remove one incorrect door if the first choice was correct
				removedDoor = (rand() % 2) + 2;				//randomly picks 2 or 3
			else if (correctDoor == 2 && firstChoice == 2)
				removedDoor = (rand() % 4) + 1 <= 2 ? 1 : 3;//randomly picks 1-4, if less than or equal to 2 evaluates to 1 else evaluates to 3
			else if (correctDoor == 3 && firstChoice == 3)
				removedDoor = (rand() % 2) + 1;				//randomly picks 1 or 2

			std::cout << "First choice: " << firstChoice << '\n';
			std::cout << "Door " << removedDoor << " is not the correct door and has been removed." << '\n' << '\n';
			wxString swapChoice{ getTextInput(wxString { "Swap to the other door or Keep yours?" },wxString { ""}, wxString {""}) };

			if ((firstChoice == 1 && removedDoor == 2) || (firstChoice == 2 && removedDoor == 1))//swaps for door 3 if 1 or 2 were removed
				secondChoice = 3;
			else if ((firstChoice == 3 && removedDoor == 1) || (firstChoice == 1 && removedDoor == 3))//swaps for door 2 if 1 or 3 were removed
				secondChoice = 2;
			else if ((firstChoice == 2 && removedDoor == 3) || (firstChoice == 3 && removedDoor == 2))//swaps for door 1 if 2 or 3 were removed
				secondChoice = 1;

			if (firstChoice == correctDoor)//counts wins for not swapping
				++keepWinCounter;

			if (secondChoice == correctDoor)//counts wins for swapping
				++swapWinCounter;

			std::cout << "The first choice was: " << firstChoice << '\n'
				<< "The door removed was: " << removedDoor << '\n';

			if (swapChoice == "swap" || swapChoice == "s")
			{
				std::cout << "You chose to swap your door." << '\n';
			}
			else if (swapChoice == "keep" || swapChoice == "k")
			{
				std::cout << "You chose to keep your door." << '\n';
			}

			std::cout << "The correct door was: " << correctDoor << '\n';

			if ((firstChoice == correctDoor && swapChoice == "keep") || (firstChoice == correctDoor && swapChoice == "k")
				|| (firstChoice != correctDoor && swapChoice == "swap") || (firstChoice != correctDoor && swapChoice == "s"))
			{
				++winsForPlayer;
				std::cout << "Congratulations, you win!" << '\n' << '\n';
			}
			else
			{
				std::cout << "Sorry, you lose." << '\n' << '\n';
			}

			iterations++;
			double doubleKeepWin{ static_cast<double>(keepWinCounter) };//convert all unsigned integers to double to use in division to find percentage of wins
			double doubleSwapWin{ static_cast<double>(swapWinCounter) };
			double doubleIterations{ static_cast<double>(iterations) };
			std::cout << std::setprecision(2) << std::fixed << "Wins for Keep: " << keepWinCounter << '/' << iterations << " = " << ((doubleKeepWin / doubleIterations) * 100) << '%' << '\n'
				<< "Wins for Swap: " << swapWinCounter << '/' << iterations << " = " << ((doubleSwapWin / doubleIterations) * 100) << '%' << '\n'
				<< "Wins for player: " << winsForPlayer << '/' << iterations << " = " << ((winsForPlayer / doubleIterations) * 100) << '%' << '\n'
				<< "Times ran: " << iterations << std::fixed << '\n' << '\n' << '\n';
			continueManual = wxMessageBox("Run again?", " ", wxYES_NO, this);
		}
		else
			goto start;
	}
}
void MainFrame::proj23()
{
	wxStreamToTextRedirector redirect(gui_out);
	wxString str{ getTextInput(wxString { "Automatic or manual Monty Hall program?" },wxString { "" }, wxString { "" }) };
	int choice23{};
	if (str == "automatic" || str == "auto" || str == "a")
	{
		choice23 = 1;
	}
	else if (str == "manual" || str == "m")
	{
		choice23 = 2;
	}
	switch (choice23)
	{
	case 1:
		proj23Auto();
		break;
	case 2:
		proj23Manual();
		break;
	default: std::cout << "Error, invalid choice. Please choose again." << '\n' << '\n';
		proj23();
		break;
	}
}
double proj24CalculateHeight(double initialHeight, int seconds)
{
	double distanceFallen = constants::gravity * seconds * seconds / 2;
	double heightNow = initialHeight - distanceFallen;

	// Check whether we've gone under the ground
	// If so, set the height to ground-level
	if (heightNow < 0.0)
		return 0.0;
	else
		return heightNow;
}
void proj24CalculateAndPrintHeight(double initialHeight, int time)
{
	if (time == 1)
		std::cout << "At " << 1 << std::setprecision(0) << std::fixed << " second, the ball is at a height of " << proj24CalculateHeight(initialHeight, time) << std::scientific << "\n";
	else if (time != 1)
	std::cout << "At " << time << std::setprecision(0) << std::fixed << " seconds, the ball is at a height of " << proj24CalculateHeight(initialHeight, time) << " meters." << std::scientific << "\n";
}
void MainFrame::proj24()
{
	wxStreamToTextRedirector redirect(gui_out);
	double initialHeight{getDblInput(wxString { "Enter the initial height of the tower in meters." },wxString { "" }, wxString { "" }) };
	std::cout << "The ball is dropped from " << std::fixed << std::setprecision(2) <<  initialHeight << " meters." << '\n';
	int seconds{ 1 };
	double heightNow{ proj24CalculateHeight(initialHeight, seconds) };
	wxBusyCursor wait;
	auto start = std::chrono::high_resolution_clock::now();
	if (heightNow > 0)
		while (heightNow > 0)
		{
			proj24CalculateAndPrintHeight(initialHeight, seconds);
			++seconds;
			heightNow = proj24CalculateHeight(initialHeight, seconds);
		}
	std::cout << "At " << seconds << " seconds, the ball is on the ground." << '\n' << '\n';
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Function run time: " << std::setprecision(2) << std::fixed << elapsed.count() << " s\n" << std::scientific;
}
bool proj25IsPrime(int num)
{
	if (num == 0 || num == 1)
		return false;
	else
		for (int count = 2; count <= num / 2; count++)
			if (num % count == 0)
			{
				return false;
			}
	return true;
}
void MainFrame::proj25()
{
	wxStreamToTextRedirector redirect(gui_out);
	std::cout << "Pre-check" << '\n';
	assert(!proj25IsPrime(0));
	assert(!proj25IsPrime(1));
	assert(proj25IsPrime(2));
	assert(proj25IsPrime(3));
	assert(!proj25IsPrime(4));
	assert(proj25IsPrime(5));
	assert(proj25IsPrime(7));
	assert(!proj25IsPrime(9));
	assert(proj25IsPrime(11));
	assert(proj25IsPrime(13));
	assert(!proj25IsPrime(15));
	assert(!proj25IsPrime(16));
	assert(proj25IsPrime(17));
	assert(proj25IsPrime(19));
	assert(proj25IsPrime(97));
	assert(!proj25IsPrime(99));
	assert(!proj25IsPrime(99));
	assert(proj25IsPrime(13417));

	std::cout << "Success!";
}