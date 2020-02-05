
#ifndef KALMAN_FILTER_H_
#define KALMAN_FILTER_H_

#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class KalmanFilter
{
    public:
      // Constructor
      KalmanFilter();

      // Destructor. A virtual function is a member function that you expect to be redefined in derived classes
      virtual ~KalmanFilter();

      // Predicts the state and the state covariance using the model
      void Predict();

      // Update the state and @param z The measurement at k + 1
      void Update(const VectorXd &z);

      VectorXd x_;        // State vector
      MatrixXd P_;        // State covariance matrix
      MatrixXd F_;        // State transition matrix
      MatrixXd Q_;        // Process covariance matrix
      MatrixXd H_;        // Measurement matrix
      MatrixXd R_;        // Measurement covariance matrix
      
};

#endif // KALMAN_FILTER_H_
