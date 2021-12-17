#include <string>
#include <iostream>
#include <iomanip> // for std::setprecision()
#include "Stack.h"

#define pi 3.14159265 
#define e 2.718281

using namespace std;

bool check_for_correct_input(string str) {
	bool check = true;
	for (int position = 0; position < str.length(); position++)
	{
		if (str[position] == '.' && (position == 0 || (str[position - 1] > 57 || str[position - 1] < 48) || (str[position + 1] > 57 || str[position + 1] < 48))) {
			throw invalid_argument("incorrect number");
			check = false;
		} // incorrect number input
		else if (str[position] == '*' && (position == 0 || str[position - 1] == '(' || str[position + 1] == ')' || str[position + 1] == '=')) {
			throw invalid_argument("incorrect application *");
			check = false;
		} // incorrect use of the multiplication symbol
		else if (str[position] == '+' && (position == 0 || str[position - 1] == '(' || str[position + 1] == ')' || str[position + 1] == '=')) {
			throw invalid_argument("incorrect application +");
			check = false;
		} // incorrect use of the addition symbol
		else if (str[position] == '-' && (str[position + 1] == ')' || str[position + 1] == '=')) {
			throw invalid_argument("incorrect application -");
			check = false;
		} // incorrect use of the subtraction symbol
		else if (str[position] == '/' && (position == 0 || str[position - 1] == '(' || str[position + 1] == ')' || str[position + 1] == '=')) {
			throw invalid_argument("incorrect application /");
			check = false;
		} // incorrect use of the division character
		else if (str[position] == '^' && (position == 0 || str[position - 1] == '(' || str[position + 1] == '=')) {
			throw invalid_argument("incorrect application ^");
			check = false;
		} // incorrect use of the exponentiation symbol

		// checking the correctness of the function input module
		else if (str[position] == 'a' && (str[position + 1] != 'b' || str[position + 2] != 's')) {
			throw invalid_argument("misspelling the abs() function");
			check = false;
		}
		else if ((str[position] == 'a' && str[position + 1] == 'b' && str[position + 2] == 's') && (str[position + 3] != '(' || (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43)))) {
			throw invalid_argument("incorrect arithmetics the abs() function");
			check = false;
		}
		else if (str[position] == 'a' && str[position + 1] == 'b' && str[position + 2] == 's') {
			position = position + 3;
		}

		//checking the correctness of the input of the cosine and cotangent function
		else if (str[position] == 'c' && ((str[position + 1] != 'o' || str[position + 2] != 's') && (str[position + 1] != 't' || str[position + 2] != 'g'))) {
			throw invalid_argument("misspelling the cos() or ctg() function");
			check = false;
		}
		else if ((str[position] == 'c' && ((str[position + 1] == 'o' && str[position + 2] == 's') || (str[position + 1] == 't' && str[position + 2] == 'g'))) && (str[position + 3] != '(' || (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43)))) {
			throw invalid_argument("incorrect arithmetics the cos() or ctg() function");
			check = false;
		}
		else if (str[position] == 'c' && str[position + 1] == 'o' && str[position + 2] == 's') {
			position = position + 3;
		}
		else if (str[position] == 'c' && str[position + 1] == 't' && str[position + 2] == 'g') {
			position = position + 3;
		}

		//checking the correctness of the input of the sine and root functions
		else if (str[position] == 's' && ((str[position + 1] != 'i' || str[position + 2] != 'n') && (str[position + 1] != 'q' || str[position + 2] != 'r' || str[position + 3] != 't'))) {
			throw invalid_argument("misspelling the sin() or sqrt() function");
			check = false;
		}
		else if ((str[position] == 's' && str[position + 1] == 'i' && str[position + 2] == 'n') && (str[position + 3] != '(' || (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43)))) {
			throw invalid_argument("incorrect arithmetics the sin() function");
			check = false;
		}
		else if ((str[position] == 's' && str[position + 1] == 'q' && str[position + 2] == 'r' && str[position + 3] == 't') && (str[position + 4] != '(' || (position != 0 && (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43))))) {
			throw invalid_argument("incorrect arithmetics the sqrt() function");
			check = false;
		}
		else if (str[position] == 's' && str[position + 1] == 'q' && str[position + 2] == 'r' && str[position + 3] == 't') {
			position = position + 4;
		}
		else if (str[position] == 's' && str[position + 1] == 'i' && str[position + 2] == 'n') {
			position = position + 3;
		}

		// checking the correctness of the input of logorithmic functions
		else if (str[position] == 'l' && ((str[position + 1] != 'o' || str[position + 2] != 'g') && (str[position + 1] != 'n'))) {
			throw invalid_argument("misspelling the log() or ln() function");
			check = false;
		}
		else if ((str[position] == 'l' && str[position + 1] == 'o' && str[position + 2] == 'g') && (str[position + 3] != '(' || (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43)))) {
			throw invalid_argument("incorrect arithmetics the log() function");
			check = false;
		}
		else if ((str[position] == 'l' && str[position + 1] == 'n') && (str[position + 2] != '(' || (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43)))) {
			throw invalid_argument("incorrect arithmetics the ln() function");
			check = false;
		}
		else if (str[position] == 'l' && str[position + 1] == 'o' && str[position + 2] == 'g') {
			position = position + 3;
		}
		else if (str[position] == 'l' && str[position + 1] == 'n') {
			position = position + 2;
		}

		// checking the correctness of the input of the tangent function
		else if (str[position] == 't' && str[position + 1] != 'g') {
			throw invalid_argument("misspelling the tg() function");
			check = false;
		}
		else if ((str[position] == 't' && str[position + 1] == 'g') && (str[position + 2] != '(' || (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43)))) {
			throw invalid_argument("incorrect arithmetics the tg() function");
			check = false;
		}
		else if (str[position] == 't' && str[position + 1] == 'g') {
			position = position + 2;
		}

		// checking the correctness of the input of the constant pi
		else if (str[position] == 'p' && str[position + 1] != 'i') {
			throw invalid_argument("misspelling the pi const");
			check = false;
		}
		else if ((str[position] == 'p' && str[position + 1] == 'i') && ((str[position + 3] != 45 && str[position + 3] != 47 && str[position + 3] != 94 && str[position + 2] != 41 && str[position + 3] != 42 && str[position + 3] != 43) || (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43)))) {
			throw invalid_argument("incorrect arithmetics the pi const");
			check = false;
		}
		else if (str[position] == 'p' && str[position + 1] == 'i') {
			position = position + 2;
		}

		// checking the correctness of the input of the constant å
		else if (str[position] == 'e' && ((str[position + 2] != 45 && str[position + 2] != 47 && str[position + 2] != 94 && str[position + 1] != 41 && str[position + 2] != 42 && str[position + 2] != 43) || (position != 0 && (str[position - 2] != 45 && str[position - 2] != 47 && str[position - 2] != 94 && str[position - 1] != 40 && str[position - 2] != 42 && str[position - 2] != 43)))) {
			throw invalid_argument("incorrect arithmetics the e const");
			check = false;
		}

		// checking the correct use of parentheses
		else if (str[position] == '(' && (str[position + 1] == ')' || str[position + 1] == '=' || str[position] == '+' || str[position] == '/' || str[position] == '*' || str[position] == '^')) {
			throw invalid_argument("open parenthesis is used incorrectly");
			check = false;
		}
		else if (str[position] == ')' && (str[position + 1] == 'a' || str[position + 1] == 's' || str[position + 1] == 'c' || str[position + 1] == 't' || str[position + 1] == 'l' || str[position + 1] == 'p' || str[position + 1] == 'e' || (str[position + 1] < 58 && str[position + 1] > 47))) {
			throw invalid_argument("the closing parenthesis is used incorrectly");
			check = false;
		}

		// if any invalid symbols are entered
		else if (str[position] != ' ' && str[position] != '=' && str[position] != 'a' && str[position] != 'b' && str[position] != 'e' && str[position] != 'c' && str[position] != 'o' && str[position] != 's' && str[position] != 't' && str[position] != 'g' && str[position] != 'i' && str[position] != 'n' && str[position] != 'q' && str[position] != 'r' && str[position] != 'l' && str[position] != 'p' && str[position] != '+' && str[position] != '-' && str[position] != '/' && str[position] != '*' && str[position] != '^' && str[position] != ')' && str[position] != '(' && !(str[position] <= 57 && str[position] >= 48)) {
			throw invalid_argument("Invalid character. The calculator can use numbers like double, brackets, actions: +, -, *, /, ^ and functions: sin(), cos(), tg(), ctg(), sqrt(), log(), ln(), abs()");
			check = false;
		}

	}
	return check;
}

