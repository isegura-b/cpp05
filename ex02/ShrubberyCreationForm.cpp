#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &t)
    : AForm("Shrubbery", 145, 137), target(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o)
    : AForm(o), target(o.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o)
{
    if (this != &o)
        target = o.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction(Bureaucrat const &) const
{
    std::ofstream file((target + "_shrubbery").c_str());    // create and open file
    if (!file.is_open())
        throw std::runtime_error("Failed to open file");
    file << "       _-_                    _-_\n"
            "    /~~   ~~\\             /~~   ~~\\\n"
            " /~~         ~~\\       /~~         ~~\\\n"
            "{               }      {               }\n"
            " \\  _-     -_  /       \\  _-     -_  /\n"
            "      \\\\ //                \\\\ //   \n"
            "       | |                    | |     \n"
            "       | |                    | |     \n"
            "      // \\                  // \\  \n";
    file.close();
}
