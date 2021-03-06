#include "HorizontalLayout.h"

namespace ire::core::gui
{
	WidgetType const HorizontalLayout::m_type = WidgetType::create<HorizontalLayout>("HorizontalLayout");

	HorizontalLayout::HorizontalLayout(const sf::Vector2f& size)
		: BoxLayout{size}
	{
		//updateWidgets();
	}
	std::unique_ptr<HorizontalLayout> HorizontalLayout::create(const sf::Vector2f& size)
	{
		return std::make_unique<HorizontalLayout>(size);
	}
	void HorizontalLayout::updateWidgets()
	{
		// # Calculate size of widget
		const auto sizeOfVector = m_widgets.size();
		float widthPerOneWidget{ 0 };
		float width{ 0 };
		float totalWidthOfSpaces = m_spaces * (sizeOfVector - 1);
		bool isStretchValid = isLayoutStretchValid();
		if (!isStretchValid)
		{
			widthPerOneWidget = m_size.x / sizeOfVector;
			width = widthPerOneWidget - (m_margins.m_left + m_margins.m_right + totalWidthOfSpaces) / sizeOfVector;
		}
		const auto height = m_size.y - m_margins.m_top - m_margins.m_bottom;

		auto position = getPosition();
		float previousPosition{ 0 };
		float previousWidth{ 0 };
		// # Calculate position of widget
		for (std::size_t i = 0; i < sizeOfVector; ++i)
		{
			float positionOfNextWidgetX{ 0 };
			if (isStretchValid)
			{
				float proportion = m_layoutStretch[i] / m_sumOfLayoutStretches;
				widthPerOneWidget = proportion * m_size.x;
				width = widthPerOneWidget - (m_margins.m_left + m_margins.m_right + totalWidthOfSpaces) / sizeOfVector;
				if (i == 0)
				{
					positionOfNextWidgetX = m_margins.m_left;
					previousPosition = positionOfNextWidgetX;
				}
				else
				{
					positionOfNextWidgetX = previousPosition + previousWidth + m_spaces;
					previousPosition = positionOfNextWidgetX;
				}
				previousWidth = width;
			}
			else
			{
				positionOfNextWidgetX = m_margins.m_left + (width * i) + (m_spaces * i);
			}

			const auto positionOfNextWidgetY = m_margins.m_top;
			m_widgets[i].get()->setOrigin(position);
			m_widgets[i].get()->setLocalPosition(sf::Vector2f{positionOfNextWidgetX, positionOfNextWidgetY});
			m_widgets[i].get()->setSize({ width, height });
		}
	}
}