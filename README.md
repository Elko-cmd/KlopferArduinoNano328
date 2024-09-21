
**Project Klopfer**
=======================

This Arduino code simulates the firing sequence of an AK47 rifle. The code is configured to mimic the rifle's firing frequency and magazine capacity. 

**Configuration**
---------------

The code includes several configurable variables:

* `KloppferPin`: The Arduino pin connected to the firing mechanism (set to 2).
* `magazinCap`: The magazine capacity (set to 40 rounds).
* `magazinWechsel`: The time it takes to change the magazine (set to 5 seconds or 5000 milliseconds).
* `interval`: The firing frequency (set to 100 milliseconds, resulting in 10 shots per second).

**Functionality**
----------------

The code uses the `setup()` function to initialize the firing pin as an output.

The `loop()` function runs continuously, simulating the firing sequence:

1. If the shot counter (`schuss`) is less than or equal to the magazine capacity, the code:
	* Sets the firing pin high for the configured interval.
	* Delays for 20 milliseconds.
	* Sets the firing pin low.
	* Increments the shot counter.
2. If the shot counter exceeds the magazine capacity, the code:
	* Resets the shot counter to 0.
	* Delays for the configured magazine change time.

