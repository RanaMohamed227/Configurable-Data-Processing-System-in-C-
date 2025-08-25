#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>
#include <iomanip>
#include "json.hpp"

class configuration
{
private:
  std::string path_;

protected:
  std::string type{"Text"};
  int MaxRetries{0};
  double Threshold{0.0};

public:
  configuration(const std::string &file = "config/settings.json") : path_{file} {}

  void setType(std::string &t);
  void setMaxRetries(int r);
  void setThreshold(double th);

  std::string getType(void) const;
  int getMaxRetries(void) const;
  double getThreshold(void) const;

  // Added this method that main.cpp needs
  std::string getOption(const std::string &key) const
  {
    if (key == "Processor.Options.Type")
      return type;
    return "";
  }

  void load();
  void save() const;
};

#endif