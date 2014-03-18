#ifndef MEMORY_H
#define MEMORY_H

#define WIDTH     640
#define HEIGHT    480
#define NUM_PIXELS  (WIDTH*HEIGHT)
#define IMAGE_SIZE  (NUM_PIXELS*3)

struct image {
  unsigned int   width;
  unsigned int   height;
  unsigned int   bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char  pixel_data[640 * 480 * 3 + 1];
}; 

void read_filtered_line(unsigned char *result);
void reset_address();

#endif // MEMORY_H