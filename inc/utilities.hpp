#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <exception>
#include <iostream>
#include <filesystem>

namespace Utilities {

// Logs an error message to stderr.
// You can redirect or extend this to log to a file, system log, etc.
inline void logError(const std::string& msg) {
    std::cerr << "[Error] " << msg << '\n';
}

// Central exception handler.
// Call this in your catch-blocks to funnel all exceptions through one place.
inline void handleException(const std::exception& ex) {
    logError(ex.what());
    // You could add cleanup or termination logic here, e.g. std::exit(EXIT_FAILURE);
}

// Returns true if the given path exists on disk.
// Uses std::filesystem (C++17).
inline bool fileExists(const std::string& path) {
    return std::filesystem::exists(path);
}

} // namespace Utilities

#endif // UTILITIES_HPP
