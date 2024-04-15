#include <iostream>
#include <vector>

using namespace std;

// class BITree {
//   vector<int> BIT;
//   int n;
//
// public:
//   BITree(int n) {
//     this->n = n;
//     BIT.resize(n + 1, 0);
//   }
//
//   void update(int index, int val) {
//     index++;
//     while (index <= n) {
//       BIT[index] += val;
//       index += index & (-index);
//     }
//   }
//
//   int query(int index) {
//     index++;
//     int sum = 0;
//     while (index > 0) {
//       sum += BIT[index];
//       index -= index & (-index);
//     }
//     return sum;
//   }
// };

// SEGMENTATION FAIL. MAKE EQUIVALENT VIA FUNCTIONS

void update(vector<int> &tree, int index, int val) {
  index++;
  while (index <= tree.size()) {
    tree[index] += val;
    index += index & (-index);
  }
}

int query(vector<int> &tree, int index) {
  index++;
  int sum = 0;
  while (index > 0) {
    sum += tree[index];
    index -= index & (-index);
  }
  return sum;
}

int main() {
  vector<int> res;
  int tests_count, arr_size, arr, add;
  cin >> tests_count;
  while (tests_count--) {
    vector<int> BIT[1000001];
    cin >> arr_size;

    BIT.resize(arr_size + 1, 0);

    add = arr_size;
    for (int i = 0; i < arr_size; i++) {
      cin >> arr;
      update(BIT, arr, 1);
      add += i - query(BIT, arr);
    }
    res.push_back(add);
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "\n";
  }

  return 0;
}