bool check_bracekts(string str)
{
	bool checkBracekts = true;
	int colL = 0;
	int colR = 0;
	int positionL, positionR;
	string checkStr = str;
	for (int i = 0; i < checkStr.length(); i++) {
		if (checkStr[i] == '(') colL++;
		if (checkStr[i] == ')') colR++;
	}
	if (colL != colR) {
		checkBracekts = false;
		throw invalid_argument("The number of opening and closing parentheses is not equal");
	}

	positionL = checkStr.find("(");
	positionR = checkStr.find(")");
	while ((positionL != -1) || (positionR != -1))
	{
		positionL = checkStr.find("(");
		positionR = checkStr.find(")");
		if ((positionL != -1) && (positionR != -1)) {
			if ((positionL < positionR))
			{
				checkStr.erase(positionL, 1);
				checkStr.erase(positionR - 1, 1);
			}
			else {
				checkBracekts = false;
				throw invalid_argument("Brackets are placed incorrectly");
			}
		}
	}

	return checkBracekts;
};

int TakesPrecedence(string operators) // function to determine operator precedence
{
	int operatorsWeight;
	if (operators == "*" || operators == "/")
		operatorsWeight = 2;
	else if (operators == "^")
		operatorsWeight = 3;
	else if (operators == "sin" || operators == "cos" || operators == "tg" || operators == "ctg" || operators == "sqrt" || operators == "log" || operators == "ln" || operators == "abs")
		operatorsWeight = 4;
	else
		operatorsWeight = 1;
	return operatorsWeight;
}

