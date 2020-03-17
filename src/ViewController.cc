//
// Created by artur on 30/01/2020.
//

#include <memory>

#include "ViewController.hh"
#include "ViewMenu.hh"
#include "ViewGame.hh"


ViewController::ViewController(Shared *_shared) :
        shared(_shared),
        currentView(ViewEnum::menu) {
    mapOfViews.insert(std::pair<ViewEnum, std::unique_ptr<ViewAbstract>>(ViewEnum::menu, new ViewMenu(this)));
}

void ViewController::display() {
    mapOfViews.at(currentView)->display();
}

Shared *ViewController::getShared() const {
    return shared;
}

void ViewController::switchTo(ViewEnum view) {
    auto view_it = mapOfViews.find(view);
    if(view_it == mapOfViews.end()){
        switch (view) {
            case ViewEnum::menu:
                mapOfViews.insert(std::pair<ViewEnum, std::unique_ptr<ViewAbstract>>(ViewEnum::menu, new ViewMenu(this)));
                break;
            case ViewEnum::game:
                mapOfViews.insert(std::pair<ViewEnum, std::unique_ptr<ViewAbstract>>(ViewEnum::game, new ViewGame(this)));
                break;
        }
    }
    currentView = view;
}
