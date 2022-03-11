/*
** EPITECH PROJECT, 2021
** B-CNA_Groundhog
** File description:
** Groundhog
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <vector>
#include <map>
#include "IGroundhog.hpp"

class Groundhog : public IGroundhog {
    public:
        Groundhog(const char *period);
        ~Groundhog() = default;
        int Loop();
        std::string CleanInput(std::string input) noexcept;
        void DisplayEnd(void) noexcept;
        void DisplayValues(void) noexcept;
        void CheckInput(std::string input);
        void ComputeG(void) noexcept;
        void ComputeR(void) noexcept;
        void ComputeS(void) noexcept;

    protected:
    private:
        int _period;
        float _tmp;
        std::vector<float> _dif;
        int _switch;
        std::vector<float> _input;
        std::map<float, float> _difM;

        float _g;
        float _r;
        float _s;
};

static const int SUCCESS = 0;
static const int ERROR = 84;

#endif /* !GROUNDHOG_HPP_ */
