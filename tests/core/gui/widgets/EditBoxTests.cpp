#include <catch2/catch.hpp>
#include "core/gui/widgets/EditBox.h"
#include "TestsUtils.h"

TEST_CASE("[EditBox]")
{
	auto editBox = ire::core::gui::EditBox::create();

	SECTION("WidgetType")
	{
		REQUIRE(editBox->getType().getName() == "EditBox");
	}
	SECTION("Name")
	{
		editBox->setWidgetName("editBox1");
		REQUIRE(editBox->getWidgetName() == "editBox1");
	}
	SECTION("Position and Size")
	{
		editBox->setPosition({ 40, 50 });
		editBox->setSize({ 100, 200 });

		REQUIRE(areAlmostEqual(editBox->getPosition(), sf::Vector2f({ 40, 50 })));
		REQUIRE(areAlmostEqual(editBox->getSize(), sf::Vector2f({ 100, 200 })));
	}
	SECTION("Text")
	{
		editBox->setTextString("Hello World");
		REQUIRE(editBox->getTextString() == "Hello World");
	}
	SECTION("Ghost Text")
	{
		editBox->setGhostTextString("Insert something");
		REQUIRE(editBox->getGhostTextString() == "Insert something");
	}
	SECTION("Caret Position")
	{
		editBox->setTextString("Hello Caret");
		editBox->setCaretPosition(4);
		REQUIRE(editBox->getCaretPosition() ==  4);
	}
}