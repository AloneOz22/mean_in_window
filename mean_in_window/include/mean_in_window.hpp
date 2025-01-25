#pragma once

#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

template <class T>
std::vector<T> mean_in_window(const std::vector<T> &data, std::size_t window_size){
    
    if (window_size == 0)
        throw std::invalid_argument("Window should be non-zero");
    if (window_size > data.size())
		throw std::invalid_argument("Window should not be larger than data size");

	if (window_size == 1)
        return data;
	if (window_size == data.size())
		return {std::accumulate(data.begin(), data.end(), static_cast<T>(0.)) / static_cast<T>(window_size)};
	
    std::vector<T> mean_data(data.size() - window_size + 1);
	auto left = data.begin();
	auto right = std::next(data.begin(), window_size);
	T sum = std::accumulate(data.begin(), std::next(data.begin(), window_size), 0.);

	std::for_each(mean_data.begin(), mean_data.end(), [&](T& mean){
		mean = sum / static_cast<T>(window_size);
		sum += *right - *left;
		left += 1;
		right += 1;
	});
	
	return mean_data;
}
