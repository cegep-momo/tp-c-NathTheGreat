#include "book.h"
#include <iostream>

Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

string Book::getBorrowerName() const {
    return borrowerName;
}

void Book::setTitle(const string& title) {
    this->title = title;
}   

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setISBN(const string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool available) {
    isAvailable = available;
}

void Book::setBorrowerName(const string& name) {
    borrowerName = name;
}

void Book::checkOut(const string& borrower) {
    if (isAvailable) {
        isAvailable = false;
        borrowerName = borrower;
    } else {
        cout << "Le livre est déjà emprunté." << endl;
    }
}

void Book::returnBook() {
    isAvailable = true;
    borrowerName = "";
}

string Book::toString() const {
    string status = isAvailable ? "Disponible" : "Emprunté par " + borrowerName;
    return "Titre: " + title + ", Auteur: " + author + ", ISBN: " + isbn + ", Statut: " + status;
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerName;
}

void Book::fromFileFormat(const string& line) {
    size_t pos = 0;
    size_t prev = 0;
    int fieldIndex = 0;
    string fields[5];

    while ((pos = line.find('|', prev)) != string::npos && fieldIndex < 4) {
        fields[fieldIndex++] = line.substr(prev, pos - prev);
        prev = pos + 1;
    }
    fields[fieldIndex] = line.substr(prev);

    title = fields[0];
    author = fields[1];
    isbn = fields[2];
    isAvailable = (fields[3] == "1");
    borrowerName = fields[4];
}