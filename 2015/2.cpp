#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void parse_dimensions(const std::string &line, int &l, int &w, int &h) {
  sscanf(line.c_str(), "%dx%dx%d", &l, &w, &h);
}

int part1(const std::vector<std::string> &lines) {
  int total_paper = 0;
  int l, w, h;

  for (const auto &line : lines) {
    parse_dimensions(line, l, w, h);
    int lw = l * w;
    int wh = w * h;
    int hl = h * l;
    total_paper += 2 * (lw + wh + hl) + std::min(lw, std::min(wh, hl));
  }
  return total_paper;
}

int part2(const std::vector<std::string> &lines) {
  int total_ribbon = 0;
  int l, w, h;

  for (const auto &line : lines) {
    parse_dimensions(line, l, w, h);
    int perimeters[] = {2 * (l + w), 2 * (w + h), 2 * (h + l)};
    total_ribbon += *std::min_element(perimeters, perimeters + 3) + l * w * h;
  }
  return total_ribbon;
}

int main() {
  std::ifstream input("2.txt");
  if (!input) {
    std::cerr << "Error: Could not open file 2.txt" << std::endl;
    return 1;
  }

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(input, line)) {
    lines.push_back(line);
  }

  std::cout << "Total paper: " << part1(lines) << std::endl;
  std::cout << "Total ribbon: " << part2(lines) << std::endl;

  return 0;
}
