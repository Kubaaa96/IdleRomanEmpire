#include "../tests/mocks/ContainerMock.hpp"
#include "../tests/mocks/WidgetMock.hpp"

#include <SFML/Graphics.hpp>

#include <gtest/gtest.h>

struct ContainerUnitTest : ::testing::Test {
    std::unique_ptr<ContainerMock> container;
    void SetUp() override {
        container = std::make_unique<ContainerMock>();
    }
};

TEST_F(ContainerUnitTest, create) {
    // given
    // when
    // then
    ASSERT_TRUE(container);
}

TEST_F(ContainerUnitTest, addWidget) {
    // given
    auto widget = std::make_unique<WidgetMock>();
    const std::size_t expected_container_widgets_size{1};

    // when
    container->add(std::move(widget));

    // then
    ASSERT_EQ(container->getWidgetsCount(), expected_container_widgets_size);
}

TEST_F(ContainerUnitTest, drawWidgets) {
    // given
    auto widget = std::make_unique<WidgetMock>();

    // then
    EXPECT_CALL(*widget, draw(::testing::_)).Times(1);
    container->add(std::move(widget));

    // when
    auto mock_render_window = new sf::RenderWindow();
    container->draw(mock_render_window);
    delete mock_render_window;
}