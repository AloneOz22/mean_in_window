#include <vector>

#include "gtest/gtest.h"

#include <mean_in_window.hpp>

TEST(
    mean_in_window_verification,
    should_return_correct_result
) {

    const std::size_t window_size = 3;
    const std::vector<float> data {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const std::vector<float> result = mean_in_window<float>(data, window_size);
    const std::vector<float> expected = {1, 2, 3, 4, 5, 6, 7, 8};
    for (std::size_t i = 0; i < result.size(); i++) {
        EXPECT_FLOAT_EQ(result[i], expected[i]);
    }
}
