#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}
Intern::~Intern() {}

static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}
static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}
static AForm *createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};         // form names
    AForm *(*creators[3])(const std::string &) = {&createShrubbery, &createRobotomy, &createPresidential};  // corresponding creators(pointers)

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            AForm *f = creators[i](target);
            std::cout << "Intern creates " << formName << std::endl;
            return f;
        }
    }
    std::cout << "Intern cannot create form '" << formName << "': form name unknown" << std::endl;
    return NULL;
}
