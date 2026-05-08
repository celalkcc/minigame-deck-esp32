Here are the most important functions/macros from [FastLED](https://fastled.io?utm_source=chatgpt.com) you’ll use most often with WS2812B / NeoPixel style LEDs on Arduino/ESP32:

```cpp
#include <FastLED.h>
```

---

# Setup

```cpp
#define NUM_LEDS 60
#define DATA_PIN 5

CRGB leds[NUM_LEDS];
```

```cpp
FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
```

Initialize LED strip.

---

# Show LEDs

```cpp
FastLED.show();
```

Actually sends data to LEDs.

---

# Set Brightness

```cpp
FastLED.setBrightness(100);
```

0–255 brightness.

---

# Set Single LED Color

```cpp
leds[0] = CRGB::Red;
```

Or:

```cpp
leds[0] = CRGB(255, 0, 0);
```

RGB format.

---

# Fill Entire Strip

```cpp
fill_solid(leds, NUM_LEDS, CRGB::Blue);
```

---

# HSV Colors

```cpp
leds[0] = CHSV(120, 255, 255);
```

Hue, saturation, brightness.

Super useful for animations.

---

# Rainbow

```cpp
fill_rainbow(leds, NUM_LEDS, startHue, deltaHue);
```

Example:

```cpp
fill_rainbow(leds, NUM_LEDS, 0, 5);
```

---

# Clear LEDs

```cpp
FastLED.clear();
```

Or:

```cpp
fill_solid(leds, NUM_LEDS, CRGB::Black);
```

---

# Delay with Frame Timing

```cpp
FastLED.delay(20);
```

Better than normal `delay()` for LED timing.

---

# Fade LEDs

```cpp
fadeToBlackBy(leds, NUM_LEDS, 20);
```

Creates motion trails.

---

# Random Colors

```cpp
leds[i] = CHSV(random8(), 255, 255);
```

---

# Blend Between Colors

```cpp
blend(color1, color2, amount);
```

Example:

```cpp
CRGB c = blend(CRGB::Red, CRGB::Blue, 128);
```

---

# Sine Wave Animation

```cpp
beatsin8(bpm, min, max);
```

Example:

```cpp
int pos = beatsin8(30, 0, NUM_LEDS - 1);
```

Very important for smooth animations.

---

# EVERY_N_MILLISECONDS

```cpp
EVERY_N_MILLISECONDS(20)
{
    hue++;
}
```

Non-blocking timing helper.

---

# Common Colors

```cpp
CRGB::Red
CRGB::Blue
CRGB::Green
CRGB::White
CRGB::Black
CRGB::Yellow
CRGB::Purple
CRGB::Orange
```

---

# Minimal Example

```cpp
#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 5

CRGB leds[NUM_LEDS];

void setup()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop()
{
    fill_rainbow(leds, NUM_LEDS, millis() / 10, 5);

    FastLED.show();

    FastLED.delay(20);
}
```

Most important concepts to master:

* `CRGB`
* `CHSV`
* `FastLED.show()`
* `fill_rainbow()`
* `fadeToBlackBy()`
* `beatsin8()`
* `EVERY_N_MILLISECONDS`

Those alone already let you build surprisingly advanced effects.
