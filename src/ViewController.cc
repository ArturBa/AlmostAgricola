//
// Created by artur on 30/01/2020.
//
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
            delete currentView;
            currentView = new ViewMenu(this);
            break;
        case ViewEnum::game:
            delete currentView;
            currentView = new ViewGame(this);
            break;
        case ViewEnum::results:
            // TODO add viewResults
            delete currentView;
            currentView = new ViewMenu(this);
            break;
    }
}
