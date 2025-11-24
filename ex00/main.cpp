#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
    }
    catch (std::exception &e)  //catching exceptions
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------" << std::endl;

    try
    {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------" << std::endl;

    try
    {
        Bureaucrat c("Charlie", 200);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
