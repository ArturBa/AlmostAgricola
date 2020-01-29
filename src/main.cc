#include "View.hh"

int main() {
    Model model;
    View view(&model);
    view.processEvents();
}