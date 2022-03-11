/*
** EPITECH PROJECT, 2021
** B-CNA_Groundhog
** File description:
** test_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Groundhog.hpp"
#include "Error.hpp"

int start(const int ac, const char **av);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error_handling, not_enough_args, .init=redirect_all_stdout)
{
    const int ac = 1;
    const char *av[] = {"\0"};

    start(ac, av);
    cr_assert_stderr_eq_str("Error: The number of arguments is invalid (retry with -h)\n");
}

Test(error_handling, too_many_args, .init=redirect_all_stdout)
{
    const int ac = 3;
    const char *av[] = {"\0", "hey", "hey"};

    start(ac, av);
    cr_assert_stderr_eq_str("Error: The number of arguments is invalid (retry with -h)\n");
}

Test(error_handling_ex, invalid_arg, .init=redirect_all_stdout)
{
    const char *period = "invalid";

    cr_assert_any_throw(Groundhog g(period));
}

Test(error_handling, invalid_arg_str, .init=redirect_all_stdout)
{
    const int ac = 2;
    const char *av[] = {"\0", "hey"};

    start(ac, av);
    cr_assert_stderr_eq_str("Error: The argument must be a positive number (retry with -h)\n");
}

Test(return_value, not_enough_args, .init=redirect_all_stdout)
{
    const int ac = 1;
    const char *av[] = {"\0"};

    cr_assert_eq(start(ac, av), 84);
}

Test(return_value, too_many_arguments, .init=redirect_all_stdout)
{
    const int ac = 3;
    const char *av[] = {"\0", "hey", "hey"};

    cr_assert_eq(start(ac, av), 84);
}

Test(return_value, invalid_argument, .init=redirect_all_stdout)
{
    const int ac = 2;
    const char *av[] = {"\0", "hey"};

    cr_assert_eq(start(ac, av), 84);
}