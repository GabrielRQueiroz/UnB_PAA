#include "iostream"
#include "string"
#include "vector"

using namespace std;

int binary_search(vector<int> &arr, int leftNum, int rightNum, int key) {
  while (leftNum <= rightNum) {
    int midNum = leftNum + (rightNum - leftNum) / 2;

    if (arr[midNum] == key)
      return midNum;

    if (arr[midNum] < key)
      leftNum = midNum + 1;

    else
      rightNum = midNum - 1;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> results_arr;

  // INPUT LOGIC 👇
  vector<int> arr;
  int n;

  string input1;
  getline(cin, input1);

  int arrSize;
  int queriesCount;

  arrSize = stoi(input1.substr(0, input1.find(" ")));
  queriesCount = stoi(input1.substr(input1.find(" ") + 1));

  string input2;
  getline(cin, input2);

  while (input2.size() > 0) {
    if (input2.find(" ") == string::npos) {
      n = stoi(input2);
      arr.push_back(n);
      break;
    } else {
      n = stoi(input2.substr(0, input2.find(" ")));
      arr.push_back(n);
      input2 = input2.substr(input2.find(" ") + 1);
    }
  }

  for (int i = 1; i <= queriesCount; i++) {
    int key;
    scanf("%d", &key);

    results_arr.push_back(binary_search(arr, 0, arr.size() - 1, key));
  }

  for (int i = 0; i < results_arr.size(); i++) {
    printf("%d\n", results_arr[i]);
  }

  return 0;
}