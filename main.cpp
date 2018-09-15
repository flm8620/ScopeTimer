#include <vector>
#include <iostream>
#include "scope_timer.h"
int main() {
    {
        ScopeTimer t0("outer timer", true, false);
        std::vector<std::vector<int>> v;
        const int N = 10000000;
        {
            ScopeTimer t1("inner timer 1");
            
            for(int i=0;i<N;i++) {
                v.push_back({1,2,3,4});
            }
        }

        {
            ScopeTimer t1("inner timer 2");
            v.clear();
        }

        {
            ScopeTimer t2("inner timer 3");
            for(int i=0;i<N;i++) {
                v.push_back({1,2,3,4});
            }
        }
    }
    return 0;
}