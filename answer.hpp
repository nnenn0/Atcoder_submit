#include <bits/stdc++.h>

namespace AtCoder
{
    template <typename T, typename = void>
    struct is_container : std::false_type {};

    template <typename... Ts>
    struct is_container_helper {};

    template <typename T>
    struct is_container<
        T,
        std::conditional_t<
            false,
            is_container_helper<
                typename T::value_type,
                typename T::size_type,
                typename T::iterator,
                typename T::const_iterator,
                decltype(std::declval<T>().size()),
                decltype(std::declval<T>().begin()),
                decltype(std::declval<T>().end()),
                decltype(std::declval<T>().cbegin()),
                decltype(std::declval<T>().cend()),
                decltype(std::declval<T>().back())>,
            void>> : public std::true_type
    {
    };

    template <typename T>
    constexpr auto is_container_v = is_container<T>::value;

    auto answer(){};

    template <typename Head, typename... Tail,
            std::enable_if_t<is_container_v<std::remove_reference_t<Head>> && 
            !is_container_v<typename std::remove_reference_t<Head>::value_type>, std::nullptr_t> = nullptr>
    auto answer(Head &&head, Tail &&... tail)
    {
        for (auto &&h : head)
        {
            if (&h != &head.back())
                std::cout << h << " ";
            else
                std::cout << h << std::endl;
        }
        answer(std::forward<Tail>(tail)...);
    }

    template <typename Head, typename... Tail,
            std::enable_if_t<is_container_v<std::remove_reference_t<Head>> && 
            is_container_v<typename std::remove_reference_t<Head>::value_type>,
            std::nullptr_t> = nullptr>
    auto answer(Head &&head, Tail &&... tail)
    {
        for (auto &&h : head)
        {
            for (auto &&a : h)
            {
                if (&a != &h.back())
                    std::cout << a << " ";
                else
                    std::cout << a << std::endl;
            }
        }
        answer(std::forward<Tail>(tail)...);
    }

    template <template <typename, size_t> typename Head, size_t Size,
            typename... Tail, 
            std::enable_if_t<is_container_v<std::remove_reference_t<Head<std::string, Size>>>, 
            std::nullptr_t> = nullptr>
    auto answer(Head<std::string, Size> head, Tail &&... tail)
    {
        for (auto &&h : head)
        {
            if (&h != &head.back())
                std::cout << h << " ";
            else
                std::cout << h << std::endl;
        }
        answer(std::forward<Tail>(tail)...);
    }

    template <template <typename Elem, 
    typename Allocator = std::allocator<Elem>> typename Head, 
    typename... Tail>
    auto answer(Head<std::string> &&head, Tail &&... tail)
    {
        for (auto &&h : head)
        {
            if (&h != &head.back())
                std::cout << h << " ";
            else
                std::cout << h << std::endl;
        }
        answer(std::forward<Tail>(tail)...);
    }

    template <typename Head, typename... Tail, 
    std::enable_if_t<!is_container_v<std::remove_reference_t<Head>>, 
    std::nullptr_t> = nullptr>
    auto answer(Head &&head, Tail &&... tail)
    {
        if (sizeof...(Tail))
            std::cout << head << " ";
        else
            std::cout << head << std::endl;
        answer(std::forward<Tail>(tail)...);
    }

    template <typename... Tail>
    auto answer(std::string &&head, Tail &&... tail)
    {
        if (sizeof...(Tail))
            std::cout << head << " ";
        else
            std::cout << head << std::endl;
        answer(std::forward<Tail>(tail)...);
    }

} // namespace AtCoder
