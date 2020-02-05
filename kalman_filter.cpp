#include "kalman_filter.hpp"


KalmanFilter::KalmanFilter()
{

}


KalmanFilter::~KalmanFilter()
{

}


void KalmanFilter::Predict()
{
    // Based on the equations in the notebook
    x_ = F_ * x_;
    P_ = F_ * P_ * F_.transpose() + Q_;
}


void KalmanFilter::Update(const VectorXd &z)
{
    // Based on the equations for update step in the book
    VectorXd z_pred = H_ * x_;
    VectorXd y = z - z_pred;

    MatrixXd S = H_ * P_ * H_.transpose() + R_;

    // Kalman gain
    MatrixXd K = P_ * H_.transpose() * S.inverse();

    // New estimate
    x_ += (K * y);

    long x_size = x_.size();

    MatrixXd I = MatrixXd::Identity(x_size, x_size);

    P_ = (I - K * H_) * P_;






}
