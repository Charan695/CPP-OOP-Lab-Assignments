#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

// Owns a dynamic array and implements all five special member functions.
class IntBuffer {
private:
    int* data;
    size_t size;

public:
    IntBuffer() : data(nullptr), size(0) {
        cout << "Default constructor\n";
    }

    explicit IntBuffer(size_t count)
        : data(count ? new int[count]{} : nullptr), size(count) {
        cout << "Parameterized constructor\n";
    }

    // Deep-copy constructor.
    IntBuffer(const IntBuffer& other)
        : data(other.size ? new int[other.size] : nullptr), size(other.size) {
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
        cout << "Copy constructor\n";
    }

    // Copy assignment uses a temporary, then swaps resources.
    IntBuffer& operator=(const IntBuffer& other) {
        if (this != &other) {
            IntBuffer temporary(other);
            swap(data, temporary.data);
            swap(size, temporary.size);
        }
        cout << "Copy assignment operator\n";
        return *this;
    }

    // Move constructor transfers ownership.
    IntBuffer(IntBuffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor\n";
    }

    // Move assignment releases the old allocation, then takes ownership.
    IntBuffer& operator=(IntBuffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        cout << "Move assignment operator\n";
        return *this;
    }

    ~IntBuffer() {
        delete[] data;
        cout << "Destructor called\n";
    }

    void set(size_t index, int value) {
        if (index >= size) throw out_of_range("Buffer index out of range");
        data[index] = value;
    }

    void display() const {
        for (size_t i = 0; i < size; ++i) cout << data[i] << ' ';
        cout << '\n';
    }
};

int main() {
    IntBuffer empty;
    IntBuffer original(3);
    original.set(0, 10);
    original.set(1, 20);
    original.set(2, 30);
    cout << "Original: ";
    original.display();

    IntBuffer copied(original);
    cout << "Copied: ";
    copied.display();

    IntBuffer copyAssigned;
    copyAssigned = original;
    cout << "Copy assigned: ";
    copyAssigned.display();

    IntBuffer moved(std::move(original));
    cout << "Move constructed: ";
    moved.display();

    IntBuffer moveAssigned;
    moveAssigned = std::move(copied);
    cout << "Move assigned: ";
    moveAssigned.display();
    return 0;
}
