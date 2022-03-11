/*
** EPITECH PROJECT, 2021
** B-CNA_Groundhog
** File description:
** TestCleanInput
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Groundhog.hpp"

Test(clean_input, already_clean)
{
    Groundhog g("7");
    std::string test = "hello";

    cr_assert_eq(g.CleanInput(test), test);
}

Test(clean_input, spaces_before)
{
    Groundhog g("7");
    std::string test = "    hello";
    std::string ref = "hello";

    cr_assert_eq(g.CleanInput(test), ref);
}

Test(clean_input, spaces_after)
{
    Groundhog g("7");
    std::string test = "hello     ";
    std::string ref = "hello";

    cr_assert_eq(g.CleanInput(test), ref);
}

Test(clean_input, spaces_after_and_before)
{
    Groundhog g("7");
    std::string test = "    hello     ";
    std::string ref = "hello";

    cr_assert_eq(g.CleanInput(test), ref);
}

Test(clean_input, tabs_after)
{
    Groundhog g("7");
    std::string test = "hello\t";
    std::string ref = "hello";

    cr_assert_eq(g.CleanInput(test), ref);
}

Test(clean_input, tabs_before)
{
    Groundhog g("7");
    std::string test = "\thello";
    std::string ref = "hello";

    cr_assert_eq(g.CleanInput(test), ref);
}

Test(clean_input, tabs_after_and_before)
{
    Groundhog g("7");
    std::string test = "\thello\t";
    std::string ref = "hello";

    cr_assert_eq(g.CleanInput(test), ref);
}