/*
** EPITECH PROJECT, 2021
** B-CNA_Groundhog
** File description:
** TestDisplay
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Groundhog.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_values, test_output, .init=redirect_all_stdout)
{
    Groundhog g("7");
    g.DisplayValues();

    cr_assert_stdout_eq_str("g=0.00\tr=0%\ts=0.00\n");
}