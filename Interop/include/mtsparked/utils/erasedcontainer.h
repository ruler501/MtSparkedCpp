//
// Created by Devon Richards on 9/9/19.
//
#ifndef MTSPARKED_ERASEDCONTAINER_H
#define MTSPARKED_ERASEDCONTAINER_H

#include <iterator>
#include <type_traits>

#include "compiletimeplugins/utils.h"

template <typename S>
struct CountingIteratorFeature {
    template <typename Buffer>
    class type {
    protected:
        size_t currentCount{0};

        using derefFunc = S&(*)(void *);
        using derefConstFunc = const S&(*)(const void*);
        using arrowFunc = S*(*)(void *);
        using arrowConstFunc = const S*(*)(const void*);
        using incrFunc = void(*)(void *);
        derefFunc derefPtr;
        derefConstFunc derefConstPtr;
        arrowFunc arrowPtr;
        arrowConstFunc arrowConstPtr;
        incrFunc incrPtr;

        template<typename Buf>
        friend class ContainingFeature<S>::type<Buf>;

        using iterator_category = std::forward_iterator_tag;
        using value_type = S;
        using difference_type = std::size_t;
        using pointer = S *;
        using reference = S &;

        template <typename T>
        type(type_value<T>)
                : derefPtr([](void* obj){ return *static_cast<T*>(obj)->operator*();}),
                  derefConstPtr([](const void* obj){ return static_cast<T*>(obj)->operator*(); }),
                  arrowPtr([](void* obj){ return static_cast<T*>(obj)->operator->(); }),
                  arrowConstPtr([](const void* obj){ return static_cast<T*>(obj)->operator->(); }),
                  incrPtr([](void* obj){ static_cast<T*>(obj)->operator++(); })
        { }

    public:
        S& operator*() {
            return this->derefPtr(static_cast<void*>(static_cast<Buffer&>(*this)));
        }

        const S& operator*() const {
            return this->derefConstPtr(static_cast<const void*>(static_cast<const Buffer&>(*this)));
        }

        S* operator->() {
            return this->arrowPtr(static_cast<void*>(static_cast<Buffer&>(*this)));
        }

        const S* operator->() const{
            return this->derefConstPtr(static_cast<const void*>(static_cast<const Buffer&>(*this)));
        }

        Buffer& operator++() {
            this->incrPtr(static_cast<void*>(static_cast<Buffer&>(*this)));
            this->currentCount++;
            return static_cast<Buffer&>(*this);
        }

        friend bool operator==(const type& left, const type& right) {
            return left.currentCount == right.currentCount;
        }

        friend bool operator!=(const type& left, const type& right) {
            return left.currentCount != right.currentCount;
        }
    };
};

template <typename S>
struct ContainerFeature {
    template<typename Buffer>
    class type {
    public:
        using iterator = erased<CountingIteratorFeature<S>::type>;
        using const_iterator = erased<CountingIteratorFeature<const S>::type>

    protected:
        using sizeFunc = std::size_t(*)(const void*);
        using beginFunc = iterator(*)(void*);
        using beginConstFunc = const_iterator(*)(const void*);
        using endFunc = iterator(*)(void*);
        using endConstFunc = const_iterator(*)(const void*);
        sizeFunc sizePtr;
        beginFunc beginPtr;
        beginConstFunc beginConstPtr;
        endFunc endPtr;
        endConstFunc endConstPtr;

        template<typename T, typename=std::enable_if_t<!std::is_base_of<type, T>>>
        type(type_value<T>)
                : sizePtr([](const void* obj){ return static_cast<const T*>(obj)->size(); }),
                  beginPtr([](void* obj){ return iterator(type_list<decltype(std::declval<T>().begin())>{}, static_cast<T*>(obj)->begin());}),
                  beginConstPtr([](const void* obj){ return const_iterator(type_list<decltype(std::declval<const T>().begin())>{}, static_cast<const T*>(obj)->begin());}),
                  endPtr([](void* obj){ iterator result(type_list<decltype(std::declval<T>().begin())>{}, static_cast<T*>(obj)->begin());
                                        result.currentCount = static_cast<const T*>(obj)->size();
                                        return result; }),
                  endConstPtr([](const void* obj){ const_iterator result(type_list<decltype(std::declval<const T>().begin())>{}, static_cast<const T*>(obj)->begin());
                      result.currentCount = static_cast<const T*>(obj)->size();
                      return result; })
        { }

    public:
        std::size_t size() const {
            return this->sizePtr(static_cast<const void*>(static_cast<const Buffer&>(obj)));
        }

        S& at(size_t index) {
            iterator iter = begin();
            return *std::advance(iter, index);
        }

        const S& at(size_t index) const {
            const_iterator iter = begin();
            return *std::advance(iter, index);
        }

        friend S& operator[](type& left, size_t index) {
            return left.at(index);
        }

        friend const S& operator[](const type& left, size_t index) const {
            return left.at(index);
        }

        iterator begin() {
            return this->beginPtr(static_cast<void*>(static_cast<Buffer&>(obj)));
        }

        const_iterator begin() const {
            return this->beginConstPtr(static_cast<const void*>(static_cast<const Buffer&>(obj)));
        }

        iterator end() {
            return this->endPtr(static_cast<void*>(static_cast<Buffer&>(obj)));
        }

        const_iterator end() const {
            return this->endConstPtr(static_cast<const void*>(static_cast<const Buffer&>(obj)));
        }
    };
};

template <typename S>
struct ErasedContainer {
    template<typename... Features>
    using type = erased<ContainerFeature, Features...>;
};

#endif //MTSPARKED_ERASEDCONTAINER_H