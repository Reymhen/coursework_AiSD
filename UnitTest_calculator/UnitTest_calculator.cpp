#include "pch.h"
#include "CppUnitTest.h"
#include "../calculator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestcalculator
{
	TEST_CLASS(UnitTestcalculator)
	{
	public:
		
		TEST_METHOD(Testcheck_for_correct_input)
		{
			string stroka("56. - 4");
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect number", error.what());
			}
			stroka = "\0";
			stroka = "8 + 9";
			try {
				check_for_correct_input(stroka);
				string check("8 9 +");
				string postcheck = postfix(stroka);
				Assert::IsTrue(check == postcheck);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application *", error.what());
			}
			stroka = "\0";
			stroka = "*8 + 9";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application *", error.what());
			}
			stroka = "\0";
			stroka = "8 + 9*";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application *", error.what());
			}
			stroka = "\0";
			stroka = "+8 + 9";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application +", error.what());
			}
			stroka = "\0";
			stroka = "8 + 9+";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application +", error.what());
			}
			stroka = "\0";
			stroka = "8 + 9-";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application -", error.what());
			}
			stroka = "\0";
			stroka = "/8 + 9";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application /", error.what());
			}
			stroka = "\0";
			stroka = "8 + 9/";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application /", error.what());
			}
			stroka = "\0";
			stroka = "8 + 9^";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect application ^", error.what());
			}
			stroka = "\0";
			stroka = "(8 + 9^)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("the closing parenthesis is used incorrectly", error.what());
			}
			stroka = "()";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("open parenthesis is used incorrectly", error.what());
			}
			stroka = "\0";
			stroka = "abc(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("misspelling the abs() function", error.what());
			}
			stroka = "\0";
			stroka = "abs-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the abs() function", error.what());
			}
			stroka = "\0";
			stroka = "son(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("misspelling the sin() or sqrt() function", error.what());
			}
			stroka = "\0";
			stroka = "sin4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the sin() function", error.what());
			}
			stroka = "\0";
			stroka = "sqrt4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the sqrt() function", error.what());
			}
			stroka = "\0";
			stroka = "con(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("misspelling the cos() or ctg() function", error.what());
			}
			stroka = "\0";
			stroka = "cos4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the cos() or ctg() function", error.what());
			}
			stroka = "\0";
			stroka = "ctg4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the cos() or ctg() function", error.what());
			}
			stroka = "\0";
			stroka = "lon(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("misspelling the log() or ln() function", error.what());
			}
			stroka = "\0";
			stroka = "log4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the log() function", error.what());
			}
			stroka = "\0";
			stroka = "ln-8)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the ln() function", error.what());
			}
			stroka = "\0";
			stroka = "tt(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("misspelling the tg() function", error.what());
			}
			stroka = "\0";
			stroka = "tg45)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the tg() function", error.what());
			}
			stroka = "\0";
			stroka = "pe";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("misspelling the pi const", error.what());
			}
			stroka = "\0";
			stroka = "pi8";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the pi const", error.what());
			}
			stroka = "\0";
			stroka = "e8";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("incorrect arithmetics the e const", error.what());
			}
			stroka = "\0";
			stroka = "8-9*ã";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Invalid character. The calculator can use numbers like double, brackets, actions: +, -, *, /, ^ and functions: sin(), cos(), tg(), ctg(), sqrt(), log(), ln(), abs()", error.what());
			}
		}
		TEST_METHOD(TestTakesPrecedence)
		{
			string stroka("*");
			Assert::IsTrue(TakesPrecedence(stroka) == 2);

			stroka = "\0";
			stroka = "/";
			Assert::IsTrue(TakesPrecedence(stroka) == 2);

			stroka = "\0";
			stroka = "-";
			Assert::IsTrue(TakesPrecedence(stroka) == 1);

			stroka = "\0";
			stroka = "+";
			Assert::IsTrue(TakesPrecedence(stroka) == 1);

			stroka = "\0";
			stroka = "^";
			Assert::IsTrue(TakesPrecedence(stroka) == 3);

			stroka = "\0";
			stroka = "sin";
			Assert::IsTrue(TakesPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "sqrt";
			Assert::IsTrue(TakesPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "cos";
			Assert::IsTrue(TakesPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "ctg";
			Assert::IsTrue(TakesPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "tg";
			Assert::IsTrue(TakesPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "abs";
			Assert::IsTrue(TakesPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "log";
			Assert::IsTrue(TakesPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "ln";
			Assert::IsTrue(TakesPrecedence(stroka) == 4);
		}
		TEST_METHOD(Testpostfix)
		{
			string stroka("abs( - 4) * 8 + sin(0) - 9 / 3 + 2 ^ 2");
			string postcheck = postfix(stroka);
			string check("4 - abs 8 * 0 sin + 9 3 / - 2 2 ^ +");
			Assert::IsTrue(check == postcheck);

			stroka = "\0";
			check = "\0";
			stroka = "tg(45) + cos(60) - ctg(45) * pi / 10 + 9";
			check = "45 tg 60 cos + 45 ctg pi* 10 / - 9 +";
			postcheck = "\0";
			postcheck = postfix(stroka);
			Assert::IsTrue(check == postcheck);
		}
		TEST_METHOD(Test_check_bracekts)
		{
			string stroka("abs( - 4) * 8 + sin(0) - 9 / 3 + 2 ^ 2");
			check_bracekts(stroka);
			bool check = true;
			Assert::IsTrue(check == check_bracekts(stroka));

			stroka = "\0";
			stroka = (")(");
			try {
				check_bracekts(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Brackets are placed incorrectly", error.what());
			}

			stroka = "\0";
			stroka = ("(9-3)+(7*(8+8)");
			try {
				check_bracekts(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("The number of opening and closing parentheses is not equal", error.what());
			}
		}
		TEST_METHOD(Testcalculate)
		{
			string stroka("4 - abs 8 * 0 sin + 9 3 / - 2 2 ^ +");
			double check = 33;
			Assert::IsTrue(check == calculate(stroka));

			stroka = "\0";
			stroka = "45 tg 45 ctg + e ln 10 log 60 cos / 4 sqrt ^ * -";
			check = -1.9999987643270738;
			Assert::IsTrue(check == calculate(stroka));
		}
	};
}
