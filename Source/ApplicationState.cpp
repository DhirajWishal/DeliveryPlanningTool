#include "ApplicationState.h"

const Truck ApplicationState::FindTruck(int ID) const
{
	for (const auto truck : mTrucks)
		if (truck.GetID() == ID)
			return truck;

	return Truck();
}

const Item ApplicationState::FindItem(const std::string& itemName) const
{
	for (const auto item : mItems)
		if (item.GetName() == itemName)
			return item;

	return Item();
}

void ApplicationState::RemoveRoute(int number)
{
	for (auto itr = mRoutes.begin(); itr != mRoutes.end(); ++itr)
	{
		if (itr->GetNumber() == number)
		{
			mRoutes.erase(itr);
			return;
		}
	}
}

const bool ApplicationState::IsRoutePresent(int number) const
{
	for (const auto route : mRoutes)
		if (route.GetNumber() == number)
			return true;

	return false;
}
