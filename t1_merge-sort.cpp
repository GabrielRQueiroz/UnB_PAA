#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int leftNum, int midNum, int rightNum) {
  int subArr1 = midNum - leftNum + 1;
  int subArr2 = rightNum - midNum;

  vector<int> LeftArr(subArr1), RightArr(subArr2);

  for (int i = 0; i < subArr1; i++)
    LeftArr[i] = arr[leftNum + i];
  for (int i = 0; i < subArr2; i++)
    RightArr[i] = arr[midNum + 1 + i];

  int subArr1Index = 0;
  int subArr2Index = 0;
  int mergedIndex = leftNum;

  while (subArr1Index < subArr1 && subArr2Index < subArr2) {

    if (LeftArr[subArr1Index] <= RightArr[subArr2Index])
      arr[mergedIndex++] = LeftArr[subArr1Index++];

    else
      arr[mergedIndex++] = RightArr[subArr2Index++];
  }

  while (subArr1Index < subArr1)
    arr[mergedIndex++] = LeftArr[subArr1Index++];

  while (subArr2Index < subArr2)
    arr[mergedIndex++] = RightArr[subArr2Index++];
}

void merge_sort(vector<int> &arr, int leftNum, int rightNum) {
  if (leftNum < rightNum) {
    int midNum = leftNum + (rightNum - leftNum) / 2;

    merge_sort(arr, leftNum, midNum);
    merge_sort(arr, midNum + 1, rightNum);

    merge(arr, leftNum, midNum, rightNum);
  }
}

int main() {
  // INPUT LOGIC 👇
  vector<int> arr;
  int n;
  string input;
  getline(cin, input);

  while (input.size() > 0) {
    if (input.find(" ") == string::npos) {
      n = stoi(input);
      arr.push_back(n);
      break;
    } else {
      n = stoi(input.substr(0, input.find(" ")));
      arr.push_back(n);
      input = input.substr(input.find(" ") + 1);
    }
  }

  // ALGORITHM CALL 👇

  merge_sort(arr, 0, arr.size() - 1);

  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}