string postfix(string str) {
	Stack<string> temp;
	string convertedStr;  // converted string
	string buf, push_temp;
	int position;
	for (int i = 0; i < str.length(); i++)
	{
		buf = str[i];
		if (buf == "0" || buf == "1" || buf == "2" || buf == "3" || buf == "4" || buf == "5" || buf == "6" || buf == "7" || buf == "8" || buf == "9" || buf == "." || buf == "e")    // if this number, add to postfix string
		{
			convertedStr += buf;
		}
		else if (buf == " ") {
			if (convertedStr.length() != 0 && (convertedStr[convertedStr.length() - 1] != ' ')) {
				convertedStr += buf;
			}
		}
		// pi
		else if (buf == "p" && str[i + 1] == 'i')
		{
			convertedStr += buf;
			convertedStr += str[i + 1];
			i = i + 2;
		}
		// abs
		else if (buf == "a" && str[i + 1] == 'b')
		{
			push_temp = "(";
			temp.push(push_temp);
			push_temp = "\0";
			position = str.find("(", i);
			push_temp.assign(str, i, position - i);
			temp.push(push_temp);
			push_temp = "\0";
			str[position] = ' ';
			i = position;
		}
		// sqrt
		else if (buf == "s" && str[i + 1] == 'q')
		{
			push_temp = "(";
			temp.push(push_temp);
			push_temp = "\0";
			position = str.find("(", i);
			push_temp.assign(str, i, position - i);
			temp.push(push_temp);
			push_temp = "\0";
			str[position] = ' ';
			i = position;
		}
		// sin
		else if (buf == "s" && str[i + 1] == 'i')
		{
			push_temp = "(";
			temp.push(push_temp);
			push_temp = "\0";
			position = str.find("(", i);
			push_temp.assign(str, i, position - i);
			temp.push(push_temp);
			push_temp = "\0";
			str[position] = ' ';
			i = position;
		}
		// cos
		else if (buf == "c" && str[i + 1] == 'o')
		{
			push_temp = "(";
			temp.push(push_temp);
			push_temp = "\0";
			position = str.find("(", i);
			push_temp.assign(str, i, position - i);
			temp.push(push_temp);
			push_temp = "\0";
			str[position] = ' ';
			i = position;
		}
		// ctg
		else if (buf == "c" && str[i + 1] == 't')
		{
			push_temp = "(";
			temp.push(push_temp);
			push_temp = "\0";
			position = str.find("(", i);
			push_temp.assign(str, i, position - i);
			temp.push(push_temp);
			push_temp = "\0";
			str[position] = ' ';
			i = position;
		}
		// tg
		else if (buf == "t" && str[i + 1] == 'g')
		{
			push_temp = "(";
			temp.push(push_temp);
			push_temp = "\0";
			position = str.find("(", i);
			push_temp.assign(str, i, position - i);
			temp.push(push_temp);
			push_temp = "\0";
			str[position] = ' ';
			i = position;
		}
		// log
		else if (buf == "l" && str[i + 1] == 'o')
		{
			push_temp = "(";
			temp.push(push_temp);
			push_temp = "\0";
			position = str.find("(", i);
			push_temp.assign(str, i, position - i);
			temp.push(push_temp);
			push_temp = "\0";
			str[position] = ' ';
			i = position;
		}
		// ln
		else if (buf == "l" && str[i + 1] == 'n')
		{
			push_temp = "(";
			temp.push(push_temp);
			push_temp = "\0";
			position = str.find("(", i);
			push_temp.assign(str, i, position - i);
			temp.push(push_temp);
			push_temp = "\0";
			str[position] = ' ';
			i = position;
		}

		else if (buf == "(")
			temp.push(buf);

		else if (buf == "+" || buf == "-" || buf == "*" || buf == "/" || buf == "^")    // if an operator
		{
			if (temp.empty() || temp.top() == "(") //  if stack is empty or top of stack is opening parenthesis
			{
				temp.push(buf);
			}
			else if (TakesPrecedence(buf) > TakesPrecedence(temp.top())) // if the operator has higher precedence
			{
				temp.push(buf);
			}

			else // if the operator has a lower priority
			{
				if (buf == "-" && TakesPrecedence(temp.top()) == 4) {
					temp.push(buf);
				}
				else {
					while (((temp.size()) != 0) && (TakesPrecedence(buf) <= TakesPrecedence(temp.top()))) {
						convertedStr += temp.top();
						convertedStr += ' ';
						temp.pop();
					}
					temp.push(buf);
				}


			}
		}
		else if (buf == ")")
		{

			while (temp.top() != "(")
			{
				if (convertedStr.length() != 0 && (convertedStr[convertedStr.length() - 1] != ' ')) {
					convertedStr += ' ';
				}
				convertedStr += temp.top();
				temp.pop();
			}
			if (temp.top() == "(")
				temp.pop();
		}
	}
	while (!temp.empty()) // until the stack is empty, add operators to the line
	{
		if (convertedStr.length() != 0 && (convertedStr[convertedStr.length() - 1] != ' ')) {
			convertedStr += ' ';
		}
		convertedStr += temp.top();
		temp.pop();
	}
	return convertedStr;
}

