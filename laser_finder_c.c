// laser_finder.c - finds the location of laser points comparing two images
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

#define POINT_BUFFER_LENGTH   200
#define MAX_COLUMNS           30
#define MAX_ROWS              30

int main(void)
{
  int num_points = 0;
  int num_columns = 0;
  int num_rows = 0;
  int row_idx[MAX_ROWS];
  int col_idx[MAX_COLUMNS];
  int center_points[POINT_BUFFER_LENGTH][2];

  num_points = point_finder(center_points, POINT_BUFFER_LENGTH);

  printf("Points Found: %d, Rows Found: %d, Columns Found: %d\n", num_points, num_rows, num_columns);

  num_rows = sort_by_row(center_points, num_points, row_idx, MAX_ROWS);
  
  for(int i=0,j=0; i<num_points; i++)
  {
    if(i == row_idx[j])
      printf("Row %d:\n", j++);
    
    printf("(%d,%d)\n", center_points[i][0], center_points[i][1]);
  }
  
  num_columns = sort_by_col(center_points, num_points, col_idx, MAX_COLUMNS);

  printf("Points Found: %d, Rows Found: %d, Columns Found: %d\n", num_points, num_rows, num_columns);

  /*
  for(int i=0,j=0; i<num_points; i++)
  {
    if(i == col_idx[j])
      printf("Column %d:\n", j++);
    
    printf("(%d,%d)\n", center_points[i][0], center_points[i][1]);
  }
  */

  return 0;
}