#ifndef __ENGINE__
#define __ENGINE__

#define ENGINE_VERSION_MAJOR @ENGINE_VERSION_MAJOR@
#define ENGINE_VERSION_MINOR @ENGINE_VERSION_MINOR@

#define engine_resource_path(__path) ("@ENGINE_RESOURCES_DIR@/" __path)

#ifdef __cplusplus
#	include <algorithm>
#	include <array>
#	include <atomic>
#	include <bitset>
#	include <cassert>
#	include <ccomplex>
#	include <cctype>
#	include <cerrno>
#	include <cfenv>
#	include <cfloat>
#	include <chrono>
#	include <cinttypes>
#	include <ciso646>
#	include <climits>
#	include <clocale>
#	include <cmath>
#	include <complex>
#	include <complex.h>
#	include <condition_variable>
#	include <csetjmp>
#	include <csignal>
#	include <cstdarg>
#	include <cstdbool>
#	include <cstddef>
#	include <cstdint>
#	include <cstdio>
#	include <cstdlib>
#	include <cstring>
#	include <ctgmath>
#	include <ctime>
#	include <cwchar>
#	include <cwctype>
#	include <cxxabi.h>
#	include <deque>
#	include <exception>
#	include <fenv.h>
#	include <forward_list>
#	include <fstream>
#	include <functional>
#	include <future>
#	include <initializer_list>
#	include <iomanip>
#	include <ios>
#	include <iosfwd>
#	include <iostream>
#	include <istream>
#	include <iterator>
#	include <limits>
#	include <list>
#	include <locale>
#	include <map>
#	include <memory>
#	include <mutex>
#	include <new>
#	include <numeric>
#	include <ostream>
#	include <queue>
#	include <random>
#	include <ratio>
#	include <regex>
#	include <scoped_allocator>
#	include <set>
#	include <sstream>
#	include <stack>
#	include <stdexcept>
#	include <streambuf>
#	include <string>
#	include <system_error>
#	include <tgmath.h>
#	include <thread>
#	include <tuple>
#	include <typeindex>
#	include <typeinfo>
#	include <type_traits>
#	include <unordered_map>
#	include <unordered_set>
#	include <utility>
#	include <valarray>
#	include <vector>
#endif

#include <GL/glew.h>
#include <SDL.h>

#ifdef __cplusplus
#	include <glm/glm.hpp>
#	include <glm/gtc/matrix_access.hpp>
#	include <glm/gtc/matrix_integer.hpp>
#	include <glm/gtc/matrix_inverse.hpp>
#	include <glm/gtc/matrix_transform.hpp>
#	include <glm/gtc/noise.hpp>
#	include <glm/gtc/quaternion.hpp>
#	include <glm/gtc/random.hpp>
#	include <glm/gtc/type_precision.hpp>
#	include <glm/gtc/type_ptr.hpp>
#endif

#endif /* ( __ENGINE__) */
