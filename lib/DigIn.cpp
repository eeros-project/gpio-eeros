#include "../include/DigIn.hpp"
#include <vector>

using namespace gpio;
using namespace eeros::hal;

DigIn::DigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted)
    : Input<bool>(id, libHandle), chip(device), offset(channel), inverted(inverted) {
  gpiod::line_settings settings;
  settings.set_direction(gpiod::line::direction::INPUT);
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

DigIn::~DigIn() {}

bool DigIn::get() {
  bool value = request->get_value(offset) == gpiod::line::value::ACTIVE;
  return inverted ? !value : value;
}

extern "C" eeros::hal::Input<bool> *createDigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted){
  return new gpio::DigIn(id, libHandle, device, subDeviceNumber, channel, inverted);
}
