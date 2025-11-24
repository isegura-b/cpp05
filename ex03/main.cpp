#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "sh");
    AForm *f2 = someRandomIntern.makeForm("robotomy request", "random");
    AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Bob");
    AForm *bad = someRandomIntern.makeForm("coffee request", "Office");             ///fail

    if (f1)
        boss.signForm(*f1);
    if (f2)
        boss.signForm(*f2);
    if (f3)
        boss.signForm(*f3);

    if (f1)
        boss.executeForm(*f1);
    if (f2)
        boss.executeForm(*f2);
    if (f3)
        boss.executeForm(*f3);

    delete f1;
    delete f2;
    delete f3;
    delete bad; // NULL safe
    return 0;
}
