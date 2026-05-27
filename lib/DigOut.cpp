#include "../include/DigOut.hpp"
#include <vector>

using namespace gpio;
using namespace eeros::hal;

DigOut::DigOut(std::string id, void *libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted)
    : Output<bool>(id, libHandle), chip(device), offset(channel), inverted(inverted) {
  gpiod::line_settings settings;
  settings.set_direction(gpiod::line::direction::OUTPUT);
  settings.set_output_value(gpiod::line::value::INACTIVE);
  gpiod::line_config line_cfg;
  line_cfg.add_line_settings(std::vector<gpiod::line::offset>{offset}, settings);
  gpiod::request_config req_cfg;
  req_cfg.set_consumer("gpio-eeros");
  request = std::make_unique<gpiod::line_request>(
    chip.prepare_request()
    .set_request_config(req_cfg)
    .set_line_config(line_cfg)
    .do_request());
}

DigOut::~DigOut() {}

bool DigOut::get(){
  bool value = request->get_value(offset) == gpiod::line::value::ACTIVE;
  return inverted ? !value : value;
}

void DigOut::set(bool value){
  bool physical = inverted ? !value : value;
  request->set_value(offset, physical ? gpiod::line::value::ACTIVE : gpiod::line::value::INACTIVE);
}

extern "C" eeros::hal::Output<bool> *createDigOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted){
  return new gpio::DigOut(id, libHandle, device, subDeviceNumber, channel, inverted);
}
