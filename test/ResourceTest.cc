//
// Created by artur on 27/02/2020.
//
#include <gmock/gmock.h>
#include <Resource.hh>

using namespace ::testing;
using namespace std;

class AResource : public Test {
public:
    AResource() : resource() {}

    Resource resource;
};

TEST_F(AResource, CheckInitValue) {
    ASSERT_EQ(0, resource.getResource());
}

TEST_F(AResource, AddResource) {
    resource.addResource(2);
    ASSERT_EQ(2, resource.getResource());
}

TEST_F(AResource, DecreseResource) {
    resource.addResource(2);
    ASSERT_TRUE(resource.decreaseResource(2));
    ASSERT_EQ(0, resource.getResource());
    ASSERT_FALSE(resource.decreaseResource(2));
}
