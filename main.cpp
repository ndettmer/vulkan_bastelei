#include <memory>
#include <iostream>
#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Window.hpp"

void printStats(VkPhysicalDevice &device) {
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(device, &properties);

    std::cout << "Name: " << properties.deviceName << "\n";
    uint32_t apiVer = properties.apiVersion;
    std::cout << "API Version: " << VK_VERSION_MAJOR(apiVer) << "." << VK_VERSION_MINOR(apiVer) << "." << VK_VERSION_PATCH(apiVer) << "\n";
    std::cout << "Vendor ID: " << properties.vendorID << "\n";
    std::cout << "Device ID: " << properties.deviceID << "\n";
    std::cout << "Device Type: " << properties.deviceType << "\n";
}

/*int main(int argc, const char * argv[]) {

    Window app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;


    // Vulkan
    // ------------------------- //
    // Definition of the Application, sType has to be filled in every VKObject
    VkApplicationInfo appInfo;
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = 0;
    appInfo.pApplicationName = "Spielwiese";
    appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 0);
    appInfo.pEngineName = "THNgine";
    appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_1;

    // Creation of Vulkan instance info
    VkInstanceCreateInfo instanceInfo;
    instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceInfo.pNext = NULL;
    instanceInfo.flags = 0;
    instanceInfo.pApplicationInfo = &appInfo;
    instanceInfo.enabledLayerCount = 0;
    instanceInfo.ppEnabledLayerNames = NULL;
    instanceInfo.enabledExtensionCount = 0;
    instanceInfo.ppEnabledExtensionNames = NULL;

    // Create instance, without it you can't access the GPU
    VkInstance instance;

    // Check if everything is fine with our instance creation
    VkResult result = vkCreateInstance(&instanceInfo, NULL, & instance);

    if (result != VK_SUCCESS) {
        std::cout << "Fuck";
    }

    // Check the amount of Physical Devices
    uint32_t amountOfPhysicalDevices = 0;
    result = vkEnumeratePhysicalDevices(instance, &amountOfPhysicalDevices, NULL);

    if (result != VK_SUCCESS) {
        std::cout << "Can't get Number of GPU(s)";
    }

    // Create some physicalDevices
    VkPhysicalDevice *physicalDevices = new VkPhysicalDevice[amountOfPhysicalDevices];
    result = vkEnumeratePhysicalDevices(instance, &amountOfPhysicalDevices, physicalDevices);

    if (result != VK_SUCCESS) {
        std::cout << "Error again";
    }

    std::cout << "I have " << amountOfPhysicalDevices << " GPU(s)\n";

    for (int i = 0; i < amountOfPhysicalDevices; i++) {
        printStats(physicalDevices[i]);
    }

    vkDestroyInstance(instance, nullptr);

//    SDLWindow;
    return 0;
}*/
