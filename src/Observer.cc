//
// Created by artur on 19/02/2020.
//

#include "Observer.hh"

Observer::Observer(Sender *_sender) {
    sender = _sender;
    sender->attach(*this);
}

Observer::~Observer() {
    sender->detach(*this);

}
