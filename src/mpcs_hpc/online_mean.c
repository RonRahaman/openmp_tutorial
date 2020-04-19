#include "mpcs_hpc/online_mean.h"
#include <math.h>

OnlineMean online_mean_init() {
  OnlineMean om = {0, 0.0, 0.0};
  return om;
}

void online_mean_update(OnlineMean *om, double val) {
  // From https://jonisalonen.com/2013/deriving-welfords-method-for-computing-variance/
  // The one on Wikipedia seems wrong??
  om->count += 1;
  double old_mean = om->mean;
  om->mean += (val - om->mean) / om->count;
  om->sum_sq  += (val - om->mean) * (val - old_mean);
}

