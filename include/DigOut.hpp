#ifndef GPIO_EEROS_DIGOUT_HPP_
#define GPIO_EEROS_DIGOUT_HPP_

#include <eeros/hal/Output.hpp>
#include <gpiod.hpp>
#include <string>

namespace gpio {

class DigOut : public eeros::hal::Output<bool> {
 public:
  DigOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted = false);
  virtual ~DigOut();
  virtual bool get();
  virtual void set(bool value);

 private:
  gpiod::chip chip;
  gpiod::line line;
};

}

extern "C"{
  eeros::hal::Output<bool> *createDigOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted);
}

#endif /* GPIO_EEROS_DIGOUT_HPP_ */
