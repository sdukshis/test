#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <utility>
#include <stdexcept>
#include <ostream>

class Person {
 public:
    template<class T, class U>
    Person(T &&firstname, U &&lastname) {
        firstname_ = std::forward<T>(firstname);
        lastname_ = std::forward<U>(lastname);

        if (firstname_.empty() ||
               lastname_.empty()) {
            throw std::invalid_argument("firstname and lastname must not be empty");
        }
    }

    template<class T>
    Person & firstname(T &&_firstname) {
        std::string tmp = std::forward<T>(_firstname);
        if (tmp.empty()) {
            throw std::invalid_argument("firstname must not be empty");
        }
        firstname_ = std::move(tmp);
        return *this;
    }

    template<class T>
    Person & lastname(T &&_lastname) {
        std::string tmp = std::forward<T>(_lastname);
        if (tmp.empty()) {
            throw std::invalid_argument("lastname must not be empty");
        }
        lastname_ = std::move(tmp);
        return *this;
    }

    const std::string & firstname() const {
        return firstname_;
    }

    const std::string & lastname() const {
        return lastname_;
    }

 private:
    std::string firstname_;
    std::string lastname_;
};  // class Person

std::ostream & operator<<(std::ostream &stream, const Person &person) {
    return stream << person.lastname() << " " << person.firstname().front() << ".";
}

#endif  // PERSON_H
