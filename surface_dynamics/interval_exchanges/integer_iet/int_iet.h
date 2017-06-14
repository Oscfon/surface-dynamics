/*****************************************************************************/
/*       int_iet.h                                                           */
/*                                                                           */
/* Interval exchange transformations with integer lengths. The functions     */
/* works for both interval exchanges and linear involutions.                 */
/*                                                                           */
/*       Copyright (C) 2015 Vincent Delecroix <vincent.delecroix@labri.fr>   */
/*                                                                           */
/*  Distributed under the terms of the GNU General Public License (GPL)      */
/*                                                                           */
/*                  http://www.gnu.org/licenses/                             */
/*                                                                           */
/*****************************************************************************/

#include <stdint.h>

typedef struct{
    uint64_t length;
    int      same_interval;  // whether or not the two belong to the same interval
} label;

typedef struct Xinterval{
    struct Xinterval *prev;    // guy on the left
    struct Xinterval *next;    // guy on the right
    struct Xinterval *twin;    // the twin interval
    label * lab;               // the label
} interval;

typedef struct {
    unsigned int nb_labels;  // number of intervals (actually pair of intervals)
    interval * top;          // first interval on top
    interval * bot;          // first interval on bot

    /* internal stuff that should not be needed beyond creation/destruction */
    label * labels;          // the labels
    interval * intervals;    // the intervals (twice the number of labels)
}int_iet;

typedef int_iet int_iet_t[1];

/* memory allocation */
void int_iet_init(int_iet_t t, unsigned int n);
void int_iet_clear(int_iet_t t);

/* safety check */
int  int_iet_check(int_iet_t t);

/* set data */
void int_iet_set_labels_and_twin(int_iet_t t, int * labels, int * twin, int k);
void int_iet_set_lengths(int_iet_t t, uint64_t * lengths);

/* output */
void int_iet_print(int_iet_t t);

/* number of cylinders */
int int_iet_num_cylinders(int_iet_t t);

