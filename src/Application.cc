//
// Created by artur on 30/01/2020.
//

#include "Application.hh"

Application::Application() :
        settings(), window(&settings) {
}

void Application::start() {
    window.start();
}
