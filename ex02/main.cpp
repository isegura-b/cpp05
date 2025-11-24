#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm s("home");
        RobotomyRequestForm r("Bender");
        PresidentialPardonForm p("Arthur Dent");

        std::cout << "\n--- SIGNING FORMS ---\n";
        intern.signForm(s);
        boss.signForm(s);
        boss.signForm(r);
        boss.signForm(p);

        std::cout << "\n--- EXECUTING FORMS ---\n";
        intern.executeForm(s);
        boss.executeForm(s);
        boss.executeForm(r);
        boss.executeForm(p);
    }
    catch (std::exception &e) {
        std::cout << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}
