#include "../tests/mocks/ContainerMock.hpp"
#include "../tests/mocks/WidgetMock.hpp"

#include <gtest/gtest.h>

struct ContainerUnitTest : ::testing::Test{
    std::unique_ptr<ContainerMock> container;
    void SetUp() override{
        container = std::make_unique<ContainerMock>();
    }
};

TEST_F(ContainerUnitTest, create){
    // given
    // when
    // then
    ASSERT_TRUE(container);
}

TEST_F(ContainerUnitTest, addWidget){
    // given
    auto widget = std::make_unique<WidgetMock>();
    std::size_t expected_container_widgets_size{1};

    // when
    container->add(std::move(widget));

    // then
    ASSERT_EQ(container->getWidgetsSize(), expected_container_widgets_size);
}