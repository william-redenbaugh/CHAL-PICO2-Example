#ifndef _PROJECT_DEFS_H
#define _PROJECT_DEFS_H

#include "stdlib.h"

#define PICO_MODULE

#define BT_HOST_MODULE
//#define MATRIX_MODULE

#define LED_STRIP_MODULE

#ifdef MATRIX_MODULE
#define MATRIX_THREAD
#define MATRIX_ANIMATION_MODULE
#endif

#ifdef BT_HOST_MODULE
#define BLE_NIMBLE_OS_PIGGYBACK
#endif

#define POWR_TWO(x) (1 << (x))
#define NUM_SAMPLES_POW 8
#define MIC_SAMPLES POWR_TWO(NUM_SAMPLES_POW)
#define MIC_SAMPLE_RATE 24000

#define INTENSITY_DIVIDER_DEFAULT (2)
#define INTENSITY_DIVIDER_MAX (6)
#define INTENSITY_DIVIDER_MIN (1)

// most microphones will probably default to left channel but you may need to tie the L/R pin low
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT

#define MAX_BLE_TIMEOUT_MS (1000)

#define PANEL_RES_X 64      // Number of pixels wide of each INDIVIDUAL panel module. 
#define PANEL_RES_Y 64     // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1      // Total number of panels chained one to another
 

#ifdef CONFIG_IDF_TARGET_ESP32S3
// either wire your microphone to the same pins or change these to match your wiring
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_35
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_37
#define I2S_MIC_SERIAL_DATA GPIO_NUM_36
#define I2S_MIC_SERIAL_DATA_CS GPIO_NUM_7

#ifndef PIN_NEOPIXEL
#define PIN_NEOPIXEL 39
#endif

#elif CONFIG_IDF_TARGET_ESP32C3
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_15
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_16
#define I2S_MIC_SERIAL_DATA GPIO_NUM_17
#define I2S_MIC_SERIAL_DATA_CS GPIO_NUM_18
#define PIN_NEOPIXEL GPIO_NUM_8


#else
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_35
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_37
#define I2S_MIC_SERIAL_DATA GPIO_NUM_36
#define I2S_MIC_SERIAL_DATA_CS GPIO_NUM_7

#endif
#endif

#define LIGHTS_SOFTWARE_VERSION 3