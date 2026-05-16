# i2c-slave-power-temperature-sensor
Embedded power and temperature monitoring module using STM32F030.

## Features
- Voltage measurement (0-30V)
- Current measurement using shunt + INA180
- Temperature measurement using NTC
- I2C slave interface
- Lookup table conversion

## System Architecture
<img width="500"  alt="image" src="https://github.com/user-attachments/assets/b21aa96a-ad85-4cae-8d7d-d131f806e046" />

## Hardware
**MCU**:
- STM32F030F4P6
  
**Sensors**
- Shunt resistor 0.01R
- INA180A1
- NTC 10K B3950
<img width="500"  alt="a_page-0001" src="https://github.com/user-attachments/assets/7f47a2da-789f-4213-8d6a-e6e24415a9c9" />

## Firmware
For STM32 Cortex-M0 MCUs such as STM32F030, multi-channel ADC works best with:
- ADC Scan Mode
- DMA
  
Polling mode may produce unstable or incorrect channel readings during continuous conversion.
### Clock
<img width="500" alt="image" src="https://github.com/user-attachments/assets/cddd2296-8d5a-4446-bf8c-513c39595318" />

### Pin config
<img width="300"  alt="image" src="https://github.com/user-attachments/assets/446ae76a-4731-4131-b435-738984f712ad" />

## I2C Packet

| Byte | Description |
|------|-------------|
| 0-1 | Voltage |
| 2-3 | Current |
| 4-5 | Temperature |
| 6 | XOR checksum |


## PCB
- High current trace for 15A

  <img width="500" alt="image" src="https://github.com/user-attachments/assets/349c5e17-15d5-4abe-a07f-34907de81d98" />

- 2 Layer PCB
  
  <img width="447" height="428" alt="image" src="https://github.com/user-attachments/assets/423b4a71-0133-4910-8ce9-1f0f61a9f395" />

- Bottom GND plane
  
  <img width="433" height="426" alt="image" src="https://github.com/user-attachments/assets/fdfcd51a-f01a-44ee-bfea-75bbe1b7bf6a" />

- 3D
  
  <img width="379" height="293" alt="image" src="https://github.com/user-attachments/assets/39c5fc2d-73a0-4435-9133-9f5ea9adccd5" />
   <img  height="293" alt="image" src="https://github.com/user-attachments/assets/c5f86431-931d-4b3c-9093-1d3c409b691f" />

## Test config

  <img width="469" height="413" alt="image" src="https://github.com/user-attachments/assets/87bd8b6c-d323-4dba-8d4b-6e048da8e8f4" />


  <img width="500"  alt="image" src="https://github.com/user-attachments/assets/982f32d1-f316-4bca-a9a3-debaad302188" />

### Voltage measurement error <= 1%

### Current Measurement error


| Expected (A) | Min (A) | Max (A) | Error |
|---|---|---|---|
| 1 | 0.97 | 0.97 | 3.0% |
| 2 | 1.94 | 1.95 | 3.0% |
| 3 | 2.93 | 2.93 | 2.3% |
| 4 | 3.93 | 3.93 | 1.8% |
| 5 | 4.93 | 5.02 | 1.4% |
| 6 | 5.93 | 6.00 | 1.2% |
| 7 | 6.98 | 7.14 | 2.0% |
| 8 | 8.00 | 8.15 | 1.9% |
| 9 | 9.02 | 9.30 | 3.3% |
| 10 | 10.15 | 10.50 | 5.0% |

<img width="500"  alt="image" src="https://github.com/user-attachments/assets/8f948eb0-e0b9-4b92-996b-bf9569440214" />

### Temperature measurement was not calibrated
## Future Improvements
### INA Output RC Filter
Add an RC low-pass filter at the INA180 output with cutoff frequency around 1 kHz (reduces PWM motor interference)
<img width="513" height="316" alt="image" src="https://github.com/user-attachments/assets/96e370e0-1bee-47c2-8741-58127274e6a1" />

### Use multiple shunt resistors in parallel.
- current sharing
- lower shunt temperature
- improved current measurement stability
  
<img width="508" height="287" alt="image" src="https://github.com/user-attachments/assets/2aa04da8-7216-47d7-823f-fa9f2d1632f6" />

### High Current PCB Redesign
<img width="483" height="458" alt="image" src="https://github.com/user-attachments/assets/6da83241-6ea8-48bf-ad98-9d4870d854b1" />


## Project Structure




