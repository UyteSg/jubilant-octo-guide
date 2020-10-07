#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int max(int first, int second) {
  if (first > second) {
    return first;
  }
  else {
    return second;
  }
}

int min(int first, int second) {
  if (first < second) {
    return first;
  }
  else {
    return second;
  }
}

int main() {
  ifstream input("newout.txt");
  int num, prev, _max = 0, _min = 10000, tooth, counter = 0;
  long long time = 0;
  bool crest = true, too = false;
  if (!input.is_open()) {
    cout << "ERROR\n";
  }
  else {
    time++;
    input >> num;
    prev = num;
    while (!input.eof()) {
      input >> num;
      cout << num;
      prev = min(prev, num);
      _max = max(_max, num);
      _min = min(_min, num);
      if (_max > num && !too && crest) {
        _max = 0;
        crest = false;
        counter++;
      }
      if (!too && !crest && _min < num) {
        too = true;
        cout << "-chk ";
      }
      if (_min < num && !too && crest) {
        _min = 10000;
      }
      if (too) {
        too = false;
        crest = true;
      }
      cout << "Max: " << _max << ' ' << "Min: " << _min << '\n';
    }
  }
  cout << counter / time << endl;
  system("pause");
  return 0;
}