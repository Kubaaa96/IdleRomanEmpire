#include <Example.hpp>

#include <gtest/gtest.h>
#include <fmt/core.h>

struct ExampleTest : testing::Test {
    Example example;
};

TEST_F(ExampleTest, test) {
    // given
    // when
    auto value = example.getXOfRectangle();

    // then
    const auto expected_value{128.f};
    ASSERT_EQ(value, expected_value);
}
