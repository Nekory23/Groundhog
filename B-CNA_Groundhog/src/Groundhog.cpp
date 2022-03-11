/*
** EPITECH PROJECT, 2021
** B-CNA_Groundhog
** File description:
** Groundhog
*/

#include <iomanip>
#include <math.h>
#include <algorithm>
#include <iterator>
#include "Groundhog.hpp"
#include "Error.hpp"

Groundhog::Groundhog(const char *period)
{
    for (int i = 0; period[i] != '\0'; i++) {
        if (period[i] >= '0' && period[i] <= '9')
            continue;
        throw Error(std::cerr, "The argument must be a positive number");
    }
    _period = std::atoi(period);
    _switch = 0;
    _g = 0;
    _r = 0;
    _s = 0;
    _tmp = 0;
}

int Groundhog::Loop()
{
    std::string input;
    int count = _period;

    while (1) {
        if (!std::getline(std::cin, input))
            throw Error(std::cerr, "No stop command");
        if (input.empty())
            throw Error(std::cerr, "The argument must be a number");
        input = CleanInput(input);
        if (input.compare("STOP") == 0) {
            if (count == 0) {
                DisplayEnd();
                break;
            }
            else
                throw Error(std::cerr, "Not enough values");
        }
        CheckInput(input);
        _input.push_back(atof(input.c_str()));
        if (count > 1) {
            std::cout << "g=nan\tr=nan%\ts=nan" << std::endl;
            count--;
        } else if (count == 1) {
            ComputeS();
            std::cout << "g=nan\tr=nan%\ts=" << std::fixed << std::setprecision(2) << _s << std::endl;
            count--;
            _s = 0;
        }
        else {
            ComputeG();
            ComputeR();
            ComputeS();
            DisplayValues();
            _g = 0;
            _tmp = _r;
            _r = 0;
            _s = 0;
        }
    }
    return SUCCESS;
}

std::string Groundhog::CleanInput(std::string str) noexcept
{
    int len = str.length();
    int free = 0;
    bool space = false;

    for (int i = 0; i < len; i++) {
        while (free == 0 && i < len && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i] == ' ' || str[i] == '\t') {
            if (!space) {
                str[free++] = str[i];
                space = true;
            }
        } else {
            str[free++] = str[i];
            space = false;
        }
    }
    if (str[free - 1] == ' ' || str[free - 1] == '\t')
        str.erase(str.begin() + free - 1, str.end());
    else
        str.erase(str.begin() + free, str.end());
    return (str);
}

void Groundhog::CheckInput(std::string input)
{
    for (size_t i = 0; i != input.length(); i++) {
        if (input.c_str()[i] == '.' || input.c_str()[i] == '-')
            continue;
        if (input.c_str()[i] >= '0' && input.c_str()[i] <= '9') 
            continue;
        throw Error(std::cerr, "The argument must be a number");
    }
}

void Groundhog::ComputeG(void) noexcept
{
    for (std::size_t counter = _input.size() - _period; counter != _input.size(); counter++) {
        float tmp = _input[counter] - _input[counter-1];
        if (tmp < 0)
            _g += 0;
        else
            _g += tmp;
    }
    _g /= _period;
}

void Groundhog::ComputeR(void) noexcept
{
    float V1 = _input[_input.size() - (_period + 1)];
    float V2 = _input.back();

    _r = V2 - V1;
    _r /= V1;
    _r *= 100;
}

void Groundhog::ComputeS(void) noexcept
{
    float mean = 0;

    for (std::size_t counter = _input.size() - _period; counter != _input.size(); counter++)
        mean += _input[counter];
    mean /= _period;
    for (std::size_t counter = _input.size() - _period; counter != _input.size(); counter++)
        _s += std::pow((_input[counter] - mean), 2);
    _s /= _period;
    _s = std::sqrt(_s);
}

void Groundhog::DisplayValues(void) noexcept
{
    std::cout << "g=";
    std::cout << std::fixed << std::setprecision(2) << _g << "\tr=";
    std::cout << std::fixed << std::setprecision(0) <<_r << "%\ts=";
    std::cout << std::fixed << std::setprecision(2) <<_s;
    if ((_r < 0 && _tmp >= 0) || (_r >= 0 && _tmp < 0)) {
        std::cout << "\ta switch occurs";
        _switch++;
    }
    std::cout << std::endl;
}

void Groundhog::DisplayEnd(void) noexcept
{
    double tmp = 0;
    double dif = 0;
    int display = 5;
    std::map<float, float>::iterator it;

    for (std::size_t i = 1; i != _input.size() - 1; i++) {
        tmp = _input[i-1] + _input[i+1];
        tmp /= 2;
        dif = std::abs(tmp - _input[i]);
        _dif.push_back(dif);
    }
    for (size_t i = 0; i != _dif.size(); i++)
        _difM.emplace(_dif[i], _input[i+1]);
    std::cout << "Global tendency switched " << _switch << " times" << std::endl;
    std::cout << "5 weirdest values are [";
    it = _difM.end();
    for (it--; ; it--, display--) {
        if (display == 1) {
            std::cout << it->second << "]" << std::endl;
            break;
        }
        std::cout << std::fixed << std::setprecision(1) << it->second << ", ";
    }
}