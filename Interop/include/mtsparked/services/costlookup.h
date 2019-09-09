#ifndef _MTSPARKED_COSTLOOKUP_H_
#define _MTSPARKED_COSTLOOKUP_H_

template<typename Buffer>
struct CostLookupPlugin {
    using func=Result(*)(Args...);
    func fPtr;
    template<typename T>
    CostLookupPlugin(type_value<T>) 
        : fPtr([](void* obj, Args... args){ return static_cast<T*>(obj)->operator()(args...); })
    { }
    Result (Args... args) override {
        return fPtr(static_cast<void*>(static_cast<Buffer&>(*this)), args...);
    }
};

#endif // _MTSPARKED_COSTLOOKUP_H_
