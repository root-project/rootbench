#include <TInterpreter.h>

#include <rootbench/Support/MemoryManager.h>

#include <benchmark/benchmark.h>


static void BM_LookupHelper_Leak(benchmark::State &state) {
   gInterpreter->Declare(R"CODE(
#ifndef BM_LookupHelper_Leak_Guard
#define BM_LookupHelper_Leak_Guard
     template <class T, class U> class __gmp_expr;
     typedef struct{ } __mpz_struct;
     typedef __gmp_expr<__mpz_struct[1],__mpz_struct[1]> mpz_class;
#endif // BM_LookupHelper_Leak_Guard
   )CODE");

   for (auto _ : state)
      gInterpreter->ClassInfo_IsEnum("std::vector<mpz_class>::value_type");
}


BENCHMARK(BM_LookupHelper_Leak);
BENCHMARK_MAIN();
