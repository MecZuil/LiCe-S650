#ifndef MYCSTDLIB_H
#define MYCSTDLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double myexp(double x);
int _itoa_(int d, char *str);
int _ftoa_(float f, char *str, int n);
void mk_time_str(char *timestr, struct tm *p_time);

#endif // MYCSTDLIB_H
