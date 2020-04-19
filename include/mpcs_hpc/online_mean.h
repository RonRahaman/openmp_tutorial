#ifndef MPCS_HPC_SPRING_2020_SRC_MPCS_HPC_ONLINE_MEAN_H
#define MPCS_HPC_SPRING_2020_SRC_MPCS_HPC_ONLINE_MEAN_H

typedef struct {
  long count;
  double mean;
  double sum_sq;
} OnlineMean;

OnlineMean online_mean_init();

void online_mean_update(OnlineMean *om, double val);

#endif // MPCS_HPC_SPRING_2020_SRC_MPCS_HPC_ONLINE_MEAN_H
