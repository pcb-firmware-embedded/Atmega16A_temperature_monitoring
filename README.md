# ATmega16A Temperature Monitoring and Alarm System

## Project Overview

This repository contains the complete development of a temperature monitoring and alarm system based on the **ATmega16A** microcontroller.

The project includes:

- Firmware development in Atmel Studio
- Circuit simulation in Proteus
- Schematic capture in KiCad
- PCB layout and 3D visualization
- Bluetooth communication
- LCD interface
- DHT11 temperature & humidity sensing
- Relay, buzzer and warning LED control

---

# Firmware Development (Atmel Studio)

The firmware was written in Embedded C using Atmel Studio.

![Atmel Studio](img/avr.png)

---

# Proteus Simulation

The complete system was verified in Proteus before manufacturing the PCB.

![Proteus Simulation](img/proteus.png)

---

# KiCad Schematic

The schematic integrates:

- ATmega16A
- DHT11
- Bluetooth module
- LCD
- Relay
- Buzzer
- LED
- Power supply

![KiCad Schematic](img/kicad1.png)

---

# PCB Design

The PCB was designed in KiCad with attention to routing, grounding and component placement.

![PCB 3D](img/kicad2.png)

---

## Project Workflow

```text
Firmware Development
        ↓
Proteus Simulation
        ↓
KiCad Schematic
        ↓
PCB Layout
        ↓
Hardware Manufacturing
        ↓
Testing
```

## Technologies

- ATmega16A
- Embedded C
- Atmel Studio
- KiCad
- Proteus
- DHT11
- LCD1602
- UART Bluetooth
