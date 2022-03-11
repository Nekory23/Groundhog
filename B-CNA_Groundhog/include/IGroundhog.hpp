/*
** EPITECH PROJECT, 2021
** B-CNA_Groundhog
** File description:
** IGroundhog
*/

#ifndef IGROUNDHOG_HPP_
#define IGROUNDHOG_HPP_

#include <string>

class IGroundhog {
    public:
        ~IGroundhog() = default;
        virtual int Loop() = 0;
        virtual std::string CleanInput(std::string input) = 0;
        virtual void DisplayEnd(void) = 0;
        virtual void DisplayValues(void) = 0;
        virtual void CheckInput(std::string input) = 0;
        virtual void ComputeG(void) = 0;
        virtual void ComputeR(void) = 0;
        virtual void ComputeS(void) = 0;

    protected:
    private:
};

#endif /* !IGROUNDHOG_HPP_ */
