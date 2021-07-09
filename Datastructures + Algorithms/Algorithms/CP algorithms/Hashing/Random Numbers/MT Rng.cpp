// for generating random numbers efficiently using mt 
// seeded with current time
#include <chrono>
#include <random>
using namespace std;

int main() {

	// random number from 0 to 2^64-1 (be careful about it taking unsigned int / long long!)
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long n = 1e5; // generates random number from 0 to n-1 now
	long long a = rng() % n; // random number a
}