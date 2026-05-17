#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeSign;
    const int gradeExec;

protected:      //so only derived forms can implement and use it
    virtual void executeAction(Bureaucrat const & executor) const = 0;

public:
    AForm();
    AForm(const std::string &name, int gradeSign, int gradeExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeSign() const;
    int getGradeExec() const;

    void beSigned(Bureaucrat const &b);

    void execute(Bureaucrat const & executor) const;


    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
