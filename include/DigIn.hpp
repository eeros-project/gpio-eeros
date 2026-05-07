#ifndef GPIO_EEROS_DIGIN_HPP_
#define GPIO_EEROS_DIGIN_HPP_

#include <eeros/hal/Input.hpp>
#include <gpiod.hpp>
#include <string>

namespace gpio {

class DigIn : public eeros::hal::Input<bool> {
 public:
  DigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted = false);
  virtual ~DigIn();
  virtual bool get();

 private:
  gpiod::chip chip;
  gpiod::line line;
};

}

extern "C"{
  eeros::hal::Input<bool> *createDigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted);
}

#endif /* GPIO_EEROS_DIGIN_HPP_ */
