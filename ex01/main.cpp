#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 50);
        Form f("TopSecret", 30, 10);

        std::cout << a << std::endl;
        std::cout << f << std::endl;

        a.signForm(f); // debería fallar, grade 50 > 30
        a.incrementGrade(); // Alice pasa a 49
        a.signForm(f); // sigue fallando
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    try
    {
        Bureaucrat b("Bob", 1);
        Form f2("LowSecret", 2, 5);
        b.signForm(f2); // éxito
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
