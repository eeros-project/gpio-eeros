# gpio-eeros

Hardware wrapper library for the gpio subsystem.

The gpio-eeros wrapper library enables the usage of the gpio subsystem together with the [EEROS Robotics Framework](https://github.com/eeros-project/eeros-framework). 


## Documentation

- Project Website: (http://www.eeros.org)
- Project Wiki: (http://wiki.eeros.org)
- Hardware Abstraction Layer: (http://wiki.eeros.org/eeros_architecture/hal/start) 


## Getting Started

The easiest way to get started using EEROS is described in [Installation and Setup](https://wiki.eeros.org/getting_started/install_and_setup_development_environment). The EEROS framework uses various [hardware libraries](http://wiki.eeros.org/eeros_architecture/hal/hardware_libraries) to access the underlying hardware. The use of this hardware wrapper library can be studied from an example in EEROS, see [Using the HAL with the gpio subsystem](https://wiki.eeros.org/getting_started/tutorials/hal3). 

The EEROS [Hardware Abstraction Layer](http://wiki.eeros.org/eeros_architecture/hal/start) needs a [configuration file](http://wiki.eeros.org/eeros_architecture/hal/configuration_file) which describes the hardware. A hardware configuration file must be created according to your actual hardware setup. An example can be found under [HalTest4ConfigGpio.json](https://github.com/eeros-project/eeros-framework/blob/master/examples/hal/HalTest4ConfigGpio.json).


## How to contribute to gpio-eeros

The [EEROS Team](http://eeros.org/eeros-team/) would love to accept your contributions! The development on the EEROS Framework is done with the work flow “**develop with a fork**”. So please fork the repository, develop and test your code changes. For code quality, please follow the guidelines put together [here](http://wiki.eeros.org/for_developers/start). In general, the code should adheres to the existing style in the project. Once the changes are ready, a pull request is submitted. Each logical change should be submitted separately to ensure that the history will be understandable.
