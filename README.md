# compactor_machine_controller
Control system for compactor machine

```mermaid
graph TD;
    Machine_App-.->|HTTPS|Machine_Controller;
    Machine_App-->|HTTPS|Machine_Controller;
    Machine_Controller-->|HTTP|Motion_Driver;
    Motion_Driver-.->|HTTP|Machine_Controller;
    Motion_Driver-.->|USB|Motion_Controller;
    Motion_Driver-->|USB|Motion_Controller;
    Motion_Driver-->|HTTP|Machine_Controller;
    Motion_Controller-->|USB|Motion_Driver;
    Motion_Controller-.->DIO;
    DIO-->Motion_Controller;
    Motion_Controller-.->AIO;
    AIO-->Motion_Controller;
    Motion_Controller-.->|i2c|TemperatureIO;
    TemperatureIO-->|i2c|Motion_Controller;

```

# Digital Inputs

# Analog Inputs
## 24V Inputs
### Buttons and Switches
- Switch 1. Operating mode manual and auto
- Switch 2. Operating mode setup or as set on switch 1.
### Endpoints
- Compactor pressure
## Temperature Inputs
4x temperature sensors of type T, Fe-CuNi