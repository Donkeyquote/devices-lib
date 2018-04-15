//Settings

#ifndef settings_h
#define settings_h
/********** INPUTS ************/

//Temperature
const int __solar_temperature_sensor_pin__ = 31;
const int __tank_temperature_sensor_pin__ = 32;
const int __pool_temperature_sensor_pin__ = 33;
const int __radiant_temperature_sensor_pin__ = 30;

//Humidity
const int __external_humidity_sensor_pin__ = 26;
const int __humidity_sensor_pin_1__ = 27;
const int __humidity_sensor_pin_2__ = 25;

//Photosensor
const int __photosensor_pin__ = 53; //OK

//Button selector
const int __selector_winter_pin__ = 51; //OK
const int __selector_summer_pin__ = 50; //OK

/********** OUTPUTS ************/

//Valves
const int __pool_valve_A_pin__ = 46; //OK
const int __pool_valve_B_pin__ = 47; //OK

const int __radiant_valve_A_pin__ = 44; //OK
const int __radiant_valve_B_pin__ = 45; //OK

//Solar Pump
const int __solar_pump_pin__ = 40; //OK

//Return Pump
const int _return_pump_pin_ = 41; //OK

//Radiant floor pump
const int _radiant_floor_pump_pin_ = 42; //OK

//Extractor system
const int __extractor_pin__ = 43; //OK

//Boiler bridge
const int __bridge_boiler_pin__ = 38; //OK

// Heat pump bridge
const int __bridge_heat_pump_pin__ = 39; //OK


/********** TIMERS *********/
// Valves
const unsigned long int __time_valves_on__ = 125000; //cutting off voltage on valves after acting
//const unsigned long int __delay_heat_exchange__ = 300000; //pause on exchanging heat on valves milliseconds

// Extractor
const unsigned long int __extractor_on_time__ = 60 * 1000.0;//45 * 60 * 1000.0; // maximum time the extractor system is running (tOn)
const unsigned long int __extractor_off_time__ = 60 * 1000.0;//5 * 3600 * 1000.0; //checking every 5 hours(tOff)

// Solar pump
const unsigned long int __solar_check_time_off__ = 10 * 60 * 1000.0; // time off before sweeping
const unsigned long int __solar_check_time_on__ = 1 * 60 * 1000.0; // time running when sweeping

// Return pump
const unsigned long int __return_check_time_off__ = 10 * 60 * 1000.0;
const unsigned long int __return_check_time_on__ = 3 * 60 * 1000.0;;

// Solar
//const unsigned long int __delay_solar_exchange__ = 120000;
const float __solar_min_temperature__ = 10.0; //ºC external minimum temperature to run solar system

// Temperature solar Sensor (35->65<-inf)
const float __lower_threshold_AB__ = 30.0; //ºC primary minimum temperature to run solar system
const float __upper_threshold_AB__ = 999.9; //ºC primary maximum temperature on solar system
const float __setup_value_AB__ = 65.0;

// Tank Sensor: (45->50<-60)
const float __lower_threshold_tank__ = 5; //ºC primary minimum temperature to run solar system
const float __upper_threshold_tank__ = 10.0; //ºC primary maximum temperature on solar system
const float __setup_value_tank__ = 50.0;

// Pool Sensor: (22->23<-33)
const float __lower_threshold_pool__ = 1.0; //ºC primary minimum temperature to run solar system
const float __upper_threshold_pool__ = 10.0; //ºC primary maximum temperature on solar system
const float __setup_value_pool__ = 23.0;

// Radiant floor Sensor: (37->40<-45)
const float __lower_threshold_radiant__ = 3.0; //ºC primary minimum temperature to run solar system
const float __upper_threshold_radiant__ = 5.0; //ºC primary maximum temperature on solar system
const float __setup_value_radiant__ = 40.0;

// Fans relative humidity external vs -1
const float __start_external_vs_1__ = 1.10;
const float __stop_external_vs_1__ = 1.05;
const float __correction_sensor_h_1__ = 1.0;

// Fans relative humidity external vs -2
const float __start_external_vs_2__ = 1.10;
const float __stop_external_vs_2__ = 1.05;
const float __correction_sensor_h_2__ = 1.25;

#endif