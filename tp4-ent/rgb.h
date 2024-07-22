#ifndef RGB_H_
#define RGB_H_

#include <stdint.h>

void RGB_init();
void RGB_setColor(uint8_t red, uint8_t green, uint8_t blue);
void RGB_setRed();
void RGB_setGreen();
void RGB_setBlue();
void RGB_setSingleColor(char color, uint8_t duty);

#endif /* RGB_H_ */