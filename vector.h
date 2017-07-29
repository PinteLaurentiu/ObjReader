#include <type_traits>
#include <vector>
#include <initializer_list>

template<typename T, unsigned int N, T DefaultValue>
class MathVector;

class MathVectorHelper {
private:
    template<typename T, unsigned int N, T DefaultValue>
    friend class MathVector;

    template<typename... Ts>
    struct all_same : std::false_type { };//TODO: Rename

    template<typename T>
    struct all_same<T> : std::true_type { };

    template<typename T, typename... Ts>
    struct all_same<T, T, Ts...> : all_same<T, Ts...> { };
};

template<typename T, unsigned int N, T DefaultValue = 0>
class MathVector
{
private:
    T* data;
public:
    MathVector();

    template<typename... T2,
             typename std::enable_if<sizeof...(T2) == N, int>::type = 0,
             typename std::enable_if<MathVectorHelper::all_same<T, T2...>::value, int>::type = 0>
    MathVector(T2... args);

    template<unsigned int N2,
             typename... T2,
             typename std::enable_if<sizeof...(T2) + N2 == N, int>::type = 0,
             typename std::enable_if<MathVectorHelper::all_same<T, T2...>::value, int>::type = 0>
    MathVector(const MathVector<T, N2, DefaultValue>& other, T2... args);

    virtual ~MathVector();

    T& operator[](unsigned int i);

    const T& operator[](unsigned int i) const;


};

template <typename T,
          unsigned int N,
          T DefaultValue>
MathVector<T,N,DefaultValue>::MathVector() {
    data = new T[N];
    for (unsigned int i = 0; i < N; i++)
        data[i] = DefaultValue;
}

template <typename T,
          unsigned int N,
          T DefaultValue>
template <typename... T2,
          typename std::enable_if<sizeof...(T2) == N, int>::type,
          typename std::enable_if<MathVectorHelper::all_same<T, T2...>::value, int>::type>
MathVector<T,N,DefaultValue>::MathVector(T2... args) {
    data = new T[N];
    int i = 0;
    for (T t : {args...}) {
        data[i] = t;
        i++;
    }
}

template <typename T,
          unsigned int N,
          T DefaultValue>
template <unsigned int N2,
          typename... T2,
          typename std::enable_if<sizeof...(T2) + N2 == N, int>::type,
          typename std::enable_if<MathVectorHelper::all_same<T, T2...>::value, int>::type>
MathVector<T,N,DefaultValue>::MathVector(const MathVector<T, N2, DefaultValue>& other, T2... args) {
    data = new T[N];
    for (int i = 0; i < N2; i++)
    {
        data[i] = other[i];
    }
    int i = N2;
    for (T t : {args...}) {
        data[i] = t;
        i++;
    }
}

template <typename T,
          unsigned int N,
          T DefaultValue>
MathVector<T,N,DefaultValue>::~MathVector() {}

template <typename T,
          unsigned int N,
          T DefaultValue>
T& MathVector<T,N,DefaultValue>::operator[](unsigned int i) {
    return data[i];
}

template <typename T,
          unsigned int N,
          T DefaultValue>
const T& MathVector<T,N,DefaultValue>::operator[](unsigned int i) const {
    return data[i];
}
