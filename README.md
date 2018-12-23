# Overview

The light tunnel was built for the inaugural Lafayette Light Festival. It was inspired by an instructable light tunnel (https://www.instructables.com/id/Holiday-Light-Tunnel/), with the addition of programmable LEDs on each connecting piece of the tunnel. 

# Hardware Platform (Light Tunnel)
The instructable was followed as per the instructions on the website with a small modification to allow the tunnel to be placed anywhere. Instead of use rebar hammered into the soil, we concreted 1" PVC pipe into 2 Gallon buckets. 

Rudimentary instructions:
1. 2x: cut 18" length of PVC
1. 2x: PVC glue a T-connector on the end (as a way to stop sliding out)
1. Mix a 60LB bag of cement
1. For each 2 gallon bucket, fill it with half the cement mixed
1. Vibrate to remove airb bubbles
1. Push in the 18" pipe with T-connector in the middle
1. Wait at least 24 hours 

# Software
## Microbit
The code has 5 modes of operation. 

1. Rainbow shift (20mS)
1. Red+White shift (20mS)
1. Blue
1. White
1. Red

### Requirements
1. Install the "Neopixel" extension
1. Lights are of WS2812B driver type

### Shared Project
- Microbit: https://makecode.microbit.org/_EaJKyKFbKU4Y

## Trinket
This code attempts to have 3 output pins that are scheduled with a rainbow motion, each output being slightly lagged with the previous to simulate the effect of a wave as a user walks through the tunnel. The code has minimal compute and memory requirements, so even though tested on a Trinket Pro, this should work on a standard Trinket.

### Requirements
1. Using Arduino IDE 
1. Install the FastLED library: https://github.com/FastLED/FastLED
1. Adafruit Trinket Pro 16MHz 
