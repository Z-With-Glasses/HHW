#pragma once
#include <string>

//begin project1
std::string proj1String()
{
	std::string str{ R"(int proj1GetInput() //This is the same as the code below without using function paramaters and arguments.
{
	std::cout << "Enter an integer:"; //prints "Enter an integer:" into the console
	int input{};
	std::cin >> input;
	return input;
}
void proj1()
{
	int num{ proj1GetInput() };
	std::cout << "Double that integer is:" << num * 2 << '\n';
})" };
	return str;
}
//begin project2
std::string proj2String()
{
	std::string str{ R"(int proj2GetInput()						//this function requests the users input, stores it in integer 'input' then returns the value when called
{
	std::cout << "Enter an integer:";	//prints "Enter an integer:" into console
	int input{};						//defines variable 'input'
	std::cin >> input;					//gets users input and stores it in variable 'input'
	return input;						//returns the integer value of 'input' when called
}
int proj2DoubleNumber(int x)			//takes one integer as a parameter
{
	return x * 2;						//returns double the value of the integer when called, the caller determines the value of the integer
}
void proj2()
{
	int num{ proj2GetInput() };													//assigns the value of function 'getNumInput' to the integer variable 'num' by calling it
	std::cout << "Double that integer is:" << proj2DoubleNumber(num) << '\n';	//calls function 'doubleNumber' to double the value of the variable 'num' then prints to console the result
	num = proj2DoubleNumber(num);
})" };
	return str;
}
//begin project 3
std::string proj3String()
{
	std::string str{ R"(int proj3GetInteger();				//forward declaration for function 'proj3GetInteger' from file 'Addition.cpp'.
									//Forward declarations can be used for a seperate file to declare the function before it's defined.
									//Forward declarations can also be used to declare a function before it's defined in the same file.
									//This forward declaration is being used in 'Addition.h', it's good practice to create a header file to handle all forward declarations.
int proj3GetInteger()					//Function from Addition.cpp
{
	std::cout << "Enter an integer: ";
	int y{};
	std::cin >> y;
	return y;
}
void proj3()
{
	int a{ proj3GetInteger() };		//the value of 'a' is determined by the 1st calling of 'getInteger'
	int b{ proj3GetInteger() };		//the value of 'b' is determined by the 2nd calling of 'getInteger'
	std::cout << a << " + " << b << " is " << a + b << '\n';
})" };
	return str;
}
//begin project 4
std::string proj4String()
{
	std::string str{ R"(void proj4()
{
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
	std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
	std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
})" };
	return str;
}
//begin project 5
std::string proj5String()
{
	std::string str{ R"(void proj5()		//Code to check for primes using a loop and flag. Return to later.
{
	std::int64_t n, i, m = 0, flag = 0;
	std::cout << "Enter the Number to check Prime: ";
	std::cin >> n;
	m = n / 2;
	for (i = 2; i <= m; i++)
	{
		if (n % i == 0)
		{
			std::cout << "Number is not Prime." << '\n';
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		std::cout << "Number is Prime." << '\n';
})" };
	return str;
}
//begin project 6
std::string proj6String()
{
	std::string str{ R"(void proj6()	//examples of the usages of chars (chapter 4.11)
{
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
	std::cout << cha2 << '\n';
})" };
	return str;
}
//begin project 7
std::string proj7String()
{
	std::string str{ R"(void proj7()//Example of how to use the compile time constants(constexpr) in Addition.h
{
	std::cout << "Enter a radius: ";
	int radius{};
	std::cin >> radius;
	double circumference{ 2.0 * radius * constants::pi }; // using the namespace 'constants' and the scope resolution operator '::' to place the value of pi, defined in Addition.h
	std::cout << "The circumference is: " << circumference << '\n';
})" };
	return str;
}
//begin project 8
//Write a program that asks the user to input an integer and tells the user whether the number is even or odd. Write a function called isEven() that returns true
//if an integer passsed to it is even and false otherwise. Use the modulus operator to test whether the integer paramater is even.

std::string proj8String()
{
	std::string str{ R"(void proj8IsEven(int x)	//This is my answer, it works but a function that only checks even/odd and returns a boolean would be reusable. Make this a habit.
{
	if (x % 2 == 0)
		std::cout << x << " is even" << '\n';
	else
		std::cout << x << " is odd" << '\n';
}
void proj8()
{
	int input{};
	std::cout << "Enter an integer:";
	std::cin >> input;
	proj8IsEven(input);
}
/*bool proj8isEven(int x)	//This is the answer provided, "isEven" is a reusable function here.
{
	// if x % 2 == 0, 2 divides evenly into our number, which means it must be an even number
	return (x % 2) == 0;
}
void proj8()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	if (isEven(x))
		std::cout << x << " is even\n";
	else
		std::cout << x << " is odd\n";
}*/)" };
	return str;
}
//begin project 9
//Write a program that asks the user to enter two integers, one named smaller, the other named larger. 
//If the user enters a smaller value for the second integer, use a block and a temporary variable to swap the smaller and larger values. 
//Then print the values of the smaller and larger variables. Add comments to your code indicating where each variable dies. 
//Note: When you print the values, smaller should hold the smaller input and larger the larger input, no matter which order they were entered in.
std::string proj9String()
{
	std::string str{ R"(void proj9Compare(int smaller, int larger)
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
void proj9()
{
	int smaller{};
	int larger{};
	std::cout << "Enter an integer:";
	std::cin >> smaller;
	std::cout << "Enter a larger integer:";
	std::cin >> larger;
	proj9Compare(smaller, larger);
})" };
	return str;
}
//begin project 10
std::string proj10String()
{
	std::string str{ R"(void proj10()
{
	std::cout << "Enter a positive number: ";
	int num{};
	std::cin >> num;
	if
		(num < 0)
	{
		std::cout << "Negative number entered.  Making positive.\n";
		num = -num;
	}
	std::cout << "You entered: " << num << '\n';
})" };
	return str;
}
//begin project 11
//Write a program that asks the user to enter their full name and their age. As output, tell the user how many years they’ve lived for each letter in their name(for simplicity, count spaces as a letter).
//Sample output :
//Enter your full name : John Doe
//Enter your age : 46
//You've lived 5.75 years for each letter in your name.
std::string proj11String()
{
	std::string str{ R"(void proj11()
{
	std::cout << "Enter your full name: ";
	std::string name{};//initializes a string
	std::getline(std::cin, name);//getline is used to capture string input
	std::cout << "Enter your age: ";
	int age{ 0 };
	std::cin >> age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//clears the buffer
	double nameLength{ static_cast<double>(name.length()) };//name.length returns an unsigned integer, bad to use and we need a double for the division anyway
	double nameAgeDiv = { age / nameLength };
	std::cout << "You've lived " << nameAgeDiv << " years for each letter in your name." << '\n';
})" };
	return str;
}
//begin project 12
//In the following code, modify str so that its value is “I saw a blue car yesterday” without repeating the string.ie.don’t do this:str = "I saw a blue car yesterday.";
//You only need to call one function to replace “red” with “blue”.
//int main()
//{
//	std::string str{ "I saw a red car yesterday." };
//
//	// ...
//
//	std::cout << str << '\n'; // I saw a blue car yesterday.
//
//	return 0;
std::string proj12String()
{
	std::string str{ R"(void proj12()
{
	std::string str{ "I saw a red car yesterday." };
	str.replace(8, 3, "blue");
	std::cout << str << '\n'; // I saw a blue car yesterday.
})" };
	return str;
}
//begin project 13
std::string proj13String()
{
	std::string str{ R"(enum proj13ItemType
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
	// Just in case we add a new item in the future and forget to update this function
	return "???";
}
void proj13()
{
	// ItemType is the enumerated type we've defined above.
	// itemType (lower case i) is the name of the variable we're defining (of type ItemType).
	// ITEMTYPE_TORCH is the enumerated value we're initializing variable itemType with.
	//proj13ItemType itemType{ ITEMTYPE_TORCH };
	auto itemType{ proj13ItemType::ITEMTYPE_TORCH };//Same as above but this is the fully scoped name. Used when enum class is used.
	std::cout << "You are carrying a " << getItemName(itemType) << ',';
	//The following is an example of using the enum class.
	enum class Colour
	{//scoped enumeration
		red,//red and blue are inside the scope of Colour
		blue
	};
	Colour colour{ Colour::red };
	if (colour == Colour::red) //red is not directly accessible, we have to use Colour::red
		std::cout << " the colour is red!\n";
	else if (colour == Colour::blue)
		std::cout << " the colour is blue!\n";
})" };
	return str;
}
//begin project 14
//1) You are running a website, and you are trying to keep track of how much money you make per day from advertising.
//Declare an advertising struct that keeps track of how many ads you’ve shown to readers,what percentage of ads were clicked on by users, and how much you earned on average from each ad that was clicked.
//Read in values for each of these fields from the user.
//Pass the advertising struct to a function that prints each of the values, and then calculates how much you made for that day(multiply all 3 fields together).

//2) Create a struct to hold a fraction.The struct should have an integer numerator and an integer denominator member.Declare 2 fraction variables and read them in from the user.
//Write a function called multiply that takes both fractions, multiplies them together, and prints the result out as a decimal number.You do not need to reduce the fraction to its lowest terms.

//Answer 1.
std::string proj14String()
{
	std::string str{ R"(struct proj14Advertising
{
	int amountViewed;
	double percentClicked;
	double earnedPerClick;
};
proj14Advertising getCompany()
{
	proj14Advertising temp;
	std::cout << "Enter amount of ads viewed: ";
	std::cin >> temp.amountViewed;
	std::cout << "Enter percentage of ads clicked: ";
	std::cin >> temp.percentClicked;
	std::cout << "Enter amount earned per click: $";
	std::cin >> temp.earnedPerClick;
	std::cout << '\n';
	return temp;
}
void proj14DailyEarning(proj14Advertising company)
{
	std::cout << "Amount of ads viewed by users: " << company.amountViewed << '\n';
	std::cout << "Percentage of ads clicked by users: " << company.percentClicked << '%' << '\n';
	std::cout << "Average amount earned per click: $" << company.earnedPerClick << '\n';
	std::cout << "Daily earnings: $" << ((company.percentClicked / 100) * company.amountViewed * company.earnedPerClick);
}
void proj14()
{
	proj14Advertising companyA{ getCompany() };
	proj14DailyEarning(companyA);
})" };
	return str;
}
//begin project 15
//Answer 2.
std::string proj15String()
{
	std::string str{ R"(struct proj15Fraction
{
	double numerator;
	double denominator;
};
proj15Fraction getValues()
{
	proj15Fraction temp;
	std::cout << "Enter a value for numerator: ";
	std::cin >> temp.numerator;
	std::cout << "Enter a value for denominator: ";
	std::cin >> temp.denominator;
	std::cout << '\n';
	return temp;
}
void proj15Multiply(proj15Fraction f1, proj15Fraction f2)
{
	std::cout << f1.numerator << '/' << f1.denominator << " * " << f2.numerator << '/' << f2.denominator << " = " <<
		static_cast<double>(f1.numerator * f2.numerator) / (f1.denominator * f2.denominator) << '\n';
}
void proj15()
{
	proj15Fraction f1{ getValues() };
	proj15Fraction f2{ getValues() };
	proj15Multiply(f1, f2);
})" };
	return str;
}
//begin project 16
//In designing a game, we decide we want to have monsters, because everyone likes fighting monsters.Declare a struct that represents your monster.
//The monster should have a type that can be one of the following : an ogre, a dragon, an orc, a giant spider, or a slime.Use an enum class for this.
//Each individual monster should also have a name(use a std::string), as well as an amount of health that represents how much damage they can take before they die.
//Write a function named printMonster() that prints out all of the struct’s members.Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().
//Your program should produce the following output :
//This Ogre is named Torg and has 145 health.
//This Slime is named Blurp and has 23 health.
std::string proj16String()
{
	std::string str{ R"(enum class proj16MonsterType
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
void proj16()
{
	Monster ogre{ {proj16MonsterType::ogre}, "Torg", 145 };
	Monster slime{ {proj16MonsterType::slime}, "Blurp", 23 };
	printMonster(ogre);
	printMonster(slime);
}})" };
	return str;
}
//begin project 17
//proj17 readNumber() and writeAnswer() are in addition.cpp with forward declarations in Addition.h
std::string proj17String()
{
	std::string str{ R"(
int proj17ReadNumber();					//From Addition.h
void proj17WriteAnswer(int input);		//From Addition.h
int proj17ReadNumber()					//From Addition.cpp
{
	int input{};
	std::cout << "Enter an integer:";
	std::cin >> input;
	return input;
}
void proj17WriteAnswer(int input)		//Fom Addition.cpp
{
	std::cout << "The sum is " << input << '\n';
}
void proj17()
{
	int a{ proj17ReadNumber() };
	int b{ proj17ReadNumber() };
	proj17WriteAnswer(a + b);
}
)" };
	return str;
}
//begin project 18
//Write the following program: The user is asked to enter 2 floating point numbers (use doubles). The user is then asked to enter one of the following mathematical symbols: +, -, *, or /.
//The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.
std::string proj18String()
{
	std::string str{ R"(double proj18Input()
{
	double input{};
	std::cout << "Enter a floating point number." << '\n';
	std::cin >> input;
	return input;
}
char proj18CharInput()
{
	char charInput{};
	std::cout << "Enter one of the following: +, -, *, or /" << '\n';
	std::cin >> charInput;
	return charInput;
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
void proj18()
{
	double a{ proj18Input() };
	double b{ proj18Input() };
	char c{ proj18CharInput() };
	proj18CalculateAndPrint(a, c, b);
}})" };
	return str;
}
//begin project19
//Write a short program to simulate a ball being dropped off of a tower. To start, the user should be asked for the height of the tower in meters.
//Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start).
//Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. The ball should not go underneath the ground (height 0).
//Your program should include a header file named constants.h that contains a symbolic constant to hold the value of gravity(9.8).
//Use a function to calculate the height of the ball after x seconds.The function can calculate how far the ball has fallen after x seconds using the following formula:
//distance fallen = gravity_constant * x_seconds / 2
std::string proj19String()
{
	std::string str{ R"(
double proj19getTowerHeight()
{
	double towerHeight{};
	std::cout << "Enter the height of the tower in meters:";
	std::cin >> towerHeight;
	return towerHeight;
}
double proj19CalculateBallHeight(double towerHeight, int secondsFallen)
{
	double distanceFallen{ (constants::gravity * (static_cast<double>(secondsFallen) * static_cast<double>(secondsFallen)) / 2.0) };
	double calculatedBallHeight{ towerHeight - distanceFallen };
	return calculatedBallHeight;
}
void proj19PrintHeight(double ballHeight, int secondsFallen)
{
	if (ballHeight > 0.0)
		std::cout << "At " << secondsFallen << " seconds , the ball is at height: " << ballHeight << " meters." << '\n';
	else
		std::cout << "At " << secondsFallen << " seconds , the ball is on the ground " << '\n';
}
void proj19CalculateAndPrintHeight(double towerHeight, int seconds)
{
	double ballHeight{ proj19CalculateBallHeight(towerHeight, seconds) };
	proj19PrintHeight(ballHeight, seconds);
}
void proj19()
{
	const double towerHeight{ proj19getTowerHeight() };
	proj19CalculateAndPrintHeight(towerHeight, 0);
	proj19CalculateAndPrintHeight(towerHeight, 1);
	proj19CalculateAndPrintHeight(towerHeight, 2);
	proj19CalculateAndPrintHeight(towerHeight, 3);
	proj19CalculateAndPrintHeight(towerHeight, 4);
	proj19CalculateAndPrintHeight(towerHeight, 5);
})" };
	return str;
}
//begin project 20
//Write a function called calculate() that takes two integers and a char representing one of the following mathematical operations: +, -, *, /, or % (modulus).
//Use a switch statement to perform the appropriate mathematical operation on the integers, and return the result.
//If an invalid operator is passed into the function, the function should print an error. For the division operator, do an integer division.
std::string proj20String()
{
	std::string str{ R"(void proj20Print();
int proj20IntegerInput()
{
	std::cout << "Enter an integer:";
	int a{};
	std::cin >> a;
	return a;
}
char proj20CharInput()
{
	std::cout << "Enter one of the following operators: +, -, *, / or %:";
	char a{};
	std::cin >> a;
	return a;
}
int proj20Calculate(int a, int b, char c)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '%':
		return a % b;
	default:
	{
		std::cout << "Please enter a valid operator." << '\n';
		proj20Print();
		break;
	}
	}
	return 0;
}
void proj20Print()
{
	int a{ proj20IntegerInput() };
	int b{ proj20IntegerInput() };
	char c{ proj20CharInput() };
	std::cout << '\n' << a << c << b << '=' << proj20Calculate(a, b, c) << '\n';
}
void proj20()
{
	proj20Print();
})" };
	return str;
}
//begin project 21
//Write a program that prints out the letters a through z along with their ASCII codes.
std::string proj21String()
{
	std::string str{ R"(void proj21Q1()
{
	char askey{ 'a' };
	while (askey <= 'z')
	{
		std::cout << askey << ' ' << static_cast<int>(askey) << '\n';
		++askey;
	}
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
void proj21()
{
	proj21Q1();
	proj21Q2();
	proj21Q3();
})" };
	return str;
}
//begin project 22
//Write a for loop that prints every even number from 0 to 20.
std::string proj22String()
{
	std::string str{ R"(void proj22Q1()
{
	for (int x{ 0 }; x <= 20; x += 2)
		std::cout << x << '\n';
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
void proj22Q2()
{
	int x{};
	std::cout << "Enter a number:";
	std::cin >> x;
	std::cout << sumTo(x);
}
void proj22()
{
	proj22Q1();
	proj22Q2();
})" };
	return str;
}
//begin project 23
//This project is not in learncpp.com I decided to make a program that tests the Monty Hall problem. The problem is as follows.
//You have three doors, one is correct the others are incorrect. You pick a door, an incorrect door is removed, then you are offered the chance to swap to the other remaining door.
//Statistically your chance of being correct with your first pick is 1/3, if you swap on the second choice your chance is 2/3 since one wrong door has been removed.
std::string proj23String()
{
	std::string str{ R"(//This is the function used in this program, optimized for speed. It's 2x as fast as the one below. 
//Here you'll see some wxWidgets code that's absent in every other shown function. 
//A lot needed to be changed to make the functions work in this GUI with wxWidgets.
//Look at HHW.cpp to see the true code this program uses.
void MainFrame::proj23Auto()		
{
	srand((unsigned)time(0));//sets the random seed to the current time
	std::vector<bool> doors(3, false);	//make three doors
	doors[0] = true;	//place correct door
	std::random_device rd;		//random number generator used for mt19937
	std::mt19937 gen{ rd() };		//one of c++'s best psuedo-random number generators ( there's no such thing as true random, google this for a better understanding, it's a deep topic)
	std::shuffle(doors.begin(), doors.end(), gen);	//shuffle doors
	double keepWinCounter{};
	double swapWinCounter{};
	std::cout << "Up to 1,000,000,000 iterations can be done." << '\n'
		<< "11.3s run time for 100,000,000 iterations on creator's machine." << '\n'
		<< "112.91s run time for 1,000,000,000 iterations on creator's machine." << '\n' << '\n';
	double iterations{ getDblInput(wxString { "Enter amount of iterations." },wxString { "" }, wxString { "" }, false) };	//get user input for how many iterations to run
	if (iterations > 0 && iterations <= 1000000000)		//ensures valid range of iterations
	{
		wxBusyCursor wait;		//sets the cursor to OS busy cursor
		auto start = std::chrono::high_resolution_clock::now();		//starts a timer
		progressMessage(wxString("Processing..."), wxString("Processed iterations: 0"), iterations, gui_out);
		for (int count = 0; count < iterations; count++)	//user chooses how many times to run this loop
		{
			if (doors[rand() % 3])		//randomly pick door, if its true(1), ++keep wins
				++keepWinCounter;
			else
				++swapWinCounter;		//if not, swapping would have won ++swap wins
			if (count % 100000 == 0)		//updates the progress dialog displayed on screen every 100000 iterations
			{
				wxString updater = wxString::Format(wxT("Processed iterations: %d"), count);
				gui_gauge_dialog->Update(count, wxString(updater));
			}
			if (gui_gauge_dialog->WasCancelled())		//closes the progress dialog, ends the function and clears the GUI if user presses cancel
			{
				gui_gauge_dialog->Destroy();
				gui_out->Clear();
				break;
			}
		}
		auto finish = std::chrono::high_resolution_clock::now();		//ends the clock
		gui_gauge_dialog->Update(iterations);		//updates the progress dialog with the final iteration count
		if (gui_gauge_dialog->WasCancelled() == false)		//doesn't run if user cancelled
		{
			std::cout << std::fixed << std::setprecision(0) << iterations <<  " iterations ran." << '\n' << '\n' << "Wins for Keep: " << keepWinCounter << '/' << iterations << " = " << std::setprecision(7) << ((keepWinCounter / iterations) * 100) << '%' << '\n'
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
	else if (iterations != 0)		//doesn't print if user cancelled
	{
		errorMessage(wxString("Valid range is 1-1,000,000,000!"), gui_out);
		gui_out->Clear();
		proj23Auto();
	}
}
void proj23Auto()		//this version was made to demonstrate the accuracy and true randomness of the function
{
	srand((unsigned)time(0));//sets the random seed to the current time
	int correctDoor{};
	int firstChoice{};
	int removedDoor{};
	int secondChoice{};
	uint64_t keepWinCounter{};
	uint64_t swapWinCounter{};
	uint64_t iterations{};
	std::cout << '\n' << "Enter amount of iterations:" << '\n';
	std::cin >> iterations;
	for (int count = 0; count < iterations; count++) //user chooses how many times to run this loop
	{
		correctDoor = (rand() % 3) + 1;					//randomly picks the correct door
		firstChoice = (rand() % 3) + 1;					//randomly makes the first door choice
		if (correctDoor != firstChoice)				//removes one incorrect door if the first choice was incorrect (example: 6 - correctdoor(2) + firstchoice(1) = 3 or 6-2+1=3)
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
		std::cout << "The first choice was: " << firstChoice << '\n'
			<< "The door removed was: " << removedDoor << '\n'
			<< "The second choice was: " << secondChoice << '\n'
			<< "The correct door was: " << correctDoor << '\n' << '\n';
	}
	float floatKeepWin{ static_cast<float>(keepWinCounter) };//convert all unsigned integers to float to use in division to find percentage of wins
	float floatSwapWin{ static_cast<float>(swapWinCounter) };
	float floatIterations{ static_cast<float>(iterations) };
	std::cout << "Wins for Keep: " << keepWinCounter << ' ' << ((floatKeepWin / floatIterations) * 100) << '%' << '\n'
		<< "Wins for Swap: " << swapWinCounter << ' ' << ((floatSwapWin / floatIterations) * 100) << '%' << '\n' << '\n';
	bool continueAuto{};
	std::cout << "Enter 1 To Run Again or Enter 0 To Quit" << '\n' << "Continue?:";
	std::cin >> continueAuto;
	if (continueAuto == 1)
		proj23Auto();
}
void proj23Manual()
{
	srand((unsigned)time(0));//sets the random seed to the current time
	int iterations{};
	int correctDoor{};
	int firstChoice{};
	int removedDoor{};
	bool swapChoice{};
	int secondChoice{};
	bool continueManual{ 1 };
	uint64_t keepWinCounter{};
	uint64_t swapWinCounter{};
	while (continueManual == 1)
	{
		std::cout << "Pick a door between 1 and 3." << '\n' << "First choice:";
		std::cin >> firstChoice;
		correctDoor = (rand() % 3) + 1; //randomly picks the correct door
		if (correctDoor != firstChoice) //removes one incorrect door if the first choice was incorrect (example: 6 - correctdoor(2) + firstchoice(1) = 3 or 6-2+1=3)
			removedDoor = (6 - (correctDoor + firstChoice));
		else if (correctDoor == 1 && firstChoice == 1)  //these next three ifs remove one incorrect door if the first choice was correct
			removedDoor = (rand() % 2) + 2;				//randomly picks 2 or 3
		else if (correctDoor == 2 && firstChoice == 2)
			removedDoor = (rand() % 4) + 1 <= 2 ? 1 : 3;//randomly picks 1-4, if less than or equal to 2 evaluates to 1 else evaluates to 3
		else if (correctDoor == 3 && firstChoice == 3)
			removedDoor = (rand() % 2) + 1;				//randomly picks 1 or 2
		std::cout << '\n' << "Door " << removedDoor << " is not the correct door and has been removed." << '\n'
			<< "Swap to the other door or keep yours? Enter 0 to keep your door or 1 to swap to the other door." << '\n' << "Keep(0) or Swap(1):";
		std::cin >> swapChoice;
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
		std::cout << '\n' << "The first choice was: " << firstChoice << '\n'
			<< "The door removed was: " << removedDoor << '\n';
		if (swapChoice)
			std::cout << "The second choice was: " << secondChoice << '\n';
		iterations++;
		float floatKeepWin{ static_cast<float>(keepWinCounter) };//convert all unsigned integers to float to use in division to find percentage of wins
		float floatSwapWin{ static_cast<float>(swapWinCounter) };
		float floatIterations{ static_cast<float>(iterations) };
		std::cout << "Wins for Keep: " << keepWinCounter << ' ' << ((floatKeepWin / floatIterations) * 100) << '%' << '\n'
			<< "Wins for Swap: " << swapWinCounter << ' ' << ((floatSwapWin / floatIterations) * 100) << '%' << '\n' << "Times ran: " << iterations << '\n' << '\n'
			<< "Enter 1 To Continue or Enter 0 To Quit" << '\n' << "Continue?:";
		std::cin >> continueManual;
	}
}
void proj23()
{
	std::cout << "(A)uto or (M)anual Monty Hall program?" << '\n' << "Program:";
	char choice23{};
	std::cin >> choice23;
	bool continue23{};
	switch (choice23)
	{
	case 'a': case 'A':
		proj23Auto();
		break;
	case 'm': case 'M':
		proj23Manual();
		break;
	default: std::cout << '\n' << "Error, invalid choice. Please choose again." << '\n' << '\n';
		system("PAUSE");
		system("CLS");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		continue23 = 1;
		proj23();
		break;
	}
})" };
	return str;
}
//begin project 24
//We wrote a program to simulate a ball falling off of a tower. Because we didn’t have loops yet, the ball could only fall for 5 seconds.
//Take the program below and modify it so that the ball falls for as many seconds as needed until it reaches the ground.
std::string proj24String()
{
	std::string str{ R"(double proj24CalculateHeight(double initialHeight, int seconds)
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
	std::cout << "At " << time << " seconds, the ball is at height: " << proj24CalculateHeight(initialHeight, time) << "\n";
}
void proj24()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	int seconds{ 1 };
	double heightNow{ proj24CalculateHeight(initialHeight, seconds) };
	if (heightNow > 0)
		while (heightNow > 0)
		{
			proj24CalculateAndPrintHeight(initialHeight, seconds);
			++seconds;
			heightNow = proj24CalculateHeight(initialHeight, seconds);
		}
	std::cout << "At " << seconds << " seconds, the ball is on the ground." << '\n';
})" };
	return str;
}
//begin project 25
//A prime number is a natural number greater than 1 that is evenly divisible (with no remainder) only by 1 and itself. 
//Complete the following program by writing the isPrime() function using a for loop.
std::string proj25String()
{
	std::string str{ R"(bool proj25IsPrime(int num)
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
void proj25()
{
	std::cout << "Pre-check";
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
})" };
	return str;
}
//begin project 26

std::string projContinueString()
{
	std::string str{ R"(bool mainContinue()
{
	std::cout << '\n' << "Do you want to view another project?" << '\n' << "(Y/N):";
	bool mContinue{};
	char input{};
	std::cin >> input;
	switch (input)
	{
	case 'Y': case 'y':
		mContinue = true;
		system("CLS");
		break;
	case 'N': case 'n':
		mContinue = false;
		break;
	default: std::cout << "Error, invalid choice. Please choose again." << '\n' << '\n';
		system("PAUSE");
		system("CLS");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mContinue = true;
		mainContinue();
		break;
	}
	return mContinue;
})" };
	return str;
}
std::string projChoiceString()
{
	std::string str{ R"(void projectChoice()
{
	std::cout
		<< "Project 1: Double Integer #1" << '\n'
		<< "Project 2: Double Integer #2" << '\n'
		<< "Project 3: Forward Declarations/Header Files" << '\n'
		<< "Project 4: Data Sizes" << '\n'
		<< "Project 5: Prime Number Check, Loop and Flag" << '\n'
		<< "Project 6: Usage Of Chars" << '\n'
		<< "Project 7: Compile Time Constants" << '\n'
		<< "Project 8: Even Or Odd" << '\n'
		<< "Project 9: Smaller And Larger" << '\n'
		<< "Project 10: Always Positive" << '\n'
		<< "Project 11: Name And Age, Years Lived" << '\n'
		<< "Project 12: String Replace" << '\n'
		<< "Project 13: RPG Example, using enum" << '\n'
		<< "Project 14: Profit Per Day" << '\n'
		<< "Project 15: Multiply Fractions Into Decimals" << '\n'
		<< "Project 16: RPG Monster Maker" << '\n'
		<< "Project 17: Chapter 2 Quiz" << '\n'
		<< "Project 18: Chapter 4 Quiz Question 1" << '\n'
		<< "Project 19: Chapter 4 Quiz Question 2" << '\n'
		<< "Project 20: Chapter 7.5 Quiz" << '\n'
		<< "project 21: Chapter 7.7 Quiz Questions 2-4" << '\n'
		<< "Project 22: Chapter 7.9 Quiz Questions 1-2" << '\n'
		<< "Project 23: Demonstration of the Monty Hall problem" << '\n'
		<< "Project 24: Chapter 7 Quiz Question 1" << '\n'
		<< "Project 25: Chapter 7 Quiz Question 2" << '\n'
		<< "Project 26: Personal project testing ptr and fcnptr" << '\n'
		<< '\n'
		<< "Which project would you like to view/run?" << '\n'
		<< "Project:";
	int choice{ 0 };
	std::cin >> choice;
	if (choice >= 1)
	{
		std::cout << '\n';
		switch (choice)
		{
		case 1: std::cout << "This project asks the user to enter an integer and then doubles it." << '\n' << '\n';
			proj1();
			break;
		case 2: std::cout << "This project asks the user to enter an integer and then doubles it." << '\n' << "Function paramaters and arguments are used in the code." << '\n' << '\n';
			proj2();
			break;
		case 3: std::cout << "This project asks the user for two integers and adds them together." << '\n' << "Forward declarations and header files are used in the code." << '\n' << '\n';
			proj3();
			break;
		case 4: std::cout << "This project lists the sizes of various data types for this complier and computer." << '\n' << '\n';
			proj1();
			break;
		case 5: std::cout << "This project checks whether an integer is a prime number or not. Loops and flags are used in the code." << '\n' << '\n';
			proj5();
			break;
		case 6: std::cout << "This project showcases the usages of various chars. Meant to be viewed as code then ran to see the result." << '\n' << '\n';
			proj6();
			break;
		case 7: std::cout << "This project asks the user to enter a radius and returns a circumfrence." << '\n' << "It is an example of the usage of constants in a header file." << '\n' << '\n';
			proj7();
			break;
		case 8: std::cout << "This project asks the user to enter a number, then declares the number even or odd using modulus." << '\n' << '\n';
			proj8();
			break;
		case 9: std::cout << "This project asks the user to enter an integer, then a larger integer." << '\n' << "Then it swaps the values if a smaller value was entered first." << '\n' << '\n';
			proj9();
			break;
		case 10: std::cout << "This project asks the user to enter a positive number, if they enter a negative number it turns it positive." << '\n' << '\n';
			proj10();
			break;
		case 11: std::cout << "This project asks the user for their name and age then tells them how many years they've lived for each letter in their name." << '\n' << '\n';
			proj11();
			break;
		case 12: std::cout << "This project replaces characters in a string. Meant to be viewed as code then ran to see the result." << '\n' << '\n';
			proj12();
			break;
		case 13: std::cout << "This project uses enumarators and enumerated classes." << '\n' << "Meant to be viewed as code then ran to see the result." << '\n' << '\n';
			proj13();
			break;
		case 14: std::cout << "This project determines the ad revenue of clicks for a website. Struct is used in the code." << '\n' << '\n';
			proj14();
			break;
		case 15: std::cout << "This project multiples two fractions together to produce a decimal. Struct is used in the code." << '\n' << '\n';
			proj15();
			break;
		case 16: std::cout << "This project creates two RPG monster types and displays their stats. Struct is used in the code." << '\n'
			<< "Meant to be viewed as code then ran to see the result." << '\n' << '\n';
			proj16();
			break;
		case 17: std::cout << "Results of the chapter 2 quiz from learncpp.com. Takes two integers from the user and adds them." << '\n' << '\n';
			proj17();
			break;
		case 18: std::cout << "Results of the chapter 4 quiz from learncpp.com." << '\n'
			<< "Enter 2 floating point numbers and a mathematical symbol." << '\n'
			<< "The program computes the numbers and prints the results." << '\n' << "If the user enters an invalid symbol the program prints nothing." << '\n' << '\n';
			proj18Q1();
			break;
		case 19: std::cout << "Results of the chapter 4 quiz from learncpp.com." << '\n'
			<< "Write a program that asks the user to enter the height of a tower in meters." << '\n'
			<< "The program then outputs the height of the ball after x seconds using the formula:" << '\n'
			<< "distance fallen = gravity_constant * x_seconds2 / 2" << '\n' << '\n';
			proj18Q2();
			break;
		case 20: std::cout << "This project asks for two integers and an operator then calculates. It uses a switch statment." << '\n' << '\n';
			proj20();
			break;
		case 21: std::cout << "This project uses loops and nested loops in various ways. Chapter 7.7" << '\n' << '\n';
			proj21();
			break;
		case 22: std::cout << "Results of the chapter 7.9 quiz from learncpp.com." << '\n'
			<< "Write a for loop that prints every even number from 0 to 20." << '\n' << '\n';
			proj22();
			break;
		case 23: std::cout << "This project demonstrates the Monty Hall problem, where one is asked to choose a door from three doors." << '\n'
			<< "Only one choice is correct, the other two are incorrect. After choosing a door one incorrect door is removed." << '\n'
			<< "They are then asked if they would like to keep their choice or switch doors." << '\n'
			<< "Statistically if they switch their chances are 2/3 while if they stay it's 1/3, this project demonstrates that." << '\n' << '\n';
			proj23();
			break;
		case 24: std::cout << "In the chapter 4 comprehensive quiz, we wrote a program to simulate a ball falling off of a tower." << '\n'
			<< "Because we didn’t have loops yet, the ball could only fall for 5 seconds." << '\n'
			<< "Take the program below and modify it so that the ball falls for as many seconds as needed until it reaches the ground." << '\n' << '\n';
			proj24();
			break;
		case 25: std::cout << "A prime number is a natural number greater than 1 that is evenly divisible (with no remainder) only by 1 and itself." << '\n'
			<< "Complete the following program by writing the isPrime() function using a for loop." << '\n' << '\n';
			proj25();
			break;
			/*case 26: std::cout << "This project prints the code for itself." << '\n' << '\n';
				proj26();
				break;*/
		default: std::cout << "Error, invalid choice. Please choose again." << '\n' << '\n';
			system("PAUSE");
			system("CLS");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			projectChoice();
			break;
		}
	}
	else
	{
		std::cout << "Error, invalid choice. Please enter a number." << '\n' << '\n';
		system("PAUSE");
		system("CLS");
		choice = 0;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		projectChoice();
	}
})" };
	return str;
}
/*bool errors = {1};
void joke(bool error)
{
	if (!errors)
		std::cout << "Nothing more to learn." << '\n';
	else
		std::cout << "There's always more to learn." << '\n';
}
int main()
{
	joke(0);
	return 0;
}*/
std::string projMainString()
{
	std::string str{ R"(int main()
{
	bool continueBool{};
	do
	{
		projectChoice();
		continueBool = (mainContinue());
	} while (continueBool == true);
	system("CLS");
	std::cout << "Bye!";
	return 0;
})" };
	return str;
}