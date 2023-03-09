#include <iostream>
#include <string>

class ParentClass
{
public:
	int Value;

	virtual void Test()
	{

	}
};

class ChildClassA : public ParentClass {};
class ChildClassB : public ParentClass {};

int main()
{
	int score = 42;
	int maxScore = 100;

	ParentClass* testClass1 = new ChildClassA();
	ParentClass* testClass2 = new ChildClassB();
	ChildClassA* testClass3 = new ChildClassA();

	{
		std::cout << "Static Cast" << std::endl;

		float percentage1 = (float)score / maxScore;
		std::cout << "Percentage is " << percentage1 << std::endl;

		float percentage2 = static_cast<float>(score) / maxScore;
		std::cout << "Percentage is " << percentage2 << std::endl;

		auto testVar1 = static_cast<ChildClassA*>(testClass1);
		auto testVar2 = static_cast<ChildClassA*>(testClass2);
		auto testVar3 = static_cast<ParentClass*>(testClass3);

		std::cout << testVar1 << ", " << testVar2 << ", " << testVar3 << std::endl;

		//std::string testValue = static_cast<std::string>(42);
	}

	{
		std::cout << "Dynamic Cast" << std::endl;

		auto testVar1 = dynamic_cast<ChildClassA*>(testClass1);
		auto testVar2 = dynamic_cast<ChildClassA*>(testClass2);
		auto testVar3 = dynamic_cast<ParentClass*>(testClass3);

		std::cout << testVar1 << ", " << testVar2 << ", " << testVar3 << std::endl;
	}

	{
		std::cout << "Const Cast" << std::endl;

		ParentClass testVar1;
		testVar1.Value = 42;

		const ParentClass& testVar2 = testVar1;
		//testVar2.Value = 500;

		const_cast<ParentClass&>(testVar2).Value = 500;

		std::cout << testVar1.Value << ", " << testVar2.Value << std::endl;
	}

	{
		std::cout << "Reinterpret Cast" << std::endl;
		std::string test = "Hello!";

		auto testVar1 = reinterpret_cast<ChildClassA*>(testClass1);
		auto testVar2 = reinterpret_cast<ChildClassA*>(testClass2);
		auto testVar3 = reinterpret_cast<ParentClass*>(testClass3);
		auto testVar4 = reinterpret_cast<ParentClass*>(&test);

		//testVar4->Test();

		std::cout << testVar1 << ", " << testVar2 << ", " << testVar3 << ", " << testVar4 << std::endl;
	}

	{
		std::cout << "C Style Cast" << std::endl;
		std::string test = "Hello!";

		auto testVar1 = (ChildClassA*)(testClass1);
		auto testVar2 = (ChildClassA*)(testClass2);
		auto testVar3 = (ParentClass*)(testClass3);
		auto testVar4 = (ParentClass*)(&test);

		//testVar4->Test();

		std::cout << testVar1 << ", " << testVar2 << ", " << testVar3 << ", " << testVar4 << std::endl;
	}

	delete testClass1;
	delete testClass2;
	delete testClass3;
}
