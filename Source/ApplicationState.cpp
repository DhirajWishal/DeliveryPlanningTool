// Copyright (c) 2021 Dhiraj Wishal
// Copyright (c) 2021 Scopic Software

#include "ApplicationState.h"

ApplicationState::ApplicationState()
{
	mLocations.push_back(Location("Top Beauty Inc.", "370 Alden Rd, Markham, ON L3R 4C1, Canada"));
	mLocations.push_back(Location("Hair Granted Beauty Supply Inc.", "200 Queens Plate Dr, Etobicoke, ON M9W 6V1, Canada"));
	mLocations.push_back(Location("MAC Cosmetics", "368 Queen St W, Toronto, ON M5V 2A2, Canada"));
	mLocations.push_back(Location("Aesop", "880 Queen St W, Toronto, ON M6J 1G3, Canada"));
	mLocations.push_back(Location("LUSH", "312 Queen St W, Toronto, ON M5V 2A2, Canada"));
	mLocations.push_back(Location("The Detox Market", "116 Spadina Ave., Toronto, ON M5V 2K6, Canada"));
	mLocations.push_back(Location("Ellemoor Cosmetics", "803 Bloor St W, Toronto, ON M6G 1L8, Canada"));
	mLocations.push_back(Location("The Body Shop", "2366 Bloor St W, Toronto, ON M6S 1P3, Canada"));
}

const Truck ApplicationState::FindTruck(int ID) const
{
	for (const auto truck : mTrucks)
		if (truck.GetID() == ID)
			return truck;

	return Truck();
}

const Location ApplicationState::FindLocation(const std::string& location) const
{
	for (const auto element : mLocations)
		if (element.GetName() == location)
			return element;

	return Location();
}

const bool ApplicationState::IsLocationPresent(const Location& location) const
{
	for (const auto element : mLocations)
		if (element == location)
			return true;

	return false;
}

const Item ApplicationState::FindItem(const std::string& itemName) const
{
	for (const auto item : mItems)
		if (item.GetName() == itemName)
			return item;

	return Item();
}

const Route ApplicationState::FindRoute(int number) const
{
	for (const auto route : mRoutes)
		if (route.GetNumber() == number)
			return route;

	return Route();
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
