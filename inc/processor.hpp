#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP
#include "configuration.hpp"
#include <iostream>
#include <string>

class processor
{
protected:
    static int countRetries;

public:
    processor(const configuration &config);
    virtual ~processor();

    virtual void process(const std::string &data) = 0;

    static int getcountRetries(void)
    {
        return countRetries;
    }
};

class TextProcessor : public processor
{
public:
    TextProcessor(const configuration &cfg) : processor(cfg) {}
    void process(const std::string &) override;
};

class NumericProcessor : public processor
{
public:
    NumericProcessor(const configuration &cfg) : processor(cfg) {}
    void process(const std::string &) override;
};

class ImageProcessor : public processor
{
public:
    ImageProcessor(const configuration &cfg) : processor(cfg) {}
    void process(const std::string &) override;
};

class AudioProcessor : public processor
{
public:
    AudioProcessor(const configuration &cfg) : processor(cfg) {}
    void process(const std::string &) override;
};

processor *createProcessor(const configuration &config);

#endif