double calculate(string str) {
	Stack<double> calculator;
	string temp;
	double number;
	int position;
	double operand1, operand2, total = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '.')
			temp += str[i];
		else if ((str[i] == ' ') && (str[i - 1] == '0' || str[i - 1] == '1' || str[i - 1] == '2' || str[i - 1] == '3' || str[i - 1] == '4' || str[i - 1] == '5' || str[i - 1] == '6' || str[i - 1] == '7' || str[i - 1] == '8' || str[i - 1] == '9')) {
			number = stod(temp);
			calculator.push(number);
			temp = "\0";;
		}
		// e
		else if (str[i] == 'e') {
			total = e;
			calculator.push(total);
		}
		// pi
		else if (str[i] == 'p') {
			total = pi;
			calculator.push(total);
		}
		// operator + 
		else if (str[i] == '+') {
			operand2 = calculator.top();
			calculator.pop();
			operand1 = calculator.top();
			calculator.pop();
			total = operand1 + operand2;
			calculator.push(total);
		}
		// operator -
		else if (str[i] == '-') {
			operand2 = calculator.top();
			calculator.pop();
			if (calculator.empty()) {
				total = 0 - operand2;
			}
			else {
				operand1 = calculator.top();
				calculator.pop();
				total = operand1 - operand2;
			}
			calculator.push(total);
		}
		// operator *
		else if (str[i] == '*') {
			operand2 = calculator.top();
			calculator.pop();
			operand1 = calculator.top();
			calculator.pop();
			total = operand1 * operand2;
			calculator.push(total);
		}
		// operator /
		else if (str[i] == '/') {
			operand2 = calculator.top();
			calculator.pop();
			operand1 = calculator.top();
			calculator.pop();
			total = operand1 / operand2;
			calculator.push(total);
		}
		// operator ^
		else if (str[i] == '^') {
			operand2 = calculator.top();
			calculator.pop();
			operand1 = calculator.top();
			calculator.pop();
			total = pow(operand1, operand2);
			calculator.push(total);
		}
		// sin
		else if (str[i] == 's' && str[i + 1] == 'i') {
			operand1 = calculator.top();
			calculator.pop();
			total = sin(operand1 * pi / 180);
			calculator.push(total);
			position = str.find("n", i);
			i = position + 1;
		}
		// cos
		else if (str[i] == 'c' && str[i + 1] == 'o') {
			operand1 = calculator.top();
			calculator.pop();
			total = cos(operand1 * pi / 180);
			calculator.push(total);
			position = str.find("s", i);
			i = position + 1;
		}
		// abs
		else if (str[i] == 'a') {
			operand1 = calculator.top();
			calculator.pop();
			total = abs(operand1);
			calculator.push(total);
			position = str.find("s", i);
			i = position + 1;
		}
		// sqrt
		else if (str[i] == 's' && str[i + 1] == 'q') {
			operand1 = calculator.top();
			calculator.pop();
			total = sqrt(operand1);
			calculator.push(total);
			position = str.find("t", i);
			i = position + 1;
		}
		// tg
		else if (str[i] == 't') {
			operand1 = calculator.top();
			calculator.pop();
			total = sin(operand1 * pi / 180) / cos(operand1 * pi / 180);
			calculator.push(total);
			position = str.find("t", i);
			i = position + 1;
		}
		// ctg
		else if (str[i] == 'c' && str[i + 1] == 't') {
			operand1 = calculator.top();
			calculator.pop();
			total = cos(operand1 * pi / 180) / sin(operand1 * pi / 180);
			calculator.push(total);
			position = str.find("g", i);
			i = position + 1;
		}
		// log
		else if (str[i] == 'l' && str[i + 1] == 'o') {
			operand1 = calculator.top();
			calculator.pop();
			total = log10(operand1);
			calculator.push(total);
			position = str.find("g", i);
			i = position + 1;
		}
		// ln
		else if (str[i] == 'l' && str[i + 1] == 'n') {
			operand1 = calculator.top();
			calculator.pop();
			total = log(operand1);
			calculator.push(total);
			position = str.find("n", i);
			i = position + 1;
		}
	}
	cout << setprecision(16);
	if (!(calculator.empty())) {
		double resultat = calculator.top();
		cout << "Calculation result: \n" << resultat << endl;
		return resultat;
	}
}


