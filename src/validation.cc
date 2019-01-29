#include "validation.hh"
#include "fft.hh"
#include <array>
#include <gsl/span>
#include <fftw3.h>
#include <iostream>
#include <numeric>

Errors validate_fft(
        shape_t const &shape,
        unsigned block,
        complex_span<float> input,
        complex_span<float> output)
{
    size_t s = 1;
    for (auto x : shape) s *= x;
    std::vector<std::complex<float>> ground_truth(s * block);

    fftwf_plan plan = fftwf_plan_many_dft(
        shape.size(), shape.data(), block,
        reinterpret_cast<fftwf_complex *>(input.data()), NULL, 1, s,
        reinterpret_cast<fftwf_complex *>(ground_truth.data()), NULL, 1, s,
        FFTW_FORWARD, FFTW_ESTIMATE);
    fftwf_execute(plan);

    Errors max = {0.0, 0.0};
    for (size_t i = 0; i < s*block; ++i) {
        double abs_err = std::abs(ground_truth[i] - output[i]);
        double rel_err = abs_err / std::abs(ground_truth[i]);
        max.abs = std::max(abs_err, max.abs);
        max.rel = std::max(rel_err, max.rel);
    }
    return max;
}

