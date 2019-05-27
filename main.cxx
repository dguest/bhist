#include <iostream>
#include <boost/histogram.hpp>
int main(int narg, char* argv[]) {
  using namespace boost::histogram;
  using axis_t = axis::regular<>;
  using hist_t = decltype(make_histogram(std::declval<axis_t>()));
  std::vector<hist_t> hists;
  for (int bins: {3, 5, 30, 300}) {
    hists.push_back(make_histogram(axis_t(bins, 0, 1)));
  }
  for (float v: {0.1, 0.2, 0.1, -1.0, 3.0}) {
    for (auto& h: hists) h(v);
  }
  for (auto& h: hists) {
    for (const auto& b: h) std::cout << b << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
