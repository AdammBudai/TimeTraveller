//
// Created by adamb on 10. 5. 2024.
//

#ifndef TIMETRAVELLER_LOGGER_H
#define TIMETRAVELLER_LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>

namespace Logger {
    void init();
    std::shared_ptr<spdlog::logger> getLogger();
}

#endif //TIMETRAVELLER_LOGGER_H
