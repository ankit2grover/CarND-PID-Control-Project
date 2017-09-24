#include "PID.h"
#include <math.h>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  // Initialize coefficients and variables.
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
  // Proportional error
  this->p_error = cte;
  // Differential error
  this->d_error = cte - prev_cte;
  // Integration error
  this->i_error += cte;
  this->prev_cte = cte;
}

double PID::sum(vector<double> &dParams) {
  double sum = 0.0;
  for (unsigned int i = 0; i < dParams.size(); i++) {
    sum += dParams[i];
  }
  return sum;
}

double PID::TotalError() {
  double error = pow(this->p_error, 2) + pow(this->d_error, 2) + pow(this->i_error, 2);
  error = sqrt(error);
  return error/3;
}

void PID::twiddle(double tolerance) {
  vector<double> dParams = {1,1,1};
  double best_err = this->TotalError();
  double *coeff = 0;
  while (this->sum(dParams) > tolerance) {
    for (unsigned int i=0; i < dParams.size(); i++) {
      if (i== 0) {
        coeff = &this->Kp;
      } else if (i ==1) {
        coeff = &this->Kd;
      } else if (i ==2) {
        coeff = &this->Ki;
      }
      *coeff += dParams[i];
      this->TotalError();
      
    }
  }

}

