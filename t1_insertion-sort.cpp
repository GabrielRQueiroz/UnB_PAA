#include <stdio.h>
#include <vector>
#define mx 1000005

using namespace std;

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
  int tests_count, arr_size, arr, add;
  scanf("%d", &tests_count);

  while (tests_count--) {
    scanf("%d", &arr_size);

    vector<int> BIT(mx, 0);

    add = arr_size;
    for (int i = 0; i < arr_size; i++) {
      scanf("%d", &arr);
      update(BIT, arr, 1);
      add += i - query(BIT, arr);
    }

    printf("%d\n", add);
  }

  return 0;
}