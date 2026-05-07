#include "../include/DigOut.hpp"

using namespace gpio;
using namespace eeros::hal;

DigOut::DigOut(std::string id, void *libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted)
    : Output<bool>(id, libHandle), chip(device), line(chip.get_line(channel)) {
  line.request({"gpio-eeros", gpiod::line_request::DIRECTION_OUTPUT, inverted}, 0); // initial logical value
}

DigOut::~DigOut() {}

bool DigOut::get(){
  return line.get_value() == 1;
}

void DigOut::set(bool value){
  line.set_value(value ? 1 : 0);
}

extern "C" eeros::hal::Output<bool> *createDigOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted){
  return new gpio::DigOut(id, libHandle, device, subDeviceNumber, channel, inverted);
}
