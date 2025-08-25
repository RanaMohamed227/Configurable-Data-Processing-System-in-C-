#ifndef PROCESSORFACTORY_HPP
#define PROCESSORFACTORY_HPP
#include "processor.hpp"
#include <string>

class ProcessorFactory
{
public:
    static processor *createProcessor(const std::string &type);
};
#endif // PROCESSORFACTORY_HPP