/*!
    \file logger_filter.h
    \brief Logger filter definition
    \author Ivan Shynkarenka
    \date 27.07.2016
    \copyright MIT License
*/

#ifndef CPPLOGGING_FILTERS_LOGGER_FILTER_H
#define CPPLOGGING_FILTERS_LOGGER_FILTER_H

#include "logging/filter.h"

#include <regex>

namespace CppLogging {

//! Logger filter
/*!
    Logger filters out logging records which logger filed is not matched
    to the given regular expression pattern.

    Thread-safe.
*/
class LoggerFilter : public Filter
{
public:
    //! Initialize logger filter with a given regular expression pattern
    /*!
         \param pattern - Regular expression pattern
    */
    explicit LoggerFilter(const std::regex& pattern) : _pattern(pattern) {}
    LoggerFilter(const LoggerFilter&) = delete;
    LoggerFilter(LoggerFilter&&) noexcept = default;
    virtual ~LoggerFilter() = default;

    LoggerFilter& operator=(const LoggerFilter&) = delete;
    LoggerFilter& operator=(LoggerFilter&&) noexcept = default;

    // Implementation of Filter
    bool FilterRecord(Record& record) override;

private:
    std::regex _pattern;
};

} // namespace CppLogging

#endif // CPPLOGGING_FILTERS_LOGGER_FILTER_H
