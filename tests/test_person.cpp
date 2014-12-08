#include "person.h"

#include <string>
#include <sstream>

#include <gtest/gtest.h>


TEST(TestPerson, Ctor1) {
    std::string firstname = "John";
    std::string lastname = "Smith";

    Person p(firstname, lastname);
    EXPECT_EQ(firstname, p.firstname());
    EXPECT_EQ(lastname, p.lastname());
}

TEST(TestPerson, Ctor2) {
    std::string firstname = "John";
    std::string lastname = "Smith";

    Person p(std::move(firstname), lastname);
    EXPECT_TRUE(firstname.empty());

    EXPECT_EQ("John", p.firstname());
    EXPECT_EQ(lastname, p.lastname());
}

TEST(TestPerson, Ctor3) {
    std::string firstname = "John";
    std::string lastname = "Smith";

    Person p(firstname, std::move(lastname));
    EXPECT_TRUE(lastname.empty());

    EXPECT_EQ(firstname, p.firstname());
    EXPECT_EQ("Smith", p.lastname());
}

TEST(TestPerson, Ctor4) {
    std::string firstname = "John";
    std::string lastname = "Smith";

    Person p(std::move(firstname), std::move(lastname));
    EXPECT_TRUE(firstname.empty());
    EXPECT_TRUE(lastname.empty());

    EXPECT_EQ("John", p.firstname());
    EXPECT_EQ("Smith", p.lastname());
}

TEST(TestPerson, CtorInvalidFirstName) {
    EXPECT_THROW(Person("", "Smith"), std::invalid_argument);
}

TEST(TestPerson, CtorInvalidLastName) {
    EXPECT_THROW(Person("John", ""), std::invalid_argument);
}

TEST(TestPerson, Printer) {
    std::ostringstream stream;

    Person p("John", "Smith");
    stream << p;
    EXPECT_EQ("Smith J.", stream.str());
}


