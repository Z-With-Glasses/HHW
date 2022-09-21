#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "Addition.h"
#include "HHWDescriptions.h"
#include "HHWProjStrings.h"
#include <algorithm>
#include <array>
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
#include <random>
#include <stdlib.h>																
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include <wx/arrstr.h>
#include <wx/choicdlg.h> 
#include <wx/colour.h>
#include <wx/font.h>
#include <wx/gauge.h>
#include <wx/listbox.h>
#include <wx/msgdlg.h>
#include <wx/numdlg.h> 
#include <wx/panel.h>
#include <wx/progdlg.h>
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
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	wxTextCtrl* gui_out;
	wxListBox* gui_choice;
	wxTextCtrl* gui_disp;
	wxTextCtrl* gui_info;
	wxSplitterWindow* gui_split;
	wxMessageDialog* gui_error;
	wxGauge* gui_gauge;
	wxProgressDialog* gui_gauge_dialog;
	wxNumberEntryDialog* getNum;

	void errorMessage(wxString message, wxWindow* parent);
	void progressMessage(wxString title, wxString message, int maximum, wxWindow* parent);
	void displayAndRunCommandEventHandler(wxCommandEvent& event);
	void displayAndRunKeyEventHandler(wxKeyEvent& event);
	void displayAndRun(int evntType);
	wxString getTextInput(wxString message, wxString prompt, wxString caption);
	double getDblInput(wxString message, wxString prompt, wxString caption, bool fractionalCheck);
	int getIntInput(wxString message, wxString prompt, wxString caption);
	wxString singleChoiceInput(wxString message, wxString caption, wxArrayString aChoices);
	void proj1();
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
		ID_gauge = 5,
		ID_panel_out = 11,
		ID_panel_disp = 12,
		ID_panel_choice = 13,
		ID_panel_controls = 14,
		ID_splitter = 15,
		ID_button_display = 21,
		ID_button_run = 22,
		ID_button_about = 23,
		ID_enter = 31
	};
};
/*
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(ID_button_display, MainFrame::displayAndRun)
EVT_BUTTON(ID_button_run, MainFrame::displayAndRun)
EVT_BUTTON(ID_button_about, MainFrame::onAbout)
EVT_LISTBOX_DCLICK(ID_dbl_click, MainFrame::displayAndRun)
EVT_LISTBOX(ID_sgl_click, MainFrame::displayAndRun)
EVT_COMMAND_ENTER(ID_enter, MainFrame::displayAndRun)
END_EVENT_TABLE()*/
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
	MainFrame* frame = new MainFrame("Hello, Hello World", wxDefaultPosition, wxDefaultSize);
	frame->Show(true);
	return true;
}
MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
	this->SetBackgroundColour(*wxBLACK);
	this->SetForegroundColour(*wxGREEN);
	wxFont myFont(10, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	this->SetFont(myFont);

	wxString choices[28] =
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
	 _T("Project 25: Prime Number Check With Assert"),
	 _T("Project Continue: Program's Continue Function"),
	 _T("Project Choice: Program's Choice Function"),
	 _T("Project Main: Program's Main Function")
	};

	gui_split = new wxSplitterWindow(this, ID_splitter, wxDefaultPosition, wxSize(600, 400), wxSP_3D | wxSP_LIVE_UPDATE);
	gui_out = new wxTextCtrl(gui_split, ID_out, wxString("Double click a project or select it with the arrow keys and press enter to run it here."), wxDefaultPosition, wxSize(600, 200), wxTE_READONLY | wxTE_MULTILINE | wxTE_DONTWRAP | wxTE_RICH | wxBORDER_THEME);
	gui_disp = new wxTextCtrl(gui_split, ID_out, wxString("Click on a project to display the code for it here."), wxDefaultPosition, wxSize(600, 200), wxTE_READONLY | wxTE_MULTILINE | wxTE_DONTWRAP | wxTE_RICH | wxBORDER_THEME);
	wxPanel* panel_choice = new wxPanel(this, ID_panel_choice, wxDefaultPosition, wxSize(315, 600), wxBORDER_RAISED);
	gui_choice = new wxListBox(panel_choice, ID_choice, wxDefaultPosition, wxSize(315, 600), 28, choices, wxLB_SINGLE | wxVSCROLL | wxWANTS_CHARS);
	gui_info = new wxTextCtrl(this, ID_info, wxString("Select a project to display the code or double click to run the project.\n\nThis program was created by Zack Green on 2021/07/05 using C++ and wxWidgets.\n\n           github.com/Z-With-Glasses"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_MULTILINE | wxTE_RICH | wxBORDER_THEME);
	gui_gauge = new wxGauge(this, ID_gauge, INT_MAX, wxDefaultPosition, wxSize(315, 15), wxGA_HORIZONTAL);

	wxBoxSizer* sizer_main = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* sizer_left = new wxBoxSizer(wxVERTICAL);
	gui_split->SplitHorizontally(gui_disp, gui_out);
	gui_split->SetSashGravity(.5);
	sizer_left->Add(panel_choice, 0);
	sizer_left->Add(gui_info, 1, wxEXPAND, 1);
	sizer_left->Add(gui_gauge);
	sizer_main->Add(sizer_left, 0, wxEXPAND);
	sizer_main->Add(gui_split, 1, wxEXPAND);
	this->SetSizerAndFit(sizer_main);

	gui_choice->Bind(wxEVT_LISTBOX, &MainFrame::displayAndRunCommandEventHandler, this);
	gui_choice->Bind(wxEVT_LISTBOX_DCLICK, &MainFrame::displayAndRunCommandEventHandler, this);
	gui_choice->Bind(wxEVT_KEY_DOWN, &MainFrame::displayAndRunKeyEventHandler, this);

	gui_disp->SetBackgroundColour(*wxBLACK);
	gui_disp->SetForegroundColour(*wxGREEN);
	gui_out->SetBackgroundColour(*wxBLACK);
	gui_out->SetForegroundColour(*wxGREEN);
	gui_choice->SetBackgroundColour(*wxBLACK);
	gui_choice->SetForegroundColour(*wxGREEN);
	gui_info->SetBackgroundColour(*wxBLACK);
	gui_info->SetForegroundColour(*wxGREEN);

	CreateStatusBar();
	SetStatusText("Select a project to display the code or double click to run the project.");
	this->SetSize(wxSize(1200, 1000));
	this->CenterOnScreen();
}
void MainFrame::errorMessage(wxString message, wxWindow* parent)
{
	gui_error = new wxMessageDialog(this, wxString(message), wxString("Error!"), wxOK | wxSTAY_ON_TOP, wxDefaultPosition);
	gui_error->ShowModal();
}
void MainFrame::progressMessage(wxString title, wxString message, int maximum, wxWindow* parent)
{

	gui_gauge_dialog = new wxProgressDialog(wxString(title), wxString(message), maximum, parent, wxPD_APP_MODAL | wxPD_REMAINING_TIME | wxPD_CAN_ABORT);
	gui_gauge_dialog->Move(wxCoord(850), wxCoord(350));
}
wxString MainFrame::getTextInput(wxString message, wxString prompt, wxString caption)
{
start:
	wxString input{ wxGetTextFromUser(wxString(message), wxString(prompt), wxString(caption), gui_disp, wxCoord(850), wxCoord(350), false) };
	int inputLength = (input.Length());
	if (wxIsspace(input.GetChar(0)))
	{
		errorMessage(wxString("Don't start with blank space."), this);
		goto start;
	}
	for (int x = 0; x < inputLength; ++x)
	{
		if (!wxIsalpha(input.GetChar(x)) && !wxIsspace(input.GetChar(x)))
		{
			errorMessage(wxString("Error! Enter a name without numbers or special characters."), this);
			goto start;
		}
	}
	return input;
}
int MainFrame::getIntInput(wxString message, wxString prompt, wxString caption)
{
start:
	getNum = new wxNumberEntryDialog(this, wxString(message), wxString(prompt), wxString(caption), long{ 0 }, long{ LONG_MIN }, long{ LONG_MAX }, wxPoint(850, 350));
	getNum->ShowModal();
	int input = getNum->GetValue();
	if (input == -2147483648)
	{
		errorMessage(wxString("Error! Enter an integer."), this);
		goto start;
	}
	return input;
}
double MainFrame::getDblInput(wxString message, wxString prompt, wxString caption, bool fractionalCheck)
{
start:
	wxString input{ wxGetTextFromUser(wxString(message), wxString(prompt), wxString(caption), gui_disp, wxCoord(850), wxCoord(350), false) };
	if (input == wxString(""))
	{
		return 0;
	}
	double value = wxAtof(input);
	int inputLength = (input.Length());
	int periodCount{};
	for (int x = 0; x < inputLength; ++x)
	{
		if (input.GetChar(x) == '.')
			periodCount++;
		if (periodCount > 1)
		{
			errorMessage(wxString("Error! Too many decimal points."), this);// emsures only one period is entered for fractional numbers
			goto start;
		}
		if (wxIsalpha(input.GetChar(x)))
		{
			errorMessage(wxString("Error! Characters not allowed."), this);//ensures no characters are entered
			goto start;
		}
		else if (!fractionalCheck && (wxIspunct(input.GetChar(x))))//if fractional number not allowed but double needed for fractional division
		{
			errorMessage(wxString("Error! Enter a whole number."), this);
			goto start;
		}
		else if (fractionalCheck && ((input.GetChar(x) != '.') && !wxIsdigit(input.GetChar(x))))//ensures only periods are allowed for fractional numbers
		{
			errorMessage(wxString("Error! Special characters not allowed."), this);
			goto start;
		}
	}
	return value;
}
wxString MainFrame::singleChoiceInput(wxString message, wxString caption, wxArrayString aChoices)
{
	wxString input{ wxGetSingleChoice(wxString(message), wxString(caption), wxArrayString(aChoices), gui_disp, wxCoord(850), wxCoord(350), false) };
	return input;
}
void MainFrame::displayAndRunCommandEventHandler(wxCommandEvent& event)
{
	int evntType = event.GetEventType();
	MainFrame::displayAndRun(evntType);
}
void MainFrame::displayAndRunKeyEventHandler(wxKeyEvent& event)
{
	int keyvntType{};
	if (event.GetKeyCode() == WXK_RETURN || event.GetKeyCode() == WXK_NUMPAD_ENTER)
		keyvntType = 1;

	//make arrow keys navigate listbox since this function handles all keypresses and overwrites the default behaviour
	int selection = gui_choice->GetSelection();
	if (event.GetKeyCode() == WXK_DOWN)
	{
		gui_choice->SetSelection(++selection);
	}
	if (selection > 0)//stops working if it hits the top so the selection can't become invalid
	{
		if (event.GetKeyCode() == WXK_UP)
		{
			gui_choice->SetSelection(--selection);
		}
	}

	MainFrame::displayAndRun(keyvntType);
}
void MainFrame::displayAndRun(int evntType)
{
	//int andRun{ event.GetId() };
	int choice{ gui_choice->GetSelection() };
	gui_out->Clear();
	if (evntType != wxEVT_LISTBOX_DCLICK && evntType != 1)
	{
		gui_out->AppendText("Double click a project or select it with the arrow keys and press enter to run it here.");
	}

	switch (choice)
	{
	case 0:
		gui_disp->SetLabel(proj1String());
		SetStatusText("Project 1: Integer Doubling");
		gui_info->SetLabel(proj1Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj1();
			break;
		}
		break;
	case 1:
		gui_disp->SetLabel(proj2String());
		SetStatusText("Project 2: Integer Doubling w/ Parameter");
		gui_info->SetLabel(proj2Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj1();
			break;
		}
		break;
	case 2:
		gui_disp->SetLabel(proj3String());
		SetStatusText("Project 3: Forward Declaration Demonstration-Integer Addition");
		gui_info->SetLabel(proj3Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj3();
			break;
		}
		break;
	case 3:
		gui_disp->SetLabel(proj4String());
		SetStatusText("Project 4: Data Types And Sizes");
		gui_info->SetLabel(proj4Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj4();
			break;
		}
		break;
	case 4:
		gui_disp->SetLabel(proj5String());
		SetStatusText("Project 5: Prime Number Checker");
		gui_info->SetLabel(proj5Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj5();
			break;
		}
		break;
	case 5:
		gui_disp->SetLabel(proj6String());
		SetStatusText("Project 6: Character Usage Demonstration");
		gui_info->SetLabel(proj6Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj6();
			break;
		}
		break;
	case 6:
		gui_disp->SetLabel(proj7String());
		SetStatusText("Project 7: Constants Demonstration-Radius To Circumfrence");
		gui_info->SetLabel(proj7Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj7();
			break;
		}
		break;
	case 7:
		gui_disp->SetLabel(proj8String());
		SetStatusText("Project 8: Even Or Odd");
		gui_info->SetLabel(proj8Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj8();
			break;
		}
		break;
	case 8:
		gui_disp->SetLabel(proj9String());
		SetStatusText("Project 9: Low And High Integer Swap");
		gui_info->SetLabel(proj9Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj9();
			break;
		}
		break;
	case 9:
		gui_disp->SetLabel(proj10String());
		SetStatusText("Project 10: Positive Number Swap");
		gui_info->SetLabel(proj10Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj10();
			break;
		}
		break;
	case 10:
		gui_disp->SetLabel(proj11String());
		SetStatusText("Project 11: Years Lived Per Character In Name");
		gui_info->SetLabel(proj11Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj11();
			break;
		}
		break;
	case 11:
		gui_disp->SetLabel(proj12String());
		SetStatusText("Project 12: Character Replacement In Strings");
		gui_info->SetLabel(proj12Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj12();
			break;
		}
		break;
	case 12:
		gui_disp->SetLabel(proj13String());
		SetStatusText("Project 13: Enumerators And Enumerated Classes");
		gui_info->SetLabel(proj13Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj13();
			break;
		}
		break;
	case 13:
		gui_disp->SetLabel(proj14String());
		SetStatusText("Project 14: Struct Demonstration-Ad Revenue");
		gui_info->SetLabel(proj14Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj14();
			break;
		}
		break;
	case 14:
		gui_disp->SetLabel(proj15String());
		SetStatusText("Project 15: Struct Demonstration-Fractional Multiplication");
		gui_info->SetLabel(proj15Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj15();
			break;
		}
		break;
	case 15:
		gui_disp->SetLabel(proj16String());
		SetStatusText("Project 16: Struct Demonstration-RPG");
		gui_info->SetLabel(proj16Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj16();
			break;
		}
		break;
	case 16:
		gui_disp->SetLabel(proj17String());
		SetStatusText("Project 17: Integer Addition");
		gui_info->SetLabel(proj17Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj17();
			break;
		}
		break;
	case 17:
		gui_disp->SetLabel(proj18String());
		SetStatusText("Project 18: Floating Point Math With Error Catch");
		gui_info->SetLabel(proj18Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj18();
			break;
		}
		break;
	case 18:
		gui_disp->SetLabel(proj19String());
		SetStatusText("Project 19: Ball Drop From Tower #1");
		gui_info->SetLabel(proj19Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj19();
			break;
		}
		break;
	case 19:
		gui_disp->SetLabel(proj20String());
		SetStatusText("Project 20: Integer Addition With Switch Statement");
		gui_info->SetLabel(proj20Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj20();
			break;
		}
		break;
	case 20:
		gui_disp->SetLabel(proj21String());
		SetStatusText("Project 21: Loops And Nested Loops");
		gui_info->SetLabel(proj21Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj21();
			break;
		}
		break;
	case 21:
		gui_disp->SetLabel(proj22String());
		SetStatusText("Project 22: For Loop Of Evens");
		gui_info->SetLabel(proj22Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj22();
			break;
		}
		break;
	case 22:
		gui_disp->SetLabel(proj23String());
		SetStatusText("Project 23: The Monty Hall Problem");
		gui_info->SetLabel(proj23Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj23();
			break;
		}
		break;
	case 23:
		gui_disp->SetLabel(proj24String());
		SetStatusText("Project 24: Ball Drop From Tower #2: ");
		gui_info->SetLabel(proj24Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj24();
			break;
		}
		break;
	case 24:
		gui_disp->SetLabel(proj25String());
		SetStatusText("Project 25: Prime Number Check With Assert");
		gui_info->SetLabel(proj25Info());
		if (evntType == wxEVT_LISTBOX_DCLICK || evntType == 1)
		{
			proj25();
			break;
		}
		break;
	case 25:
		gui_disp->SetLabel(projContinueString());
		SetStatusText("Program's Continue Function");
		gui_info->SetLabel(projContinueInfo());
		break;
	case 26:
		gui_disp->SetLabel(projChoiceString());
		SetStatusText("Program's Choice Function");
		gui_info->SetLabel(projChoiceInfo());
		break;
	case 27:
		gui_disp->SetLabel(projMainString());
		SetStatusText("Program's Main Function");
		gui_info->SetLabel(projMainInfo());
		break;
	default:
	{
		wxStreamToTextRedirector redirect(gui_out);
		std::cout << "Select a project, then click Display or Run." << '\n';
		break;
	}
	}
}
//--------------------------------------------------|Projects|--------------------------------------------------//
void MainFrame::proj1()
{
	wxStreamToTextRedirector redirect(gui_out);
	int num{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	if (num != 0)
		std::cout << "Double that integer is: " << num * 2 << '\n';
}

void MainFrame::proj3()
{
	wxStreamToTextRedirector redirect(gui_out);
	int a{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	int b{ getIntInput(wxString { "Enter another integer." },wxString { "" }, wxString { "" }) };
	if ((a + b) != 0)
		std::cout << a << " + " << b << " = " << a + b << '\n';
}

void MainFrame::proj4()
{
	wxStreamToTextRedirector redirect(gui_out);
	std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
	std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
	std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
	std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n"; // C++11 only
	std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n"; // C++11 only
	std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
	std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
	std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
	std::cout << "long long:\t" << sizeof(long long) << " bytes\n"; // C++11 only
	std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
	std::cout << "double:\t" << sizeof(double) << " bytes\n";
	std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
}

void MainFrame::proj5()
{
	wxStreamToTextRedirector redirect(gui_out);
	long n, i, m = 0, flag = 0;
	n = getIntInput(wxString{ "Enter a number." }, wxString{ "Number:" }, wxString{ "" });
	if (n > 0)
	{
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
	else if (n < 0)
	{
		errorMessage(wxString("Enter a positive number."), gui_out);
		gui_out->Clear();
		proj5();
	}

}

void MainFrame::proj6()
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

void MainFrame::proj7()
{
	wxStreamToTextRedirector redirect(gui_out);
	int radius{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString {""}) };
	if (radius > 0)
	{
		double circumference{ 2.0 * radius * constants::pi };
		std::cout << std::fixed << "The circumference is: " << circumference << '\n';
	}
	else if (radius < 0)
	{
		errorMessage(wxString("Enter a positive number."), gui_out);
		gui_out->Clear();
		proj7();
	}
}

bool proj8IsEven(int x)
{
	return (x % 2 == 0);
}

void MainFrame::proj8()
{
	wxStreamToTextRedirector redirect(gui_out);
	int x = getIntInput(wxString{ "Enter an integer." }, wxString{ "" }, wxString{ "" });
	if (x != 0)
	{
		if (x % 2 == 0)
			std::cout << x << " is even" << '\n';
		else
			std::cout << x << " is odd" << '\n';
	}
}

void proj9Compare(int smaller, int larger)
{
	if ((smaller + larger) != 0)
	{
		if (smaller > larger)
		{
			std::cout << "Swapping the values" << '\n';
			int temp{ smaller };
			smaller = larger;
			larger = temp;
		}
		std::cout << "The smaller value is " << smaller << '\n';
		std::cout << "The larger value is " << larger << '\n';
	}
}

void MainFrame::proj9()
{
	wxStreamToTextRedirector redirect(gui_out);
	int smaller{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	int larger{ getIntInput(wxString { "Enter a larger integer." },wxString { "" }, wxString {""}) };
	proj9Compare(smaller, larger);
}

void MainFrame::proj10()
{
	wxStreamToTextRedirector redirect(gui_out);
	int num{ getIntInput(wxString { "Enter a positive number." },wxString { "Positive Number:"}, wxString {""}) };
	if (num != 0)
	{
		if (num < 0)
		{
			std::cout << "Negative number entered.  Making positive.\n";
			num = -num;
		}
		std::cout << "You entered: " << num << '\n';
	}
}

void MainFrame::proj11()
{
	wxStreamToTextRedirector redirect(gui_out);
	wxString name{ getTextInput(wxString { "Enter your full name." },wxString { "Name:" }, wxString { "" }) };
agestart:
	int age{ getIntInput(wxString { "Enter your age." },wxString { "Age" }, wxString { "" }) };
	if (age > 0)
	{
		double nameLength{ static_cast<double>(name.length()) };
		double nameAgeDiv = { age / nameLength };
		std::cout << "You've lived " << nameAgeDiv << " years for each letter in your name.";
	}
	else if (age != 0)
	{
		errorMessage(wxString("Enter a valid age."), gui_out);
		goto agestart;
	}
}

void MainFrame::proj12()
{
	wxStreamToTextRedirector redirect(gui_out);
	std::string str{ "I saw a red car yesterday." };
	str.replace(8, 3, "blue");
	std::cout << str << '\n';
}

enum proj13ItemType
{
	ITEMTYPE_SWORD,
	ITEMTYPE_TORCH,
	ITEMTYPE_POTION
};

std::string getItemName(proj13ItemType itemType)
{
	if (itemType == ITEMTYPE_SWORD)
		return "sword";
	if (itemType == ITEMTYPE_TORCH)
		return "torch";
	if (itemType == ITEMTYPE_POTION)
		return "potion";

	return "???";
}

void MainFrame::proj13()
{
	wxStreamToTextRedirector redirect(gui_out);

	auto itemType{ proj13ItemType::ITEMTYPE_TORCH };

	enum class Colour
	{
		red,
		blue
	};
	Colour colour{ Colour::red };

	std::cout << "You are carrying a " << getItemName(itemType) << ',';

	if (colour == Colour::red)
		std::cout << " the colour is red!\n";
	else if (colour == Colour::blue)
		std::cout << " the colour is blue!\n";
}

void MainFrame::proj14()
{
	wxStreamToTextRedirector redirect(gui_out);
	int amountViewed{ getIntInput(wxString { "Enter amount of ads viewed." },wxString { "" }, wxString { "" }) };
	if (amountViewed > 0)
	{
		double percentClicked{ getDblInput(wxString { "Enter percentage of ads clicked." },wxString { "" }, wxString { "" }, true) };
		if (percentClicked > 0)
		{
			double earnedPerClick{ getDblInput(wxString { "Enter amount earned per click." },wxString { "" }, wxString { "" }, true) };
			if (earnedPerClick > 0)
			{
				std::cout << "Amount of ads viewed by users: " << amountViewed << '\n';
				std::cout << "Percentage of ads clicked by users: " << percentClicked << '%' << '\n';
				std::cout << "Average amount earned per click: $" << earnedPerClick << '\n';
				std::cout << "Daily earnings: $" << ((percentClicked / 100) * amountViewed * earnedPerClick);
			}
		}
	}
}

void MainFrame::proj15()
{
	wxStreamToTextRedirector redirect(gui_out);
	double numerator1{ getDblInput(wxString { "Enter a value for the numerator." },wxString { "" }, wxString { "" }, false) };
	if (numerator1 > 0)
	{
		double denominator1{ getDblInput(wxString { "Enter a value for the denominator." },wxString { ""}, wxString { "" }, false) };
		if (denominator1 > 0)
		{
			double numerator2{ getDblInput(wxString { "Enter a value for the nuerator." },wxString { "" }, wxString { "" }, false) };
			if (numerator2 > 0)
			{
				double denominator2{ getDblInput(wxString { "Enter a value for the denominator." },wxString { "" }, wxString { "" }, false) };
				if (denominator2 > 0)
				{
					std::cout << std::fixed << std::setprecision(2) << numerator1 << '/' << denominator1 << " * " << numerator2 << '/' << denominator2 << " = "
						<< static_cast<double>(numerator1 * numerator2) / (denominator1 * denominator2) << '\n';
				}
			}
		}
	}
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

void MainFrame::proj17()
{
	wxStreamToTextRedirector redirect(gui_out);
	int a{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	int b{ getIntInput(wxString { "Enter another integer." },wxString { "" }, wxString { "" }) };
	if ((a + b) != 0)
		std::cout << "The sum is " << (a + b) << '\n';
}

void MainFrame::proj18()
{
	wxArrayString operatorChoices;
	operatorChoices.Add(wxT("+"));
	operatorChoices.Add(wxT("-"));
	operatorChoices.Add(wxT("*"));
	operatorChoices.Add(wxT("/"));

	wxStreamToTextRedirector redirect(gui_out);
	double a{ getDblInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }, true) };
	wxString operatorChoiceStr{ singleChoiceInput(wxString{ "Add, subtract, multiply, or divide?" },wxString { "" }, operatorChoices) };
	wxChar c = operatorChoiceStr[0];
	double b{ getDblInput(wxString { "Enter another integer." },wxString { "" }, wxString { "" }, true) };
	if ((a + b) != 0)
	{
		{
			switch (c)
			{
			case ('+'):
				std::cout << std::fixed << a << " + " << b << " = " << (a + b) << '\n';
				break;
			case  ('-'):
				std::cout << std::fixed << a << " - " << b << " = " << (a - b) << '\n';
				break;
			case  ('*'):
				std::cout << std::fixed << a << " * " << b << " = " << (a * b) << '\n';
				break;
			case  ('/'):
				std::cout << std::fixed << a << " / " << b << " = " << (a / b) << '\n';
				break;
			default:
			{
				break;
			}
			}
		}
	}
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
	const double towerHeight{ getDblInput(wxString { "Enter the height of the tower in meters." },wxString { "" }, wxString { "" }, true) };
	if (towerHeight > 0)
	{
		proj19CalculateAndPrintHeight(towerHeight, 0);
		proj19CalculateAndPrintHeight(towerHeight, 1);
		proj19CalculateAndPrintHeight(towerHeight, 2);
		proj19CalculateAndPrintHeight(towerHeight, 3);
		proj19CalculateAndPrintHeight(towerHeight, 4);
		proj19CalculateAndPrintHeight(towerHeight, 5);
	}
}

void MainFrame::proj20()
{
	wxArrayString operatorChoices;
	operatorChoices.Add(wxT("+"));
	operatorChoices.Add(wxT("-"));
	operatorChoices.Add(wxT("*"));
	operatorChoices.Add(wxT("/"));
	operatorChoices.Add(wxT("%"));

	wxStreamToTextRedirector redirect(gui_out);
	int a{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	wxString operatorChoiceStr{ singleChoiceInput(wxString{ "Add, subtract, multiply, divide or modulus division?" },wxString { "" }, operatorChoices) };
	wxChar c = operatorChoiceStr[0];
	int b{ getIntInput(wxString { "Enter another integer." },wxString { "" }, wxString { "" }) };
	if ((a + b) != 0)
	{
		{
			switch (c)
			{
			case ('+'):
				std::cout << std::fixed << std::setprecision(10) << a << " + " << b << " = " << (a + b) << '\n';
				break;
			case  ('-'):
				std::cout << std::fixed << std::setprecision(10) << a << " - " << b << " = " << (a - b) << '\n';
				break;
			case  ('*'):
				std::cout << std::fixed << std::setprecision(10) << a << " * " << b << " = " << (a * b) << '\n';
				break;
			case  ('/'):
				std::cout << std::fixed << std::setprecision(10) << a << " / " << b << " = " << (a / b) << '\n';
				break;
			case  ('%'):
				std::cout << std::fixed << std::setprecision(10) << a << " % " << b << " = " << (a % b) << '\n';
				break;
			default:
			{
				break;
			}
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

void proj22Q1(int value)
{
	for (int y{ 0 }; y <= value; y += 2)
	{
		std::cout << y << '\n';
	}
}
int sumTo(int value)
{
	int total{ 0 };
	for (int count{ 1 }; count <= value; ++count)
	{
		total += count;
	}
	return total;
}
void MainFrame::proj22()
{
start:
	wxStreamToTextRedirector redirect(gui_out);
	int value{ getIntInput(wxString { "Enter an integer." },wxString { "" }, wxString { "" }) };
	if (value > 0)
	{
		std::cout << "Printing every even number from 0 to " << value << '.' << '\n';
		proj22Q1(value);
		std::cout << '\n' << "Printing the sum of all the numbers from 1 to " << value << ". Example: entered number 5: (1 + 2 + 3 + 4 + 5) = 15" << '\n';
		std::cout << sumTo(value);
	}
	else if (value < 0)
	{
		errorMessage(wxString("Enter a positive number."), gui_out);
		goto start;
	}
}

void MainFrame::proj23Auto()
{
	srand((unsigned)time(0));//sets the random seed to the current time
	std::vector<bool> doors(3, false);//make three doors
	doors[0] = true; // place correct door
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::shuffle(doors.begin(), doors.end(), gen);//shuffle doors
	double keepWinCounter{};
	double swapWinCounter{};
	std::cout << "Up to 1,000,000,000 iterations can be done." << '\n'
		<< "11.3s run time for 100,000,000 iterations on creator's machine." << '\n'
		<< "112.91s run time for 1,000,000,000 iterations on creator's machine." << '\n' << '\n';

	double iterations{ getDblInput(wxString { "Enter amount of iterations." },wxString { "" }, wxString { "" }, false) };

	if (iterations > 0 && iterations <= 1000000000)
	{
		wxBusyCursor wait;
		auto start = std::chrono::high_resolution_clock::now();
		progressMessage(wxString("Processing..."), wxString("Processed iterations: 0"), iterations, gui_out);
		for (int count = 0; count < iterations; count++) //user chooses how many times to run this loop
		{
			if (doors[rand() % 3])//randomly pick door, if its true(1), ++keep wins
				++keepWinCounter;
			else
				++swapWinCounter;//if not, swapping would have won ++swap wins

			if (count % 100000 == 0)
			{
				wxString updater = wxString::Format(wxT("Processed iterations: %d"), count);
				gui_gauge_dialog->Update(count, wxString(updater));
			}

			if (gui_gauge_dialog->WasCancelled())
			{
				gui_gauge_dialog->Destroy();
				gui_out->Clear();
				break;
			}
		}
		auto finish = std::chrono::high_resolution_clock::now();
		gui_gauge_dialog->Update(iterations);
		if (gui_gauge_dialog->WasCancelled() == false)
		{
			std::cout << std::fixed << std::setprecision(0) << iterations << " iterations ran." << '\n' << '\n' << "Wins for Keep: " << keepWinCounter << '/' << iterations << " = " << std::setprecision(7) << ((keepWinCounter / iterations) * 100) << '%' << '\n'
				<< "Wins for Swap: " << std::setprecision(0) << swapWinCounter << '/' << iterations << " = " << std::setprecision(7) << ((swapWinCounter / iterations) * 100) << '%' << '\n' << '\n';

			std::chrono::duration<double> elapsed = finish - start;
			std::cout << "Run time: " << std::setprecision(2) << elapsed.count() << 's';
			int continueAuto = wxMessageBox("Run again?", " ", wxYES_NO, this);
			if (continueAuto == wxYES)
			{
				gui_out->Clear();
				proj23Auto();
			}
		}
	}
	else if (iterations != 0)
	{
		errorMessage(wxString("Valid range is 1-1,000,000,000!"), gui_out);
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
	int swappedToDoor{};
	int winsForPlayer{};
	int continueManual = wxYES;
	uint64_t keepWinCounter{};
	uint64_t swapWinCounter{};
	while (continueManual == wxYES)
	{
		wxArrayString manualChoices;
		manualChoices.Add(wxT("1"));
		manualChoices.Add(wxT("2"));
		manualChoices.Add(wxT("3"));
		wxString firstChoiceStr{ singleChoiceInput(wxString{ "Pick door 1, 2 or 3?" },wxString { "" }, manualChoices) };
		int firstChoice = wxAtoi(firstChoiceStr);
		if (firstChoice != 0)
		{
			correctDoor = (rand() % 3) + 1; //randomly picks the correct door

			if (correctDoor != firstChoice)//removes one incorrect door if the first choice was incorrect (example: 6 - correctdoor(2) + firstchoice(1) = 3 or 6-2+1=3)
				removedDoor = (6 - (correctDoor + firstChoice));
			else if (correctDoor == 1 && firstChoice == 1)  //these next three ifs remove one incorrect door if the first choice was correct
				removedDoor = (rand() % 2) + 2;				//randomly picks 2 or 3
			else if (correctDoor == 2 && firstChoice == 2)
				removedDoor = (rand() % 4) + 1 <= 2 ? 1 : 3;//randomly picks 1-4, if less than or equal to 2 evaluates to 1 else evaluates to 3
			else if (correctDoor == 3 && firstChoice == 3)
				removedDoor = (rand() % 2) + 1;				//randomly picks 1 or 2

			wxArrayString manualSwapKeepChoices;
			manualSwapKeepChoices.Add(wxT("Swap"));
			manualSwapKeepChoices.Add(wxT("Keep"));
			wxString swapChoice{ singleChoiceInput(wxString{ "Swap to the other door or Keep yours?" },wxString { "" }, manualSwapKeepChoices) };

			if ((firstChoice == 1 && removedDoor == 2) || (firstChoice == 2 && removedDoor == 1))//swaps for door 3 if 1 or 2 were removed
				swappedToDoor = 3;
			else if ((firstChoice == 3 && removedDoor == 1) || (firstChoice == 1 && removedDoor == 3))//swaps for door 2 if 1 or 3 were removed
				swappedToDoor = 2;
			else if ((firstChoice == 2 && removedDoor == 3) || (firstChoice == 3 && removedDoor == 2))//swaps for door 1 if 2 or 3 were removed
				swappedToDoor = 1;

			if (firstChoice == correctDoor)//counts wins for not swapping
				++keepWinCounter;

			if (swappedToDoor == correctDoor)//counts wins for swapping
				++swapWinCounter;

			std::cout << "You chose door: " << firstChoice << '\n'
				<< "The door removed was: " << removedDoor << '\n';

			if (swapChoice == "Swap")
				std::cout << "You chose to swap your door." << '\n';
			else
				std::cout << "You chose to keep your door." << '\n';

			std::cout << "The correct door was: " << correctDoor << '\n';

			if ((firstChoice == correctDoor && swapChoice == "Keep") || (firstChoice != correctDoor && swapChoice == "Swap"))
			{
				++winsForPlayer;
				std::cout << "Congratulations, you win!" << '\n' << '\n';
			}
			else
				std::cout << "Sorry, you lose." << '\n' << '\n';

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
		{
			continueManual = wxNO;
		}
	}
}
void MainFrame::proj23()
{
	wxStreamToTextRedirector redirect(gui_out);
	wxArrayString proj23Choices;
	proj23Choices.Add(wxT("Automatic"));
	proj23Choices.Add(wxT("Manual"));
	wxString choice23{ singleChoiceInput(wxString{ "Automatic or manual Monty Hall program?" },wxString { "" }, proj23Choices) };
	if (choice23 == "Automatic")
		proj23Auto();
	else if (choice23 == "Manual")
		proj23Manual();
}

double proj24CalculateHeight(double initialHeight, int seconds)
{
	double distanceFallen = constants::gravity * seconds * seconds / 2;
	double heightNow = initialHeight - distanceFallen;

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
	double initialHeight{ getDblInput(wxString { "Enter the initial height of the tower in meters." },wxString { "" }, wxString { "" }, true) };
	if (initialHeight > 0)
	{
		std::cout << "The ball is dropped from " << std::fixed << std::setprecision(2) << initialHeight << " meters." << '\n';
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
				gui_gauge->Pulse();
			}
		gui_gauge->SetValue(0);
		std::cout << "At " << seconds << " seconds, the ball is on the ground." << '\n' << '\n';
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::cout << std::fixed << "Run time: " << elapsed.count() << 's' << std::scientific;
	}
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