#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "TimedSharedPtr.h"
#include <thread>

TEST_CASE("Empty pointer behaves correctly") {
    TimedSharedPtr<int> p;
    CHECK(p.get() == nullptr);
    CHECK(p.use_count() == 0);
    CHECK(p.expired());
}

TEST_CASE("Basic usage and expiration") {
    TimedSharedPtr<int> p(new int(99), 100);
    CHECK(p.get() != nullptr);
    CHECK(p.use_count() == 1);

    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    CHECK(p.get() == nullptr);
    CHECK(p.expired());
}

TEST_CASE("Copy increases use count") {
    TimedSharedPtr<int> p(new int(10), 200);
    TimedSharedPtr<int> q = p;

    CHECK(p.use_count() == 2);
    CHECK(q.use_count() == 2);
    CHECK(p.get() == q.get());
}

int main(int argc, char** argv) {
    doctest::Context ctx;
    ctx.applyCommandLine(argc, argv);
    return ctx.run();
}