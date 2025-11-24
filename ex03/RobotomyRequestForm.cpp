#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &t)
    : AForm("Robotomy", 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o)
    : AForm(o), target(o.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &o)
{
    if (this != &o)
        target = o.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction(Bureaucrat const &) const
{
    std::cout << "* drilling noises *\n";
    srand(time(NULL)); // Seed the random number generator
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
}
