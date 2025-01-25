#include <memory>
#include <random>
#include <utility>

#include <benchmark/benchmark.h>

#include <mean_in_window.hpp>

static void CustomArguments(benchmark::internal::Benchmark *b) {
    const int min_window = 1;
    const int max_window = 512;
    for (int i = min_window; i <= max_window; i *= 2)
        b->Arg(i);
}

template <typename T>
class mean_in_window_fixture : public ::benchmark::Fixture {
public:
    std::vector<T> input;

    void SetUp(const ::benchmark::State &state) override {
        const std::size_t size = 1048576;
        std::random_device device;
        std::mt19937 engine {device()};
        std::uniform_real_distribution<T> distribution {0, 10};
        auto gen = [&](){ return distribution(engine); };
        input = std::vector<T>(size);
        std::generate(input.begin(), input.end(), gen);
    }
};
using mean_float = mean_in_window_fixture<float>;
using mean_double = mean_in_window_fixture<double>;
BENCHMARK_DEFINE_F(mean_float, run)(benchmark::State &state) {
    while (state.KeepRunning()) {
        mean_in_window<float>(input, state.range(0));
    }
}
BENCHMARK_DEFINE_F(mean_double, run)(benchmark::State &state) {
    while (state.KeepRunning()) {
        mean_in_window<double>(input, state.range(0));
    }
}
BENCHMARK_REGISTER_F(mean_float, run)
    ->ComputeStatistics(
        "min",
        [](const std::vector<double> &v) -> double {
            return *(std::min_element(std::begin(v), std::end(v)));
        }
    )
    ->Unit(benchmark::kSecond)
    ->Apply(CustomArguments)
    ->Iterations(1)
    ->Repetitions(20);
BENCHMARK_REGISTER_F(mean_double, run)
    ->ComputeStatistics(
        "min",
        [](const std::vector<double> &v) -> double {
            return *(std::min_element(std::begin(v), std::end(v)));
        }
    )
    ->Unit(benchmark::kSecond)
    ->Apply(CustomArguments)
    ->Iterations(1)
    ->Repetitions(20);

BENCHMARK_MAIN();
