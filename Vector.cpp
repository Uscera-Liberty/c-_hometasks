template<typename T>
class Vector {
    T* buffer;
    unsigned int size = 0;
    unsigned int capacity = 10;

    void SetNewCapacity(unsigned int newCap) {
        capacity = newCap;
        T* newBuffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
    }

public:

    Vector() {
        buffer = new T[capacity];
    }

    Vector(unsigned int size) : size(size), capacity(2 * size) {
        buffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            buffer[i] = T();
        }
    }

    Vector(unsigned int size, const T& defaultValue) : size(size), capacity(2 * size) {
        buffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            buffer[i] = defaultValue;
        }
    }

    Vector(const Vector& another) : size(another.size), capacity(another.capacity) {
        buffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            buffer[i] = another.buffer[i];
        }
    }

    Vector& operator=(const Vector& another) {
        if (&another == this) {
            return *this;
        }
        delete[] buffer;
        size = another.size;
        capacity = another.capacity;
        buffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            buffer[i] = another.buffer[i];
        }
    }

    ~Vector() {
        delete[] buffer;
    }

    T& operator[](unsigned int index) {
        return buffer[index];
    }

    const T& operator[](unsigned int index) const {
        return buffer[index];
    }

    void PushBack(const T& element) {
        if (size == capacity) {
            SetNewCapacity(2 * capacity);
        }
        auto newIndex = size;
        buffer[newIndex] = element;
        ++size;
    }

    void PopBack() {
        --size;
    }

    void Resize(unsigned int newSize) {
        if (newSize > capacity) {
            SetNewCapacity(2 * newSize);
        }
        size = newSize;
    }

    unsigned int Size() const {
        return size;
    }
    void Insert(unsigned int atIndex, const T& element) {
        if (size == capacity) {
            SetNewCapacity(2 * capacity);
        }
        for (unsigned int i = size; i >= atIndex + 1; --i) {
            buffer[i] = buffer[i - 1];
        }
        buffer[atIndex] = element;
        ++size;
    }
    void Erase(unsigned int atIndex) {
        for (unsigned int i = atIndex + 1; i < size; ++i) {
            buffer[i - 1] = buffer[i];
        }
        --size;
    }
};
