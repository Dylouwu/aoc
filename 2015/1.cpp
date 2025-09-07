#include <iostream>

int part1(FILE *file) {
  int floor{0};
  char c;
  while ((c = char(fgetc(file))) != EOF) {
    if (c == '(') {
      floor++;
    } else if (c == ')') {
      floor--;
    }
  }
  return floor;
}

int part2(FILE *file) {
  int floor{0};
  char c;
  int position{0};
  while ((c = char(fgetc(file))) != EOF) {
    position++;
    if (c == '(') {
      floor++;
    } else if (c == ')') {
      floor--;
    }
    if (floor == -1) {
      return position;
    }
  }
  // Theoretically impossible
  return position;
}

int main() {
  FILE *file = fopen("1.txt", "r");
  std::cout << "Final floor: " << part1(file) << std::endl;
  fseek(file, 0, SEEK_SET);
  std::cout << "Position of first entry to basement: " << part2(file)
            << std::endl;
  fclose(file);
  return 0;
}
