#include <iostream>
#include <vector>
#include <cstring>
#include <type_traits> // Para std::enable_if y std::is_same

using namespace std;

// Sobrecarga de fff para std::vector
template<typename T>
void fff(const char* x, const std::vector<T>& vec) { 
    cout << x << " : [";
    for(size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

// Plantilla fff para tipos generales con SFINAE
template<typename T>
typename enable_if<!is_same<typename decay<T>::type, std::vector<typename decay<T>::type::value_type>>::value>::type
fff(const char* x, T&& val1) { 
    cout << x << " : " << std::forward<T>(val1) << "\n"; 
}

// Caso base para la recursión variádica
void fff(const char* x) { }

// Plantilla variádica fff para múltiples argumentos
template<typename T1, typename... Tn>
void fff(const char* x, T1&& val1, Tn&&... valn) {
    const char* xd = strchr(x+1, ',');
    cout.write(x, xd-x) << " : " << std::forward<T1>(val1);
    if constexpr (sizeof...(valn) > 0) {
        cout << " | ";
        fff(xd+1, std::forward<Tn>(valn)...);
    } else {
        cout << "\n";
    }
}

#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)

int main() {
    int a = 5;
    double b = 3.14;
    std::string c = "hello";
    std::vector<int> d = {1, 2, 3, 4, 5};

    trace(a, b, c, d);
    return 0;
}
