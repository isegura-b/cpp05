#include "Bureaucrat.hpp"
#include "Form.hpp"
Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Parameterized constructor called for " << name << " with grade " << grade << std::endl;
    if (grade < 1)
        throw GradeTooHighException(); // returns error
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called for " << _name << std::endl;
}

// Getters
const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade -= 1;
    std::cout << "Grade incremented for " << _name << " to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade += 1;
    std::cout << "Grade decremented for " << _name << " to " << _grade << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade too high";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade too low";
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}