#ifndef POINT_H
#define POINT_H

#define WIDTH 640
#define HEIGHT  480
#define NUM_PIXELS  (WIDTH*HEIGHT)

#define XVAL(idx) (idx%WIDTH)
#define YVAL(idx) (idx/WIDTH)

#define THRESHOLD 10  // threshold for point test
#define MIN_SIZE  3
#define MAX_SIZE  (30*30)
#define MIN_SKEW  -5
#define MAX_SKEW  5

#define COL_THRESHOLD 20  // threshold for being in the same column
#define ROW_THRESHOLD 20

struct Point {
  int min[2];
  int max[2];
  int size;
  int center[2];
};

void init_point(struct Point *p);
void add_line(struct Point *p, int left, int right); // adds a line of pixels to POINT
void add_point(struct Point *p, int index);
int* get_center(struct Point *p); // calculates center and returns pointer to center
int test_point(struct Point *p, int index); // x-failure: 0, y-falure: -1, new point and success = 1
int test_shape(struct Point *p); // 

/** point finder
takes the working green array, finds center points

returns number of center points
*/
int point_finder(int (*center_points)[2], int length);

/* sorts array of order pairs and sorts them by column
 * @param center_points     array of center points
 * @param num_points      number of center points
 * @param col_idx         array of colom index points (output)
 * @param col_idx_size      size of col_idx array
 * @returns number of columns         
*/
int sort_by_col(int (*center_points)[2], int num_points, int* col_idx, int col_idx_size);

/**
 * assumes points are already sorted in rows (that's how their read)
 */
int sort_by_row(int (*center_points)[2], const int num_points, int* row_idx, int row_idx_size);

#endif //POINT_H