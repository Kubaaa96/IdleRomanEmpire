#include <catch2/catch.hpp>

#include "core/gui/widgets/Container.h"
#include "core/gui/widgets/Button.h"
#include "core/gui/widgets/VerticalLayout.h"

TEST_CASE("[Container]")
{
	std::unique_ptr<ire::core::gui::Container> container =
		ire::core::gui::VerticalLayout::create({ 100, 100 });

	auto widget1 = ire::core::gui::Button::create();
	auto widget2 = ire::core::gui::Button::create();
	auto widget3 = ire::core::gui::Button::create();

	container->add(std::move(widget1), "Widget1");
	container->add(std::move(widget2), "Widget2");
	container->add(std::move(widget3), "Widget3");

	SECTION("Add")
	{
		container->removeAllWidgets();

		auto w1 = ire::core::gui::Button::create();
		auto w2 = ire::core::gui::Button::create();
		auto w3 = ire::core::gui::Button::create();

		REQUIRE(container->getWidgets().empty());

		container->add(std::move(w1), "w1");
		container->add(std::move(w2), "w2");
		container->add(std::move(w3), "w3");

		REQUIRE(container->getWidgets().size() == 3);
		REQUIRE(container->getWidgets()[0]->getWidgetName() == "w1");
		REQUIRE(container->getWidgets()[1]->getWidgetName() == "w2");
		REQUIRE(container->getWidgets()[2]->getWidgetName() == "w3");
	}

	SECTION("Remove")
	{
		SECTION("Remove one widget")
		{
			REQUIRE(container->getWidgets().size() == 3);

			REQUIRE(container->remove("Widget2"));
			REQUIRE(container->getWidgets().size() == 2);

			REQUIRE(container->getWidgets()[1]->getWidgetName() == "Widget3");

			REQUIRE(container->remove("Widget1"));
			REQUIRE(!container->remove("Widget5"));

			REQUIRE(container->remove("Widget3"));

			REQUIRE(container->getWidgets().empty());
		}
		SECTION("Remove All Widgets")
		{
			REQUIRE(container->getWidgets().size() == 3);
			container->removeAllWidgets();
			REQUIRE(container->getWidgets().empty());
		}
	}
	SECTION("Widget Name")
	{
		REQUIRE(container->getWidgets().size() == 3);
		container->getWidgets()[0]->setWidgetName("Widget11");
		REQUIRE(container->getWidgets()[0]->getWidgetName() == "Widget11");
	}
}
