#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class DeerInZooDivTwo {
  public:
    vector <int> getminmax(int N, int K) {
      vector<int> res;
      if( N <= K) {
        res.push_back(0);
      } else {
        res.push_back(N-K);
      }
      int max_remain = 0;
      if(K % 2 == 0 ) {
        max_remain = K / 2;
      } else {
        max_remain =  K / 2 + 1;
      }
      max_remain = N - max_remain;
      res.push_back( max_remain);
      return res;
    }
}; // 

bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, vector <int> p2) {
  cout << "Test " << testNum << ": [" << p0 << "," << p1;
  cout << "]" << endl;
  DeerInZooDivTwo *obj;
  vector <int> answer;
  obj = new DeerInZooDivTwo();
  clock_t startTime = clock();
  answer = obj->getminmax(p0, p1);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
      if (i > 0) {
        cout << ",";
      }
      cout << p2[i];
    }
    cout << "}" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "{";
  for (int i = 0; int(answer.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << answer[i];
  }
  cout << "}" << endl;
  if (hasAnswer) {
    if (answer.size() != p2.size()) {
      res = false;
    } else {
      for (int i = 0; int(answer.size()) > i; ++i) {
        if (answer[i] != p2[i]) {
          res = false;
        }
      }
    }
  }
  if (!res) {
    cout << "DOESN'T MATCH!!!!" << endl;
  } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
    cout << "FAIL the timeout" << endl;
    res = false;
  } else if (hasAnswer) {
    cout << "Match :-)" << endl;
  } else {
    cout << "OK, but is it right?" << endl;
  }
  cout << "" << endl;
  return res;
}
int main() {
  bool all_right;
  all_right = true;

  int p0;
  int p1;
  vector <int> p2;

  {
    // ----- test 0 -----
    p0 = 3;
    p1 = 2;
    int t2[] = {1,2};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    p0 = 3;
    p1 = 3;
    int t2[] = {0,1};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    p0 = 10;
    p1 = 0;
    int t2[] = {10,10};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    p0 = 654;
    p1 = 321;
    int t2[] = {333,493};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    p0 = 100;
    p1 = 193;
    int t2[] = {0,3};
    p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
    // ------------------
  }

  if (all_right) {
    cout << "You're a stud (at least on the example cases)!" << endl;
  } else {
    cout << "Some of the test cases had errors." << endl;
  }
  return 0;
}
