#include <cstdio>
#include <cstdlib>
#include <string>
#include <string_view>
#include <type_traits>

namespace {

	constexpr std::string_view kAlphabet = "0123456789"
										  "abcdefghijklmnopqrstuvwxyz"
										  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	constexpr int kAlphabetSize = kAlphabet.size();

	template<typename T>
	std::string base62(T t) {
		static_assert(std::is_integral_v<T> && std::is_signed_v<T>);
		std::string result;
		while (t > 0) {
			auto [quot, rem] = std::div(t, static_cast<T>(kAlphabetSize));
			result.push_back(kAlphabet[rem]);
			t = quot;
		}
		return result;
	}
}

int main() {

	int64_t value;
	while (std::scanf("%ld", &value) == 1) {
		std::puts(base62(value).c_str());
	}
}


