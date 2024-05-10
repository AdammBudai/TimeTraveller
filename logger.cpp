//
// Created by adamb on 10. 5. 2024.
//

#include "logger.h"

void Logger::init() {

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("events.log", true);

    auto console_sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();

    auto logger = std::make_shared<spdlog::logger>("multi_sink", spdlog::sinks_init_list{file_sink, console_sink});

    logger->set_level(spdlog::level::debug);

    spdlog::set_pattern("[%H:%M:%S] [%t] [%l] %v");

    spdlog::register_logger(logger);
}

std::shared_ptr<spdlog::logger> Logger::getLogger() {
    return spdlog::get("multi_sink");
}