//
// Created by artur on 30/01/2020.
//

#include <memory>

#include "ViewController.hh"
#include "ViewMenu.hh"
#include "ViewGame.hh"


ViewController::ViewController(Shared *_shared) :
        shared(_shared),
        currentView(new ViewMenu(this)) {

}

void ViewController::display() {
    currentView->display();
}

Shared *ViewController::getShared() const {
    return shared;
}

void ViewController::switchTo(ViewEnum view) {
    switch (view) {
        case ViewEnum::menu:
            currentView = std::make_unique<ViewMenu>(this);
            break;
        case ViewEnum::game:
            currentView = std::make_unique<ViewGame>(this);
            break;
    }
}
