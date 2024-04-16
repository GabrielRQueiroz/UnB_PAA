#include "iostream"
#include "vector"

using namespace std;

int binary_search(vector<int> &arr, int leftNum, int rightNum, int key) {
  int returnNum = -1;

  while (leftNum <= rightNum) {
    int midNum = (leftNum + rightNum) / 2;

    if (arr[midNum] == key) {
      returnNum = midNum;
      rightNum = midNum - 1;
    } else if (arr[midNum] < key)
      leftNum = midNum + 1;
    else
      rightNum = midNum - 1;
  }

  return returnNum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int arr_size, queries_count, key;
  scanf("%d %d", &arr_size, &queries_count);

  vector<int> arr(arr_size, 0);

  for (int i = 0; i < arr_size; i++)
    scanf("%d", &arr[i]);

  while (queries_count--) {

    scanf("%d", &key);

    printf("%d\n", binary_search(arr, 0, arr_size - 1, key));
  }

  return 0;
}