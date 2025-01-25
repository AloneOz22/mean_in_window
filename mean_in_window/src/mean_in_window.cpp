#include "mean_in_window.hpp"

template std::vector<float> mean_in_window(const std::vector<float> &data, std::size_t window_size);
template std::vector<double> mean_in_window(const std::vector<double> &data, std::size_t window_size);