#include "GLFW/glfw3.h"
#include <iostream>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"




int main() {
    // Initialize GLFW
    glfwInit();

    // Set the GLFW window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create the GLFW window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Audio Circle", nullptr, nullptr);

    // Check if the window was successfully created
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Create a menu bar
    ImGui::BeginMainMenuBar();

    // Add menu items
    if (ImGui::BeginMenu("File"))
    {
        ImGui::MenuItem("Open", "Ctrl+O");
        ImGui::MenuItem("Save Playlist", "Ctrl+S");
        ImGui::MenuItem("Prefrences", "Ctrl+P");
        ImGui::MenuItem("Exit", "Alt+F4");
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Edit"))
    {
        ImGui::MenuItem("Track List", "Ctrl+T");
        ImGui::MenuItem("Show Track List", "Ctrl+Y");
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Audio"))
    {
        ImGui::MenuItem("Track List", "Ctrl+T");
        ImGui::MenuItem("Show Track List", "Ctrl+Y");
        ImGui::MenuItem("Choose Audio Device","Ctrl+A");
    }

    if (ImGui::BeginMenu("Audio"))
    {
        ImGui::MenuItem("Track List", "Ctrl+T");
        ImGui::MenuItem("Show Track List", "Ctrl+Y");
        ImGui::MenuItem("Choose Audio Device", "Ctrl+A");
        ImGui::EndMenu();
    }


    // End the menu bar
    ImGui::EndMainMenuBar();


    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Update the window
        glfwPollEvents();

        // Clear the window
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw your graphics here

        // Swap the front and back buffers
        glfwSwapBuffers(window);
    }

    // Clean up

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}