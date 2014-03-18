#include "memory.h"

extern struct image no_dots_image;
extern struct image dots_image;

int location = 0;

// result = dots - no_dots
void read_filtered_line(unsigned char *result) {
  int i;
  for(i = 0; i < WIDTH*3; i+=3) {
    int l = i+location;
    if(no_dots_image.pixel_data[l] > dots_image.pixel_data[l]) {
      *result = 0;
    } else {
      *(result) = dots_image.pixel_data[l] - no_dots_image.pixel_data[l];
    }
    result++;
  }
  location += WIDTH*3;
}

void reset_address() {
  location = 0;
}