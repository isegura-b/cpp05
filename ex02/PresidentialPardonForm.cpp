#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &t)
    : AForm("Presidential Pardon", 25, 5), target(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &o)
    : AForm(o), target(o.target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &o)
{
    if (this != &o)
        target = o.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction(Bureaucrat const &) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
