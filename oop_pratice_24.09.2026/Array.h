#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array
{
private:
    T* data;
    int size;
    int count;
    int grow;

public:
    Array()
    {
        data = nullptr;
        size = 0;
        count = 0;
        grow = 1;
    }

    Array(int size, int grow = 1)
    {
        if (size < 0 || grow <= 0)
            throw invalid_argument("Invalid size or grow");

        this->size = size;
        this->grow = grow;
        count = 0;
        data = size > 0 ? new T[size]{} : nullptr;
    }

    Array(const Array<T>& obj)
    {
        size = obj.size;
        count = obj.count;
        grow = obj.grow;

        data = size > 0 ? new T[size]{} : nullptr;

        for (int i = 0; i < count; i++)
            data[i] = obj.data[i];
    }

    ~Array()
    {
        delete[] data;
    }

    int GetSize() const
    {
        return size;
    }

    void SetSize(int newSize, int newGrow = 1)
    {
        if (newSize < 0 || newGrow <= 0)
            throw invalid_argument("Invalid size or grow");

        if (newSize != size)
        {
            T* temp = newSize > 0 ? new T[newSize]{} : nullptr;

            int limit = count;

            if (limit > newSize)
                limit = newSize;

            for (int i = 0; i < limit; i++)
                temp[i] = data[i];

            delete[] data;

            data = temp;
            size = newSize;
            count = limit;
        }

        grow = newGrow;
    }

    int GetUpperBound() const
    {
        return count - 1;
    }

    bool IsEmpty() const
    {
        return count == 0;
    }

    void FreeExtra()
    {
        SetSize(count, grow);
    }

    void RemoveAll()
    {
        delete[] data;

        data = nullptr;
        size = 0;
        count = 0;
    }

    T& GetAt(int index)
    {
        if (index < 0 || index >= count)
            throw out_of_range("Invalid index");

        return data[index];
    }

    const T& GetAt(int index) const
    {
        if (index < 0 || index >= count)
            throw out_of_range("Invalid index");

        return data[index];
    }

    void SetAt(int index, const T& value)
    {
        if (index < 0 || index >= size)
            throw out_of_range("Invalid index");

        data[index] = value;

        if (index >= count)
            count = index + 1;
    }

    T& operator[](int index)
    {
        return GetAt(index);
    }

    const T& operator[](int index) const
    {
        return GetAt(index);
    }

    void Add(const T& value)
    {
        if (count >= size)
            SetSize(size + grow, grow);

        data[count] = value;
        count++;
    }

    void Append(const Array<T>& obj)
    {
        if (this == &obj)
        {
            Array<T> temp(obj);
            Append(temp);
            return;
        }

        int required = count + obj.count;

        if (required > size)
        {
            int newSize = size;

            while (newSize < required)
                newSize += grow;

            SetSize(newSize, grow);
        }

        for (int i = 0; i < obj.count; i++)
        {
            data[count] = obj.data[i];
            count++;
        }
    }

    Array<T>& operator=(const Array<T>& obj)
    {
        if (this == &obj)
            return *this;

        T* temp = obj.size > 0 ? new T[obj.size]{} : nullptr;

        try
        {
            for (int i = 0; i < obj.count; i++)
                temp[i] = obj.data[i];
        }
        catch (...)
        {
            delete[] temp;
            throw;
        }

        delete[] data;

        data = temp;
        size = obj.size;
        count = obj.count;
        grow = obj.grow;

        return *this;
    }

    T* GetData()
    {
        return data;
    }

    const T* GetData() const
    {
        return data;
    }

    void InsertAt(int index, const T& value)
    {
        if (index < 0 || index > count)
            throw out_of_range("Invalid index");

        if (count >= size)
            SetSize(size + grow, grow);

        for (int i = count; i > index; i--)
            data[i] = data[i - 1];

        data[index] = value;
        count++;
    }

    void InsertAt(int index, const Array<T>& obj)
    {
        if (index < 0 || index > count)
            throw out_of_range("Invalid index");

        if (this == &obj)
        {
            Array<T> temp(obj);
            InsertAt(index, temp);
            return;
        }

        if (obj.count == 0)
            return;

        int required = count + obj.count;

        if (required > size)
        {
            int newSize = size;

            while (newSize < required)
                newSize += grow;

            SetSize(newSize, grow);
        }

        for (int i = count - 1; i >= index; i--)
            data[i + obj.count] = data[i];

        for (int i = 0; i < obj.count; i++)
            data[index + i] = obj.data[i];

        count = required;
    }

    void RemoveAt(int index, int amount = 1)
    {
        if (index < 0 || amount < 1 ||
            index >= count || amount > count - index)
            throw out_of_range("Invalid index or amount");

        for (int i = index; i < count - amount; i++)
            data[i] = data[i + amount];

        count -= amount;

        for (int i = count; i < count + amount; i++)
            data[i] = T{};
    }

    void Show() const
    {
        for (int i = 0; i < count; i++)
            cout << data[i] << " ";

        cout << endl;
    }
};

