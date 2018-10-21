#include <memory>
#include <iostream>
#include <vulkan/vulkan.h>

int main(int argc, const char * argv[]) {

    // Definition of the Application, sType has to be filled in every VKObject
    VkApplicationInfo appInfo;
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = 0;
    appInfo.pApplicationName = "Spielwiese";
    appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 0);
    appInfo.pEngineName = "THNgine";
    appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_1;

    // Creation of Vulkan instance
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
    vkEnumeratePhysicalDevices(instance, &amountOfPhysicalDevices, NULL);

    VkPhysicalDevice *physicalDevices = new VkPhysicalDevice[amountOfPhysicalDevices];

    vkEnumeratePhysicalDevices(instance, &amountOfPhysicalDevices, physicalDevices);


    uint32_t instance_layer_count;

    result = vkEnumerateInstanceLayerProperties(&instance_layer_count, nullptr);
    std::cout << instance_layer_count << " layers found!\n";
    if (instance_layer_count > 0) {
        std::unique_ptr<VkLayerProperties[]> instance_layers(new VkLayerProperties[instance_layer_count]);
        result = vkEnumerateInstanceLayerProperties(&instance_layer_count, instance_layers.get());
        for (int i = 0; i < instance_layer_count; ++i) {
            std::cout << instance_layers[i].layerName << "\n";
        }
    }

    result = vkCreateInstance(&instanceInfo, NULL, &instance);
    std::cout << "vkCreateInstance result: " << result  << "\n";

    vkDestroyInstance(instance, nullptr);
    return 0;
}
