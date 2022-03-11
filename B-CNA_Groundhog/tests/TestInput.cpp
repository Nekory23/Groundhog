/*
** EPITECH PROJECT, 2021
** B-CNA_Groundhog
** File description:
** TestInput
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Groundhog.hpp"

Test(checkInput, invalid_input)
{
    Groundhog g("7");

    cr_assert_any_throw(g.CheckInput("aaaaaaa"));
}