#include "../include/DigIn.hpp"

using namespace gpio;
using namespace eeros::hal;

DigIn::DigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted)
    : Input<bool>(id, libHandle), chip(device), line(chip.get_line(channel)) {
  line.request({"gpio-eeros", gpiod::line_request::DIRECTION_INPUT, inverted}, 0); // initial logical value
}

DigIn::~DigIn() {}

bool DigIn::get() {
    return line.get_value() == 1;
}

extern "C" eeros::hal::Input<bool> *createDigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted){
  return new gpio::DigIn(id, libHandle, device, subDeviceNumber, channel, inverted);
}
