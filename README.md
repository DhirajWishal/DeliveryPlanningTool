# Delivery Planning Tool
This tool is developed by the specifications specified in the Scopic Desktop Test Task - Part 1 and 2.

## How to build
This project is based on the Qt framework and uses the qmake build system. Additionally the `.sln` and `.pro` files are provided for easy setup in Visual Studio or Qt Creator.

### Prerequisite
To build and run the application, you need the following tools and frameworks.
1. [Qt](https://www.qt.io/) SDK.
2. [Visual Studio](https://visualstudio.microsoft.com/) or [Qt Creator](https://www.qt.io/product/development-tools).
3. [Qt Visual Studio Tools](https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools2019) if using Visual Studio.

### Steps
First things first, clone this repository to a local directory either using the command shell or [GitHub Desktop](https://desktop.github.com/).
```shell
# If using the command shell.
> git clone https://github.com/DhirajWishal/DeliveryPlanningTool {Directory}
> cd {Directory}
```

After cloning the repository, you can directly open the `.pro` file in Qt Creator. If your using Visual Studio, you may follow the following steps.
1. Open Visual Studio (continue without code).
2. Extensions -> Qt VS Tools -> Open Qt Project File (.pro)...

This will generate the required `.sln` files and `.vcxproj` files needed for Visual Studio. After this, navigate to the `{Directory}` and open up the project in Visual Studio. After successfully opening it, you can select the required configuration (`Debug` or `Release`) and Build and Run.

## License
This repository is licensed under MIT.