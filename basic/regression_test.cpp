/**
 * Copyright 2018-2020 Pejman Ghorbanzade. All rights reserved.
 */

#include "regression_test.hpp"
#include <iostream>
#include <thread>

int main()
{
    weasel::configure(
        { { "api-key", "d0aace33-a146-4e47-9944-28b6164afe63" },
            { "api-url", "https://getweasel.com/api/@/mydemo/test" },
            { "version", "2.0" } });

    if (!weasel::is_configured()) {
        std::cerr << weasel::configuration_error() << std::endl;
        return EXIT_FAILURE;
    }

    for (const auto& username : { "rweasley", "hpotter", "hgranger" }) {
        weasel::declare_testcase(username);

        const auto& wizard = parse_profile(username);

        weasel::add_assertion("username", wizard.username);
        weasel::add_result("fullname", wizard.fullname);
        weasel::add_result("height", wizard.height);
        weasel::add_result(L"weight", wizard.weight);
        weasel::add_result("birth_date", wizard.dob);

        custom_function_1(wizard);

        std::thread t(custom_function_2, wizard);
        t.join();

        weasel::start_timer("func3");
        custom_function_3(wizard);
        weasel::stop_timer("func3");
    }

    weasel::save_binary("weasel_tutorial.bin");
    weasel::save_json("weasel_tutorial.json");

    if (!weasel::post()) {
        std::cerr << "failed to post results to weasel server" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