int main() {
	string stroka;
	char ch = 0;		// input character
	int i = 0;
	cout << "Enter the expression you want to calculate. Don't forget the '=' at the end." << endl;
	do {
		cin >> ch;
		if (((stroka[i] < 58 && stroka[i] > 47) || stroka[i] == 41) && (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')) {
			stroka += ' ';
			stroka += ch;
		}
		else if (((ch < 58 && ch > 47) || ch == 40) && (stroka[i] == '+' || stroka[i] == '-' || stroka[i] == '*' || stroka[i] == '/' || stroka[i] == '^')) {
			stroka += ' ';
			stroka += ch;
		}
		else if (((ch < 91 && ch > 64) || (ch < 123 && ch > 96)) && (stroka[i] == '+' || stroka[i] == '-' || stroka[i] == '*' || stroka[i] == '/' || stroka[i] == '^')) {
			stroka += ' ';
			stroka += ch;
		}
		else if (((stroka[i] < 91 && stroka[i] > 64) || (stroka[i] < 123 && stroka[i] > 96)) && (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')) {
			stroka += ' ';
			stroka += ch;
		}
		else stroka += ch;
		i = stroka.length() - 1;

	} 	while (ch != '=');
	/*cout << stroka << endl;*/
	string postFixString;
	try {
		if (check_bracekts(stroka) && check_for_correct_input(stroka)) {
			postFixString = postfix(stroka); // convert to postfix
			cout << "Reverse Polish notation:" << endl;
			cout << postFixString << '\n';
		}
		calculate(postFixString);
	}
	catch (const invalid_argument error) {
		cout << error.what() << endl << endl;
	}

}