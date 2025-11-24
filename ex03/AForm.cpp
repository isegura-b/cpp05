#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Form"), isSigned(false), gradeSign(150), gradeExec(150) {}

AForm::AForm(const std::string &n, int gs, int ge)
    : name(n), isSigned(false), gradeSign(gs), gradeExec(ge)
{
    if (gs < 1 || ge < 1)
        throw GradeTooHighException();
    if (gs > 150 || ge > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &o)
    : name(o.name), isSigned(o.isSigned), gradeSign(o.gradeSign), gradeExec(o.gradeExec) {}

AForm &AForm::operator=(const AForm &)
{
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return name; }
bool AForm::getIsSigned() const
{
    return isSigned;
}
int AForm::getGradeSign() const
{
    return gradeSign;
}
int AForm::getGradeExec() const
{
    return gradeExec;
}

void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > gradeSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeExec)
        throw GradeTooLowException();
    executeAction(executor);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "Form " << f.getName()
       << " | Signed: " << f.getIsSigned()
       << " | Grade to sign: " << f.getGradeSign()
       << " | Grade to execute: " << f.getGradeExec();
    return os;
}
