#include <iostream>
#include "first_contest.h"


using namespace FirstContest;

int main()
{
    int problemset{};
    int task{};
    std::cout << "Choose problemset: ";
    std::cin >> problemset;
    std::cout << "Choose task to test: ";
    std::cin >> task;

    if(!(1 <= problemset && problemset <= 6) || !(1 <= task && task <= 6))
        throw std::range_error("Problemset or task number out of range.\n");

    switch(10*problemset + task)
    {
    case 11:
        Problemset1::Task1::main();
        break;
    case 12:
        Problemset1::Task2::main();
        break;
    case 13:
        Problemset1::Task3::main();
        break;
    case 14:
        Problemset1::Task4::main();
        break;
    case 15:
        Problemset1::Task5::main();
        break;
    case 16:
        Problemset1::Task6::main();
        break;
    case 21:
        Problemset2::Task1::main();
        break;
    case 22:
        Problemset2::Task2::main();
        break;
    case 23:
        Problemset2::Task3::main();
        break;
    case 24:
        Problemset2::Task4::main();
        break;
    case 31:
        Problemset3::Task1::main();
        break;
    case 32:
        Problemset3::Task2::main();
        break;
    case 33:
        Problemset3::Task3::main();
        break;
    case 34:
        Problemset3::Task4::main();
        break;
    case 41:
        Problemset4::Task1::main();
        break;
    case 42:
        Problemset4::Task2::main();
        break;
    case 43:
        Problemset4::Task3::main();
        break;
    case 51:
        Problemset5::Task1::main();
        break;
    case 52:
        Problemset5::Task2::main();
        break;
    case 53:
        Problemset5::Task3::main();
        break;
    case 61:
        Problemset6::Task1::main();
        break;
    case 62:
        Problemset6::Task2::main();
        break;
    case 63:
        Problemset6::Task3::main();
        break;
    case 64:
        Problemset6::Task4::main();
        break;
    default:
        throw std::logic_error("Given problemset does not have specified task for test.\n");
    }

    return 0;
}
