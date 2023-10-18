#include "../tests/mocks/WidgetMock.hpp"

#include <gtest/gtest.h>

struct WidgetUnitTest : ::testing::Test{
    std::unique_ptr<WidgetMock> widget;

    void SetUp() override {
        widget = std::make_unique<WidgetMock>();
    }
};

TEST_F(WidgetUnitTest, create){
    // given
    // when
    // then
    ASSERT_TRUE(widget);
}

TEST_F(WidgetUnitTest, set_size){
    // given
    const sf::Vector2f expected_size{5, 5};

    // when
    widget->setSize(expected_size);
    auto actual_size = widget->getSize();

    // then
    ASSERT_EQ(expected_size, actual_size);
}

TEST_F(WidgetUnitTest, get_size){
    // given
    const sf::Vector2f expected_size{0, 0};

    // when
    auto actual_size = widget->getSize();

    // then
    ASSERT_EQ(expected_size, actual_size);
}

TEST_F(WidgetUnitTest, set_position){
    // given
    const sf::Vector2f expected_position{5, 5};

    // when
    widget->setPosition(expected_position);
    auto actual_position = widget->getPosition();

    // then
    ASSERT_EQ(expected_position, actual_position);
}


TEST_F(WidgetUnitTest, get_position){
    // given
    const sf::Vector2f expected_position{0, 0};

    // when
    auto actual_position = widget->getPosition();

    // then
    ASSERT_EQ(expected_position, actual_position);
}

TEST_F(WidgetUnitTest, set_origin){
    // given
    const sf::Vector2f expected_origin{5, 5};

    // when
    widget->setOrigin(expected_origin);
    auto actual_origin = widget->getOrigin();

    // then
    ASSERT_EQ(expected_origin, actual_origin);
}

TEST_F(WidgetUnitTest, get_origin){
    // given
    const sf::Vector2f expected_origin{0, 0};

    // when
    auto actual_origin = widget->getOrigin();

    // then
    ASSERT_EQ(expected_origin, actual_origin);
}

TEST_F(WidgetUnitTest, get_type){
    // given
    const std::string expected_type_name{"WidgetMock"};
    const uint64_t expected_first_widget_index{0};
    const uint64_t expected_second_widget_index{1};
    auto second_widget = std::make_unique<WidgetMock>();

    // when
    auto first_type = widget->getType();
    auto second_type = second_widget->getType();

    // then
    ASSERT_EQ(expected_type_name, first_type.getName());
    ASSERT_EQ(expected_first_widget_index, first_type.getIndex());
    ASSERT_EQ(expected_second_widget_index, second_type.getIndex());
}