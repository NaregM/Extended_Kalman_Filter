#include <iostream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>
#include "measurement_package.hpp"
#include "tracking.hpp"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main()
{
    // Set measurements
    vector<MeasurementPackage> measurement_pack_list;

    // Hardcoded input file with laser and radar measurements
    string in_file_name_ = "obj_pose-laser-radar-synthetic-input.txt";
    ifstream in_file(in_file_name_.c_str(), ifstream::in);

    if (!in_file.is_open())
    {
        cout << "Cannot open input file: " << in_file_name_ << endl;
    }

    string line;
    // set i so to get only the first 3 measurements
    int i = 0;
    while (getline(in_file, line) && (i <= 5))
    {
        MeasurementPackage meas_package;

        istringstream iss(line);
        string sensor_type;
        iss >> sensor_type;    // Reads first element from current line

        int64_t timestamp;

        if (sensor_type.compare("L") == 0)
        {
            // Laser measurement; read measurements
            meas_package.sensor_type_ = MeasurementPackage::LASER;
            meas_package.raw_measurements_ = VectorXd(2);

            float x;
            float y;
            iss >> x;
            iss >> y;
            meas_package.raw_measurements_ << x, y;
            iss >> timestamp;
            meas_package.timestamp_ = timestamp;
            measurement_pack_list.push_back(meas_package);

        } else if (sensor_type.compare("R") == 0)
          {
              // Skip Radar measurements
              continue;
          }
         ++i;
    }

    // Create a Tracking instance
    Tracking tracking;

    // Call the ProcessingMeasurement() function for each measurement
    size_t N = measurement_pack_list.size();

    // Start filtering from the second frame (the speed is unkown in the first frame)
    for (size_t k = 0; k < N; ++k)
    {
        tracking.ProcessMeasurement(measurement_pack_list[k]);
    }

    if (in_file.is_open())
    {
        in_file.clear();
    }

return 0;
}
