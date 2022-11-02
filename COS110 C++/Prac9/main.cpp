#include <iostream>
#include <string>
#include <sstream>

/*Do not remove this unless you want endless amounts of errors*/
#include "Operator.cpp"
#include "MinusOperator.cpp"
#include "MultiplyOperator.cpp"
#include "PlusOperator.cpp"
#include "Node.cpp"
#include "Stack.cpp"
#include "Calculator.cpp"
int main()
{
    Calculator<int> calc;
    calc.addValue(1);
    calc.addValue(2);
    calc.addValue(3);
    Operator<int>* minus = new MinusOperator<int>;
    Operator<int>* plus = new PlusOperator<int>;
    Operator<int>* multiply = new MultiplyOperator<int>;
    calc.addOperator(plus);
    calc.addOperator(multiply);
    std::cout << calc.calculate() << std::endl;
    calc.addValue(4);
    calc.addValue(5);
    calc.addValue(6);
    calc.addOperator(minus);
    std::cout << calc.numOperators() << " " << calc.numValues() << std::endl;
    calc.removeValue();
    std::cout << calc.calculate() << std::endl;
    calc.addOperator(multiply);
    std::cout << calc.calculate() << std::endl;
    calc.removeOperator();
    std::cout << calc.calculate() << std::endl;
    return 0;
}